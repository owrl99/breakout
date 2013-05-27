#include "libincludes.h"
#include "constants.h"
#include "globals.h"
#include "functions.h"
#include "classes.h"

/*
class Paddle
{
public:
    Paddle::Paddle() { reset(); }
    void reset();
    void show( SDL_Surface* screen );
    void handle_input();
    void move();
private:
    int x;
    int y;
    int xVel;
};*/

void Paddle::reset()
{
    box.x = ( SCREEN_WIDTH / 2 ) - ( PADDLE_WIDTH / 2 );
    box.y = SCREEN_HEIGHT - ( PADDLE_HEIGHT * 3 );
    box.w = PADDLE_WIDTH;
    box.h = PADDLE_HEIGHT;
    xVel = 0;
}

void Paddle::show( SDL_Surface* screen )
{
    SDL_Rect paddleRectGhost1{ box.x - xVel * 0.9, box.y, box.w, box.h };
    SDL_FillRect( screen, &paddleRectGhost1, SDL_MapRGB( screen->format, 64, 64, 64 ) );

    SDL_Rect paddleRectGhost2{ box.x - xVel * 0.6, box.y, box.w, box.h };
    SDL_FillRect( screen, &paddleRectGhost2, SDL_MapRGB( screen->format, 128, 128, 128 ) );

    SDL_Rect paddleRect{ box.x, box.y, box.w, box.h };
    SDL_FillRect( screen, &paddleRect, SDL_MapRGB( screen->format, 255, 255, 255 ) );
}

void Paddle::handle_input()
{
    if( event.type == SDL_KEYDOWN )
    {
        switch( event.key.keysym.sym )
        {
            case SDLK_RIGHT: xVel += PADDLE_SPEED; break;
            case SDLK_LEFT: xVel -= PADDLE_SPEED; break;
            default: break;
        }
    }
    if( event.type == SDL_KEYUP )
    {
        switch( event.key.keysym.sym )
        {
            case SDLK_RIGHT: xVel -= PADDLE_SPEED; break;
            case SDLK_LEFT: xVel += PADDLE_SPEED; break;
            default: break;
        }
    }
}

void Paddle::move()
{
    box.x += xVel;

    if( ( box.x + box.w ) > SCREEN_WIDTH )
    {
        box.x -= ( box.x + box.w - SCREEN_WIDTH );
    }

    if( ( box.x < 0 ) )
    {
        box.x += ( -box.x );
    }
}










