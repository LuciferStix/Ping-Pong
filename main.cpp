#include <raylib.h>

#include "./shared/shared.hpp"
#include "./header/windows.hpp"
#include "./header/keypress.hpp"
#include "./header/screens.hpp"
// driver code
int main()
{
    // initializing window
    InitWin();

    // initializing ball and paddle
    Paddle paddle(PaddleWidth, PaddleHeight, Pad, 0, GREEN);
    PingPong ball(BallRadius, YELLOW);
    ScoreBoard score = ScoreBoard();

    // game loop
    while (!WindowShouldClose())
    {
        switch (gmscr)
        {
        case START:
            FirstScreen();
            break;
        case GAMEPLAY:
            MainScreen(paddle, ball, score);
            break;
        case END:
            EndScreen();
            break;
        }

        switch (gmscr)
        {
        case START:
            if (IsKeyPressed(KEY_ENTER))
                gmscr = GAMEPLAY;
            break;
        case GAMEPLAY:
            if (GameOver)
                gmscr = END;
            break;
        case END:
            if (IsKeyPressed(KEY_ENTER))
                exit(0);
        }
    }

    // close window
    CloseWindow();
    return 0;
}