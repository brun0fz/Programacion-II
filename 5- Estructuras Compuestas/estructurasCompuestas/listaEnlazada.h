#ifndef LISTAENLAZADA_H_INCLUDED
#define LISTAENLAZADA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "notaAlumno.h"

//#define Lista nodo*


////////////////////////////////////////////////////////
typedef struct _nodo {
   notaAlumno dato;
   struct _nodo *siguiente;
} nodo;

////////////////////////////////////////////////////////

void inicLista(nodo **pLista);
nodo *crearNodo(notaAlumno dato);
void agregarPpio(nodo **pLista, nodo *nuevoNodo);
void agregarFinal(nodo **pLista, nodo *nuevonodo);
nodo *buscarUltimo(nodo *pLista);
void borrarTodaLaLista(nodo **pLista);
void mostrarLista(nodo **pLista);
void borrarPrimerNodo(nodo **pLista);
void borrarUltimoNodo(nodo **pLista);
nodo *desvincularPrimerNodo(nodo **pLista);
void mostrarNodo(nodo *aux);
nodo *buscarNodo(nodo **pLista, char nombre[]);
void borrarNodo(nodo **pLista, char nombre[]);
void agregarEnOrden(nodo **pLista, nodo *nuevoNodo);

////////////////////////////////////////////////////////

#endif // LISTAENLAZADA_H_INCLUDED
