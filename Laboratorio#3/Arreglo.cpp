#include <iostream>
#include <cstdlib>

using namespace std;

class arreglo
{
private: 
    int *a; // arreglo a utilizar
    int n;
    //matrices 
public: 
    arreglo();
    arreglo(int n);
    void llenar();
    void mostrar();
        
};

arreglo::arreglo(){
}

arreglo::arreglo(int n) {
    this->n =n;
   
    this->a = new int [this->n];
}

void arreglo::llenar()
{
    for (int i=0 ; i<this->n ; i++)
    {
        *(this->a + i) = i;
    }
}

void arreglo::mostrar()
{
    for (int i=0 ; i<this->n ; i++)
    {
       cout << *(this->a + i) <<endl;
    }
}


int main()
{
    int n;
   
    cout << "Ingrese el tamano del arreglo: ";
    cin >> n;
    arreglo a(n);
    a.llenar();
    a.mostrar();
    
    return 0;
}