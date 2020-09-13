#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

////////////////////////////////////////////////////////

typedef struct
{
    char nombre[20];
    int edad;
} persona;

////////////////////////////////////////////////////////

persona cargarPersona();
void mostrarPersona(persona dato);

////////////////////////////////////////////////////////


#endif
