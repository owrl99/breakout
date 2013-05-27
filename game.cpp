#include "libincludes.h"
#include "constants.h"
#include "globals.h"
#include "functions.h"
#include "classes.h"

Game::Game()
{
    score = 0;
    Ball ball;
    Paddle paddle;
    for( int i = 0; i < BLOCK_COLUMNS; i++ )
    {
        for( int j = 0; j < BLOCK_ROWS; j++ )
        {
            blocks.push_back(Block( i, j ));
        }
    }
}

void Game::reset()
{
    Ball ball((SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2));
    Paddle paddle;
}

void Game::show( SDL_Surface* screen )
{
    paddle.show( screen );
    ball.show( screen );

    for( int i = 0; i < blocks.size(); i++ )
    {
        //if( blocks[i].isBlockDead() == false )

        blocks[i].show(screen);

    }
}

void Game::tick()
{
    paddle.move();
    int i = ball.move( paddle, blocks ); //lazy
    if( i == -1 ) //paddle hit
    {

    }
    //if( blocks[i].isBlockDead() == false )
        //blocks[i].hit();
}

void Game::handle_input()
{
    paddle.handle_input();
}

