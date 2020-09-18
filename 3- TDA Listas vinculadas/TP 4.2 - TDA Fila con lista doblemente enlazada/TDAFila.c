#include "TDAFila.h"

void inicFila(Fila* pFila)
{
    inicListaDoble(&pFila->inicio);
    inicListaDoble(&pFila->Fin);
}

void mostrar(Fila* pFila)
{
    printf("INICIO <-- ");
    mostrarListaDoble(pFila->inicio);
    printf("FIN\n");
}

void agregar(Fila* pFila, int dato)
{
    nodoDoble *nuevo=crearNodoDoble(dato);

    agregarFinalDoble(&pFila->Fin, nuevo);

    if(pFila->inicio==NULL)
    {
        pFila->inicio=pFila->Fin;
    }

    pFila->Fin=nuevo;
}

int extraer(Fila* pFila)
{
    int dato;

    if(pFila->inicio!=NULL)
    {
        dato=PrimerNodoDoble(pFila->inicio);

        borrarPrimerNodoDoble(&pFila->inicio);

        if(pFila->inicio==NULL)
        {
            inicListaDoble(&pFila->Fin);
        }
    }

    return dato;
}

void leer(Fila* pFila)
{
    int dato;

    printf("Ingrese un dato: ");
    scanf("%d", &dato);
    agregar(pFila, dato);
}

int primero(Fila* pFila)
{
    return PrimerNodoDoble(pFila->inicio);
}

int filaVacia(Fila* pFila)
{
    int flag=1;

    if(pFila->inicio!=NULL)
    {
        flag=0;
    }
    return flag;
}
