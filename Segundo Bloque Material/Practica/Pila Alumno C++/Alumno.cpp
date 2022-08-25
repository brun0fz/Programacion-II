#include "Alumno.h"

Alumno::Alumno()
{
    legajo=0;
    //setLegajo(0);
    strcpy(nya, "");
    edad=0;
    dni=0;
}
Alumno::Alumno(int leg, char p_nya[30])
{
    legajo=leg;
    //setLegajo(leg);
    strcpy(nya, p_nya);
    edad=0;
    dni=0;
}

void Alumno::setLegajo(int leg)
{
    legajo = leg;
}

int Alumno::getLegajo()
{
    return legajo;
}

void Alumno::setNya(char nombre[40])
{
    strcpy(nya, nombre);
}

char *Alumno::getNya()
{
    return nya;
}

void Alumno::setEdad(int e)
{
    edad = e;
}

int Alumno::getEdad()
{
    return edad;
}

void Alumno::setDni(long int doc)
{
    dni = doc;
}

long int Alumno::getDni()
{
    return dni;
}

void Alumno::leer ()
{
    int aux_legajo = 0;
    char aux_nya[40];
    int aux_edad;
    long int aux_dni;

    printf("Ingrese legajo: ");
    fflush(stdin);
    scanf("%d", &aux_legajo);
    printf("Ingrese nombre y apellido: ");
    fflush(stdin);
    gets(aux_nya);
    printf("Ingrese edad: ");
    fflush(stdin);
    scanf("%d", &aux_edad);
    printf("Ingrese un dni: ");
    fflush(stdin);
    scanf("%ld", &aux_dni);
    setEdad(aux_edad);
    setNya(aux_nya);
    setLegajo(aux_legajo);
    setDni(aux_dni);

};
