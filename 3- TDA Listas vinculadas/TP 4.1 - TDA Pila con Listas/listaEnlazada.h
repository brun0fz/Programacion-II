#ifndef LISTAENLAZADA_H_INCLUDED
#define LISTAENLAZADA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

////////////////////////////////////////////////////////

typedef struct _nodo
{
    int dato;
    struct _nodo * siguiente;
} nodo;

////////////////////////////////////////////////////////
void lInicLista(nodo **pLista);
nodo *lCrearNodo(int dato);
void lAgregarPpio(nodo **pLista, nodo *nuevoNodo);
void lMostrarLista(nodo **pLista);
int lDesvincularPrimero(nodo **pLista);
void lAgregarFinal(nodo **pLista, nodo *nuevonodo);
nodo *lBuscarUltimo(nodo *pLista);
void lBorrarNodosMenores(nodo **pLista, int dato);
////////////////////////////////////////////////////////

#endif // LISTAENLAZADA_H_INCLUDED
