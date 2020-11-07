#ifndef ARBOLES_H_INCLUDED
#define ARBOLES_H_INCLUDED

#include "animales.h"

typedef struct nodoArbol
{
    animal dato;
    struct nodoArbol * izq;
    struct nodoArbol * der;
} nodoArbol;

void inicArbol(nodoArbol **arbolito);
nodoArbol* crearNodoArbol(animal dato);
nodoArbol* insertarArbolOrdenado(nodoArbol *arbolito, animal dato);
void preorder(nodoArbol *arbolito);
void inorder(nodoArbol *arbolito);
void postorder(nodoArbol *arbolito);
//nodo *arbolToLista(nodoArbol* arbolito, nodo *lista);
//nodo *arbolToListaFiltrado(nodoArbol* arbolito, nodo *lista);
nodoArbol *buscarNodoArbol(nodoArbol *arbolito, int legajo);
nodoArbol *buscarNombre(nodoArbol *arbolito, char nombre[]);
int contarNodos(nodoArbol *arbolito);
int contarNodosFiltrado(nodoArbol *arbolito);
int contarHojas(nodoArbol *arbolito);
int sumarArbol(nodoArbol *arbolito);
int sumarArbolFiltrado(nodoArbol *arbolito);

#endif // ARBOLES_H_INCLUDED
