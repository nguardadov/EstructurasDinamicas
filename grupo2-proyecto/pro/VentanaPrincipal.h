#include <SDL2/SDL.h>
#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

class VentanaPrincipal
{
private:
    string player1;
    string player2;
    bool isRunning;
    SDL_Window *windows;
    SDL_Surface *windowSurface;
    SDL_Surface *fondoPrin;
    SDL_Surface *jugando;
    SDL_Surface *puntos;
    SDL_Surface *ayuda;
    
public:
    VentanaPrincipal();
    int corriendo();
    void llenando();
    void colocando(int, int, SDL_Surface *);
    string getplayer1();
    string getplayer2();
};