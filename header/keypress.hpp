#ifndef KEYPRESS
#define KEYPRESS

#include<raylib.h>
#include "./objects.hpp"
#include "../shared/shared.hpp"



void ListenKeyP(Paddle &p){
    if (IsKeyDown(KEY_UP)){
        if (p.pos.y >=0)
            p.pos.y-=PaddleVelY;
        // else {
        //     if (IsKeyReleased(KEY_UP))
        //         p.y=Pad;    
        // }
    }    
    else if (IsKeyDown(KEY_DOWN)){
        if(p.pos.y <= (ScreenHeight-PaddleHeight))
            p.pos.y+=PaddleVelY;   
        // else {
        //     if (IsKeyReleased(KEY_DOWN))
        //         p.y=ScreenHeight-PaddleHeight-Pad;
        // }   
    }
}

#endif