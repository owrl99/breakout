#include "libincludes.h"
#include "constants.h"
#include "globals.h"
#include "functions.h"
#include "classes.h"

Ball::Ball( int X , int Y  )
{
    box.x = X;
    box.y = Y;
    box.w = BALL_WIDTH;
    box.h = BALL_HEIGHT;
    xVel = (rand() % 15) - (rand() % 30) - 15;
    yVel = (rand() % 5) + 15;
}

void Ball::reset( int X , int Y  )
{
    box.x = X;
    box.y = Y;
    box.w = BALL_WIDTH;
    box.h = BALL_HEIGHT;
    xVel = (rand() % 15) - (rand() % 30) - 15;
    yVel = (rand() % 5) + 15;
}

void Ball::show( SDL_Surface* screen )
{
    SDL_FillRect( screen, &box, SDL_MapRGB( screen->format, 255, 255, 255 ) );
}

int Ball::move( const Paddle &paddle, const std::vector<Block> &blocks )
{
    //returns -2 = didn't collide, -1 = collided with paddle, >=0 = number corresponding to block in vector

    box.x += xVel;
    if( (box.x < 0) || (box.x + xVel > SCREEN_WIDTH) )
    {
        box.x -= xVel;
        xVel = -xVel;
    }

    if( check_collision( box, paddle.get_rect() ) )
    {
        box.x -= xVel;
        xVel = -xVel;
        return -1;
    }

    for( int i = 0; i < blocks.size(); i++ )
    {
        if( check_collision( box, blocks[i].get_rect() ) )
        {
            box.x -= xVel;
            xVel = -xVel;
            return i;
        }
    }

    box.y += yVel;
    if( (box.y < 0) || (box.y + yVel > SCREEN_HEIGHT) )
    {
        box.y -= yVel;
        yVel = -yVel;
    }

    if( check_collision( box, paddle.get_rect() ) )
    {
        box.y -= yVel;
        yVel = -yVel;
        return -1;
    }

    for( int i = 0; i < blocks.size(); i++ )
    {
        if( check_collision( box, blocks[i].get_rect() ) )
        {
            box.y -= yVel;
            yVel = -yVel;
            return i;
        }
    }



    return -2;
}


