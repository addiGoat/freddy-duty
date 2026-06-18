#include <raylib.h>
#include <functional>

enum ButtonState { IDLE, HOVER, PRESS };

struct ButtonStyle {
    Color idle;
    Color hover;
    Color press;
};

class Button {
public:
    Button(Vector2 pos, Vector2 size, int camera, ButtonStyle s = { GRAY, GREEN, RED });

    void UpdateButton(Vector2 mousePos);
    void DrawButton();

    std::function<void()> onClick;

    int cameraNumber;
private:
    Rectangle bounds;
    Color color;

    ButtonStyle style;
    ButtonState state;
};
