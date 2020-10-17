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
    //Si la lista esta vacia, lista apunta a nuevo nodo
    if(*listaDoble==NULL)
    {
        *listaDoble=nuevo;
    }
    else
    {
        nuevo->siguiente=*listaDoble; //el nuevo nodo ahora apunta al primero por siguiente

        (*listaDoble)->anterior=nuevo; //el nodo que estaba apunta al nuevo por anterior

        *listaDoble=nuevo; //la lista ahora apunta al nuevo
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
    if(*listaDoble==NULL)///Caso 1: Si la lista esta vacia, se enlaza con el nuevo dato
    {
        *listaDoble=nuevo;
    }
    else
    {
        if(nuevo->dato < (*listaDoble)->dato) ///Caso  2: Si el dato a insertar es menor que el primer dato, lo agregamos al principio
        {
            agregarPpioDoble(listaDoble, nuevo);
        }
        else
        {
            nodoDoble *seg = (*listaDoble)->siguiente;//bajamos la lista a una variable auxiliar para no modificarla

            while(seg!=NULL && nuevo->dato > seg->dato)//Buscamos el dato mientras que la lista no este vacia o el dato a insertar sea mayor que el de la lista
            {
                seg=seg->siguiente;
            }

            if(seg!=NULL) ///Caso 3: El dato va entre medio de dos nodos, verificamos que no nos hayamos caido de la lista
            {
                nodoDoble *ante=seg->anterior; //bajamos el nodo anterior a una variable

                ante->siguiente=nuevo; //ante siguiente se enalza con el nuevo nodo

                nuevo->anterior=ante; //el nuevo nodo por anterior se enlaza con ante

                nuevo->siguiente=seg; //nuevo nodo siguiente se enlaza con seg que es el nodo actual

                seg->anterior=nuevo; //seg por anterior se enlaza al nodo nuevo
            }
            else ///caso 4: si no encontramos el hueco para ubicar el dato, quiere decir que nos caimos de la lista y el nuevo dato se inserta al final
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
        if((*pListaDoble)->dato == dato) //Si el nodo a borrar es el primero, bajamos el nodo a una variable, salteamos el nodo y lo borramos
        {
            nodoDoble *aBorrar=*pListaDoble;

            *pListaDoble=(*pListaDoble)->siguiente;

            if(*pListaDoble!=NULL) //si la lista quedo con al menos un dato, tenemos que enlazar por anterior a NULL
            {
                (*pListaDoble)->anterior=NULL;
            }

            free(aBorrar);
        }
        else
        {
            seg=(*pListaDoble)->siguiente;//bajamos la variable a una auxiliar para no modificar la lista

            while((seg !=NULL) && seg->dato != dato) //recorremos la lista mientra que no este vacia y el dato sea distinto
            {
                seg=seg->siguiente;
            }

            if(seg!=NULL)//si encontramos el dato a borrar
            {
                nodoDoble *ante = seg->anterior; //bajamos el nodo anterior a una variable

                ante->siguiente = seg->siguiente; // salteamos el nodo a aborrar

                if(seg->siguiente != NULL)
                {
                    nodoDoble *proximo = seg->siguiente;
                    proximo->anterior=ante;
                }

                free(seg);
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
    printf("[%d]", listaDoble->dato);
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


