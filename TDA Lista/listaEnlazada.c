#include "listaEnlazada.h"
#include "persona.h"

////////////////////////////////////////////////////////

nodo *inicLista()
{
    return NULL;
}

////////////////////////////////////////////////////////

nodo *crearNodo(persona dato)
{
    nodo *nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    return nuevo;
}

////////////////////////////////////////////////////////

nodo *agregarPpio(nodo *lista, nodo *nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
    }
    return lista;
}

////////////////////////////////////////////////////////

void mostrarNodo(nodo *aux)
{
    mostrarPersona(aux->dato);
}

////////////////////////////////////////////////////////

void recorrerYmostrar(nodo *lista)
{
    nodo *seg = lista;
    while(seg !=NULL)
    {
        mostrarNodo(seg);
        seg=seg->siguiente;
    }
}

////////////////////////////////////////////////////////

nodo *buscarUltimo(nodo *lista)
{
    nodo *seg=lista;
    if(seg)
    {
        while(seg->siguiente !=NULL)
        {
            seg=seg->siguiente;
        }
    }
    return seg;
}

////////////////////////////////////////////////////////

nodo *agregarFinal(nodo *lista, nodo *nuevonodo)
{
    if(lista == NULL)
    {
        lista = nuevonodo;
    }
    else
    {
        nodo *ultimo=buscarUltimo(lista);
        ultimo->siguiente=nuevonodo;
    }
    return lista;
}

////////////////////////////////////////////////////////

nodo *buscarNodo(nodo *lista, char nombre[])
{
    nodo *seg=lista;

    while((seg !=NULL) && (strcmp(nombre, seg->dato.nombre) !=0))
    {
        seg=seg->siguiente;
    }
    return seg;
}

/////////////////////////////////////////////////////////////////// Referencia

/*
void agregarNodoPpio(nodo **lista, nodo *nuevoNodo)
{
    if(*lista == NULL)
    {
        *lista = nuevoNodo;
    }
    else
    {
        nuevoNodo->siguiente = *lista;
        *lista = nuevoNodo;
    }
}

void agregarNodosPpio(nodo **lista)
{
    char com='s';

    while(com=='s')
    {
        agregarNodoPpio(lista, crearNodo(cargarPersona()));
        fflush(stdin);
        printf("\nDesea cargar otra perona? [s/n]: ");
        scanf("%c", &com);
    }
}
*/

//////////////////////////////////////////////////////////////////////////////
