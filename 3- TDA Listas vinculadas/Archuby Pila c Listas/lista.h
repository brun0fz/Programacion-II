#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int dato;
    struct nodo * siguiente;
} nodo;



nodo * inicLista();
nodo * crearNodo(int dato);
nodo * agregarPpio(nodo * lista, nodo * nuevoNodo);
nodo * buscarUltimo(nodo * lista);
nodo * buscarNodo(int dato, nodo * lista);
nodo * agregarFinal(nodo * lista, nodo * nuevoNodo);
nodo * borrarNodoBuscado(int dato, nodo * lista);
nodo * agregarEnOrden(nodo * lista, nodo * nuevoNodo);
nodo * borrarTodaLaLista(nodo * lista);
nodo * borrarPrimerNodo(nodo * lista);
nodo * borrarUltimoNodo(nodo * lista);
int retornarPrimerDato(nodo * lista);
int sumarEdadesLista(nodo * lista);
void mostrarNodo(nodo * aux);
void recorrerYmostrar(nodo * lista);
nodo * IngresarDatosAlFinal(nodo * lista);
nodo * IngresarDatosAlPpio(nodo * lista);
nodo * AgregarUnNodoEnOrden(nodo * lista);
nodo * CrearListaOrdenada(nodo * lista);
void SubprogramaBusquedaDeUnNodo(nodo * lista);
nodo * SubprogramaBorrarNodo(nodo * lista);
nodo * SubprogramaIngresarNuevoDato();


#endif // LISTA_H_INCLUDED
