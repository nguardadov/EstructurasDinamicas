#include "interfaz.h" // incluimos nuestros prototipos
#include <SDL2/SDL_image.h> //para poder trabajar con imagenes jpg , png, bmp
#include <iostream>
#include <cstdlib>
using namespace std;
//Inicializamos nuestras variables

Ventana::Ventana() {
    
    for(int i=0 ; i< 3 ; i++)
    {
        for(int j=0 ; j<3 ; j++)
        {
            if(j%2 == 0)
            {
             this->M[i][j]=0;   
            }
            else
            {
              this->M[i][j]=1;  
            }
            
        }
    }
    this->windows = nullptr;
    this->windowSurfcae=nullptr;
    this->isRunning = true; //inicamos run en true  
    
    this->imagen1 = nullptr;
    this->imagen2 = nullptr;
    this->fondo = nullptr;
    
    //inicamos SDL2
    SDL_Init(SDL_INIT_VIDEO); //iniciamos los servicios de sdl2 en este caso el de video
    
    //creamos nuestra ventana
    this->windows = SDL_CreateWindow("Hola mundo",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,510,510,SDL_WINDOW_SHOWN);
}

//metodo principal
void Ventana::correrJuego(){
    bool flag = true;
    //creamos una variable que controlara los eventos
    SDL_Event ev;
    //this->windows = SDL_CreateWindow("Hola mundo",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,640,480,SDL_WINDOW_SHOWN);
    if(this->windows == NULL){ //validamos que la ventana se haya creado
        cout << "Error al crear la ventana: "<<SDL_GetError()<<endl;
    }
    else{
        //cargamos las imagenes
        this->fondo = IMG_Load("cuadro.png");
        this->imagen1=IMG_Load("cuadron2.png");
        this->imagen2=IMG_Load("cuadron.png");
        //extremos el canvas
        this->windowSurfcae = SDL_GetWindowSurface(this->windows);
        
        
/*****************************cargar el fondo ***********************************************************/
        
        for(int i=0; i<3 ; i++)
        {
            for(int j=0 ; j<3 ; j++)
            {

                Ventana::ColocarImagen(i*170,j*170,fondo);      
            }   
            SDL_UpdateWindowSurface(this->windows);
        }
        
        
        //el while controlara el juego
        while(this->isRunning){
            
            while(SDL_PollEvent(&ev) != 0) // verificamos si se a ejecutado algun evento
            {
                //verificamos que tipo de evento
                if(ev.type == SDL_QUIT) //si el usuario da clic al boton salir(X)
                {
                    this->isRunning = false;
                }
                else if(ev.type == SDL_MOUSEBUTTONDOWN)
                {
                    if(ev.button.button == SDL_BUTTON_LEFT)
                    {
                        cout << "x" << ev.button.x<< endl;
                        cout << "y" << ev.button.y<< endl;
                        
                        if(this->M[ev.button.y/170][ev.button.x/170] == 0)
                        {
                            Ventana::ColocarImagen((ev.button.y/170)*170,(ev.button.x/170)*170,imagen1);
                        }
                        else
                        {
                            Ventana::ColocarImagen((ev.button.y/170)*170,(ev.button.x/170)*170,imagen2);
                        }
                    }
                }
            }
            
             //refrescamos la ventana
            SDL_UpdateWindowSurface(this->windows);
        }        
        //liberamos memoria
        SDL_FreeSurface(this->fondo);
        SDL_FreeSurface(this->imagen1);
        SDL_FreeSurface(this->imagen2);
        SDL_DestroyWindow(this->windows);
        this->windows = nullptr;
        this->windowSurfcae = nullptr;
        SDL_Quit();
    }
}
/*******************************************************************************************************************************/
void Ventana::ColocarImagen(int x, int y, SDL_Surface *image)
{
    SDL_Rect destination;
    destination.x=y;
    destination.y=x;
    SDL_BlitSurface(image,NULL,this->windowSurfcae,&destination);
}