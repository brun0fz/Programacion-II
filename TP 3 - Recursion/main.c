#include <stdio.h>
#include <stdlib.h>

int factorial (int x);
int potencia(int b, int e);
void mostrarArreglo(int A[], int cantidad, int i);
void mostrarArregloInvertido(int A[], int cantidad, int i);
int sumarArreglo(int A[], int validos, int i);
int sumarArregloAlt(int A[], int validos, int i);
int buscarMenorArray(int A[], int validos, int i);




int main()
{
    /*FILE *buffer = fopen("arInt.dat", "ab");
    int x=6;
    fwrite(&x, sizeof(int), 1,buffer);
    fclose(buffer);*/

    printf("%d", buscarMenorAr("arInt.dat", 0));


    return 0;
}

int factorial (int x)
{
    int rta;

    if(x==0)
    {
        rta=1;
    }
    else
    {
        rta=x*factorial(x-1);
    }

    return rta;
}

int potencia(int b, int e)
{
    int rta;

    if(e==0)
    {
        rta=1;
    }
    else
    {
        rta=b * potencia(b, e-1);
    }

    return rta;
}

/*void mostrarArreglo(int A[], int cantidad, int i) ///Se rompe si el arreglo esta vacio.
{
    if(i == cantidad-1)
    {
        printf("[%d]=%d\n", i, A[i]);
    }
    else
    {
        printf("[%d]=%d\n", i, A[i]);
        mostrarArreglo(A, cantidad, i+1);
    }
}*/

void mostrarArreglo(int A[], int cantidad, int i) ///No se rompe si el arreglo esta vacio.
{
    if(i<cantidad)
    {
        printf("[%d]=%d\n", i, A[i]);
        mostrarArreglo(A, cantidad, i+1);
    }
}

void mostrarArregloInvertido(int A[], int cantidad, int i)
{
    if(i<cantidad)
    {
        mostrarArreglo(A, cantidad, i+1);
        printf("[%d]=%d\n", i, A[i]);
    }
}

/*int arregloCapicua(int A[], int validos, int i)
{
    int flag;

    if(A[i]!=A[validos-1])
    {
        flag=0
    }
    else
    {
        arregloCapicua(A, validos, i+1);

    }
}*/

int sumarArreglo(int A[], int validos, int i)
{
    int rta;

    if(i == validos) //Condicion de corte
    {
        rta=0; //Solucion trivial
    }
    else
    {
        rta=A[i];
        rta+=sumarArreglo(A, validos, i+1);
    }

    return rta;
}

int sumarArregloAlt(int A[], int validos, int i)
{
    int rta=0;

    if(i<validos)
    {
        rta=A[i]+sumarArreglo(A, validos, i+1);
    }

    return rta;
}

int buscarMenorArray(int A[], int validos, int i)
{
    int menor;

    if(i == validos-1)
    {
        menor=A[i];
    }
    else
    {
        menor=buscarMenorArray(A, validos, i+1);
        if(A[i]<menor)
        {
            menor=A[i];
        }
    }
    return menor;
}

int buscarMenorAr(char filename[], int pos)
{
    int aux;
    int menor;

    FILE *buffer = fopen(filename, "rb");

    if(buffer)
    {
        if(fread(&aux,sizeof(int),1,buffer)==1)
        {
            menor=aux;
        }
        else
        {
            fseek(buffer,sizeof(int)*pos, SEEK_SET);
            fread(&aux,sizeof(int),1,buffer);
            menor=buscarMenorAr(filename, pos+1);

            if(aux<menor)
            {
                menor=aux;
            }
        }

        fclose(buffer);
    }

    return menor;
}

int buscarArray(int A[], int validos, int i, int dato)
{
    int flag=0;

    if(i<validos)
    {
        if(A[i]==dato)
        {
            flag=1;
        }
        else
        {
            flag=buscarArray(A,validos,i+1,dato);
        }

    }
    return flag;
}
