#ifndef LISTAENLAZADA_H_INCLUDED
#define LISTAENLAZADA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "persona.h"

////////////////////////////////////////////////////////

typedef struct _nodo
{
    persona dato;
    struct _nodo * siguiente;
} nodo;

////////////////////////////////////////////////////////

////////////////////////////////////////////////////////

nodo *inicLista();
nodo *crearNodo(persona dato);
nodo *agregarPpio(nodo *lista, nodo *nuevoNodo);
void mostrarNodo(nodo *aux);
void recorrerYmostrar(nodo *lista);
nodo *buscarUltimo(nodo *lista);
nodo *agregarFinal(nodo *lista, nodo *nuevonodo);
nodo *buscarNodo(nodo *lista, char nombre[]);

////////////////////////////////////////////////////////

#endif // LISTAENLAZADA_H_INCLUDED
