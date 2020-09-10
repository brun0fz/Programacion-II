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

nodo *agregarNodosPpio(nodo *lista)
{
    char com='s';

    while(com=='s')
    {
        lista=agregarPpio(lista, crearNodo(cargarPersona()));
        fflush(stdin);
        printf("\nDesea cargar otra perona? [s/n]: ");
        scanf("%c", &com);
    }
    return lista;
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

nodo *agregarNodosFinal(nodo *lista)
{
    char com='s';

    while(com=='s')
    {
        lista=agregarFinal(lista, crearNodo(cargarPersona()));
        fflush(stdin);
        printf("\nDesea cargar otra perona? [s/n]: ");
        scanf("%c", &com);
    }
    return lista;
}

nodo *buscarNodo(nodo *lista, char nombre[])
{
    nodo *seg=lista;

    while((seg !=NULL) && (strcmp(nombre, seg->dato.nombre) !=0))
    {
        seg=seg->siguiente;
    }
    return seg;
}

nodo *borrarNodo(nodo *lista, char nombre[])
{
    nodo *seg;
    nodo *ante;

    if((lista != NULL) && (strcmp(nombre, lista->dato.nombre)==0))
    {
        nodo *aux=lista;
        lista=lista->siguiente;
        free(aux);
    }
    else
    {
        seg=lista;
        while((seg !=NULL) && (strcmp(nombre, seg->dato.nombre) !=0))
        {
            ante=seg;
            seg=seg->siguiente;
        }

        if(seg!=NULL)
        {
            ante->siguiente=seg->siguiente;
            free(seg);
        }
    }
    return lista;
}
