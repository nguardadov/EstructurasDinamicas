#include <cstdlib>
#include<iostream>
#include "ClaseJuego.h"

using namespace std;

Juego::Juego()
{
    this->token='X';
    inizializarTablero();
}
void Juego::inizializarTablero()
{
    for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                tablero[i][j]='_';
            }
        }
}
void Juego::mostrarTablero()
{
    for(int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        { 
            cout << tablero[i][j] << " ";
        }
        cout << endl;
    }
}
void Juego::turno(int m, int n)
{
    if(cont%2 == 0)
        token='X';
    else
        token='0';
    
    if(Juego::jugarTurno(m,n,token))
    {
        cont ++;
    }
    
}
void Juego::escribir(int i, int j , char tok)
{
    tablero[i][j] = tok;
}


bool Juego::jugarTurno(int fil, int col, char tok)
{
    cout << "Turno de: " << tok << endl;
    
    if (tablero[fil][col] == '_')
        {
            tablero[fil][col] = tok;
            return true;
        }    
    else 
    {
        cout << "Intente nuevamente." << endl;
        return false;
    }
           
}
bool Juego::validarGanador()
{
    if(tablero[0][0]!='_' && tablero[0][0] ==  tablero[0][1] && tablero[0][1] == tablero[0][2])
    {    
        token=tablero[0][0];
        return true; 
    }
    if(tablero[1][0]!='_' and tablero[1][0] == tablero[1][1]  and tablero[1][1] ==tablero[1][2])
    {
        token=tablero[1][0];
        return true;
    }
    if(tablero[2][0]!='_' and tablero[2][0]==tablero[2][1] and tablero[2][1]==tablero[2][2])
    {
        token=tablero[2][0];
        return true;
    }

    if(tablero[0][0]!='_' and tablero[0][0]==tablero[1][0]  and tablero[1][0]==tablero[2][0])
    {
        token=tablero[0][0];
        return true;
    }   
    if(tablero[0][1]!='_' and tablero[0][1]==tablero[1][1]  and tablero[1][1]==tablero[2][1])
    {
        token=tablero[0][1];
        return true;
    }
    if(tablero[0][2]!='_' and tablero[0][2]==tablero[1][2] and tablero[1][2]==tablero[2][2])
    {
        token=tablero[0][2];
        return true;
    }

    if(tablero[0][0]!='_' and tablero[0][0]==tablero[1][1] and tablero[1][1]==tablero[2][2])
    {
        token=tablero[0][0];
        return true;
    }   
    if (tablero[0][2]!='_' and tablero[0][2]==tablero[1][1] and tablero[1][1]==tablero[2][0])
    {
        token=tablero[0][2];
        return true;
    }
    return false;
}
bool Juego::validarEmpate()
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3;j++)
        {
            if(tablero[i][j]=='_')
                return false;
        }
    }
    return true;
}

char Juego::getToken()
{
    return token;
}
char Juego::getposicion(int m, int n)
{
    return tablero[m][n];
}
