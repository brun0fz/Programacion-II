#include "TDALista2.h"

void inicListaDoble(nodoDoble **listaDoble)
{
    *listaDoble=NULL;
}

nodoDoble *crearNodoDoble(int dato)
{
    nodoDoble *nuevo = (nodoDoble*)malloc(sizeof(nodoDoble));
    nuevo->dato=dato;
    nuevo->siguiente=NULL;

    nuevo->anterior=NULL; ///Diferencia con lista simple

    return nuevo;
}

void agregarPpioDoble(nodoDoble **listaDoble, nodoDoble *nuevo)
{
    if(*listaDoble==NULL)
    {
        *listaDoble=nuevo;
    }
    else
    {
        nuevo->siguiente=*listaDoble; ///El nuevo->siguiente apunta al que estaba en primer lugar

        (*listaDoble)->anterior=nuevo; ///El que se corrio un lugar, apunta al nuevo por anterior

        *listaDoble=nuevo; ///la lista apunta al nuevo nodo agregado
    }
}

void agregarFinalDoble(nodoDoble **listaDoble, nodoDoble *nuevo)
{
    nodoDoble *ultimo;

    if(*listaDoble==NULL)
    {
        *listaDoble=nuevo;
    }
    else
    {
        ultimo=buscarUltimoDoble(*listaDoble);

        ultimo->siguiente=nuevo; ///Enlaza el ultimo nodo con el nuevo

        nuevo->anterior=ultimo; ///Enlaza el nuevo con el anteultimo
    }

}

nodoDoble *buscarUltimoDoble(nodoDoble *listaDoble)
{
    nodoDoble *ultimo=listaDoble;

    if(ultimo!=NULL)
    {
        while(ultimo->siguiente !=NULL)
        {
            ultimo=ultimo->siguiente;
        }
    }
    return ultimo;
}

void agregarEnOrdenDoble(nodoDoble **listaDoble, nodoDoble *nuevo)
{
    if(*listaDoble==NULL)///Caso 1: Lista vacia, agrego al principio
    {
        *listaDoble=nuevo;
    }
    else
    {
        if(nuevo->dato < (*listaDoble)->dato) ///Caso  2: lista con datos, el dato va al principio
        {
            agregarPpioDoble(listaDoble, nuevo);
        }
        else
        {
            nodoDoble *seg = (*listaDoble)->siguiente;
            while(seg!=NULL && seg->dato < nuevo->dato)
            {
                seg=seg->siguiente;
            }

            if(seg!=NULL) ///Caso 3: El dato va entre medio de dos nodos
            {
                nodoDoble *ante=seg->anterior;

                ante->siguiente=nuevo;

                nuevo->anterior=ante;

                nuevo->siguiente=seg;

                seg->anterior=nuevo;
            }
            else ///caso 4: El dato va al final
            {
                agregarFinalDoble(listaDoble, nuevo);
            }
        }
    }
}

void borrarNodoDoble(nodoDoble **pListaDoble, int dato)
{
    nodoDoble *seg=NULL;

    if(*pListaDoble!=NULL)
    {
        if((*pListaDoble)->dato == dato)
        {
            nodoDoble *aBorrar=*pListaDoble;

            *pListaDoble=(*pListaDoble)->siguiente;

            if(*pListaDoble!=NULL)
            {
                (*pListaDoble)->anterior=NULL;
            }

            free(aBorrar);
        }
        else
        {
            seg=*pListaDoble;
            while((seg !=NULL) && seg->dato != dato)
            {
                seg=seg->siguiente;
            }

            if(seg!=NULL)
            {
                nodoDoble *ante = seg->anterior;
                ante->siguiente = seg->siguiente;
                if(seg->siguiente != NULL)
                {
                    nodoDoble *sig = seg->siguiente;
                    sig->anterior=ante;
                }

            }
        }
    }
}

nodoDoble *buscarNodoDoble(nodoDoble **pListaDoble, int dato)
{
    nodoDoble *seg=*pListaDoble;

    while((seg !=NULL) && seg->dato==dato)
    {
        seg=seg->siguiente;
    }
    return seg;
}

void borrarPrimerNodoDoble(nodoDoble **pListaDoble)
{
    if(*pListaDoble!=NULL)
    {
        nodoDoble *aBorrar=*pListaDoble;

        *pListaDoble=(*pListaDoble)->siguiente;

        if(*pListaDoble!=NULL)
        {
            (*pListaDoble)->anterior=NULL;
        }

        free(aBorrar);
    }
}

void borrarUltimoNodoDoble(nodoDoble **pListaDoble)
{
    nodoDoble *seg=*pListaDoble;

    if(*pListaDoble !=NULL)
    {
        if(seg->siguiente==NULL)
        {
            *pListaDoble=NULL;
            free(seg);
        }
        else
        {
            while(seg->siguiente!=NULL)
            {
                seg=seg->siguiente;
            }
            nodoDoble *ante=seg->anterior;
            ante->siguiente=NULL;
            free(seg);
        }
    }

}

void mostrarUnNodoDoble(nodoDoble *listaDoble)
{
    printf("[%d] <-- ", listaDoble->dato);
}

void mostrarListaDoble(nodoDoble *listaDoble)
{
    nodoDoble *seg=listaDoble;

    while(seg!=NULL)
    {
        mostrarUnNodoDoble(seg);
        seg=seg->siguiente;
    }
}

int PrimerNodoDoble(nodoDoble *listaDoble)
{
    int primero=0;

    if(listaDoble)
    {
        primero=listaDoble->dato;
    }

    return primero;
}
