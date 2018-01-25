/*Intercambiano valores de un arreglo*/

#include <iostream>
#include <cstdlib>

using namespace std;
void crear(int **);

int main(int argc, char const *argv[])
{
	int *a ; //arreglo el cula llenarmos de forma dinamica
	/*Creamos el arreglo*/
	crear(&a);
	/*LLenamos el arreglo*/
	for (int i = 0; i < 6; ++i)
	{
		a[i]=i+1;
	}

	/*mostrando los valores del arreglo*/
	for (int i = 0; i < 6; ++i)
	{
		cout << *(a+i) << endl;
	}

	int final = 6-1,aux; // aux nos servira para almacenar temporalmente un elemento del arreglo
	//final nos indica el ultimo inidce del arreglo

	//dando vuelta al arreglo
	/*
	la forma *(a+i) es equivalente a decir a[i]
	*/
	for (int i = 0; i < (6/2); i++)
	{
		aux = *(a+i);
		*(a+i)=*(a+final);
		*(a+final)=aux;
		final=final-1; //vamos disminuyendo nuestra varaible para final
	}
	/*Desplegamos para comprobar que se a invertido el arreglo*/
	cout << "al reves" << endl;
	for (int i = 0; i < 6; ++i)
	{
		cout << *(a+i) << endl;
	}
	return 0;
}

void crear(int **a)
{
	*a = new int[6]; //creamos el arreglo de forma dinamica
}