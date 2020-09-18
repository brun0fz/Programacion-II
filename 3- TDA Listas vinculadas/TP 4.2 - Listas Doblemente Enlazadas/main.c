#include <stdio.h>
#include <stdlib.h>

#include "TDALista2.h"

void subprogramaCargarListaDoblePpio(nodoDoble **pListaDoble);
void subprogramaCargarListaDobleFinal(nodoDoble **pListaDoble);
void subprogramaCargarListaDobleOrdenado(nodoDoble **pListaDoble);

nodoDoble* buscarNodoMedio(nodoDoble *pListaDoble);
void eliminarNodoMedio(nodoDoble **pListaDoble);



int main()
{
    nodoDoble *listaDoble;
    inicListaDoble(&listaDoble);

    subprogramaCargarListaDobleFinal(&listaDoble);

    eliminarNodoMedio(&listaDoble);

    mostrarListaDoble(listaDoble);

    return 0;
}

void subprogramaCargarListaDoblePpio(nodoDoble **pListaDoble)
{

    int dato=0;
    char com='s';

    while(com=='s')
    {
        printf("Ingrese un entero: ");
        scanf("%d", &dato);

        agregarPpioDoble(pListaDoble, crearNodoDoble(dato));

        printf("Desea ingresar otro dato [s/n]: ");
        fflush(stdin);
        scanf("%c", &com);
    }
}

void subprogramaCargarListaDobleFinal(nodoDoble **pListaDoble)
{

    int dato=0;
    char com='s';

    while(com=='s')
    {
        printf("Ingrese un entero: ");
        scanf("%d", &dato);

        agregarFinalDoble(pListaDoble, crearNodoDoble(dato));

        printf("Desea ingresar otro dato [s/n]: ");
        fflush(stdin);
        scanf("%c", &com);
    }
}

void subprogramaCargarListaDobleOrdenado(nodoDoble **pListaDoble)
{

    int dato=0;
    char com='s';

    while(com=='s')
    {
        printf("Ingrese un entero: ");
        scanf("%d", &dato);

        agregarEnOrdenDoble(pListaDoble, crearNodoDoble(dato));

        printf("Desea ingresar otro dato [s/n]: ");
        fflush(stdin);
        scanf("%c", &com);
    }
}

nodoDoble* buscarNodoMedio(nodoDoble *pListaDoble)
{
    nodoDoble *p=pListaDoble;
    nodoDoble *q=pListaDoble;

    while(q!=NULL && q->siguiente!=NULL)
    {
        p=p->siguiente;
        q=q->siguiente->siguiente;
    }

    return p;
}

void eliminarNodoMedio(nodoDoble **pListaDoble)
{
    nodoDoble *medio=buscarNodoMedio(*pListaDoble);
    borrarNodoDoble(pListaDoble, medio->dato);
}
