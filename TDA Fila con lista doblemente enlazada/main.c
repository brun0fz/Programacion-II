#include <stdio.h>
#include <stdlib.h>

#include "TDAFila.h"

int main()
{
    Fila filita;
    inicFila(&filita);

    agregar(&filita, 1);
    agregar(&filita, 2);

    leer(&filita);

    mostrar(&filita);

    if(!filaVacia(&filita))
    {
       printf("\nEXTRAJO: %d\n\n", extraer(&filita));
    }


    mostrar(&filita);

    printf("\nPRIMERO: %d\n", primero(&filita));




    return 0;
}
