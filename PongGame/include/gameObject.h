#pragma once

class GameObject {

protected:
    float x, y;  // Position
    float width, height;  // Größe

public:
    //Konstruktor
    GameObject(float x, float y, float width, float height)
        : x(x), y(y), width(width), height(height) {}

    //Destruktor
    virtual ~GameObject() = default;

    virtual void draw() = 0;    // Virtuelle Methode zum Zeichnen des Objekts

    // Getter und Setter
    virtual float getX() const { return x; }
    virtual float getY() const { return y; }
    float getWidth() const { return width; }
    float getHeight() const { return height; }

    void setPosition(float x, float y) { this->x = x; this->y = y; }
};
