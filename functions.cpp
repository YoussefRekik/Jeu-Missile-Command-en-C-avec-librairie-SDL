#include "functions.h"

//a one time called function
void affichagewelcome(SDL_Surface *screen)
{
    SDL_Rect a ;

    a.x=0 ;

    a.y=0 ;

    int highscore=0 ;

    FILE* fichier =fopen("scores.txt", "r+");

    fscanf(fichier, "%d", &highscore);

    char ch[10];

    TTF_Font *police = NULL;

    police = TTF_OpenFont("fonts/Terminus.ttf", 140);

    itoa(highscore,ch,10);

    SDL_BlitSurface(home,NULL,screen,&a);

    TTF_CloseFont(police);

}


//a one time called function
void welcome(SDL_Surface *screen)
{
    Mix_Chunk *sound1 = Mix_LoadWAV("sounds/welcome.wav"); // a one time played sound
    Mix_Resume(1);
    SDL_Event event1;
    Mix_PlayChannel(1,sound1,0);
    while(!repeat)
        {
        affichagewelcome(screen);
        SDL_Flip(screen);



        while(SDL_PollEvent(&event1))
            {
            switch(event1.type)
                {
                case SDL_KEYDOWN:   switch (event1.key.keysym.sym)
                                {
                                    case SDLK_KP_ENTER:start=false;avatar=true;repeat=true;break;
                                    case SDLK_RETURN:start=false;avatar=true;repeat=true ;break;
                                    default:break;
                                }
                                break;
                }

           }


        }

    Mix_Pause(1) ;
}



void pause(SDL_Surface *screen)

{
    SDL_Event event;
    bool b=true;
    SDL_Rect postxt; postxt.x=100 ;postxt.y=300;

    TTF_Font *police = TTF_OpenFont("fonts/Terminus.ttf", 50);
    char ch[]="__Game paused please press enter to continue__";
    SDL_Surface *texte = TTF_RenderText_Solid(police,ch,couleurBlanche);
    SDL_BlitSurface(texte, NULL,screen, &postxt);
    SDL_Flip(screen);
    while (b)
    {
       SDL_WaitEvent(&event);
       switch (event.type)
       {
        case SDL_QUIT:b=false;done=true;break;
        case SDL_KEYDOWN:   switch (event.key.keysym.sym)
                                {

                                    case SDLK_ESCAPE:b=false; break;
                                    case SDLK_KP_ENTER:b=false;break;
                                    case SDLK_RETURN:b=false;break;
                                    default: break;
                                }break;
        default: break;

       }
    };



}



//options menu blitting
void affichageoptions(SDL_Surface *screen)
{
    SDL_Rect posmenuoptions;
    posmenuoptions.x=0;
    posmenuoptions.y=0;
    if (sound)
        SDL_BlitSurface(menuon,0, screen, &posmenuoptions);
    else
        SDL_BlitSurface(menuoff,0, screen, &posmenuoptions);
}



//options menu event control fucntion
void options_menu(SDL_Surface* screen)
{
    SDL_Event event;
    Mix_Chunk *sound2 = Mix_LoadWAV("sounds/hitmarker.wav");
    bool t=true;
    SDL_Rect a,b;
    a.x=354;
    a.y=200;
    b.x=626;
    b.y=200;

    while (t)
    {

       affichageoptions(screen);

       SDL_Flip(screen);

       while(SDL_PollEvent(&event))
        {

        switch (event.type)
            {
            case SDL_QUIT:
                t=false;
                if (sound)
                    Mix_PlayChannel(2,sound2,0);
                done=true;
                start=false;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        t=false;
                        Mix_PlayChannel(2,sound2,0);
                        break;

                    default:
                        break;
                }
                break;
            case SDL_MOUSEBUTTONUP:
                if (event.button.x>=a.x && event.button.x<=a.x+200 && event.button.y>=a.y && event.button.y<=a.y+200)
                {
                   if (sound) {sound=false;Mix_Pause(5);Mix_Pause(2);}
                   else {sound=true;Mix_Resume(5);Mix_Resume(2);}
                   if (sound) Mix_PlayChannel(2,sound2,0);
                }
                if (event.button.x>=b.x && event.button.x<=b.x+200 && event.button.y>=b.y && event.button.y<=b.y+200)
                {
                   t=false;
                   if (sound)
                    Mix_PlayChannel(2,sound2,0);
                }
            default: break;
            }
       }
    }
SDL_Delay(100);

}




