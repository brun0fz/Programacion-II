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
void MostrarPosParRecursivo(nodo *lista, int pos);
void otroMuestraPosParRecursivo(nodo * lista);
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

int sumarListaRecursivo2(nodo *lista)
{
    int suma=0;

    return (lista!=NULL) ? lista->dato.edad+sumarListaRecursivo(lista->siguiente) : suma;
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
            mostrarNodo(lista);
            otroMuestraPosParRecursivo(lista->siguiente);
        }
    }
}

//4. Invertir una lista cambiando los vínculos.

nodo * invertirListaRecursivo (nodo * lista)
{
    /*
        si esta vacia, retorno NULL
        si tiene un solo nodo, retorna lista
        si tiene mas de un nodo, tomo el 1er nodo, invierto lo que sigue y
        lo agrego al final de la lista invertida

        nos vamos a ayudar con la funcion agregar al final

        primero tengo que desvicular al nodo de la lista
        OJO no perder las referencias...
    */

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

//5. Borrar un nodo de una lista.

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

//6. Insertar un nodo en una lista en forma recursiva (manteniendo el orden de forma creciente).

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
