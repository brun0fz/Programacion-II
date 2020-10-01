#include "TDAPila.h"

///INICIALIZAR PILA
/////////////////////////////////////////////////////
void inicPila(nodo **pila)
{
    lInicLista(pila);
}


///PILA VACIA
/////////////////////////////////////////////////////
int pilavacia(nodo** pila)
{
    int flag=1;

    if(*pila!=NULL)
    {
        flag=0;
    }

    return flag;
}


///TOPE DE LA PILA
/////////////////////////////////////////////////////
int tope(nodo** pila)
{
    int tope;

    if(*pila)
    {
        tope=(*pila)->dato;
    }

    return tope;
}


///DESAPILAR
/////////////////////////////////////////////////////
int desapilar(nodo** pila)
{
    return lDesvincularPrimero(pila);
}


///APILAR
/////////////////////////////////////////////////////
void apilar(nodo** pila, int dato)
{
    lAgregarPpio(pila, lCrearNodo(dato));
}


///LEER
/////////////////////////////////////////////////////
void leer(nodo** pila)
{
    int dato;

    printf("Ingrese un dato: ");
    scanf("%d", &dato);

    apilar(pila, dato);
}


///MOSTRAR
/////////////////////////////////////////////////////
void mostrar(nodo **pila)
{
    printf("\nTope\n");
    lMostrarLista(pila);
    printf("Base\n");
}
