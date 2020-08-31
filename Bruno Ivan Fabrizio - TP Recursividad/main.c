#include <stdio.h>
#include <stdlib.h>

long int fibonacciIterativo(int Pos);
void mostrarFibonacciIterativo();

long int fibonacciRecursivo(int Pos);
void mostrarFibonacciRecursivo();

int main()
{
    int T;

    printf("FUNCION ITERATIVA\n\n");

    printf("Ingrese un termino: ");
    scanf("%d", &T);

    T=fibonacciIterativo(T);
    printf("[%d]\n", T);

    printf("\nFUNCION RECURSIVA\n\n");

    printf("Ingrese un termino: ");
    scanf("%d", &T);

    T=fibonacciRecursivo(T);
    printf("[%d]\n", T);

    mostrarFibonacciIterativo();

    mostrarFibonacciRecursivo();

    return 0;
}

///Funcion iterativa 1.a
long int fibonacciIterativo(int T)
{
    long int A=0, B=1, N;

    if(T<=1)
    {
        N=T;
    }
    else
    {
        for (int i=2; i<=T; i++)
        {
            N = A + B;
            A = B;
            B = N;
        }
    }

    return N;
}

///Funcion iterativa 1.b
void mostrarFibonacciIterativo()
{
    int T=0;

    printf("\n\nFUNCION ITERATIVA\n\n");

    printf("Ingrese un termino: ");
    scanf("%d", &T);

    for(int i=0; i<=T; i++)
    {
        printf("[%ld]",fibonacciIterativo(i));
    }
}

///////////////////////////////////////////////////////////

///Funcion recursiva 1.a
long int fibonacciRecursivo(int T)
{
    return (T == 0 || T == 1) ? T : fibonacciRecursivo(T-1) + fibonacciRecursivo(T-2);
}

///Funcion recursiva 1.b
void mostrarFibonacciRecursivo()
{
    int T=0;

    printf("\n\nFUNCION RECURSIVA\n\n");

    printf("Ingrese un termino: ");
    scanf("%d", &T);

    for (int i=0 ; i<=T; i++)
    {
        printf("[%ld]",fibonacciRecursivo(i));
    }
}
