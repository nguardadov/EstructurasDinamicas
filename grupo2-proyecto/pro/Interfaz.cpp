#include "Interfaz.h"
#include <SDL2/SDL_image.h>
#include <iostream>
#include <cstdlib>
#include "ClaseJuego.h"
#include "ClasePuntaje.h"
#include "VentanaPrincipal.h"


using namespace std;

Ventana::Ventana(string p1, string p2)
{
    
    this->turno = 1;
    this->contadorX = 0;
    this->contador0 = 0;
    this->conta0 = 0;
    this->contaE = 0;
    this->contaX = 0;
    this -> windows=nullptr;
    this ->windowSurface=nullptr; 
    this ->isRunning=true;
    
    this->imagen1 = NULL;
    this->imagen2 = NULL;
    this->fondo1 = NULL; 
    this->fondo = NULL;
    this->ganador1 = NULL;
    this->ganador2 = NULL;
    this->empate = NULL;
    this->turnoX = NULL;
    this->turno0 = NULL;
    this->borrart = NULL;
    this->lineaH = NULL;
    this->lineaV = NULL;
    this->menu = NULL;
    this->reiniciar = NULL;
    
    this->player1=p1;
    this->player2=p2;
    
    SDL_Init(SDL_INIT_VIDEO);
    
  this-> windows  =  SDL_CreateWindow("'Tic tac toe'", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_SHOWN);
}
int Ventana::correrJuego()
{
    int flag=-1;
    
    Juego mijuego;
    SDL_Event ev; 
    this ->windowSurface= SDL_GetWindowSurface(this-> windows);
    
    this->fondo1 = IMG_Load("fondoP.jpg");
    this->fondo = IMG_Load("fondo.jpg");
    this->imagen1 = IMG_Load("X.jpg");
    this->imagen2 = IMG_Load("0.jpg");
    this->ganador1 = IMG_Load("jugador1.jpg");
    this->ganador2 = IMG_Load("jugador2.jpg");
    this->empate = IMG_Load("empate.jpg");
    this->turnoX = IMG_Load("turnoX.jpg");
    this->turno0 = IMG_Load("turno0.jpg");
    this->borrart = IMG_Load("borrador.jpg");
    this->lineaH = IMG_Load("horizontal.jpg");
    this->lineaV = IMG_Load("vertical.jpg");
    this->menu = IMG_Load("menuBoton.jpg");
    this->reiniciar = IMG_Load("reiniciarBoton.jpg");
    
    Ventana::colocarImagen(0, 0, fondo1);
            
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3;j++)
        {
            Ventana::colocarImagen((i*170)+50,(j*170)+45,fondo);
        }
        SDL_UpdateWindowSurface(this->windows);
    }
    for (int i=0; i<2; i++)
    {
        for (int j=0; j<2;j++)
        {
            Ventana::colocarImagen(i+50,(j*170)+215,lineaV);
            Ventana::colocarImagen((i*170)+220,j+45,lineaH);
        }
        SDL_UpdateWindowSurface(this->windows);
    }
    Ventana::colocarImagen(560,45,this->menu);
    Ventana::colocarImagen(560,385,this->reiniciar);
    
    while(this->isRunning)
    {
        while(SDL_PollEvent(&ev) != 0) 
        {
            if(ev.type == SDL_QUIT)
            {
                flag = 0;
                this ->isRunning =false;
            }
            else if(ev.type == SDL_MOUSEBUTTONDOWN)
            {
                if(ev.button.button == SDL_BUTTON_LEFT)
                {
                    int x,y;
                    x=(ev.button.y/170)+50/170;
                    y=(ev.button.x/170)+45/170; 
                    
                    if(ev.button.x >=45 && ev.button.x<=555 && ev.button.y>=50 && ev.button.y<=560)
                    {
                        if(mijuego.getposicion(x,y)=='_' && this->turno == 1)
                        {
                            Ventana::colocarImagen(0,220,this->turno0);
                            Ventana::colocarImagen(((ev.button.y/170)*170)+50, ((ev.button.x/170)*170)+45, this->imagen1); 
                            for (int i=0; i<2; i++)
                            {
                                for (int j=0; j<2;j++)
                                {
                                    Ventana::colocarImagen(i+50,(j*170)+215,lineaV);
                                    Ventana::colocarImagen((i*170)+220,j+45,lineaH);
                                }
                                    SDL_UpdateWindowSurface(this->windows);
                            }
                            mijuego.escribir(x,y,'X');

                            if(mijuego.validarGanador())
                            {
                                Ventana::colocarImagen(0,220,this->borrart);
                                Ventana::colocarImagen(50, 45, this->ganador1);
                                this->contadorX=contadorX+2;
                                this->contaX=contaX+1;
                                break;
                            }
                            else if(mijuego.validarEmpate())
                            {
                                Ventana::colocarImagen(0,220,this->borrart);
                                Ventana::colocarImagen(50, 45, this->empate);
                                this->contador0=contador0+1;
                                this->contadorX=contadorX+1;
                                this->contaE=contaE+1;
                                break;
                            }
                            this->turno=0;
                        }
                        else if(mijuego.getposicion(x,y)=='_' && this->turno == 0)
                        {
                            Ventana::colocarImagen(0,220,this->turnoX);
                            mijuego.escribir(x,y,'0');
                            
                            Ventana::colocarImagen(((ev.button.y/170)*170)+50, ((ev.button.x/170)*170)+45, this->imagen2);
                            for(int i=0; i<2; i++)
                            {
                                for (int j=0; j<2;j++)
                                {
                                    Ventana::colocarImagen(i+50,(j*170)+215,lineaV);
                                    Ventana::colocarImagen((i*170)+220,j+45,lineaH);
                                }
                                SDL_UpdateWindowSurface(this->windows);
                            }
                            if(mijuego.validarGanador())
                            {
                                Ventana::colocarImagen(0,220,this->borrart);
                                Ventana::colocarImagen(50, 45, this->ganador2);
                                this->contador0=contador0+2;
                                this->conta0=conta0+1;
                                break;
                            }
                            this->turno =1;
                        }
                    }
                    if(ev.button.x >=45 && ev.button.x<=215 && ev.button.y>=560 && ev.button.y<=600)
                    {
                        flag=0;
                        this->isRunning = false;
                        
                    }
                    if(ev.button.x >=385 && ev.button.x<=555 && ev.button.y>=560 && ev.button.y<=600)
                    {
                        flag=1;
                        this->isRunning = false;
                    }
                }
            }
        }
        SDL_UpdateWindowSurface(this->windows);
    }
    lista l;
    l.leerarchivo();
    if(this->contador0!=0 && this->contadorX!=0)
    {
        l.insertardecreciente(contaX,contaE,((contaX*2)+contaE),this->player1);
        l.insertardecreciente(conta0,contaE,((conta0*2)+contaE),this->player2);
        l.llenararchivo();
    }
    else if(this->contador0!=0 && this->contadorX==0)
    {
        l.insertardecreciente(conta0,contaE,((conta0*2)+contaE),this->player2);
        l.llenararchivo();
    }
    else if(this->contador0==0 && this->contadorX!=0)
    {
        l.insertardecreciente(contaX,contaE,((contaX*2)+contaE),this->player1);
        l.llenararchivo();
    }
    
    SDL_FreeSurface(this->fondo1);
    SDL_FreeSurface(this->fondo);
    SDL_FreeSurface(this->imagen1);
    SDL_FreeSurface(this->imagen2);
    SDL_FreeSurface(this->ganador1);
    SDL_FreeSurface(this->ganador2);
    SDL_FreeSurface(this->empate);
    SDL_FreeSurface(this->turnoX);
    SDL_FreeSurface(this->turno0);
    SDL_FreeSurface(this->borrart);
    SDL_FreeSurface(this->lineaH);
    SDL_FreeSurface(this->lineaV);
    SDL_FreeSurface(this->menu);
    SDL_FreeSurface(this->reiniciar);
    SDL_DestroyWindow(this->windows);
    this->windows=nullptr;
    SDL_Quit();
    return flag;
}

void Ventana::colocarImagen(int x, int y, SDL_Surface*imagen1)
{
    SDL_Rect destination;
    destination.x = y;
    destination.y = x;
    SDL_BlitSurface(imagen1,NULL,this->windowSurface,&destination);
    
}