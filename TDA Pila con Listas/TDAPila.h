#ifndef TDAPILA_H_INCLUDED
#define TDAPILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "listaEnlazada.h"

#define Pila nodo*

void inicPila(nodo **pila);
int pilavacia(nodo **pila);
int tope(nodo **pila);
int desapilar(nodo **pila);
void apilar(nodo **pila, int dato);
void leer(nodo **pila);
void mostrar(nodo **pila);

#endif // TDAPILA_H_INCLUDED
