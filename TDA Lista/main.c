#include "libreria.h"
#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////

int main()
{
    nodo *lista = inicLista();

    lista=agregarNodosPpio(lista);

    recorrerYmostrar(lista);

    return 0;
}

