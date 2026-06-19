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
            40, 40, 40, BLACK
            );
}

int main() {
    int windowWidth = 1280;
    int windowHeight = 720;
    InitWindow(windowWidth, windowHeight, "freddy-duty");
    SetTargetFPS(120);

    CamManager camManager;

    Rectangle camDest = {
        0, 0,
        (float)GetScreenWidth(),
        (float)GetScreenHeight(),
    };

    while (!WindowShouldClose()) {
        camManager.UpdateButtons();

        BeginDrawing();
        ClearBackground(RAYWHITE);

        camManager.DrawButtons();
        camManager.DrawInterface();
        
        EndDrawing();
    }
}

