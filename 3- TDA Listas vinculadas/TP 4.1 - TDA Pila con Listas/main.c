#include <stdio.h>
#include <stdlib.h>
#include "TDAPila.h"

void cargarPila(Pila *pPila);
void pilaToLista(Pila *p, nodo **lista);

int main()
{
    Pila pilita;
    nodo *lista;

    inicPila(&pilita);
    lInicLista(&lista);

    cargarPila(&pilita);

    mostrar(&pilita);

    pilaToLista(&pilita, &lista);

    printf("LISTA");
    lMostrarLista(&lista);


    lBorrarNodosMenores(&lista, 10);



    printf("LISTA");
    lMostrarLista(&lista);




    return 0;
}

void cargarPila(Pila *pPila)
{
    char com='s';

    while(com=='s')
    {
        leer(pPila);

        printf("Desea agregar otro dato? [s/n]: ");
        fflush(stdin);
        scanf("%c", &com);
    }
}

void pilaToLista(Pila *p, nodo **lista)
{
    Pila aux;
    inicPila(&aux);
    int dato;
    while(!pilavacia(p))
    {
        dato=tope(p);

        if(dato%2==0)
        {
            lAgregarFinal(lista, lCrearNodo(dato));
        }
        apilar(&aux, desapilar(p));
    }
    while(!pilavacia(&aux))
    {
        apilar(p,desapilar(&aux));
    }
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
