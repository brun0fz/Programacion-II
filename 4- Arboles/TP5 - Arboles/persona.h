#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

////////////////////////////////////////////////////////

typedef struct
{
    int legajo;
    char nombre[20];
    int edad;
} persona;

////////////////////////////////////////////////////////

persona cargarPersona();
void mostrarPersona(persona dato);
void arGuardarPersonas(char fileName[]);
void arMostrarPersonas(char fileName[]);

////////////////////////////////////////////////////////

#endif
