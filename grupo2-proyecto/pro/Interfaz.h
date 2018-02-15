#include <SDL2/SDL.h>
#include <string>
using namespace std;
class Ventana
{
private:
    bool isRunning; 
    SDL_Window *windows;
    SDL_Surface *windowSurface;
    SDL_Surface *imagen1;
    SDL_Surface *imagen2;
    SDL_Surface *fondo1;
    SDL_Surface *fondo;
    SDL_Surface *ganador1;
    SDL_Surface *ganador2;
    SDL_Surface *empate;
    SDL_Surface *turnoX;
    SDL_Surface *turno0;
    SDL_Surface *borrart;
    SDL_Surface *lineaH;
    SDL_Surface *lineaV;
    SDL_Surface *menu;
    SDL_Surface *reiniciar;
    int turno;
    int contadorX;
    int contador0;
    int contaE;
    int contaX;
    int conta0;
    string player1;
    string player2;
    
public:
    Ventana(string, string);
    int correrJuego();
    void llenarMatriz();
    void colocarImagen(int, int, SDL_Surface *);
};