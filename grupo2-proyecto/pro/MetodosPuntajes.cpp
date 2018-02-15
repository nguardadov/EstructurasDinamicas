#include <iostream>
#include <cstdlib>
#include"ClasePuntaje.h"

int lista::cast(string cad,int i){
    int h = 0, b=1, b1=1;
    while(cad[i])
    {
        i++;
    }
    i=i-1;
    while(i>=0)
    {
        while(cad[i]=='0')
        {
            h=h+0*b;
           
            b=b*10;
            break;
        }
        while(cad[i]=='1')
        {
            h=h+1*b;
            
            b=b*10;
            break;
        }
       
        while(cad[i]=='2')
        {
            h=h+2*b;
            
            b=b*10;
            break;
        }
        while(cad[i]=='3')
        {
            h=h+3*b;
            
            b=b*10;
            break;
        }
        while(cad[1]=='4')
        {
            h=h+4*b;
            b=b*10;
            break;
        }
        while(cad[i]=='5')
        {
            h=h+5*b;
            b=b*10;
           break;
        }
        while(cad[i]=='6')
        {
            h=h+6*b;
            b=b*10;
            break;
        }
        while(cad[i]=='7')
        {
            h=h+7*b;
            b=b*10;
            break;    }
    
        while(cad[i]=='8')
        {
            h=h+8*b;
            b=b*10;
           break;
        }
        while(cad[i]=='9')
        {
            h=h+9*b;
            b=b*10;
           break;
        }
        i--; 
        
    }
    return h;
}

bool lista::buscarjdor(string nombre){
    
    nodo *act = this->pInicio;
    
    if(act){

        while(act)
        {
            if (act-> nombre == nombre )
            {
                return true;
            }
            else 
            {
                act = act ->sig;
            }
        }return false;
    }
}

void lista::mostrarnombre(void)
{
    nodo *aux = this->pInicio;
    while(aux)
    {
        cout << aux->dato << endl;
        cout << aux->dato2 << endl;
        cout << aux->sumatotal << endl;
        aux = aux->sig;
    }
}

void lista::insertardecreciente(int dato,int dato2,int sumatotal,string nombre)
{
    nodo *nuevo=new nodo;
    nuevo->dato=dato;
    nuevo->dato2=dato2;
    nuevo->sumatotal=sumatotal;
    nuevo->nombre=nombre;
    
     nodo *salto=this->pInicio;
     nodo *aux=NULL;
   
     if (salto)
     {
        while(salto->sig != NULL && salto->sumatotal >= sumatotal)
        {
            aux=salto;
            salto=salto->sig;
        }
        if(salto->sumatotal<sumatotal)
        {
            if (aux==NULL)
            {
                nuevo->sig=salto;
                this->pInicio=nuevo;
                 
            }
            else
            {
                nuevo->sig=salto;
                aux->sig=nuevo;
            }
        }
        else
        {
            if (salto->sig==NULL)
            {
                salto->sig=nuevo;
                nuevo->sig=NULL;
            }
        }
         
    }
    else
    {
        nuevo->sig=this->pInicio;
        this->pInicio=nuevo;
        nuevo->sig=NULL;
    }
     
}
void lista::leerarchivo(void)
{
    
    int ban=0;
    string linea;
    string linea2,linea3,linea4,linea5;
    ifstream aaa;
    aaa.open("archivolistas.txt",ios::in);
    
    while(getline(aaa,linea))
    {
        ban=0;
        int i=0;
        linea2 =""; 
        linea3 ="";
        linea4="";
        linea5="";
        
        while(i < linea.length())
        {
            if (linea[i]!='-' && ban==0)
            {
            linea2=linea2+linea[i];
            }
        else if(linea[i]=='-' && ban==0)
        {
            ban=1;
        }
        else if(linea[i]!='-' && ban ==1)
        {
          linea3=linea3+linea[i];
        }
        else if(linea[i]=='-' && ban ==1)
        {
            ban=3;
        }
        else if(linea[i]!='-' && ban ==3)
        {
            linea4=linea4+linea[i];
        }
        else if(linea[i]=='-' && ban ==3)
        {
            ban=5;
        }
        else if(linea[i]!='-' && ban ==5)
        {
            linea5=linea5+linea[i];
        }
        i++;
    }
        insertardecreciente(cast(linea2,0),cast(linea3,0),cast(linea4,0),linea5);
    }
    aaa.close();
    
}

void lista::limpiar(void)
{
    nodo *p=this->pInicio;
    if(p)
    {
        if(p->sig)
        {
            this->pInicio=this->pInicio->sig;
            delete(p);
            limpiar();
        }
        else
        {
            this->pInicio=NULL;
            delete(p);
        }
    }
}


void lista::llenararchivo(void)
{
    nodo *aux=this->pInicio;
    int cont=0;                                      
    fstream bbb("archivolistas.txt",ios::out);
    fstream mmm("archivoarreglado.txt",ios::out);
    mmm<<"--------------------------top 10--------------------------------"<<endl;
    mmm<<"      jugador           victorias              empates               puntaje total  "<<endl;
    while(aux)
    {
        if (cont>=10)
        {
            break;
        }
        else
        {
        bbb<<aux->dato<<"-";
        mmm<<aux->nombre<<".......................";
        mmm<<aux->dato<<".........................";
        mmm<<aux->dato2<<"........................";
        mmm<<aux->sumatotal<<endl;
        bbb<<aux->dato2<<"-";
        bbb<<aux->sumatotal<<"-";
        bbb<<aux->nombre<<endl;
        aux=aux->sig;
        cont++;
        }
    }
    bbb.close();
    mmm.close();
}
