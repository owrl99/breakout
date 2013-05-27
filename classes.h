#ifndef CLASSES_H
#define CLASSES_H
#include "libincludes.h"
#include "constants.h"
#include "globals.h"
#include "functions.h"

class Paddle
{
public:
    Paddle() { reset(); }
    void reset();
    void show( SDL_Surface* screen );
    void handle_input();
    void move();
    int getX() { return box.x; }
    int getY() { return box.y; }
    SDL_Rect get_rect() const { return box; }
private:
    SDL_Rect box;

    int xVel;
};

class Block
{
public:
    Block( int X, int Y );
    void reset( int X, int Y );
    void show( SDL_Surface* screen );
    int getX() { return gridx; }
    int getY() { return gridy; }
    SDL_Rect get_rect() const { return box; }
    int hit(); //returns value
    bool isBlockDead() { return isDead; }
private:
    SDL_Rect box;
    bool isDead;
    int value;
    int gridx;
    int gridy;
};

class Ball
{
public:
    Ball( int X = 0, int Y = 0 );
    void reset( int X = 0, int Y = 0 );
    void show( SDL_Surface* screen );
    int move( const Paddle &paddle, const std::vector<Block> &blocks ); //returns -2 = didn't collide, -1 = collided with paddle, >=0 = number corresponding to block in vector
    int getX() { return box.x; }
    int getY() { return box.y; }
    SDL_Rect get_rect() const { return box; }
private:
    int xVel;
    int yVel;
    SDL_Rect box;
};

class Game
{
    friend class Ball;
    friend class Paddle;
public:
    Game();
    void reset();
    void handle_input();
    void tick();
    void show( SDL_Surface* screen );
private:
    int score;
    Ball ball;
    Paddle paddle;
    std::vector<Block> blocks;
};

class Text
{
public:
    Text( std::string str, int X, int Y );
    void show( SDL_Surface* screen );
    void set_text( const std::string &str );
    std::string get_text() const { return text; }
    void set_pos( int X, int Y);
private:
    SDL_Color textColor;
    std::string text;
    SDL_Surface* message;
    int x;
    int y;
};

class Timer
{
private:
    int startTicks;
    int pausedTicks;

    bool paused;
    bool started;
public:
    Timer();

    void start();
    void stop();
    void pause();
    void unpause();

    int get_ticks();

    bool is_started() { return started; }
    bool is_paused() { return paused; }
};


#endif // CLASSES_H
