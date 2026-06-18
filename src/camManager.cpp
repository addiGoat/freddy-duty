#include "camManager.hpp"

CamManager::CamManager() {
    cameraButtons.emplace_back(Button({ 200, 200 }, { 100, 100 }, 1));
    cameraButtons.emplace_back(Button({ 600, 200 }, { 100, 100 }, 2));


    for (Button& button : cameraButtons) {
        button.onClick = [this, &button]() {
            currentCam = button.cameraNumber;
        };
    }
    // cameraButtons[0].onClick = [this]() {
    //     currentCam = cameraButtons[0].cameraNumber;
    // };
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

}
