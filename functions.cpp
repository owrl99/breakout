#include "libincludes.h"
#include "constants.h"
#include "globals.h"
#include "functions.h"

bool check_collision( SDL_Rect A, SDL_Rect B )
{
    int leftA = A.x;
    int topA = A.y;
    int rightA = A.x + A.w;
    int bottomA = A.y + A.h;

    int leftB = B.x;
    int topB = B.y;
    int rightB = B.x + B.w;
    int bottomB = B.y + B.h;

    if( bottomA <= topB ) { return false; }
    if( topA >= bottomB ) { return false; }
    if( rightA <= leftB ) { return false; }
    if( leftA >= rightB ) { return false; }

    return true;
}

SDL_Surface *load_image( std::string filename )
{
    SDL_Surface *loadedImage = NULL;
    SDL_Surface *optimizedImage = NULL;
    loadedImage = IMG_Load( filename.c_str() );
    if( loadedImage != NULL )
    {
        optimizedImage = SDL_DisplayFormat( loadedImage );
        SDL_FreeSurface( loadedImage );
        if( optimizedImage != NULL )
        {
            SDL_SetColorKey( optimizedImage, SDL_RLEACCEL | SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0, 255, 255 ) );
        }
    }
    return optimizedImage;
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip )
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface( source, clip, destination, &offset );
}

bool init()
{
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 ) { return false; }

    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
    if( screen == NULL ) { return false; }

    if( TTF_Init() == -1 ) { return false; }
    return true;
}

bool load_files()
{
    font = TTF_OpenFont( "ARCADECLASSIC.ttf", 40 );
    if( font == NULL ) { return false; }

    backgroundGradient = load_image( "backgroundGradient.png" );
    if( backgroundGradient == NULL ) { return false; }


    return true;
}

void clean_up()
{
    TTF_CloseFont( font );
    TTF_Quit();
    SDL_Quit();
}



