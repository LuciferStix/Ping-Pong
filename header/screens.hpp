#ifndef SCREEENS
#define SCREENS

#include <raylib.h>

#include "../shared/shared.hpp"
#include "./objects.hpp"
#include "./keypress.hpp"

using namespace std;
void FirstScreen()
{
    ClearBackground(RED);
    BeginDrawing();
    {
        DrawText("Let's Roll", ScreenWidth / 4 + 200, ScreenHeight / 2, 35, YELLOW);
    }
    EndDrawing();
}

void MainScreen(Paddle &paddle, PingPong &ball, ScoreBoard &score)
{
    ClearBackground(DARKGRAY);
    BeginDrawing();
    {
        DrawText("Ping Pong World", ScreenWidth / 4 + 200, ScreenHeight / 2, 32, CLITERAL(Color){255, 228, 48, 255});
        score.Draw();
        Collision(paddle, ball, score);
        paddle.Draw();
        ball.Draw();
        ListenKeyP(paddle);
    }
    EndDrawing();
}

void EndScreen()
{
    std::string endtext = "Game Over !!!!\n You Scored :";
    // endtext.append(std::to_string());

    ClearBackground(RED);
    BeginDrawing();
    {
        DrawText("Game Over", ScreenWidth / 4 + 200, ScreenHeight / 2, 32, YELLOW);
    }
    EndDrawing();
}
#endif