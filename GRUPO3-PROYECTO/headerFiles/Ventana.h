#include <iostream>
#include <cstdlib>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

using namespace std; 

class Ventana
{
    public:
        int wPantalla = 1366, hPantalla = 768, mWindowID;
        bool focused;

        string rutaBG = "F:/Desarrollo/Cpp/Juego/assets/background.png",
        rutaFuente = "F:/Desarrollo/Cpp/Juego/assets/sample.ttf";

        SDL_Window *ventana;
        SDL_Renderer *ren;
        
        SDL_Texture *bg;
    

        Ventana(){
            this->ventana = NULL;
            this->ren = NULL;
            this->bg = NULL;
            this->focused = false;
            //Identificador de la ventana asignado por SDL
            this->mWindowID = -1;
            
        }

        void crearVentana(int wVentana=930,int hVentana = 630,string fondo = "F:/Desarrollo/Cpp/Juego/assets/background.png"){
            //Centrando la ventana    
            int posX = this->wPantalla / 2 - wVentana / 2;
            int posY = this->hPantalla / 2 - hVentana / 2;
            //Creacion de la ventana               titulo   x    y   w   h      banderas
            this->ventana = SDL_CreateWindow("Juego",posX,posY, wVentana,hVentana, SDL_WINDOW_SHOWN);
            if(ventana == NULL){
                SDL_DestroyWindow(this->ventana);
                this->mostrarError();
                SDL_Quit();
            }
            //Creando el renderer 
            this->ren = SDL_CreateRenderer(this->ventana,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if(this->ren == NULL){
                SDL_DestroyRenderer(this->ren);
                SDL_DestroyWindow(this->ventana);
                this->mostrarError();
                SDL_Quit();
            }
            
            SDL_RenderClear(this->ren);
            this->bg = this->crearDibujo(fondo);
            this->dibujar(this->bg,0,0);
            SDL_RenderPresent(this->ren);
            //Asignando id de ventana
            this->mWindowID = SDL_GetWindowID(this->ventana);
            
        }
        

        void controlarEventos(SDL_Event &e){
            if( e.type == SDL_WINDOWEVENT && e.window.windowID == mWindowID )
	        {
                switch(e.window.event){
                    /*//Hide on close
                    case SDL_WINDOWEVENT_CLOSE:
                        if (this->mWindowID != 2 && this->mWindowID!=3 && this->mWindowID!=1){
                            SDL_DestroyRenderer(this->ren);
                            SDL_DestroyWindow(this->ventana);
                        }
                        
                    break;*/
                    //Keyboard focus gained
                    case SDL_WINDOWEVENT_FOCUS_GAINED:
                        this->focused = true;
                    break;
                    
                    //Keyboard focus lost
                    case SDL_WINDOWEVENT_FOCUS_LOST:
                        this->focused = false;
                    break;
                }
                
            }
        }
        
        void mostrarMensaje(string men){
            SDL_ShowSimpleMessageBox(0, "Atencion",men.c_str(), this->ventana);
        }

        SDL_Texture *crearDibujo(const string &archivo){
            
            SDL_Texture *tex = IMG_LoadTexture(this->ren,archivo.c_str());
            return tex;

        }

        void mostrarError(){
            cout<<"Ha ocurrido un error: "<<SDL_GetError()<<endl;
            return;
        }

        void dibujar(SDL_Texture *tex, int x, int y){
           
            //Inicializando el rectangulo donde estara localizado en la posicion especificada
            SDL_Rect rect;
            rect.x = x;
            rect.y = y;
            //Obteniendo la altura y anchura de la textura y asignandoselos al rectangulo
            SDL_QueryTexture(tex,NULL,NULL,&rect.w,&rect.h);
            SDL_RenderCopy(this->ren,tex,NULL,&rect);
            
        }

        SDL_Texture *renderizarTexto(const string &mensaje, const string &archivoFuente, SDL_Color color, int fontTama){

            //Abriendo fuente
            TTF_Font *font = TTF_OpenFont(archivoFuente.c_str(),fontTama);
            if(font  == nullptr ){
                return nullptr;
            }
            SDL_Surface *surf = TTF_RenderText_Blended(font, mensaje.c_str(),color);
            if(surf == nullptr){
                return nullptr;
            }
            SDL_Texture *texture = SDL_CreateTextureFromSurface(this->ren,surf);
            if(texture == nullptr){
                return nullptr;
            }
            SDL_FreeSurface(surf);
            TTF_CloseFont(font);
            
            return texture;
        }

        SDL_Texture *crearTexto(string contenido, int tama,SDL_Color color){
            
            SDL_Texture *texturaFuente = this->renderizarTexto(contenido,rutaFuente,color,tama);
            if (!texturaFuente){
                TTF_Quit();
                SDL_Quit();
            }
            return texturaFuente;
        }

        int centrarX(int tamaOb){
            return  this->wPantalla / 2 - tamaOb / 2;

        }

        
        void crearContorno(int x, int y, int w, int h,int r= 0, int g = 0, int b = 0,int a = 1){
            SDL_SetRenderDrawColor(this->ren,r,g,b,a);
            //Inicializando el rectangulo donde estara localizado en la posicion especificada
            SDL_Rect rect;
            rect.x = x;
            rect.y = y;
            rect.w = w;
            rect.h = h;
            SDL_RenderFillRect(this->ren,&rect);
            SDL_SetRenderDrawColor(this->ren,0,0,0,1);


        }
};


