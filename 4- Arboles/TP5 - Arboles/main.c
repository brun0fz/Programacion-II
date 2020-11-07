#include <stdio.h>
#include <stdlib.h>

#include "listaEnlazada.h"
#include "arboles.h"

void cargarArbolBinario(nodoArbol **arbol);

int main()
{
    nodoArbol *arbolito;
    inicArbol(&arbolito);

    nodo *listita;
    inicLista(&listita);

    cargarArbolBinario(&arbolito);

    printf("ARBOL\n");

    preorder(arbolito);

    printf("nodos%d\n\n",contarNodos(arbolito));
    printf("mayores%d",contarNodosFiltrado(arbolito));

    /*
    listita=arbolToLista(arbolito, listita);

    printf("LISTA\n");

    mostrarLista(&listita);*/

    return 0;
}

void cargarArbolBinario(nodoArbol **arbol)
{
    char com='s';

    while(com =='s')
    {
        printf("Ingrese los datos de la persona\n");

        *arbol=insertarArbolOrdenado(*arbol, cargarPersona());

        printf("\nDesea cargar otra persona? [s/n]: ");
        fflush(stdin);
        scanf("%c", &com);
    }
}
