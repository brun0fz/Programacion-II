#include "listaEnlazada.h"

////////////////////////////////////////////////////////

void inicLista(nodo **pLista)
{
    *pLista=NULL;
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

void agregarPpio(nodo **pLista, nodo *nuevoNodo)
{
    if(*pLista == NULL)
    {
        *pLista = nuevoNodo;
    }
    else
    {
        nuevoNodo->siguiente = *pLista;
        *pLista = nuevoNodo;
    }
}

////////////////////////////////////////////////////////

void mostrarNodo(nodo *aux)
{
    printf("\n%p ---> Siguiente: %p\n", aux, aux->siguiente);
    mostrarPersona(aux->dato);
}

////////////////////////////////////////////////////////

void mostrarLista(nodo **pLista)
{
    nodo *seg = *pLista;
    while(seg !=NULL)
    {
        mostrarNodo(seg);
        seg=seg->siguiente;
    }
}

////////////////////////////////////////////////////////

nodo *buscarUltimo(nodo *pLista)
{
    nodo *seg=pLista;
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

void agregarFinal(nodo **pLista, nodo *nuevonodo)
{
    if(*pLista == NULL)
    {
        *pLista = nuevonodo;
    }
    else
    {
        nodo *ultimo=buscarUltimo(*pLista);
        ultimo->siguiente=nuevonodo;
    }

}

////////////////////////////////////////////////////////

nodo *buscarNodo(nodo **pLista, char nombre[])
{
    nodo *seg=*pLista;

    while((seg !=NULL) && (strcmp(nombre, seg->dato.nombre) !=0))
    {
        seg=seg->siguiente;
    }
    return seg;
}

////////////////////////////////////////////////////////

void borrarNodo(nodo **pLista, char nombre[])
{
    nodo *seg;
    nodo *ante;

    if(*pLista!=NULL)
    {
        if((strcmp(nombre, (*pLista)->dato.nombre)==0))
        {
            nodo *aux=*pLista;
            *pLista=(*pLista)->siguiente;
            free(aux);
        }
        else
        {
            seg=*pLista;
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
}

////////////////////////////////////////////////////////
void agregarEnOrden(nodo **pLista, nodo *nuevoNodo)
{
    if(*pLista==NULL)
    {
        *pLista = nuevoNodo;
    }
    else
    {
        if(nuevoNodo->dato.edad < (*pLista)->dato.edad)
        {
            agregarPpio(pLista, nuevoNodo);

        }
        else
        {
            nodo *seg = (*pLista)->siguiente;
            nodo *ante = *pLista;

            while(seg!=NULL && nuevoNodo->dato.edad > seg->dato.edad)
            {
                ante=seg;
                seg=seg->siguiente;
            }

            ante->siguiente = nuevoNodo;
            nuevoNodo->siguiente = seg;
        }
    }
}

////////////////////////////////////////////////////////

void borrarTodaLaLista(nodo **pLista)
{
    nodo *aux;

    while(*pLista!=NULL)
    {
        aux = (*pLista)->siguiente;
        free(*pLista);
        *pLista=aux;
    }
}

////////////////////////////////////////////////////////

void eliminarPrimerNodo(nodo **pLista)
{
    nodo *aux;

    if(*pLista!=NULL)
    {
        aux=*pLista;
        *pLista=(*pLista)->siguiente;
        free(aux);
    }
}


////////////////////////////////////////////////////////

void eliminarUltimoNodo(nodo **pLista)
{
    nodo *ante=*pLista;
    nodo *seg=*pLista;

    if(*pLista!=NULL)
    {
        if(seg->siguiente==NULL)
        {
            *pLista=NULL;
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
}

////////////////////////////////////////////////////////

void desvincularPrimero(nodo **pLista)
{
    nodo *primero=NULL;

    if(*pLista)
    {
        primero=*pLista;

        *pLista=(*pLista)->siguiente;

        primero->siguiente=NULL;
    }
}
