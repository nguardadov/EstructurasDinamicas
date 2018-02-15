/* Mery Elizabeth Acevedo Montoya 00267917
   Roxana Carolina Cortéz Díaz 00502211 */
#include <cstdlib>
#include <string.h>
#include<iostream>
#include "Interfaz.h"
#include "VentanaPrincipal.h"


using namespace std;


int main(int argc, char ** argv) 
{
    bool bandera = true;
    string player1,player2;
    int numero = 0;
    while(bandera)
    {
        if(numero == 0)
        {
            VentanaPrincipal vp;
            numero=vp.corriendo();
            player1 = vp.getplayer1();
            player2 = vp.getplayer2();
        }
        else if(numero == 1)
        {
            Ventana v(player1,player2);
            numero=v.correrJuego();
            player1 = "";
            player2 = "";
        }
        else
        {
            bandera = false;
        }
            
    }

   
    return 0;
}