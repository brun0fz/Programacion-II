#include <stdio.h>
#include <stdlib.h>
// #include "Pila.h"
#include "PilaConStructConLista.h"

int main ()
{
    Pila pilita; /// Pila equivale a nodo* lista
    inicPila(&pilita);
    apilar(&pilita, 10);
    apilar(&pilita, 20);
    apilar(&pilita, 30);
    printf("Apile por sistema un 10, un 20 y un 30 en Pilita y ahora pido al user que cargue 3 nros mas\n");
    leer(&pilita);
    leer(&pilita);
    leer(&pilita);
    printf("\n Muestro Pilita\n");
    if(pilavacia(&pilita))
        printf("La pila esta vacia");
    else
    {
        mostrar(&pilita);
        printf("\nEl tope de Pilita es %d", tope(&pilita));
    }

    Pila pilota;
    inicPila(&pilota);

    printf("\n Paso lo de Pilita a Pilota\n");
    while(!pilavacia(&pilita))
    {
        apilar(&pilota, desapilar(&pilita));
    }
    printf(
           "\n Muestro Pilota\n");

    mostrar(&pilota);

    printf("\n Muestro Pilita\n");
    if(pilavacia(&pilita))
        printf("La pila esta vacia");
    else
    {
        mostrar(&pilita);
        printf("\nEl tope es %d", tope(&pilita));
    }

    return 0;
}
