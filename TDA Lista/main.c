#include "libreria.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

void subprogramaBusqeudaDeUnNodo(nodo *lista);

////////////////////////////////////////////////////////

int main()
{
    nodo *lista = inicLista();

    //lista=agregarNodosPpio(lista);

    lista=agregarNodosFinal(lista);

    recorrerYmostrar(lista);

    subprogramaBusqeudaDeUnNodo(lista);

    return 0;
}

void subprogramaBusqeudaDeUnNodo(nodo *lista)
{
    char nombre[20];
    nodo *nodobuscado;

    printf("Ingrese nombre a buscar: ");
    fflush(stdin);
    gets(nombre);

    nodobuscado=buscarNodo(lista, nombre);

    if(nodobuscado != NULL)
    {
        mostrarNodo(nodobuscado);
    }
    else
    {
        printf("No se ha encontrado a la persona.");
    }
}


