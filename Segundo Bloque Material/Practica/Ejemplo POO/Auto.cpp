#include "Auto.h"

Auto::Auto()
{
    patente=0;
    color[0]='\0';
    marca[0]='\0';
};

Auto::Auto(int p, char c[], char m[])
{
    this->patente=p; ///no es necesario usar el this
    strcpy(this->color, c);
    strcpy(this->marca, m);
};

void Auto::setPatente(int p)
{
    //this->patente=p; //ejemplo con this y sin this.
    patente=p;

};

int Auto::getPatente()
{
    return patente;
};

void Auto::setColor(char c[])
{
    strcpy(color, c);
};

char* Auto::getColor()
{
    return color;
};

void Auto::setMarca(char m[])
{
    strcpy(marca, m);
};

char* Auto::getMarca()
{
    return marca;
};

void Auto::mostrar()
{
    cout<<"la patente es: "<<patente<<endl;
    cout<<"el color es: "<<color<<endl;
    cout<<"la marca es: "<<marca<<endl;
};
