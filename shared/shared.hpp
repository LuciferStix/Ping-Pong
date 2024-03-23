#ifndef SHARED
#define SHARED

// Window attributes
int ScreenWidth = 1200;
int ScreenHeight = 800;
int Pad = 5;

// Paddle attributes
int PaddleHeight = 200;
int PaddleWidth = 50;
int PaddleVelY = 18;
int PaddleMult = 1;

// Ball attributes
int BallRadius = 30;

typedef enum GameScreen
{
    START = 0,
    GAMEPLAY,
    END
} GameScreen;
GameScreen gmscr = START;

bool GameOver = false;

#endif