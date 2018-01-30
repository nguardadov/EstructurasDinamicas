#include <SDL2/SDL.h> //libreria para incluir sdl2

class Ventana{

private:  
/******************Variables que nos ayudaran para la logica del juego*******************************************/
    char M[3][3]; // Matriz del Juego
    bool isRunning; //variable que indica si el juego esta corriendo
/*******************************************************************************************************************/
    
/********************variables que usaremos para SDL2 ***********************************************************/
    SDL_Window *windows; //->windows contendra 
    SDL_Surface *windowSurfcae; //contendra el canvas de nuestro juego
    SDL_Surface *imagen1;
    SDL_Surface *imagen2;
    SDL_Surface *fondo;
/************************************************************************************************************/
    
public:
    Ventana(); //iniciara las variables para nuestra interfaz
    void correrJuego();
    void llenarMatriz();
    void ColocarImagen(int, int , SDL_Surface *); // funcion para colocar la imagen
};