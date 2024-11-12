#pragma once
#include "gameObject.h"


class Paddle : public GameObject{

private:
    float speed; //Geschwindigkeit

public:
    // Konstruktor
    Paddle(float x, float y, float width, float height, float speed)
       : GameObject(x, y, width, height), speed(speed) {}

    // Update-Methode: Steuerung der Paddles, je nachdem, ob linkes oder rechtes Paddle
    void update(bool isLeftPaddle);

    // Getter für Position
    float getX() const override  { return x; }
    float getY() const override  { return y; }

    // Zeichnen des Paddles
    void draw() override;
};
