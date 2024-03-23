// rectangle and ping pong ball

#ifndef OBJECTS
#define OBJECTS
#include <raylib.h>
#include <string>

//-------------------------META DATA-------------------------
class meta
{
public:
    Vector2 pos;
    Color color;
};
//------------------------------------------------------------

// -------------------------PADDLE--------------------------

class Paddle : public meta
{
    Vector2 size;

public:
    Paddle(int w, int h, int x = 0, int y = 0, Color col = RAYWHITE)
    {
        this->size.x = w; // width
        this->size.y = h; // height
        this->color = col;
        this->pos.x = x;
        this->pos.y = y;
    }

    void Draw() { DrawRectangleV(this->pos, this->size, color); }

    // void Move(){

    // }
};
// --------------------------------------------------------------

// -------------------------PING PONG BALL--------------------------

class PingPong : public meta
{
    float radius;

public:
    int VelX = 10, VelY = 10;

    PingPong(int rad, Color col)
    {
        this->radius = rad;
        this->color = col;
        RandomVal();
    }

    void RandomVal()
    {
        pos.x = GetRandomValue(PaddleWidth + 100, ScreenWidth - 100);
        pos.y = GetRandomValue(100, ScreenHeight - 100);
    }

    void Draw()
    {
        Move();
        DrawCircleV(this->pos, radius, color);
    }

    void Move(bool stop = false)
    {
        if (!stop)
        {
            pos.x += VelX;
            pos.y += VelY;
        }
        else
        {
            pos.x = -BallRadius - 10;
            pos.y = -BallRadius - 10;
        }
    }
};

class ScoreBoard
{
    int Score;
    std::string score;

public:
    ScoreBoard()
    {

        Score = 0;
        score = "score:0";
    }
    void Draw()
    {
        DrawText(score.c_str(), ScreenWidth - 200, Pad + 10, 35, BLACK);
    }
    void updateScore()
    {
        Score += 10;
        score.erase(6);
        score.append(std::to_string(Score));
    }
};

// ---------------------------------------------------------------------

void Collision(Paddle &paddle, PingPong &ball, ScoreBoard &score)
{
    // collision logic
    if (ball.pos.x >= ScreenWidth)
        ball.VelX *= -1;
    if (ball.pos.y >= ScreenHeight || ball.pos.y <= 0)
        ball.VelY *= -1;

    // collision with paddle
    if ((ball.pos.y <= (paddle.pos.y + PaddleHeight) && (ball.pos.y >= paddle.pos.y)) && (ball.pos.x <= (PaddleWidth + Pad + BallRadius)))
    {
        score.updateScore();
        ball.VelX *= -1;

    } // collided
    else if (ball.pos.x < 0)
    {
        DrawText("Game Over", 100, 50, 36, BLACK);
        ball.Move(true);
        GameOver = true;
    }
}

#endif