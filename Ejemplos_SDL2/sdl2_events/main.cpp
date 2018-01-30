#include <iostream>
#include <SDL2/SDL.h>

using namespace std;


int main(int argc, char** argv) {
    
    //para crear la ventana
    SDL_Window *window = nullptr;
    //crear el canvas
    SDL_Surface *windowSurface=nullptr;
    //para colocar las images de fondo
    SDL_Surface *currentImage=nullptr;
    //cargar imagenes
    SDL_Surface *image1=nullptr;
    SDL_Surface *image2=nullptr;
    SDL_Surface *image3=nullptr;
    
    //variable que controlora si el juego esta activo
    bool isRunning=true; //si esta true significa que la aplicacion sigue abierta
    SDL_Event ev; //aca capturara los diferentes eentos que estemos realizando.
    
    //verificamos si se puede inicar el modo video
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        //de no poderse iniciar nos mostrara un error
        cout << "Error al inicializar el video: "<<SDL_GetError()<<endl;
    }
    else
    {
        //creamos la ventana.
        window = SDL_CreateWindow("Hola mundo",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,640,480,SDL_WINDOW_SHOWN);
        //verificamos si la ventana se pudo crear
        if(window == NULL)
        {
            cout << "Error al crear la ventana: "<<SDL_GetError()<<endl;
        }
        else
        {
            //si fue creada cargamos la imges y capturarmos los eventos
            windowSurface=SDL_GetWindowSurface(window);
            //cargamos las imagenes
            image1=SDL_LoadBMP("test.bmp");
            image2=SDL_LoadBMP("test1.bmp");
            image3=SDL_LoadBMP("test2.bmp");
            currentImage=image1;
            //comenzamos el while que endra arriba nuestro programa
            while(isRunning)
            {
                while(SDL_PollEvent(&ev))
                {
                    if(ev.type==SDL_QUIT)
                    {
                        isRunning=false; //con esto salimos del while
                    }
                    else
                    {
                        //aca capturamos el evento del teclado
                        //s ¿i la tecla es presionada
                        if(ev.type==SDL_KEYDOWN)
                        {
                            //si el 
                            switch(ev.key.keysym.sym)
                            {
                                case SDLK_1:
                                    currentImage=image1;
                                break;
                                case SDLK_2:
                                    currentImage=image2;
                                break;
                                case SDLK_3:
                                    currentImage=image3;
                                break;
                                case SDLK_4:
                                    isRunning=false;
                                break;
                            }
                        }
                    }
                   
                }
                SDL_BlitSurface(currentImage,NULL,windowSurface,NULL);
                SDL_UpdateWindowSurface(window);
            }   
        }
    }
   
    SDL_FreeSurface(image1);
    SDL_FreeSurface(image2);
    SDL_FreeSurface(image3);
    SDL_DestroyWindow(window);
    currentImage=image1=image2=image3=nullptr;
    window=nullptr;
    windowSurface=nullptr;
    SDL_Quit();
    return 0;
}

