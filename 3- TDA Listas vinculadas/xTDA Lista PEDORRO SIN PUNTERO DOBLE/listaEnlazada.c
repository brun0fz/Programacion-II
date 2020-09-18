#include "listaEnlazada.h"

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
    printf("\n%p ---> Siguiente: %p\n", aux, aux->siguiente);
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

////////////////////////////////////////////////////////

nodo *borrarNodo(nodo *lista, char nombre[])
{
    nodo *seg;
    nodo *ante;

    if(lista!=NULL)
    {
        if((strcmp(nombre, lista->dato.nombre)==0))
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
    }
    return lista;
}

////////////////////////////////////////////////////////

nodo *agregarEnOrden(nodo *lista, nodo *nuevoNodo)
{
    if(lista==NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        if(nuevoNodo->dato.edad < lista->dato.edad)
        {
            lista=agregarPpio(lista, nuevoNodo);

        }
        else
        {
            nodo *seg = lista->siguiente;
            nodo *ante = lista;

            while(seg!=NULL && nuevoNodo->dato.edad > seg->dato.edad)
            {
                ante=seg;
                seg=seg->siguiente;
            }

            ante->siguiente = nuevoNodo;
            nuevoNodo->siguiente = seg;
        }
    }

    return lista;
}

////////////////////////////////////////////////////////

nodo *borrarTodaLaLista(nodo *lista)
{
    nodo *proximo;
    nodo *seg;
    seg=lista;

    while(seg!=NULL)
    {
        proximo = seg->siguiente;
        free(seg);
        seg=proximo;
    }

    return seg;
}

////////////////////////////////////////////////////////

nodo *eliminarPrimerNodo(nodo *lista)
{
    nodo *ante;
    nodo *seg=lista;

    if(seg!=NULL)
    {
        ante=seg;
        seg=seg->siguiente;
        free(ante);
    }

    return seg;
}


////////////////////////////////////////////////////////

nodo *eliminarUltimoNodo(nodo *lista)
{
    nodo *ante=lista;
    nodo *seg=lista;

    if(lista!=NULL)
    {
        if(seg->siguiente==NULL)
        {
            lista=NULL;
            free(seg);
        }
        else
        {
            while(seg->siguiente != NULL)
            {
                ante=seg;
                seg=seg->siguiente;

            }
            ante->siguiente=NULL;
            free(seg);
        }
    }
    return lista;
}

////////////////////////////////////////////////////////
//Referencia

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
