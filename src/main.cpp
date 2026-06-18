#include <raylib.h>
#include "camManager.hpp"

Texture2D MakeTexture(const char *fileName) {
    Image img = LoadImage(fileName);
    Texture2D tex = LoadTextureFromImage(img);
    UnloadImage(img);
    return tex;
}

int main() {
    InitWindow(1280, 720, "freddy-duty");
    SetTargetFPS(60);

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

