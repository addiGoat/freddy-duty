#include <raylib.h>
#include "camManager.hpp"

void DrawDebugCursor(Vector2 mousePos) {
    DrawLine(
            mousePos.x,
            mousePos.y - 20,
            mousePos.x,
            mousePos.y + 20,
            BLACK
            );

    DrawLine(
            mousePos.x - 20,
            mousePos.y,
            mousePos.x + 20,
            mousePos.y,
            BLACK
            );

    int x = mousePos.x;
    int y = mousePos.y;
    DrawText(
            TextFormat("X: %i, Y: %i", x, y),
            1000, 20, 40, BLACK
            );
}


enum GameMode { OFFICE, CAMERA };

int main() {
    int windowWidth = 1280;
    int windowHeight = 720;
    InitWindow(windowWidth, windowHeight, "freddy-duty");
    SetTargetFPS(60);

    CamManager camManager;
    
    // Define the camera to look into our 3d world
    Camera3D camera;
    camera.position = (Vector3){ 0.0f, 10.0f, 9.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };

    GameMode gameMode = OFFICE;
    
    DisableCursor();
    while (!WindowShouldClose()) {
        camManager.UpdateButtons();
        UpdateCamera(&camera, CAMERA_PERSPECTIVE);

        if (IsKeyPressed(KEY_Z)) camera.target = (Vector3){ 0.0f, 5.0f, 0.0f };

        BeginDrawing();
        ClearBackground(RAYWHITE);
        switch (gameMode) {
            case OFFICE:
                BeginMode3D(camera);
                    DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
                    DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);
                    DrawGrid(10, 1.0f);
                EndMode3D();
                break;
            case CAMERA:
                camManager.DrawCameraFeed();
                camManager.DrawButtons();
                camManager.DrawInterface();
                break;
        }



        DrawDebugCursor(GetMousePosition());
        
        EndDrawing();
    }
}

