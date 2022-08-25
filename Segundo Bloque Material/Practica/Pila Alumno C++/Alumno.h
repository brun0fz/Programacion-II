#include <string.h>
#include <stdio.h>
#include <stdlib.h>

class Alumno
{
private:
    int legajo;
    char nya[40];
    int edad;
    long int dni;

public:
    Alumno();
    Alumno(int leg, char p_nya[40]);

    void setLegajo(int leg);
    int getLegajo();

    void setNya(char nombre[40]);
    char *getNya();

    void setEdad(int e);
    int getEdad();

    void setDni(long int doc);
    long int getDni();

    void leer();
};
