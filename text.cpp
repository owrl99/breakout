#include "libincludes.h"
#include "constants.h"
#include "globals.h"
#include "functions.h"
#include "classes.h"


Text::Text( std::string str = "", int X = 0, int Y = 0 )
{
    textColor = { 255, 255, 255 };
    x = X;
    y = Y;
    text = str;
    message = TTF_RenderText_Solid( font, text.c_str(), textColor );
}

void Text::show( SDL_Surface* screen )
{
    apply_surface( x, y, message, screen );
}

void Text::set_text( const std::string &str )
{
    text = str;
    message = TTF_RenderText_Solid( font, text.c_str(), textColor );
}

void Text::set_pos( int X = -1, int Y = -1 )
{
    if( X != -1 )
    {
        x = X;
    }
    if( Y != -1 )
    {
        y = Y;
    }
}
