/*Intercambiano valores usando punteros*/

#include <iostream>
#include <cstdlib>

using namespace std;
void intercambiar(int * , int *);

int main(int argc, char const *argv[])
{
	int a = 2 , b = 3;
	cout << "Valores Normales" << endl;
	cout << a << " " << b << endl;
	intercambiar(&a,&b);
	cout << "Valores intercambiados" << endl;
	cout << a << " " << b << endl;

	return 0;
}

void intercambiar(int *a , int *b)
{
	int aux; //variable auxiliar para guardar el valor de a

	aux=*a; //en aux almecamos el valor de aux en a
	*a = *b; //apuntamos *a con el contenido de b
	*b = aux; //modificamos el contenido de aux
}