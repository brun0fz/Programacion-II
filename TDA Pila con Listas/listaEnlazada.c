#include "listaEnlazada.h"

////////////////////////////////////////////////////////

void lInicLista(nodo **pLista)
{
    *pLista=NULL;
}

////////////////////////////////////////////////////////

nodo *lCrearNodo(int dato)
{
    nodo *nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    return nuevo;
}

////////////////////////////////////////////////////////

void lAgregarPpio(nodo **pLista, nodo *nuevoNodo)
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

void lMostrarLista(nodo **pLista)
{
    nodo *seg = *pLista;
    while(seg !=NULL)
    {
        printf("%d\n", seg->dato);
        seg=seg->siguiente;
    }
}

int lDesvincularPrimero(nodo **pLista)
{
    nodo *aux;
    int dato=0;

    if(*pLista)
    {
        aux=*pLista;
        *pLista=(*pLista)->siguiente;
        dato=aux->dato;
        free(aux);
    }

    return dato;
}

void lAgregarFinal(nodo **pLista, nodo *nuevonodo)
{
    if(*pLista == NULL)
    {
        *pLista = nuevonodo;
    }
    else
    {
        nodo *ultimo=lBuscarUltimo(*pLista);
        ultimo->siguiente=nuevonodo;
    }

}

nodo *lBuscarUltimo(nodo *pLista)
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

void lBorrarNodosMenores(nodo **pLista, int dato)
{
    nodo *seg;
    nodo *ante;
    nodo *aux=*pLista;

    if(*pLista!=NULL)
    {
        while(aux!=NULL)
        {
            if((*pLista)->dato < dato)
            {
                nodo *aux=*pLista;
                *pLista=(*pLista)->siguiente;
                free(aux);
            }
            else
            {
                seg=*pLista;
                while((seg !=NULL) && seg->dato > dato)
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
            aux=aux->siguiente;
        }
    }
}
