#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "libincludes.h"
#include "constants.h"
#include "globals.h"

bool init();
bool load_files();
void clean_up();

SDL_Surface* load_image( std::string filename );
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL );

bool check_collision( SDL_Rect A, SDL_Rect B );



#endif // FUNCTIONS_H
