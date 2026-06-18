#include <raylib.h>
#include "button.hpp"

struct CamButtonInfo {
    Vector2 pos;
    int camID;
};

struct CamFeed {
    int ID;
    Texture2D feedTexture;
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
    std::vector<Button> cameraButtons;
    std::vector<CamFeed> cameraFeeds;
};
