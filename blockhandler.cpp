#include "libincludes.h"
#include "constants.h"
#include "globals.h"
#include "functions.h"
#include "classes.h"

BlockHandler::BlockHandler()
{
    score = 0;
    ball = new Ball(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    paddle = new Paddle;
}

BlockHandler::~BlockHandler()
{
    delete(ball);
    delete(paddle);
}

void BlockHandler::reset()
{
    delete(ball);
    delete(paddle);
    ball = new Ball(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    paddle = new Paddle;
}

void BlockHandler::show( SDL_Surface* screen )
{
    paddle->show( screen );
    ball->show( screen );
}

void BlockHandler::tick()
{
    ball->move();
    paddle->move();
}

void BlockHandler::handle_input()
{
    paddle->handle_input();
}
