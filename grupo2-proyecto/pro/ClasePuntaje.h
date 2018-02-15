#include<iostream>
#include <cstdlib>
#include<fstream>
#include<string>


using namespace std;

struct nodo{
    int dato;
    int dato2;
    int sumatotal;
    string nombre;
    nodo * sig;
};

class lista{
private:
    nodo *pInicio=NULL;
public:
    bool buscarjdor(string);
    void insertardecreciente(int,int,int,string);
    void mostrarnombre(void);
   int  cast(string,int);
   void limpiar(void);
    void leerarchivo(void);
    void llenararchivo(void);
};