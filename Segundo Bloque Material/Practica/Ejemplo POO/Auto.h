#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED

#include <iostream>
#include "strings.h"

using namespace std;

class Auto
{
private:
    int patente;
    char color[20]; ///Atributos
    char marca[20];

public:
    Auto(); //Constructor vacio para inicializar sin datos basura.
    Auto(int p, char c[], char m[]); ///Constructores

    void setPatente(int p);
    int getPatente();

    void setColor(char c[]); ///Metodos
    char* getColor();

    void setMarca(char m[]);
    char* getMarca();

    void mostrar();
};

#endif // AUTO_H_INCLUDED
