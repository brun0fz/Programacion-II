#include "Pila.h"


///     void inicPila (nodo ** lista)
///     {
///         (*lista)= inicLista();
///     }

///     SE TRANSFORMA EN...


void inicPila (Pila* pila) // Pila*pila en realidad es nodo** pila
{                           // se trabaja con punt doble porque todas las funciones reciben &dada
    (*pila) = inicLista();   // *pila porq pila es punt doble (a donde apunta el punt doble)
}



int desapilar (Pila* pila)
{
    int rta=-1;
    if( (*pila) != NULL )
    {
        rta = retornarPrimerDato(*pila);
        *pila = borrarPrimerNodo(*pila);
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
    *pila = agregarPpio(*pila,aux);
}


void leer (Pila* pila)
{
    int dato;
    nodo* nuevoNodo;
    printf("\nIngrese un numero:  ");
    scanf("%d", &dato);
    apilar(pila, dato);
}


void mostrar(Pila* pila)
{
    // mostramos 1ro el tope y luego la base, al reves,
    // pq en la lista agregamos al ppio en vez de al final como en la pila
    printf("\nTope                                          Base\n\n");
    recorrerYmostrar(*pila);
    printf("\n\nTope                                          Base\n");
}


int pilavacia (Pila* pila)
{
    int rta=0;
    if ( (*pila) == NULL )
    {
        rta = 1;
    }
    return rta;  //PODRIA DECIR DIRECTAMENTE solo return (*pila)==NULL (es como si preguntara: "if (pilavacia)...
}


int tope (Pila* pila)
{
    int rta=-1;
    if ((*pila) != NULL)
    {
        rta = retornarPrimerDato(*pila); //mostramos el 1ro en vez del ultimo porque en la lista agregamos
    }
    else
    {
        printf("\n La pila está vacía, se retornará -1\n");
    }                        // al ppio, entonces el tope es el 1ro en vez del ultimo
    return rta;
}

