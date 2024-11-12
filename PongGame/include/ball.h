#pragma once
#include "gameObject.h"

class Ball : public GameObject {

public:
    float velocityX, velocityY; //Ballgeschwindigkeit

    //Konstruktor
    Ball(float x, float y, float size, float velocityX, float velocityY)
        : GameObject(x, y, size, size), velocityX(velocityX), velocityY(velocityY) {}

    void update();

    //Mehtode zum Überschreiben
    void draw() override;
};
