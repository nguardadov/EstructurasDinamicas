#include <SDL2/SDL.h>

class Ventana
{
private:
    /*Variable donde se alamcenara nuestra ventana*/
    SDL_Window *window; 
    /*Variable donde guardara el canvas*/
    SDL_Surface *windowSurface;
public:
    Ventana(); // constructor para incializar las variables para la interfaz
    void IniciarVentana(); // aca iniciarmeos nuestra ventana
    void llenarLaberinto();
    void ColocarImagen(int , int , SDL_Surface *); // fucnion que nos servira para colocar una imagen
};
