#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int valores[100];
    int posTope; //posición de nuevo tope, lugar en donde se almacenará el nuevo valor
} Pila;

void apilar(Pila * p, int valor);
int desapilar(Pila * p);
int tope(Pila * p);
int pilavacia(Pila * p);
void mostrar(Pila * p);
void leer (Pila * p);
void inicPila(Pila * p);

int main()
{
    return 0;
}

void apilar(Pila * p, int valor)
{
    if(p->posTope<100)
    {
        p->valores[p->posTope]=valor;
        p->posTope++;
    }
    else
    {
        printf("\nERROR: La pila esta llena.");
    }
}

int desapilar(Pila * p)
{
    int aux;
    aux=p->valores[p->posTope-1];
    p->posTope--;

    return aux;
}

int tope(Pila * p)
{
    return p->valores[p->posTope-1];
}

int pilavacia(Pila * p)
{
    int flag=0;

    if(p->posTope==0)
    {
        flag=1;
    }
    return flag;
}

void mostrar(Pila * p)
{
    printf("|BASE---------------------TOPE|\n\n");
    for(int i=0; i< p->posTope; i++)
    {
        printf("|%d", p->valores[i]);
    }
    printf("\n\n|BASE---------------------TOPE|\n\n");
}

void leer(Pila * p)
{
    int dato;
    printf("\nIngrese un valor entero: ");
    scanf("%d", &dato);
    apilar(p, dato);
}

void inicPila(Pila * p)
{
    p->posTope=0;
}
