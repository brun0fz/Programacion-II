#include "TDAPila.h"


void inicPila(nodo **pila)
{
    lInicLista(pila);
}

int pilavacia(nodo** pila)
{
    int flag=1;

    if(*pila)
    {
        flag=0;
    }

    return flag;
}

int tope(nodo** pila)
{
    int tope;

    if(*pila)
    {
        tope=(*pila)->dato;
    }
    return tope;
}

int desapilar(nodo** pila)
{
    return lDesvincularPrimero(pila);
}

void apilar(nodo** pila, int dato)
{
    lAgregarPpio(pila, lCrearNodo(dato));
}

void leer(nodo** pila)
{
    int dato;

    printf("Ingrese un dato: ");
    scanf("%d", &dato);

    apilar(pila, dato);
}

void mostrar(nodo **pila)
{
    printf("\nTope\n");
    lMostrarLista(pila);
    printf("Base\n");
}

