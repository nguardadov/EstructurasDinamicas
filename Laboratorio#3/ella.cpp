/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: estructuras
 *
 * Created on 25 de enero de 2018, 11:27 AM
 */

#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

/*
 * 
 */

class Ella
{
private :
    string nombre;
    string wathsapp;
public:
    Ella();
    Ella(string, string);
    /**Metodos*/
    string getNombre();
    string getWathsapp();
    /**Set*/
    void setNombre(string);
    void setWathsapp(string);
};

/**COnstructores */
Ella::Ella(){}

Ella::Ella(string nombre , string wathsapp)
{
    this->nombre = nombre;
    this->wathsapp=wathsapp;
}

/**Getter*/
string Ella::getNombre(){
    return this->nombre;
}

string Ella::getWathsapp(){
    return this->wathsapp;
}

/**Setter*/

void Ella::setNombre(string nombre){
    this->nombre=nombre;
}

void Ella::setWathsapp(string wathsapp){
    this->wathsapp =  wathsapp;
}


int main(int argc, char** argv) {
    Ella e1("Laura","2257777");
    cout << e1.getNombre() << endl;
    cout << e1.getWathsapp() << endl;
    cout << "Modificando "<< endl;
    e1.setWathsapp("79771354");
    cout << e1.getNombre() << endl;
    cout << e1.getWathsapp() << endl;
    
    return 0;
}

