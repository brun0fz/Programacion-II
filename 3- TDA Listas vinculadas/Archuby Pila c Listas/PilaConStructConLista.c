#include "PilaConStructConLista.h"


void inicPila (Pila* pila)
{
    pila->lista = inicLista();
}



int desapilar (Pila* pila)
{
    int rta= -1;
    if( (pila->lista) != NULL )
    {
        rta = retornarPrimerDato(pila->lista);
        pila->lista = borrarPrimerNodo(pila->lista);
    }
    else
    {
        printf("\n La pila está vacía, se retornará -1\n");
    }
    return rta;
}


void apilar (Pila* pila, int dato)
{
    nodo* aux = crearNodo(dato);
    pila->lista = agregarPpio(pila->lista, aux);
}


void leer (Pila* pila)
{
    int dato;
    printf("\nIngrese un numero:  ");
    scanf("%d", &dato);

    apilar(pila, dato);
}


void mostrar(Pila* pila)
{
    // mostramos 1ro el tope y luego la base, al reves,
    // pq en la lista agregamos al ppio en vez de al final como en la pila
    printf("\nTope                                          Base\n\n");
    recorrerYmostrar(pila->lista);
    printf("\n\nTope                                          Base\n");
}


int pilavacia (Pila* pila)
{
    int rta=0;
    if ( (pila->lista) == NULL )
    {
        rta = 1;
    }
    return rta;  //PODRIA DECIR DIRECTAMENTE solo return (pila->lista)==NULL (es como si preguntara: "if (pilavacia)...
}


int tope (Pila* pila)
{
    int rta= -1;
    if ((pila->lista) != NULL)
    {
        rta = retornarPrimerDato(pila->lista); //mostramos el 1ro en vez del ultimo porque en la lista agregamos al ppio
    }                                          // entonces el 1° de la lista fue el ult en entrar y es el tope
    else
    {
        printf("\n La pila está vacía, se retornará -1\n");
    }
    return rta;
}

