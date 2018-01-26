#include <iostream>
#include <cstdlib>

using namespace std;

class Matrices
{
    private:
        int M[2][2];
        int N[2][2];
        int R[2][2];
        
public :
    Matrices();
    void Sumar();
    void llenarN();
    void llenarM();
    void MostrarSuma();
    
};

Matrices::Matrices(){
    
}


void Matrices::Sumar() {
    for(int i=0 ; i<2 ; i++)
    {
        for(int j=0 ; j<2 ; j++)
        {
            R[i][j] = M[i][j] + N[i][j];
        }
    }
}


void Matrices::MostrarSuma()
{
     for(int i=0 ; i<2 ; i++)
    {
        for(int j=0 ; j<2 ; j++)
        {
            cout <<"["<<i<<"]"<<"["<<j<<"]"<< R[i][j] << endl;
        }
    }
}

void Matrices::llenarM(){
     for(int i=0 ; i<2 ; i++)
    {
        for(int j=0 ; j<2 ; j++)
        {
            M[i][j] = j;
        }
    }
}

void Matrices::llenarN(){
     for(int i=0 ; i<2 ; i++)
    {
        for(int j=0 ; j<2 ; j++)
        {
            N[i][j] = j+2;
        }
    }
}

int main(int argc, char** argv) {
    Matrices m;
    m.llenarM();
    m.llenarN();
    m.Sumar();
    m.MostrarSuma();
    return 0;
}

