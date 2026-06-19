#include <raylib.h>
#include "button.hpp"

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

    int currentCamera = 0;

    Button testButton({ 640, 320 }, { 100, 80 }, 1);

    testButton.onClick = [&]() {
        currentCamera = testButton.cameraNumber;
    };

    while (!WindowShouldClose()) {
        testButton.UpdateButton(GetMousePosition());

        BeginDrawing();
        ClearBackground(RAYWHITE);

        testButton.DrawButton();
        DrawText(TextFormat("Camera: %i", currentCamera),
                windowWidth / 2, 40, 40, BLACK);

        DrawDebugCursor(GetMousePosition());
        EndDrawing();
    }
}
