#ifndef TDAFILA_H_INCLUDED
#define TDAFILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "TDALista2.h"

typedef struct
{
    nodoDoble* inicio;
    nodoDoble* Fin;
} Fila;

void inicFila(Fila* pFila);

void mostrar(Fila* pFila);

void agregar(Fila* pFila, int dato);

int extraer(Fila* pFila);

void leer(Fila* pFila);

int primero(Fila* pFila);

int filaVacia(Fila* pFila);

#endif // TDAFILA_H_INCLUDED
