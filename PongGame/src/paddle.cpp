#include "paddle.h"
#include <raylib.h>

void Paddle::update(bool isLeftPaddle) {
    if (isLeftPaddle) {
        // Steuerung für das linke Paddle (mit 'W' und 'S')
        if (IsKeyDown(KEY_W) && y > 0) {  // Paddle nach oben bewegen
            y -= speed;
        }
        if (IsKeyDown(KEY_S) && y < GetScreenHeight() - height) {  // Paddle nach unten bewegen
            y += speed;
        }
    } else {
        // Steuerung für das rechte Paddle (mit Pfeiltasten)
        if (IsKeyDown(KEY_UP) && y > 0) {  // Paddle nach oben bewegen
            y -= speed;
        }
        if (IsKeyDown(KEY_DOWN) && y < GetScreenHeight() - height) {  // Paddle nach unten bewegen
            y += speed;
        }
    }
}

void Paddle::draw() {
    DrawRectangle(x, y, width, height, RAYWHITE);
}
