#ifndef TDALISTA2_H_INCLUDED
#define TDALISTA2_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct _nodoDoble
{
    int dato;
    struct _nodoDoble *siguiente;
    struct _nodoDoble *anterior;

}nodoDoble;

void inicListaDoble(nodoDoble **listaDoble);
nodoDoble *crearNodoDoble(int dato);
void agregarPpioDoble(nodoDoble **listaDoble, nodoDoble *nuevo);
void agregarFinalDoble(nodoDoble **listaDoble, nodoDoble *nuevo);
nodoDoble *buscarUltimoDoble(nodoDoble *listaDoble);
void agregarEnOrdenDoble(nodoDoble **listaDoble, nodoDoble *nuevo);
void borrarNodoDoble(nodoDoble **pListaDoble, int dato);
nodoDoble *buscarNodoDoble(nodoDoble **pListaDoble, int dato);
void borrarPrimerNodoDoble(nodoDoble **pListaDoble);
void borrarUltimoNodoDoble(nodoDoble **pListaDoble);
void mostrarUnNodoDoble(nodoDoble *listaDoble);
void mostrarListaDoble(nodoDoble *listaDoble);
int PrimerNodoDoble(nodoDoble *listaDoble);

#endif // TDALISTA2_H_INCLUDED
