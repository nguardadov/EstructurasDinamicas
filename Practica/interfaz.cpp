#include "interfaz.h"
#include <SDL2/SDL_image.h>
#include <iostream>
#include <cstdlib>

using namespace std;

Ventana::Ventana() {
    this->windows=nullptr;
    this->windowSurface=nullptr;
    this->isRunning = true;
    SDL_Init(SDL_INIT_VIDEO);
    
    this->windows = SDL_CreateWindow("Hola Mundo", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,510,510,SDL_WINDOW_SHOWN);
}

void Ventana::correrJuego(){
    SDL_Event ev;
    this->windowSurface = SDL_GetWindowSurface(this->windows);
    
    while(this->isRunning)
    {
        while(SDL_PollEvent(&ev) != 0)
        {
            if(ev.type == SDL_QUIT)
            {
                this->isRunning = false;
            }
        }
         SDL_UpdateWindowSurface(this->windows);
    }
    
    
   
    
    //SDL_Delay(10000);
    
    SDL_DestroyWindow(this->windows);
    this->windows = nullptr;
    SDL_Quit();
}