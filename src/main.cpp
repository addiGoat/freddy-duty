#include <raylib.h>
#include "button.hpp"


int main() {
    InitWindow(1280, 720, "freddy-duty");
    SetTargetFPS(60);

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
        DrawText(TextFormat("Camera: %i", currentCamera), 40, 40, 40, BLACK);
        EndDrawing();
    }
}
