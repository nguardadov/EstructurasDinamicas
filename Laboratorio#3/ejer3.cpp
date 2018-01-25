#include <iostream>
#include <cstdlib>

using namespace std;

void crearMatriz(int ***);

int main(int argc, char const *argv[])
{
	int **a;
	crearMatriz(&a);
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			a[i][j]=j;
		}
	}

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			cout << a[i][j] << endl;
		}
	}
	return 0;
}


//creando la matriz de forma dinamica
/*
void crearMatriz(int ***a)
{
	*a = new int * [2];
	for (int i = 0; i < 2; ++i)
	{
		*(*a+i) = new int [2];
	}
}*/
