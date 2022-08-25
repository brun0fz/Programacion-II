#include "pila.h"
#include <string.h>
#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <ctype.h>

Pila::Pila()
{
    inicpila();
};

void Pila::inicpila()
{
   cantidad =0;
};

void Pila::apilar(Alumno dato)
{
    valores[cantidad]=dato;
    cantidad++;
};

Alumno Pila::desapilar()
{
    Alumno tope = valores[cantidad - 1];
    cantidad--;
    return tope;
};

bool Pila::pilavacia()
{
    bool rta = false;
    if (cantidad==0)
        rta=true;
    return rta;
};

void Pila::mostrar()
{
    int i;
    printf("\nBase .............................................. Tope\n\n");
    for (i=0; i < cantidad; i++)
    {
        printf(" %d ", valores[i].getLegajo());
        printf(" %s ", valores[i].getNya());
        printf(" %d ", valores[i].getEdad());
        printf(" %ld ", valores[i].getDni());
        printf("\n");
    }
    printf("\n\nBase .............................................. Tope\n\n");
};

Alumno Pila::tope()
{
    return valores[cantidad -1];
};

void Pila::leer()
{
    Alumno aux_alumno;
    aux_alumno.leer();

    if (cantidad < 50)
    {
        valores[cantidad]=aux_alumno;
        cantidad++;
    }
    else
        printf("Error: la pila esta llena");
};

void Pila::cargarMuchos()
{
    char c='s';
    while(c=='s')
    {
        leer();
        printf("\ndesea continuar?:");
        fflush(stdin);
        scanf("%c", &c);
    }
};

void Pila::pasar(Pila *otra)
{
    while (!otra->pilavacia())
    {
        apilar(otra->desapilar());
    }
};
