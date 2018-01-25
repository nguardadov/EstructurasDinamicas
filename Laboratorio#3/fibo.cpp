#include <iostream>
#include <cstdlib>

using namespace std;

class Metodos
{
public:
    int fibo(int);
};

int Metodos::fibo(int n)
{
    if(n == 0)
    {
        return 0;
    }
    else if(n==1)
    {
        return 1;
    }
    else
    {
        return Metodos::fibo(n-2) + Metodos::fibo(n-1);
    }
}

void intercambiar(int * , int *);

int main(int argc, char** argv) {
    int n;
    Metodos m;
    cout << "Ingrese un numero: ";
    cin >> n;
    cout << m.fibo(n) << endl;
    
   
    int a=3,b=5;
    cout << "a "<<a <<"  b:"<<b<<endl;
    intercambiar(&a,&b);
    cout << "a "<<a <<"  b:"<<b<<endl;
    return 0;
}

void intercambiar(int *a, int *b)
{
    cout << a << endl;
    int aux = *a;
    *a = *b;
    *b = aux;
}