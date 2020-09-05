#ifndef _LIBRERIA_H_
#define _LIBRERIA_H_

#include <stdio.h>
#include <stdlib.h>

///Estructuras
////////////////////////////////////////////////////////

typedef struct
{
    char nombre[20];
    int edad;
} persona;

typedef struct _nodo
{
    persona dato;
    struct _nodo * siguiente;
} nodo;

////////////////////////////////////////////////////////

///Cabeceras
////////////////////////////////////////////////////////
nodo *inicLista();
nodo *crearNodo(persona dato);
nodo *agregarNodoPpio(nodo *lista, nodo *nuevoNodo);
nodo *agregarNodosPpio(nodo *lista);

persona cargarPersona();
void mostrarPersona(persona dato);
void mostrarNodo(nodo *aux);
void recorrerYmostrar(nodo *lista);

#endif