//blitting main menu function
void affichagemenuprincipale(SDL_Surface *screen)
{
    SDL_Rect zero;
    zero.x=0;
    zero.y=0;
    SDL_Rect b,c,d ;
    b.x=200;
    b.y=250;
    c.x=550;
    c.y=250;
    d.x=900;
    d.y=250;
    int highscore=0 ;
    FILE* fichier =fopen("scores.txt", "r+");
    fscanf(fichier, "%d", &highscore);
    char ch[10];
    TTF_Font *police = NULL;
    SDL_Rect scorepos;
    scorepos.x=350 ;
    scorepos.y=150 ;
    police = TTF_OpenFont("fonts/Terminus.ttf", 50);
    itoa(highscore,ch,10);
    char ch1[40]="Current Highscore = ";
    strcat(ch1,ch);
    SDL_Surface *texte = TTF_RenderText_Solid(police,ch1,couleurBlanche);
    SDL_BlitSurface(texte, NULL,screen, &scorepos);
    SDL_BlitSurface(start0, 0, screen, &zero);
    SDL_BlitSurface(exit1,NULL,screen,&d);
    SDL_BlitSurface(play,NULL,screen,&b);
    SDL_BlitSurface(settings,NULL,screen,&c);
    SDL_BlitSurface(texte, NULL,screen, &scorepos);
    SDL_Delay(430);
    TTF_CloseFont(police);
}



//welcome screen blitted
void startgame(SDL_Surface  *screen)
{

    SDL_Rect b,c,d ;
    b.x=200;
    b.y=250;
    c.x=550;
    c.y=250;
    d.x=900;
    d.y=250;

    Mix_Chunk *music1=Mix_LoadWAV("sounds/music1.wav");
    Mix_Chunk *sound2 = Mix_LoadWAV("sounds/hitmarker.wav");
    start=false;
    avatar=true;
    repeat=true;
    start1= true;
    if (sound)
        Mix_Resume(5);
    if (sound)
        Mix_PlayChannel(5,music1,0);
    SDL_Event event;



    while(start1)
    {

    affichagemenuprincipale(screen);

     while(SDL_PollEvent(&event))
        {
            switch (event.type)
            {

            case SDL_MOUSEBUTTONUP:
                if (event.button.x>=b.x && event.button.x<=b.x+200 && event.button.y>=b.y && event.button.y<=b.y+200)
                {
                   start1=false;avatar=true;if (sound) Mix_PlayChannel(2,sound2,0);
                }
                if (event.button.x>=c.x && event.button.x<=c.x+200 && event.button.y>=c.y && event.button.y<=c.y+200)
                {
                    if (sound) Mix_PlayChannel(2,sound2,0); options_menu(screen);
                }
                if (event.button.x>=d.x && event.button.x<=d.x+200 && event.button.y>=d.y && event.button.y<=d.y+200)
                {
                   start1=false;avatar=false;done=true;if (sound) Mix_PlayChannel(2,sound2,0);
                }

            case SDL_KEYDOWN:   switch (event.key.keysym.sym)
                                {
                                    case SDLK_KP_ENTER:start1= false ;start=false;avatar=true;Mix_PlayChannel(2,sound2,0);break;
                                    case SDLK_RETURN:start1= false ;start=false;avatar=true;Mix_PlayChannel(2,sound2,0);break;
                                    default:break;
                                }
                                break;
            case SDL_QUIT:start1= false ;start=false;done=true;break;
            default:break;
         }

        }



        SDL_Flip(screen);

    }


Mix_Pause(5);

SDL_Delay(1000/FPS);
}



//blitting playername menu
void affichageplayername (SDL_Surface *screen, char ch[7])
{
    SDL_Rect zero,postxt;
    zero.x=0;
    zero.y=0;
    postxt.x=220;
    postxt.y=300;
    TTF_Font *police = NULL;
    police = TTF_OpenFont("fonts/Terminus.ttf", 140);
    SDL_BlitSurface(player_name,0, screen, &zero);
    SDL_Surface *texte= TTF_RenderText_Solid(police,ch,couleurNoire);
    SDL_BlitSurface(texte, NULL,screen, &postxt);
    TTF_CloseFont(police);
}



