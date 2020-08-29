#include <stdio.h>
#include <stdlib.h>

long int fibonacciIterativo(int Pos);
void mostrarFibonacciIterativo();

long int fibonacciRecursivo(int Pos);
void mostrarFibonacciRecursivo();

int main()
{
    int Rta;

    //printf("FUNCION ITERATIVA\n\n");

    //Rta=fibonacciIterativo(46);
    //printf("[%d]\n", Rta);

    printf("FUNCION RECURSIVA\n\n");

    Rta=fibonacciRecursivo(10);
    printf("[%d]\n", Rta);

    //mostrarFibonacciIterativo();

    //mostrarFibonacciRecursivo();

    return 0;
}

///Funcion iterativa 1.a
long int fibonacciIterativo(int T)
{
    long int A=0, B=1, N;

    if(T==1)
    {
        N=0;
    }
    else if(T==2)
    {
        N=1;
    }
    else
    {
        for (int i=3; i<=T; i++)
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

    printf("FUNCION ITERATIVA\n\n");

    printf("Ingrese una termino: ");
    scanf("%d", &T);

    for(int i=1; i<=T; i++)
    {
        printf("[%ld]",fibonacciIterativo(i));
    }
}

///////////////////////////////////////////////////////////

///Funcion recursiva 1.a
long int fibonacciRecursivo(int T)
{
    return (T == 1 || T == 2) ? T-1 : fibonacciRecursivo(T-2) + fibonacciRecursivo(T-1);
}

///Funcion recursiva 1.b
void mostrarFibonacciRecursivo()
{
    int T=0;

    printf("FUNCION RECURSIVA\n\n");

    printf("Ingrese un termino: ");
    scanf("%d", &T);

    for (int i=1 ; i<=T; i++)
    {
        printf("[%ld]",fibonacciRecursivo(i));
    }
}
