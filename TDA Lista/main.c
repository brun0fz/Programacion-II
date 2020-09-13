#include "listaEnlazada.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

////////////////////////////////////////////////////////

nodo *SubProgramaagregarNodosPpio(nodo *lista);
nodo *SubProgramaagregarNodosFinal(nodo *lista);
void subprogramaBusqeudaDeUnNodo(nodo *lista);
nodo *SubProgramaborrarNodo(nodo *lista, char nombre[]);

////////////////////////////////////////////////////////

int main()
{
    //nodo *lista = inicLista();

    return 0;
}

////////////////////////////////////////////////////////

nodo *SubProgramaagregarNodosPpio(nodo *lista)
{
    char com='s';

    while(com=='s')
    {
        lista=agregarPpio(lista, crearNodo(cargarPersona()));
        fflush(stdin);
        printf("\nDesea cargar otra perona? [s/n]: ");
        scanf("%c", &com);
    }
    return lista;
}

////////////////////////////////////////////////////////

nodo *SubProgramaagregarNodosFinal(nodo *lista)
{
    char com='s';

    while(com=='s')
    {
        lista=agregarFinal(lista, crearNodo(cargarPersona()));
        fflush(stdin);
        printf("\nDesea cargar otra perona? [s/n]: ");
        scanf("%c", &com);
    }
    return lista;
}

////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////

nodo *SubProgramaborrarNodo(nodo *lista, char nombre[])
{
    nodo *seg;
    nodo *ante;

    if((lista != NULL) && (strcmp(nombre, lista->dato.nombre)==0))
    {
        nodo *aux=lista;
        lista=lista->siguiente;
        free(aux);
    }
    else
    {
        seg=lista;
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
    return lista;
}

////////////////////////////////////////////////////////


