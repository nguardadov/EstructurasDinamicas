#include "interfaz.h"
#include <SDL2/SDL_image.h>
#include <iostream>
#include <cstdlib>
using namespace std;

Ventana::Ventana()
{
    this->window=nullptr; // colocamos nuestro puneteros a null;
    this->windowSurface=nullptr; // colocamos // nuestro canas a null
    
    SDL_Init(SDL_INIT_VIDEO); // inciamos la interfaz grafica
    
}


void Ventana::IniciarVentana()
{
    
    /**Matriz de ejemplo**/
    char M[5][5]={{'p','p','p','p','p'}, {'p','0','p','p','p'} , {'p','0','p','p','p'} ,{'p','0','0','0','s'} , {'p','p','p','p','p'} };
    int antx=0, anty=0,f=1; 
    SDL_Surface *image1=nullptr, *image2=nullptr , *image3=nullptr, *image4=nullptr;
   
    
    bool isRunning =true; // con esta bandera indicaremos que el programa esta correindo
    SDL_Event ev; //variable que tendra los eventos
    /*Creando la ventana*/
    this->window=SDL_CreateWindow("Hola Mundo",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,600,600,SDL_WINDOW_SHOWN);
    this->windowSurface = SDL_GetWindowSurface(this->window);
    /*Cragando las imagenes*/
    image1=IMG_Load("pared.png");
    image2=IMG_Load("pasillo.png");
    image3=IMG_Load("salida.png");
    image4=IMG_Load("raton.png");
    /*Luego para que este activa crearemos un eveno para configurar
     el boton salir*/
   
    while(isRunning) // si esta en true continuara el juego
    {
      
        while(SDL_PollEvent(&ev) != 0) //escuchamos los diferentes eventos que se producen
        {
            if(ev.type == SDL_QUIT) // si el usuario da clic en boton salir de la venana
            {
                isRunning=false; // colocamos false para salir del while y terminar el juego
            }
            
            else if(ev.type == SDL_MOUSEBUTTONDOWN)
            {
                if(ev.button.button == SDL_BUTTON_LEFT)
                {
                 //posicionar el raton
                    cout << "x: " << ev.button.x << endl;
                    cout << "y: " << ev.button.y << endl;
                   
                    if( (ev.button.x >= 0 && ev.button.x <= 250) && (ev.button.y >= 0 && ev.button.y <= 250))
                    {
                        if(M[ev.button.y/50][ev.button.x/50] == '0')
                        {
                            cout << "Pasillo " <<M[ev.button.y/50][ev.button.x/50]<< endl;
                            Ventana::ColocarImagen((ev.button.y/50)*50,(ev.button.x/50)*50,image4);
                        }
                    }
                    
                    
                }
            }
            
            if(f==1)
            {
                    // recorremos la matriz para llenarla
                for(int i=0;i<5;i++)
                {
                     for(int j=0;j<5;j++)
                     {
                         if(M[i][j] == 'p')
                         {
                             Ventana::ColocarImagen(i*50,j*50,image1);
                         }
                         else if(M[i][j] == '0')
                         {
                             Ventana::ColocarImagen(i*50,j*50,image2);
                         }
                         else
                         {
                              Ventana::ColocarImagen(i*50,j*50,image3);
                         }
                     }
                }
                f=0;
            }
            
             
        }
        
        //SDL_BlitSurface(currentImage,NULL,windowSurface,NULL);
        SDL_UpdateWindowSurface(this->window); // refresacmos la ventana
    }
   
   SDL_FreeSurface(image1);
    SDL_FreeSurface(image2); 
    
    SDL_DestroyWindow(this->window); // destruimos la ventana
   image1 = image2 = nullptr;
    this->window=nullptr;
    SDL_Quit(); // salimos de sdl
}

void Ventana::ColocarImagen(int x, int y, SDL_Surface *image)
{
    SDL_Rect destination;
    destination.x=y;
    destination.y=x;
    SDL_BlitSurface(image,NULL,this->windowSurface,&destination);
    //SDL_Flip(this->windowSurface);
    //SDL_UpdateWindowSurface(this->window);
}


// funcion para llenar el laberinto
void Ventana::llenarLaberinto()
{
    
}