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

// Función miembro para insertar un nodo en una fila y
// columna dadas de la hoja electrónica.
void HojaElectronica::insNodo(float dato, int fil, int col)
{
    cout << "hola" << endl;
    // Creación de un nuevo nodo:
    nodo *nuevo = new nodo;
    nuevo->dato = dato;
    nuevo->nFil = fil;
    nuevo->nCol = col;
    
    struct nodo *pFil = pHoja->sigFil;
    struct nodo *pCol = pHoja->sigCol;
    
    int i;
    
    int cont=0; //me dira en fila o columna Avanzo;
    // Localización de la posición sobre la fila que va a quedar.
    for(i = 1; i < fil; i++) // Avanzar sobre la columna base;
        pFil = pFil->sigFil;

    if(pFil != pFil->sigCol) {

    while(pFil->sigCol->nCol < col && pFil->sigCol->nCol != 0) // Avanzar sobre la fila y quedar apuntando al anod anteriro.
       {

          cout << pFil->nCol << " " <<col << endl;
          pFil = pFil->sigCol;
          cout << "Aca" << endl;
       } 
       cont = 0;
   }
    // Localización de la posición sobre la columna que va a quedar.
    for(i = 1; i < col; i++) // Avanzar sobre la fila base.
        pCol = pCol->sigCol;

    if(pCol != pCol->sigFil)
    {
         while(pCol->sigFil->nFil < fil && pCol->sigFil->nFil != 0) // Avanzar sobre la columna y quedar apuntando al anod anteriro.
        {
            pCol = pCol->sigFil;
            cout << pCol->dato << endl;
             cout << "hola3" << endl;
        }
    }
   
    
    // Enlazar el nuevo nodo a la estructura.
    nuevo->sigCol = pFil->sigCol;
    pFil->sigCol = nuevo;

    nuevo->sigFil = pCol->sigFil;
    pCol->sigFil = nuevo;


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

//imprimiendo el contenido de la hoja de calculo

void HojaElectronica::imprimirHoja(int fila)
{
     struct nodo *pFil = pHoja->sigFil;
     struct nodo *pCol = NULL;

     for(int i=0; i<fila ; i++)
     {
        pCol = pFil->sigCol;
        while(pCol != pFil)
        {
            cout << "fila: "<<pFil->nFil << " columna: "<< pCol->nCol << " dato: "<< pCol->dato << endl;
            pCol=pCol->sigCol;
        }
        pFil=pFil->sigFil;
     }
}


int main(void) {
    HojaElectronica hoja;
    int nFil, nCol,dato,fil,col;
    
    cout << "Digite cuantas filas y columnas quiere en su hoja: ";
    cin >> nFil >> nCol;
    
    //iniciando la hoja de calculo
    hoja.iniHoja(nFil, nCol);
  /*
       hoja.insNodo(5,2,1);
       hoja.insNodo(5.3,1,1);
       hoja.insNodo(5.3,2,1);
       hoja.insNodo(5.3,2,2);
       hoja.insNodo(5.3,2,3);
       hoja.insNodo(5.3,2,4);

   */
    //Verificar que la fila base se ha creado:
      cout << "\nFila Base "<< endl;  
     hoja.imprimeFilaBase();
    //ingresar un dato en la hoja de calulo
    cout << "\nIngrese el dato a insertar: ";
    cin >> dato;
    // ingresando la fila a donde se va a insertar
    cout << "\nIngrese la fila donde lo va a insertar: ";
    cin >> fil;
    //Ingresandolo en la columna 
    cout << "\nIngrese la columna donde lo va a insertar: ";
    cin >> col;
   //validando que el dato se ingrese en el espacio reservado de filas y columnas
    if(fil >=1 && fil <= nFil && col >=1 && col <= nCol)
    {
        hoja.insNodo(dato,fil,col);
        cout << "\nDatos de la hoja de calculo "<< endl;
        hoja.imprimirHoja(nFil);
    }
    else
    {
        cout << "La fila o columna no existen " << endl;
    }
  
    return 0;
}
