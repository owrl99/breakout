#include "libincludes.h"
#include "constants.h"
#include "globals.h"
#include "functions.h"
#include "classes.h"

Block::Block( int X, int Y )
{
    value = 1;
    isDead = false;
    gridx = X;
    gridy = Y;

    SDL_Rect box{ ( X * BLOCK_WIDTH ) + BLOCK_MARGIN, ( Y * BLOCK_HEIGHT ) + BLOCK_MARGIN, BLOCK_WIDTH, BLOCK_HEIGHT };
}

void Block::reset( int X, int Y )
{
    value = 1;
    isDead = false;
    gridx = X;
    gridy = Y;

    SDL_Rect box{ ( X * BLOCK_WIDTH ) + BLOCK_MARGIN, ( Y * BLOCK_HEIGHT ) + BLOCK_MARGIN, BLOCK_WIDTH, BLOCK_HEIGHT };
}

void Block::show( SDL_Surface* screen )
{
    SDL_FillRect( screen, &box, SDL_MapRGB( screen->format, 255, 255, 255 ) );
}

int Block::hit() //returns value
{
    isDead = true;
    return value;
}
