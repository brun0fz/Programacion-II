#include "libreria.h"

nodo *inicLista()
{
    return NULL;
}

nodo *crearNodo(persona dato)
{
    nodo *nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    return nuevo;
}

nodo *agregarNodoPpio(nodo *lista, nodo *nuevoNodo)
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

nodo *agregarNodosPpio(nodo *lista)
{
    char com='s';

    while(com=='s')
    {
        lista=agregarNodoPpio(lista, crearNodo(cargarPersona()));

        fflush(stdin);
        printf("\nDesea cargar otra perona? [s/n]: ");
        scanf("%c", &com);
    }
    return lista;
}

persona cargarPersona()
{
    persona p;

    printf("\n---------------\n");
    printf("NOMBRE: ");
    fflush(stdin);
    gets(p.nombre);
    printf("EDAD: ");
    scanf("%d", &p.edad);
    printf("\n---------------\n");

    return p;
}

void mostrarPersona(persona dato)
{
    printf("---------------\n");
    printf("NOMBRE: %s\n", dato.nombre);
    printf("EDAD: %d", dato.edad);
    printf("\n---------------\n");
}

void mostrarNodo(nodo *aux)
{
    mostrarPersona(aux->dato);
}

void recorrerYmostrar(nodo *lista)
{
    nodo *seg = lista;
    while(seg !=NULL)
    {
        mostrarNodo(seg);
        seg=seg->siguiente;
    }
}
