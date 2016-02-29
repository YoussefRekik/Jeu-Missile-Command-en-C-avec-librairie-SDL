#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <string.h>



// global structures and data are in the header functions.h

int main ( int argc, char** argv )
{

    TTF_Init();

    SDL_Init(SDL_INIT_EVERYTHING);

    Mix_OpenAudio(22050,AUDIO_S16SYS,2,640);

    SDL_WM_SetCaption("*Missile Challenge*", NULL);

    SDL_WM_SetIcon(IMG_Load("icon.png"), NULL);

    SDL_Surface *screen = SDL_SetVideoMode(1280, 720, 32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_FULLSCREEN);

    SDL_Cursor *cursor;

    cursor = SDL_CreateCursor( CURSOR, MASK,16,16,7,7 );

    SDL_SetCursor(cursor);

    // Boucle principale du progrmme

    gamestate=1 ;

    while (!done)

    { start = true;avatar = false;game=false;


        switch(gamestate)
        {
            case 1 : {welcome(screen);gamestate=2; }
            case 2 : {startgame(screen) ; gamestate=3 ;}
            case 3 : {if (avatar) playername(screen); gamestate=4 ;}
            case 4 : {if (game) main_game(screen) ;gamestate=1 ; }

            SDL_Flip(screen);
        }


    }



    //freeing surfaces and closing sdl , ttf

    SDL_FreeSurface(screen);

    Mix_CloseAudio();

    SDL_FreeSurface(menuon);
    SDL_FreeSurface(menuoff);
    SDL_FreeSurface(start0);
    SDL_FreeSurface(exit1);
    SDL_FreeSurface(play);
    SDL_FreeSurface(settings);
    SDL_FreeSurface(player_name);
    SDL_FreeSurface(highscores);
    SDL_FreeSurface(iconpause);
    SDL_FreeSurface(maingame);
    SDL_FreeSurface(home);
    SDL_FreeSurface(explo1);
    SDL_FreeSurface(explo2);
    SDL_FreeSurface(explo3);
    SDL_FreeSurface(explo11);
    SDL_FreeSurface(explo22);
    SDL_FreeSurface(explo33);

    SDL_Quit();

    TTF_Quit();

    return 0;


}

