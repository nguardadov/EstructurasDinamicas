#include "VentanaPrincipal.h"
#include "ClasePuntaje.h"
#include "ClaseJuego.h"
#include <SDL2/SDL_image.h>
#include <iostream>
#include <cstdlib>



VentanaPrincipal::VentanaPrincipal()
{
    this -> windows=nullptr;
    this ->windowSurface=nullptr;
    this ->isRunning=true;
    this->player1="";
    this->player2="";
    this->fondoPrin = NULL;
    this->jugando = NULL;
    this->puntos = NULL;
    this->ayuda = NULL;
    
    SDL_Init(SDL_INIT_VIDEO);
    
    this-> windows  =  SDL_CreateWindow("'MI TIC TAC TOE'", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_SHOWN);
}

int VentanaPrincipal::corriendo()
{
    int flag=-1;
    SDL_Event ev;
    
    this ->windowSurface= SDL_GetWindowSurface(this-> windows);
    
    
    this->fondoPrin = IMG_Load("fondoPrincipal.jpg");
    this->jugando = IMG_Load("jugando.jpg");
    this->puntos = IMG_Load("puntajes.jpg");
    this->ayuda = IMG_Load("ayuda.jpg");
    
    VentanaPrincipal::colocando(0, 0, fondoPrin);
    VentanaPrincipal::colocando(310,100, jugando);
    VentanaPrincipal::colocando(370,100, puntos);
    VentanaPrincipal::colocando(430,100, ayuda);
    
    while(this->isRunning)
    {
        while(SDL_PollEvent(&ev) != 0) 
        {
            if(ev.type == SDL_QUIT)
            {
                flag=-1;
                this ->isRunning =false;
            }
            else if(ev.type == SDL_MOUSEBUTTONDOWN)
            {
                if(ev.button.button == SDL_BUTTON_LEFT)
                {
                    if(ev.button.x >=100 && ev.button.x<=500 && ev.button.y>=310 && ev.button.y<=360)
                    {
                        SDL_DestroyWindow(this->windows);
                        
                        while (true)
                        {
                            lista l;
                            cout << "Ingrese el nombre del primer jugador: ";
                            cin >>this->player1;
                            if(!l.buscarjdor(player1))
                            {
                                break;
                            }
                        }
                        while (true)
                        {
                            lista l;
                            cout << "Ingrese el nombre del segundo jugador: ";
                            cin >>this->player2;
                            if(!l.buscarjdor(player2))
                            {
                                break;
                            }
                        }
                        flag= 1;
                        this->isRunning=false;
                    }
                    if(ev.button.x >=100 && ev.button.x<=500 && ev.button.y>=370 && ev.button.y<=420)
                    {
                        bool bandera=true;
                        while(bandera==true)
                        {
                            system("xdg-open archivoarreglado.txt");
                            bandera=false;
                        } 
                        flag =1;
                    }
                    
                    if(ev.button.x >=100 && ev.button.x<=500 && ev.button.y>=430 && ev.button.y<=480)
                    {
                        bool bandera=true;
                        while(bandera==true)
                        {
                            system("xdg-open instrucciones.pdf");
                            bandera=false;
                        } 
                        flag =1;
                    }
                }
            }
        SDL_UpdateWindowSurface(this->windows);
        }
    }
    SDL_FreeSurface(this->fondoPrin);
    SDL_FreeSurface(this->jugando);
    SDL_FreeSurface(this->puntos);
    SDL_FreeSurface(this->ayuda);
    SDL_DestroyWindow(this->windows);
    this->windows=nullptr;
    SDL_Quit();
    return flag;
}

void VentanaPrincipal::colocando(int x, int y, SDL_Surface*imagen1)
{
    SDL_Rect destination;
    
    destination.x = y;
    destination.y = x;
    SDL_BlitSurface(imagen1,NULL,this->windowSurface,&destination);
    
}
string VentanaPrincipal::getplayer1()
{
    return this->player1;
}
string VentanaPrincipal::getplayer2()
{
    return this->player2;
}
