#include "TDAFila.h"

///Estructura FILA
typedef struct
{
    nodoDoble* inicio;
    nodoDoble* Fin;
} Fila;

///INICIALIZAR FILA
void inicFila(Fila* pFila) ///Se inicializan las dos listas
{
    inicListaDoble(&pFila->inicio);
    inicListaDoble(&pFila->Fin);
}

///MOSTRAR FILA
void mostrar(Fila* pFila)
{
    printf("INICIO <-- ");
    mostrarListaDoble(pFila->inicio);
    printf("FIN\n");
}

///AGREGAR DATO EN LA FILA
void agregar(Fila* pFila, int dato)
{
    nodoDoble *nuevo=crearNodoDoble(dato);

    agregarFinalDoble(&pFila->Fin, nuevo); ///agregamos el nuevo dato por el fin de la lista

    if(pFila->inicio==NULL) ///si el inicio es igual a NULL, nuestro nuevo dato tambien es el inicio
    {
        pFila->inicio=pFila->Fin;
    }

    pFila->Fin=nuevo; ///Se tiene que actualizar el final de la lista, ahora apunta al nuevo nodo.
}

///EXTRAER DATO DE LA FILA
int extraer(Fila* pFila)
{
    int dato;

    if(pFila->inicio!=NULL) ///Si hay un dato para extraer
    {
        dato=PrimerNodoDoble(pFila->inicio); ///extraemos el dato crudo para poder retornarlo

        borrarPrimerNodoDoble(&pFila->inicio); ///borramos el nodo

        if(pFila->inicio==NULL) ///Si el nodo que borre era el unico de la lista, hay que inicializar el fin
        {
            inicListaDoble(&pFila->Fin); ///inicializamos el final
        }
    }

    return dato;
}

///LEER UN DATO EN LA FILA
void leer(Fila* pFila)
{
    int dato;

    printf("Ingrese un dato: ");
    scanf("%d", &dato);
    agregar(pFila, dato);
}

///RETORNAR EL PRIMER NODO DE LA FILA
int primero(Fila* pFila)
{
    return PrimerNodoDoble(pFila->inicio); ///retornamos el primer nodo 
}

///SABER SI LA FILA ESTA VACIA
int filaVacia(Fila* pFila)
{
    int flag=1;

    if(pFila->inicio!=NULL) ///Si por inicio no tiene datos, es porque esta vacia.
    {
        flag=0;
    }
    return flag;
}
