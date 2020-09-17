#ifndef LISTAENLAZADA_H_INCLUDED
#define LISTAENLAZADA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "persona.h"

#define Lista nodo*

////////////////////////////////////////////////////////

typedef struct _nodo
{
    persona dato;
    struct _nodo * siguiente;
} nodo;

////////////////////////////////////////////////////////

nodo *inicLista();
nodo *crearNodo(persona dato); ///struct persona
nodo *agregarPpio(nodo *lista, nodo *nuevoNodo);
nodo *agregarFinal(nodo *lista, nodo *nuevonodo);
nodo *buscarUltimo(nodo *lista);
nodo *borrarTodaLaLista(nodo *lista);
void recorrerYmostrar(nodo *lista);
nodo *eliminarPrimerNodo(nodo *lista);
nodo *eliminarUltimoNodo(nodo *lista);

///struct Persona
void mostrarNodo(nodo *aux);
nodo *buscarNodo(nodo *lista, char nombre[]);
nodo *borrarNodo(nodo *lista, char nombre[]);
nodo *agregarEnOrden(nodo *lista, nodo *nuevoNodo);

////////////////////////////////////////////////////////

#endif // LISTAENLAZADA_H_INCLUDED
