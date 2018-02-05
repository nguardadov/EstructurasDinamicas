#include <SDL2/SDL.h>

class Ventana
{
private:
    char M[3][3];
    bool isRunning;
    //variables para la interfaz
    SDL_Window *windows;
    SDL_Surface *windowSurface;
public:
    Ventana();
    void correrJuego();
    void llenarMatriz();
    void colocarImagen(int, int, SDL_Surface *);
};