void playername(SDL_Surface* screen)
{

    bool t=true;

    Mix_Chunk *sound2 = Mix_LoadWAV("sounds/hitmarker.wav");
    Mix_Chunk *sound3 = Mix_LoadWAV("sounds/writename.wav");
    if (sound)
    {
        Mix_Resume(3);
        Mix_PlayChannel(3,sound3,0);
    }
    char ch[15];
    strcpy(ch,"");
    SDL_Event event;


    int longeur=10 ;
    int l=2;
    SDL_EnableUNICODE(SDL_ENABLE);




while (t)
{

    affichageplayername(screen,ch);


    while(SDL_PollEvent(&event))
    {
        switch (event.type)
       {
        case SDL_QUIT:t=false;done=true;break;
        case SDL_KEYDOWN:switch (event.key.keysym.sym)
                                {
                                    case SDLK_RETURN:if(l != 0) {
                                                                t=false;
                                                                if (sound) {Mix_Resume(2);Mix_PlayChannel(2,sound2,0);}
                                                                else {Mix_Pause(2);}
                                                                avatar=false;
                                                                game=true;
                                                                }break;

                                    case SDLK_BACKSPACE:if(l>0) ch[l-1]='\0';break;
                                    default: break;
                                }
                                if (l<longeur)
                                {
                                    if ( event.key.keysym.unicode >= (Uint16)'a' and event.key.keysym.unicode <= (Uint16)'z' )
                                        {

                                            sprintf(ch,"%s%c",ch,toupper((char)event.key.keysym.unicode));
                                            l=strlen(ch);
                                        }
                                    else if ( event.key.keysym.unicode >= (Uint16)'A' and event.key.keysym.unicode <= (Uint16)'Z' )
                                        {

                                            sprintf(ch,"%s%c",ch,toupper((char)event.key.keysym.unicode));
                                            l=strlen(ch);
                                        }
                                }
                                break;
        default: break;
       }
    }

SDL_Flip(screen);

}
Mix_Pause(3);

SDL_Delay(1000/FPS);
};



//initialising missiles : a one time called function
void intialise_missiles()
{
    SDL_Surface *missilegreen = IMG_Load("images/missilegreen.png");
    SDL_Surface *missilered = IMG_Load("images/missilered.png");
    SDL_Surface *missileyellow = IMG_Load("images/missileyellow.png");
    SDL_Surface *missilewhite = IMG_Load("images/missilewhite.png");



    int k=0 ;
    for (int i=0;i<2000;i++)
    {
        M[i].pos.y=0;M[i].pos.x=rand() % 1200;
        M[i].alive=true;
        M[i].explosion=0;
        if (k==0) M[i].surface=missilegreen;
        if (k==1) M[i].surface=missilered;
        if (k==2) M[i].surface=missileyellow;
        if (k==3) M[i].surface=missilewhite;
        k++;
        if (k==4) k=0 ;


    }

}




//initialising smartbombs : a one time called function

void intialise_smartbombs()
{
    SDL_Surface *missile1 = IMG_Load("images/Missile1.png");

    SDL_Surface *missile2 = IMG_Load("images/Missile2.png");

    int k=0 ;
    for (int i=0;i<30;i++)

    {
        N[i].pos.y=100;
        N[i].alive=true;
        N[i].explosion=0;
        N[i].surface=missile1;
        if (k==0)
            {N[i].surface=missile1;N[i].pos.x=0;N[i].type=1;}
        if (k==1)
            {N[i].surface=missile2;N[i].pos.x=1280;N[i].type=2;}

        k++;
        if (k==2)
            k=0 ;


    }

}



//drawing explosions

void Draw_explosions(SDL_Surface *screen ,int debut , int fin)
{


    Mix_Chunk *sound4 = Mix_LoadWAV("sounds/boom.wav");
    for (int i=debut;i<fin;i++)
     {

    if (M[i].explosion==3)
        {SDL_BlitSurface(explo3,NULL,screen,&M[i].pos);M[i].explosion++;}
    if (M[i].explosion==2)
        {SDL_BlitSurface(explo2,NULL,screen,&M[i].pos);M[i].explosion++;}
    if (M[i].explosion==1)
        {
         SDL_BlitSurface(explo1,NULL,screen,&M[i].pos);
         M[i].explosion++;
         if (sound)
            {Mix_Resume(4);Mix_PlayChannel(4,sound4,0);}
         explosed++;
        }
     }

    if (N[f].explosion==3)
        {SDL_BlitSurface(explo33,NULL,screen,&N[f].pos);N[f].explosion++;}
    if (N[f].explosion==2)
        {SDL_BlitSurface(explo22,NULL,screen,&N[f].pos);N[f].explosion++;}
    if (N[f].explosion==1)
        {
         SDL_BlitSurface(explo11,NULL,screen,&N[f].pos);
         N[f].explosion++;
         if (sound)
                  {Mix_Resume(4);Mix_PlayChannel(4,sound4,0);}

        }
}


void explosedbase(SDL_Surface* screen)

{
    Mix_Chunk *sound4 = Mix_LoadWAV("sounds/bigboom.wav");
    SDL_Rect ex;
    ex.x=0;
    ex.y=520;
    int k=0 ;
    if (sound)
        {Mix_Resume(4);Mix_PlayChannel(4,sound4,0);}
     while (k!=3)
     {

       if (k==2)
            {SDL_BlitSurface(explo333,NULL,screen,&ex);k++;}
       if (k==1)
            {SDL_BlitSurface(explo222,NULL,screen,&ex);k++;}
       if (k==0)
            {SDL_BlitSurface(explo111,NULL,screen,&ex);k++;}

    SDL_Flip(screen);
    SDL_Delay(500);

     }


}


