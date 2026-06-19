#include <raylib.h>
#include "button.hpp"

struct CamButtonInfo {
    int camID;
    Vector2 pos;
};

struct CamFeed {
    int ID;
    Texture2D texture;
};

class CamManager {
public:
    CamManager();

    int GetCurrentCam();
    void SetCurrentCam();

    void UpdateButtons();
    void DrawButtons();
    void DrawInterface();
    void DrawCameraFeed();
    
private:
    int currentCam = 0;
    std::vector<CamButtonInfo> buttonInfo = {
        { 0, { 400, 400 }},
        { 1, { 200, 200 }},
        { 2, { 600, 200 }},
        { 3, { 200, 600 }},
        { 4, { 600, 600 }},
    };
    std::vector<Button> cameraButtons;
    std::vector<CamFeed> cameraFeeds;

    Texture2D MakeTexture(const char* fileName) {
        Image img = LoadImage(fileName);
        Texture2D tex = LoadTextureFromImage(img);
        UnloadImage(img);
        return tex;
    }
};
