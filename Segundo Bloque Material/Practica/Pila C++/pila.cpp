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
   cantidad=0;
};

void Pila::apilar(int dato)
{
    valores[cantidad]=dato;
    cantidad++;
};

int Pila::desapilar()
{
    int tope = valores[cantidad - 1];
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
        printf("| %d ", valores[i]);
    printf("\n\nBase .............................................. Tope\n\n");
};

int Pila::tope()
{
    return valores[cantidad -1];
};

void Pila::leer ()
{
    int aux = 0;
    if (cantidad < 50)
    {
        printf("Ingrese un valor entero: ");
        fflush(stdin);
        scanf("%d", &aux);
        apilar(aux);
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
