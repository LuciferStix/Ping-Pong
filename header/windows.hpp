
#ifndef WINDOW
#define WINDOW

#include <raylib.h>
#include "../shared/shared.hpp"
#include "./objects.hpp"

// initializing window
void InitWin()
{
    InitWindow(ScreenWidth, ScreenHeight, "ping pong");
    SetTargetFPS(60);
}

void ScreenMonitor()
{
    switch (gmscr)
    {
    case START:
        // logic
        if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
            gmscr = START;
        break;
    case GAMEPLAY:

        DrawText("gameplay", 0, 0, 32, BLACK);
        break;

    case END:
        // restart game

        gmscr = START;
        DrawText("start", 0, 0, 32, BLACK);
        break;
    default:
        break;
    }
}

// or SCREENCHANGER
void ScreenSwiper()
{
    // change screen
}

#endif