//drawing missiles
void Draw_missiles(SDL_Surface *screen , int &debut , int fin , bool &game )
{


    for (int i=debut ; i<fin ;i++)
        {
        if ((!M[debut].alive))
            debut ++ ;
        if (M[i].alive)
            {SDL_BlitSurface(M[i].surface,NULL,screen,&M[i].pos);M[i].pos.y+=difficulty;}
        if ((M[i].pos.y>530)&&(M[i].alive==true))
            {game=false;}

        }

    if (explosed == 10 )
        {explosed=0;f++;} ;



    if (N[f].alive)
        {SDL_BlitSurface(N[f].surface,NULL,screen,&N[f].pos);
         if (N[f].type==1)
            N[f].pos.x+=10 ;
         if (N[f].type==2)
            N[f].pos.x-=10 ;
         }
    if ((N[f].pos.x>1280)||(N[f].pos.x<0))
        {N[f].alive=false;}


}





void main_game(SDL_Surface* screen)
{

    Mix_Resume(6);
    Mix_Chunk *music2=Mix_LoadWAV("sounds/music2.wav");
    Mix_PlayChannel(6,music2,0);
    TTF_Init();
    int score=0;
    char ch1[10];
    TTF_Font *police = NULL;
    police = TTF_OpenFont("fonts/Terminus.ttf", 50);
    SDL_Rect postxt;
    postxt.x=1000 ;
    postxt.y=50;
    SDL_Surface *texte;

    SDL_Rect zero;
    zero.x=0;
    zero.y=0;

    SDL_Event event;
    SDL_Rect pausepos;
    pausepos.x=1000 ;
    pausepos.y=600 ;



    SDL_BlitSurface(maingame,NULL,screen,&zero);



    intialise_missiles();

    intialise_smartbombs();



    int fin=10;

    int debut =0 ;

    bool game=true ;




    while (game)
    {
      SDL_BlitSurface(maingame,NULL,screen,&zero);

      Draw_explosions(screen,debut,fin) ;

      Draw_missiles(screen,debut,fin,game);

      SDL_BlitSurface(iconpause,NULL,screen,&pausepos);
      itoa(score,ch1,10);
      char ch[40]="Score : ";
      strcat(ch,ch1);
      texte = TTF_RenderText_Solid(police,ch,couleurBlanche);
      SDL_BlitSurface(texte, NULL,screen, &postxt);


      while(SDL_PollEvent(&event))
        {

        switch (event.type)
            {
            case SDL_QUIT:game=false;done=true;break;

            case SDL_MOUSEBUTTONUP:{ if (((event.button.x)<pausepos.x+200) &&  ((event.button.x)>(pausepos.x)) && ((event.button.y)<pausepos.y+80) &&  ((event.button.y)>(pausepos.y) ))
                                            pause(screen) ;

                                    for (int i=debut; i<fin ;i++)
                                    {
                                    if (((event.button.x)<M[i].pos.x+58) &&  ((event.button.x)>(M[i].pos.x)-10) && ((event.button.y)<M[i].pos.y+88) &&  ((event.button.y)>(M[i].pos.y)-10) )
                                                {
                                                    if(M[i].alive)
                                                        {M[i].explosion=1;score++;}
                                                   M[i].alive=false;fin++;
                                                }

                                    };
                                    if (((event.button.x)<N[f].pos.x+100) &&  ((event.button.x)>(N[f].pos.x)-10) && ((event.button.y)<N[f].pos.y+50) &&  ((event.button.y)>(N[f].pos.y)-10) )
                                                {
                                                    if(N[f].alive)
                                                        {N[f].explosion=1;score+=20;}
                                                    N[f].alive=false;
                                                }





                                }
            break;
            default:break;
            }

        }
     SDL_Flip(screen);
     SDL_Delay(10);
    }

    explosedbase(screen);
    char chh[4];
    int scoreancien=0;
    itoa(score,chh,10);
    FILE* fichier =fopen("scores.txt", "r+");
    fscanf(fichier, "%d", &scoreancien);
    if (score>scoreancien)
        {
            fclose(fichier);
            fichier =fopen("scores.txt", "w+");
            fprintf(fichier,chh);
        }

    SDL_BlitSurface(highscores,NULL,screen,&zero);
    SDL_Flip(screen);
    SDL_Delay(1000);
    Mix_Pause(6);
    TTF_CloseFont(police);
    TTF_Quit();
    fclose(fichier);
}

