#include "ball.h"
#include <raylib.h>

void Ball::update() {
    x += velocityX;
    y += velocityY;

    // Ballkollision mit den Wänden
    if (y <= 0 || y >= GetScreenHeight() - height) {
        velocityY *= -1;  // Umkehren der Y-Geschwindigkeit
    }
}

void Ball::draw() {
    DrawCircle(x + width / 2, y + height / 2, width / 2, RAYWHITE);
}
