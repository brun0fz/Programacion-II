#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <conio.h>

#include "listaEnlazada.h"

////////////////////////////////////////////////////////

void SubProgramaAgregarNodosPpio(nodo **lista);
void mostrarListaInvertidaRecursivo(nodo *pLista);
int sumarListaRecursivo(nodo *lista);
void MostrarPosParRecursivo(nodo *lista, int pos);
void otroMuestraPosParRecursivo(nodo * lista);

////////////////////////////////////////////////////////

int main()
{
    nodo *listita;
    inicLista(&listita);

    SubProgramaAgregarNodosPpio(&listita);

    //mostrarListaInvertidaRecursivo(listita);

    //printf("La suma es: %d",sumarListaRecursivo(listita));


    MostrarPosParRecursivo(listita, 1);

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


///Recursivo

//1. Recorrer una lista y mostrarla en forma invertida.

void mostrarListaInvertidaRecursivo(nodo *lista)
{
    if(lista!=NULL)
    {
        mostrarListaInvertidaRecursivo(lista->siguiente);
        mostrarNodo(lista);
    }
}

//2. Sumar los elementos de una lista.

int sumarListaRecursivo(nodo *lista)
{
    int suma=0;

    if(lista!=NULL)
    {
        suma=lista->dato.edad+sumarListaRecursivo(lista->siguiente);
    }

    return suma;
}

//3. Mostrar los elementos de una lista ubicados en una posición par.

void MostrarPosParRecursivo(nodo *lista, int pos)
{
    if(lista!=NULL)
    {
        if(pos%2==0)
        {
            mostrarNodo(lista);
        }
        MostrarPosParRecursivo(lista->siguiente, pos+1);
    }
}

void otroMuestraPosParRecursivo(nodo * lista)
{
    if(lista!=NULL)
    {
        lista= lista->siguiente;
        // avanzo por cada etapa 2 nodos... si existe el segundo (seria la posicion par)
        // lo muestro...
        // y llamo a la recursividad
        if(lista!=NULL)
        {
            mostrar(lista);
            otroMuestraPosPar(lista->siguiente);
        }
    }
}

//4. Invertir una lista cambiando los vínculos.





