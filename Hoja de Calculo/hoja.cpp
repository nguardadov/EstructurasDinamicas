#include <cstdlib>
#include <iostream>

using namespace std;

struct nodo{
    int nFil, nCol;
    struct nodo *sigCol, *sigFil;
    float dato; // Asumremos que esta hoja electrónica solo acepta datos reales.
    /*int tipo; //1:caracter, 2:enero, 3:real, 4:cadena.
    union tipoDato{
        char car;
        int entero;
        float real;
        char cadena[11];
    } dato;*/
};

class HojaElectronica{
private:
    nodo * pHoja;
public:
    HojaElectronica();
    void iniHoja(int, int);
    void insNodo(float, int, int);
    void imprimeFilaBase(void);
    void imprimirHoja(int); // el enetero q recibe es el numero de la fila
};

// Constructor que inicializa el puntero de la estructura
// de la hoja electrónica.
HojaElectronica::HojaElectronica(void){
    pHoja = NULL;
}

// función miembro que crea la estructura básica de la
// hoja electrónica.
void HojaElectronica::iniHoja(int totFil, int totCol)
{
    struct nodo *s;
    int i;
    
    // Creacion del nodo base de la hoja electronica:
    pHoja = new nodo;
    pHoja->nFil = pHoja->nCol = 0;
    pHoja->sigCol = pHoja->sigFil = pHoja;

    // Creacion de la fila base (nodos base de columnas):
    s = pHoja;
    for(i = 1; i <= totCol; i++){
        s->sigCol = new nodo;
        s = s->sigCol;
        s->nCol = i;
        s->nFil = 0;
        s->sigFil = s; 
        s->sigCol = pHoja;
    };
    // Creacion de la columna base (nodos base de filas):
    s = pHoja;
    for(i = 1; i <= totFil; i++){
        s->sigFil = new nodo;
        s = s->sigFil;
        s->nFil = i;
        s->nCol = 0;
        s->sigCol = s;
        s->sigFil = pHoja;
    }
}


void HojaElectronica::imprimeFilaBase(void)
{
    // Imprimir la fila base:
    nodo *s = pHoja;
    int i = 0;
    cout << "La fila base es:" << endl;
    do{
        cout << "Nodo " << i << ": " << "nFil: " << s->nFil << "    nCol: " << s->nCol << endl;
        s = s->sigCol;
        i++;
    }
    while(s != pHoja);
    
    cout << endl << endl;
    
    // Imprimir la columna base:
    s = pHoja;
    i = 0;
    cout << "La columna base es:" << endl;
    do{
        cout << "Nodo " << i << ": " << "nFil: " << s->nFil << "    nCol: " << s->nCol << endl;
        s = s->sigFil;
        i++;
    }
    while(s != pHoja);
}




int main(void) {
    HojaElectronica hoja;
    int nFil, nCol,dato,fil,col;
    
    cout << "Digite cuantas filas y columnas quiere en su hoja: ";
    cin >> nFil >> nCol;
    
    //iniciando la hoja de calculo
    hoja.iniHoja(nFil, nCol);

    //Verificar que la fila base se ha creado:
      cout << "\nFila Base "<< endl;  
     hoja.imprimeFilaBase();
    
   
  
    return 0;
}
