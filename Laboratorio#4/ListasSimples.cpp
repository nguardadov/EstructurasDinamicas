#include <iostream>
#include <cstdlib>

using namespace std;

/*
 * 
 */

struct nodo
{
    int dato;
    nodo *sig;
};

class ListaSimple
{
private:
    nodo *pInicio;
public:
    ListaSimple();
    void insertarInicio(int);
    void insertarFinal(int);
    void mostrarLista();
};


ListaSimple::ListaSimple(){
    this->pInicio=NULL;
}

void ListaSimple::insertarInicio(int dato)
{
    nodo *cab = new nodo;
    cab->dato = dato;
    
    if(!this->pInicio){
        cab->sig = NULL;
        this->pInicio = cab;
    }
    else
    {
        cab->sig = this->pInicio;
        this->pInicio = cab;
    }
    
}

void ListaSimple::insertarFinal(int dato)
{
    nodo *saltarin = this->pInicio;
    nodo *cab = new nodo;
    
    cab->dato = dato;
    
    if(! this->pInicio)
    {
        cab->sig = this->pInicio;
        this->pInicio = cab;
    }
    else
    {
        while(saltarin->sig){
            saltarin = saltarin->sig;
        }
        saltarin->sig = cab;
        cab->sig=NULL;
    }
    
    
    
    
}

void ListaSimple::mostrarLista(){
    nodo *aux = this->pInicio;
    while(aux)
    {
        cout << aux->dato << endl;
        aux = aux->sig;
    }
}

int main(int argc, char** argv) {
    
    ListaSimple l;
    for (int i=0 ; i<21 ; i++)
    {
        l.insertarInicio(i);
    }
    
    l.mostrarLista();
    
    return 0;
}

