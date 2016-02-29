#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <string.h>


#define FPS 60

#define difficulty 2   //a variable set between 1 for easy 2,3 for meduim 4,5 for hard

/************  declaration des types  ***********************/

// Missile's structure
 typedef struct
{
    SDL_Surface *surface ;
    SDL_Rect pos ;
    bool alive ;
    int explosion ;
}missile;


//smart bombs structure
typedef struct
{
    SDL_Surface *surface ;
    SDL_Rect pos ;
    bool alive ;
    int explosion ;
    int type ;
}smartbombs;

int gamestate=0 ;

/*
game state is a variable that states the current phase of the game
0 game off
1 welcome screen phase
2 main menu phase
3 creating avatar phase
4 in game phase
*/



// a list of general game data booleans

 bool done = false;

 bool repeat=false ;

 bool start = true;

 bool avatar = false;

 bool game=false;

 bool start1=false ;

 bool sound=true;


//a Custom cursor
Uint8 CURSOR[] = { 0, 0, 0, 0, 0, 0, 0, 0, 8, 16, 4, 32, 2, 64, 0, 0,
                       0, 0, 2, 64, 4, 32, 8, 16, 0, 0, 0, 0, 0, 0, 0, 0 };
Uint8 MASK[]   = { 1, 128, 1, 128, 1, 128, 1, 128, 1, 128, 1, 128, 1, 128,
                       254, 127, 254, 127,
                       1, 128, 1, 128, 1, 128, 1, 128, 1, 128, 1, 128, 1, 128};


SDL_Color couleurNoire = {0, 0, 0};

SDL_Color couleurBlanche = {255, 255, 255};


//loading main surfaces : the ones who will get blitted more than once
SDL_Surface *menuon=IMG_Load("images/option.png"),
            *menuoff=IMG_Load("images/optionoff.png"),
            *start0 = IMG_Load("images/highscores.png"),
            *exit1 = IMG_Load("images/exit.png"),
            *play= IMG_Load("images/play.png")
            , *settings= IMG_Load("images/settings.png")
            , *player_name=IMG_Load("images/Player_name.png")
            , *highscores=IMG_Load("images/highscores.png")
            , *iconpause=IMG_Load("images/pause.png")
            , *maingame=IMG_Load("images/game.png")
            , *home = IMG_Load("images/home.png")

//loading explosions surfaces
            , *explo1=IMG_Load("images/1.png")
            , *explo2=IMG_Load("images/2.png")
            , *explo3=IMG_Load("images/3.png")

            , *explo11=IMG_Load("images/11.png")
            , *explo22=IMG_Load("images/22.png")
            , *explo33=IMG_Load("images/33.png")

            , *explo111=IMG_Load("images/111.png")
            , *explo222=IMG_Load("images/222.png")
            , *explo333=IMG_Load("images/333.png");

//a table of missiles
missile M[2000];

smartbombs N[30];

int d=0 ;
int f=0;
int explosed=0; //a variable used to count explosed missiles



void affichagewelcome(SDL_Surface *screen) ;

void welcome(SDL_Surface *screen) ;

void pause(SDL_Surface *screen) ;

void affichageoptions(SDL_Surface *screen) ;

void affichageoptions(SDL_Surface *screen) ;

void options_menu(SDL_Surface* screen) ;

void affichagemenuprincipale(SDL_Surface *screen) ;

void startgame(SDL_Surface  *screen) ;

void affichageplayername (SDL_Surface *screen, char ch[7]);

void playername(SDL_Surface* screen) ;

void intialise_missiles() ;

void intialise_smartbombs() ;

void Draw_explosions(SDL_Surface *screen ,int debut , int fin) ;

void explosedbase(SDL_Surface* screen) ;

void Draw_missiles(SDL_Surface *screen , int &debut , int fin , bool &game ) ;

void main_game(SDL_Surface* screen) ;

#endif // FUNCTIONS_H
