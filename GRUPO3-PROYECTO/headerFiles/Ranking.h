#include<iostream>
#include <cstdlib>
#include<string.h>
#include<fstream> //Nos ayudara para la creación,escritura y lectura de un archivo.
#include<string>

using namespace std;
//eof: me ayuda a recorrer todo el archivo.
//atoi: convierte una cadena de caracteres en enteró.

struct Nodo
{
    string frase;
    int puntos;   
    Nodo *sig;
};

class Ranking {
private:
    Nodo *pInicio;
public:
    Ranking();
    void escribiendoArchivo(string,int,string,int);
    void lecturaDeArchivo();
    void OrdenarMayor_Menor(string, int);
    void Mostrar();
};
Ranking::Ranking(){
    this->pInicio = NULL;
}
//Escribrir texto en un block de notas.
void Ranking::escribiendoArchivo(string jugador1,int punta1,string jugador2,int punta2) 
{
    ofstream Archivo_Nombres; //Creando archivo que tendra los nombres.
    ofstream Archivo_Puntajes; //Creando archivo que almacenara los puntajes de cada jugador.
    //Abriendo archivos en modo de escritura.
    Archivo_Nombres.open("F:/Desarrollo/Cpp/Juego/assets/Jugadores.txt", ios::app); //Creando, abriendo archivo de nombres y asignandole nombre.
    Archivo_Puntajes.open("F:/Desarrollo/Cpp/Juego/assets/Ranking.txt", ios::app); //Creando, abriendo archivo de puntajes y asignandole nombre.
    
    //Archivo.Fail devolvera True o False. Si no se crea devolvera True y no se podra crear.
    if (Archivo_Nombres.fail() && Archivo_Puntajes.fail())//Validación de creación.
    {
        cout << "No se pudo crear el archivo";
        return; //Saliendo del programa.
    }
    //Escribiendo
    Archivo_Nombres << jugador1 << endl;
    Archivo_Puntajes<< punta1 << endl;
    Archivo_Nombres << jugador2 << endl<<endl;
    Archivo_Puntajes<< punta2 << endl<<endl;
    
    //Cerrando archivos.
    Archivo_Nombres.close();
    Archivo_Puntajes.close();
}
//Leer texto en un block de notas.
void Ranking::lecturaDeArchivo()
{ 
    //Lectura de los archivos.
    ifstream Archivo_Nombres;
    ifstream Archivo_Puntajes;
    
    string frase;
    string f_aux;
    int puntos;
    //Abriendo archivos en modo lectura.
    Archivo_Nombres.open("F:/Desarrollo/Cpp/Juego/assets/Jugadores.txt", ios::in);
    Archivo_Puntajes.open("F:/Desarrollo/Cpp/Juego/assets/Ranking.txt", ios::in);
    
    //Archivo.Fail devolvera True o False. Si no se crea devolvera True y no se podra crear.
    if (Archivo_Nombres.fail() && Archivo_Puntajes.fail())
    {
        cout << "No se pudo crear el archivo";
        exit(1); //Saliendo del programa.
    }
    //Recorriendo todo el archivo de texto.
    while (!Archivo_Nombres.eof() && !Archivo_Puntajes.eof())//Mientras no sea el final de los archivos.
    {
        getline(Archivo_Nombres, frase);//Copiando todo el archivo dentro de la variable "frase".
        getline(Archivo_Puntajes,f_aux);//Copiando todo el archivo dentro de la variable "f_aux".
        puntos = atoi(f_aux.c_str());
        Ranking::OrdenarMayor_Menor(frase, puntos);
    }
    //Cerrando archivos.
    Archivo_Nombres.close();
    Archivo_Puntajes.close();
}
/*Guarda el archivo de texto en una sola funcion para ordenar los nombres basados
 en el puntaje que cada jugador obtiene y se muestran de mayor a menor puntaje.*/

void Ranking::OrdenarMayor_Menor(string frase, int puntos )
{
    Nodo *cajita= new Nodo;
    cajita->frase = frase; // ACA LLAMAR A NOMBRE
    cajita->puntos = puntos;
	
    Nodo *f_aux=this->pInicio;
    Nodo *q;
	
    while (f_aux != NULL && f_aux->puntos < puntos)
    {
        q = f_aux;
        f_aux = f_aux->sig;
    }
    if (pInicio == f_aux)
    {
        pInicio = cajita;
    }
    else 
    {
        q->sig = cajita;
    }
    cajita->sig = f_aux;
}