#include "camManager.hpp"

CamManager::CamManager() {
    // Initialize camera buttons
    for (CamButtonInfo& button : buttonInfo) {
        cameraButtons.emplace_back(Button(button.pos, { 100, 100 }, button.camID));
    }

    //Declare the onClick function for each button
    for (Button& button : cameraButtons) {
        button.onClick = [this, &button]() {
            currentCam = button.cameraNumber;
        };
    }

    // Initialize camera feeds
    cameraFeeds.emplace_back(CamFeed(0, MakeTexture("assets/Cam0.png")));
    cameraFeeds.emplace_back(CamFeed(1, MakeTexture("assets/Cam1.png")));
    cameraFeeds.emplace_back(CamFeed(2, MakeTexture("assets/Cam2.png")));
    cameraFeeds.emplace_back(CamFeed(3, MakeTexture("assets/Cam3.png")));
    cameraFeeds.emplace_back(CamFeed(4, MakeTexture("assets/Cam4.png")));
}

void CamManager::UpdateButtons() {
    for (Button& button : cameraButtons) {
        button.UpdateButton(GetMousePosition());
    }
}

void CamManager::DrawButtons() {
    for (Button& button : cameraButtons) {
        button.DrawButton();
    }
}

void CamManager::DrawInterface() {
    DrawText(TextFormat("Camera: %i", currentCam), 40, 40, 40, BLACK);
}

void CamManager::DrawCameraFeed() {
    Texture2D& tex =  cameraFeeds.at(currentCam).texture;

    Rectangle camDest = {
        0, 0,
        (float)GetScreenWidth(),
        (float)GetScreenHeight(),
    };

    DrawTexturePro(tex,
            {0, 0, (float)tex.width, (float)tex.height},
            camDest,
            {0, 0},
            0.0f,
            WHITE
            );
}
