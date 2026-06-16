#include <raylib.h>
#include "button.hpp"

Button::Button(Vector2 pos, Vector2 size, int camera, ButtonStyle s) 
    : cameraNumber(camera), bounds({ pos.x, pos.y, size.x, size.y }), style(s) {};

void Button::UpdateButton(Vector2 mousePos) {
    if (CheckCollisionPointRec(mousePos, bounds)) {
        state = HOVER;
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            state = PRESS;
        }
        if (onClick && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) onClick();
    }
    else state = IDLE;
    switch (state) {
        case IDLE: color = style.idle; break;
        case HOVER: color = style.hover; break;
        case PRESS: color = style.press; break;
    }
};

void Button::DrawButton() {
    DrawRectangleRec(bounds, color);
    DrawText(
        TextFormat("%i", cameraNumber),
        (bounds.x + (bounds.width / 2.0f) - (MeasureText(TextFormat("%i", cameraNumber), 42) / 2.0f)),
        (bounds.y + (bounds.height / 2.0f) - (42 / 2.0f)),
        42,
        RAYWHITE
            );
}
