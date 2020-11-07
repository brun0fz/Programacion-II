#ifndef ANIMALES_H_INCLUDED
#define ANIMALES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

////////////////////////////////////////////////////////

typedef struct
{
    char nombreAnimal [30];
    int cantidad;
    int habitat;
// 1 - selva, 2- savana, 3-bosque, 4-mar
} animal;

////////////////////////////////////////////////////////

animal cargaranimal();
void mostraranimal(animal dato);
void arGuardaranimals(char fileName[]);
void arMostraranimals(char fileName[]);

////////////////////////////////////////////////////////

#endif
