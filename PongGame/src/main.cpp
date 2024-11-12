#include <raylib.h>
#include "paddle.h"
#include "ball.h"
#include "gameObject.h"

constexpr int SCREEN_WIDTH = 800;
constexpr int SCREEN_HEIGHT = 600;

constexpr int PADDLE_WIDTH = 20;
constexpr int PADDLE_HEIGHT = 100;
constexpr int BALL_SIZE = 20;
constexpr float PADDLE_SPEED = 5.0f;
constexpr float BALL_SPEED_X = 4.0f;
constexpr float BALL_SPEED_Y = 4.0f;

int main() {
    // Initialisiere Raylib
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pong in C++");

    // Spielobjekte erstellen
    Paddle leftPaddle(50.0f, SCREEN_HEIGHT / 2 - PADDLE_HEIGHT / 2, PADDLE_WIDTH, PADDLE_HEIGHT, PADDLE_SPEED);
    Paddle rightPaddle(SCREEN_WIDTH - 50.0f - PADDLE_WIDTH, SCREEN_HEIGHT / 2 - PADDLE_HEIGHT / 2, PADDLE_WIDTH, PADDLE_HEIGHT, PADDLE_SPEED);
    Ball ball(SCREEN_WIDTH / 2 - BALL_SIZE / 2, SCREEN_HEIGHT / 2 - BALL_SIZE / 2, BALL_SIZE, BALL_SPEED_X, BALL_SPEED_Y);

    // Framerate setzen
    SetTargetFPS(60);

    bool gameStarted = false;  // Spiel erst nach Tastendruck starten
    bool gameOver = false;


    // Game loop
    while (!WindowShouldClose()) {
        if (!gameStarted) {
            if (IsKeyDown(KEY_SPACE)) {
                gameStarted = true;
            }
        } else if(!gameOver) {
            // Eingaben und Updates
            leftPaddle.update(true);  // Linkes Paddle steuern (mit 'W' und 'S')
            rightPaddle.update(false);  // Rechtes Paddle steuern (mit Pfeiltasten)
            ball.update();

            // Ballkollision mit Paddles
            if (ball.getX() <= leftPaddle.getX() + PADDLE_WIDTH && ball.getY() + BALL_SIZE >= leftPaddle.getY() && ball.getY() <= leftPaddle.getY() + PADDLE_HEIGHT) {
                ball.velocityX *= -1;
            }
            if (ball.getX() >= rightPaddle.getX() - BALL_SIZE && ball.getY() + BALL_SIZE >= rightPaddle.getY() && ball.getY() <= rightPaddle.getY() + PADDLE_HEIGHT) {
                ball.velocityX *= -1;
            }

            // Überprüfe ob der Ball aus dem Bildschirm fliegt
            if (ball.getX() < 0 || ball.getX() > SCREEN_WIDTH) {
                gameOver = true;
            }
        }
        // Zeichen
        BeginDrawing();
        ClearBackground(BLACK);

        if (!gameStarted) {

            // Startbildschirm anzeigen
            DrawText("Press SPACE to start", SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT / 2 - 10, 25, RAYWHITE);
            DrawText("S + W to control", 30, SCREEN_HEIGHT / 2 + 200, 18, RAYWHITE); // Linke Seite
            DrawText("Key UP + Key DOWN to control", SCREEN_WIDTH - 300, SCREEN_HEIGHT / 2 + 200, 18, RAYWHITE); // Rechte Seite

            // Game Over Text zeichnen
        } else if (gameOver) {
            DrawText("GAME OVER!", SCREEN_WIDTH / 2 - 120, SCREEN_HEIGHT / 2 - 20, 40, RAYWHITE);

            //Paddles und Ball zeichnen
        } else {
            leftPaddle.draw();
            rightPaddle.draw();
            ball.draw();
        }
        EndDrawing();
    }

    // Raylib schließen
    CloseWindow();

    return 0;
}
