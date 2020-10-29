#ifndef NOTAALUMNO_H_INCLUDED
#define NOTAALUMNO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

////////////////////////////////////////////////////////

typedef struct
{
    int nota;
    int legajo;
    char nombreApe[30];

} notaAlumno;

////////////////////////////////////////////////////////

notaAlumno cargarNotaAlumno();
void mostrarNotaAlumno(notaAlumno dato);
void arGuardarNotaAlumno(char fileName[]);
void arMostrarNotaAlumno(char fileName[]);

////////////////////////////////////////////////////////

#endif
