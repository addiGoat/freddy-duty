#include <raylib.h>
#include <iostream>
#include <functional>

enum ButtonState { IDLE, HOVER, PRESS };

struct ButtonStyle {
    Color idle;
    Color hover;
    Color press;
};

class Button {
public:
    Button(Vector2 pos, Vector2 size, ButtonStyle s = { GRAY, GREEN, RED }) {
        bounds = { pos.x, pos.y, size.x, size.y };
        style = s;
    };

    void UpdateButton(Vector2 mousePos) {
        if (CheckCollisionPointRec(mousePos, bounds)) {
            state = HOVER;
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
                state = PRESS;
            }
            if (onClick && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) onClick();
        }
        switch (state) {
            case IDLE: color = style.idle; break;
            case HOVER: color = style.press; break;
            case PRESS: color = style.idle; break;
        }
    };

    void DrawButton() {
        DrawRectangleRec(bounds, color);
    };

    std::function<void()> onClick;

private:
    Rectangle bounds;
    Color color;

    ButtonStyle style;
    ButtonState state;
};

int main() {
    InitWindow(1280, 720, "Window");
    SetTargetFPS(60);

    Button testButton({ 640, 320 }, { 100, 80 });

    testButton.onClick = []() {
        std::cout << "Button Clicked\n";
    };

    while (!WindowShouldClose()) {
        testButton.UpdateButton(GetMousePosition());

        BeginDrawing();
        ClearBackground(RAYWHITE);

        testButton.DrawButton();
        DrawText("hello nerd", 40, 40, 40, BLACK);
        EndDrawing();
    }
}
