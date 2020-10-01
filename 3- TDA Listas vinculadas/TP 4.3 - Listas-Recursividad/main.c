#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <conio.h>

#include "listaEnlazada.h"

////////////////////////////////////////////////////////

void SubProgramaAgregarNodosPpio(nodo **lista);
void SubProgramaAgregarNodosFinal(nodo **pLista);

void mostrarListaInvertidaRecursivo(nodo *pLista);
int sumarListaRecursivo(nodo *lista);
void MostrarPosParRecursivo(nodo * lista);
void otroMuestraPosParRecursivo(nodo *lista, int pos);
nodo * invertirListaRecursivo (nodo * lista);
nodo * borrarNodoRecursivo(nodo *pLista, char nombre[]);
nodo* insertarEnOrdenRecursivo(nodo * lista, nodo * nuevo);

////////////////////////////////////////////////////////

int main()
{
    nodo *listita;
    inicLista(&listita);

    SubProgramaAgregarNodosPpio(&listita);

    mostrarListaInvertidaRecursivo(listita);

    //printf("La suma es: %d",sumarListaRecursivo(listita));


    //MostrarPosParRecursivo(listita, 1);

    //listita=invertirListaRecursivo(listita);

    //mostrarLista(&listita);

    //listita=borrarNodoRecursivo(listita, "bruno");

    //printf("\n\nNODO BORRADO\n\n");
    //mostrarLista(&listita);


    return 0;
}


////////////////////////////////////////////////////////

void SubProgramaAgregarNodosPpio(nodo **pLista)
{
    char com='s';

    while(com=='s')
    {
        agregarPpio(pLista, crearNodo(cargarPersona()));
        printf("\nDesea cargar otra persona? [s/n]: ");
        fflush(stdin);
        scanf("%c", &com);
    }
}

////////////////////////////////////////////////////////

void SubProgramaAgregarNodosFinal(nodo **pLista)
{
    char com='s';

    while(com=='s')
    {
        agregarFinal(pLista, crearNodo(cargarPersona()));
        printf("\nDesea cargar otra persona? [s/n]: ");
        fflush(stdin);
        scanf("%c", &com);
    }
}

///Recursivo

///MOSTRAR LISTA INVERTIDA RECURSIVO
////////////////////////////////////////////////////////

void mostrarListaInvertidaRecursivo(nodo *lista)
{
    if(lista!=NULL)
    {
        mostrarListaInvertidaRecursivo(lista->siguiente);
        mostrarNodo(lista);
    }
}


///SUMAR LISTA RECURSIVO
////////////////////////////////////////////////////////

int sumarListaRecursivo(nodo *lista)
{
    int suma;

    if(lista==NULL)
    {
        suma=0;
    }
    else
    {
        suma=lista->dato.edad+sumarListaRecursivo(lista->siguiente);
    }

    return suma;
}

///MOSTRAR POSICION PAR RECURSIVO
////////////////////////////////////////////////////////

void MostrarPosParRecursivo(nodo * lista)
{
    if(lista!=NULL)
    {
        lista= lista->siguiente;

        if(lista!=NULL)
        {
            mostrarNodo(lista);
            MostrarPosParRecursivo(lista->siguiente);
        }
    }
}


///MOSTRAR POSICION PAR RECURSIVO PEDORRO
void otroMuestraPosParRecursivo(nodo *lista, int pos)
{
    if(lista!=NULL)
    {
        if(pos%2==0)
        {
            mostrarNodo(lista);
        }
       otroMuestraPosParRecursivo(lista->siguiente, pos+1);
    }
}


///INVERTIR UNA LISTA RECURSIVO
////////////////////////////////////////////////////////

nodo * invertirListaRecursivo (nodo * lista)
{
    nodo * primero=NULL;

    if(lista!=NULL)
    {
        primero=lista;  // guardo el primero nodo

        lista=lista->siguiente;   // avanzo en la lista

        primero->siguiente=NULL;  // desvinculo el primero nodo

        lista=agregarFinalpSimple(invertirListaRecursivo(lista),primero);
    }

    return lista;
}

///BORRAR NODO RECURSIVO
////////////////////////////////////////////////////////

nodo *borrarNodoRecursivo(nodo *lista, char nombre[])
{
    nodo *aBorrar=NULL;

    if(lista!=NULL)
    {
        if(strcmp(lista->dato.nombre, nombre)==0)
        {
            aBorrar=lista;
            lista=lista->siguiente;
            free(aBorrar);
        }
        else
        {
            lista->siguiente=borrarNodoRecursivo(lista->siguiente, nombre);
        }
    }

    return lista;
}

///INSERTAR NODO EN ORDEN RECURSIVO
////////////////////////////////////////////////////////

nodo* insertarEnOrdenRecursivo(nodo *lista, nodo *nuevo)
{
    if(lista == NULL)
    {
        lista=nuevo;
    }
    else
    {
        if(nuevo->dato.edad < lista->dato.edad)
        {
            nuevo->siguiente = lista;
            lista = nuevo;
        }
        else
        {
            lista->siguiente = insertarEnOrdenRecursivo(lista->siguiente, nuevo);
        }
    }

    return lista;
}
