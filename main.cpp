#include "libincludes.h"
#include "constants.h"
#include "classes.h"
#include "functions.h"
#include "globals.h"

using namespace std;

int main( int argc, char* args[] )
{
    bool quit = false;
    bool playing = false;

    if( init() == false ) { return 1; }
    if( load_files() == false ) { return 1; }

    Timer fps;

    srand(time(NULL));

    Game thegame;

    int score = 0;

    stringstream scoreStr;

    Text scoreText("", 0, 0);

    while( quit == false )
    {
        fps.start();
        while( SDL_PollEvent( &event ) )
        {
            thegame.handle_input();
            if( event.type == SDL_KEYDOWN )
            {
                switch( event.key.keysym.sym )
                {
                    case SDLK_ESCAPE: quit = true; break;
                    default: break;
                }
            }
            if( event.type == SDL_QUIT )
            {
                quit = true;
            }
        }
        scoreStr.str(string());
        scoreStr << "Score ";
        scoreStr << score;

        scoreText.set_text( scoreStr.str() );

        thegame.tick();

        apply_surface( 0, 0, backgroundGradient, screen, NULL );

        thegame.show( screen );
        scoreText.show( screen );

        if( SDL_Flip( screen ) == -1 ) { return 1; }

        if( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
        {
            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
        }
    }
}


