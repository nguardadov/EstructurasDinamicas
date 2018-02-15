#include<iostream>
#include<cstdlib>
using namespace std;

class Juego
{
private:
    char tablero[3][3];
    int cont;
    char token;
public:
    
    Juego();
    char getToken();
    void inizializarTablero();
    void mostrarTablero();
    void turno(int, int);
    bool jugarTurno(int, int, char);
    char getposicion(int, int);
    bool validarGanador();
    bool validarEmpate();
    void escribir(int, int, char);
};


