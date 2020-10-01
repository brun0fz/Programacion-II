#include <stdio.h>
#include <stdlib.h>

int factorial (int x);
int potencia(int b, int e);

void mostrarArreglo(int A[], int cantidad, int i);
void mostrarArregloInvertido(int A[], int cantidad, int i);
int arregloCapicua(int A[], int i, int u);
int sumarArreglo(int A[], int validos, int i);
int sumarArregloAlt(int A[], int validos, int i);
int buscarMenorArray(int A[], int validos, int i);
int buscarArray(int A[], int validos, int i, int dato);

int arAbrirBuscarMenor(char archivo[]);
int arBuscarMenor(FILE *Buffer);
void cargarArchivo(char archivo[]);
void arAbrirMostrar(char archivo[]);
void arMostrar(FILE *Buffer);
int arCuentaRegistro(FILE *Buffer);
void arAbrirInvertir(char archivo[], int i, int u);
void arInvertir(FILE *Buffer, int i, int u);



int main()
{
    return 0;
}

///EJ 01 FACTORIAL
/////////////////////////////////////////////////////////////////////

int factorial (int x)
{
    int rta;

    if(x==0) ///CONDICION DE CORTE
    {
        rta=1; ///SOLUCION TRIVIAL O CASO BASE
    }
    else
    {
        rta=x*factorial(x-1); ///LLAMADA RECURSIVA ||| ACERCAMIENTO A LA CONDICION DE CORTE
        ///EXPRESION DE LA SOLUCION TOTAL
    }

    return rta;
}

///EJ 02 POTENCIA
/////////////////////////////////////////////////////////////////////

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

///EJ 03 MOSTRAR ARREGLO RECURSIVO
/////////////////////////////////////////////////////////////////////

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

///EJ 04 MOSTRAR ARREGLO RECURSIVO INVERTIDO
/////////////////////////////////////////////////////////////////////

void mostrarArregloInvertido(int A[], int cantidad, int i)
{
    if(i<cantidad) ///VERIFICAMOS QUE NO NOS HAYAMOS CAIDO DEL ARREGLO
    {
        mostrarArreglo(A, cantidad, i+1);
        printf("[%d]=%d\n", i, A[i]);
    }
}

///EJ 05 ARREGLO CAPICUA RECRUSIVO
/////////////////////////////////////////////////////////////////////

int arregloCapicua(int A[], int i, int u)
{
    int flag=1;

    if(i<u) ///VERIFICAMOS SI NO NOS CRUZAMOS EN EL ARREGLO
    {
        if(A[i]!=A[u])
        {
            flag=0;
        }
        else
        {
            flag=arregloCapicua(A, i+1, u-1);

        }
    }

    return flag;
}

///EJ 06 SUMAR ARREGLO RECURSIVO
/////////////////////////////////////////////////////////////////////

int sumarArreglo(int A[], int validos, int i)
{
    int rta;

    if(i == validos) ///SI I ES IGUAL A VALIDOS QUIERE DECIR QUE NOS CAIMOS DEL ARREGLO, ENTONCES LA SUMA ES 0
    {
        rta=0; //Solucion trivial
    }
    else
    {
        rta=A[i]+sumarArreglo(A, validos, i+1);
    }

    return rta;
}

int sumarArregloAlt(int A[], int validos, int i)
{
    int rta=0;

    if(i<validos) ///I MENOR QUE VALIDOS SIGNIFICA QUE TRABAJO MIENTRAS HAY ARREGLO
    {
        rta=A[i]+sumarArreglo(A, validos, i+1);
    }

    return rta;
}

///EJ 07 BUSCAR MENOR ARREGLO
/////////////////////////////////////////////////////////////////////

int buscarMenorArray(int A[], int validos, int i)
{
    int menor;

    if(i == validos-1) /// I == VALIDOS -1 SIGNIFICA QUE VA A PASAR ALGO SI ESTOY EN LA ULTIMA POSICION
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

///EJ 12 BUSCAR EN ARREGLO
/////////////////////////////////////////////////////////////////////

int buscarArray(int A[], int cantidad, int i, int dato)
{
    int flag=0;

    if(i<cantidad)
    {
        if(A[i]==dato)
        {
            flag=1;
        }
        else
        {
            flag=buscarArray(A,cantidad,i+1,dato);
        }

    }
    return flag;
}

///Cargar Archivo
/////////////////////////////////////////////////////////////////////

void cargarArchivo(char archivo[])
{
    char com='s';
    int num=0;

    FILE *Buffer = fopen(archivo, "ab");

    if(Buffer)
    {
        while(com =='s')
        {
            printf("\nIngrese un numero: ");
            scanf("%d", &num);

            fwrite(&num, sizeof(int), 1, Buffer);

            printf("Desea cargar otro numero? [s/n]: ");
            fflush(stdin);
            scanf("%c", &com);
        }
        fclose(Buffer);
    }
}

///EJ 08 BUSCAR MENOR EN UN ARCHIVO
/////////////////////////////////////////////////////////////////////

int arAbrirBuscarMenor(char archivo[])
{
    int menor;

    FILE *Buffer = fopen(archivo, "rb");

    if(Buffer)
    {
        menor = arBuscarMenor(Buffer);

        fclose(Buffer);
    }
    else
    {
        printf("\nError al abrir el archivo.\n");
    }

    return menor;
}


int arBuscarMenor(FILE *Buffer)
{
    int dato;
    int menor;

    if(fread(&dato, sizeof(int),1,Buffer)==0)
    {
        fseek(Buffer, -1*sizeof(int), SEEK_END);
        fread(&menor, sizeof(int), 1, Buffer);
    }
    else
    {
        menor=arBuscarMenor(Buffer);
        if(dato<menor)
        {
            menor=dato;
        }
    }
    return menor;
}

///EJ 09 INVERTIR ARCHIVO
/////////////////////////////////////////////////////////////////////

int arCuentaRegistro(FILE *Buffer)
{
    int cant=0;

    fseek(Buffer, 0, SEEK_END);
    cant=ftell(Buffer)/sizeof(int);

    return cant;
}


void arAbrirInvertir(char archivo[], int i, int u)
{
    FILE *Buffer = fopen(archivo, "ab");

    if(Buffer)
    {
        u=arCuentaRegistro(Buffer);
        arInvertir(Buffer, i,u);

        fclose(Buffer);
    }
    else
    {
        printf("\nError al abrir el archivo.\n");
    }
}

void arInvertir(FILE *Buffer, int i, int u)
{
    int num;
    int num2;

    if(i<u)
    {
        fseek(Buffer,i*sizeof(int),SEEK_SET);
        fread(&num, sizeof(int), 1, Buffer);

        fseek(Buffer,u*sizeof(int),SEEK_SET);
        fread(&num2, sizeof(int), 1, Buffer);

        fseek(Buffer, i*sizeof(int),SEEK_SET);
        fwrite(&num2, sizeof(int), 1, Buffer);

        fseek(Buffer, u*sizeof(int),SEEK_SET);
        fwrite(&num, sizeof(int), 1, Buffer);

        arInvertir(Buffer, i+1,u-1);
    }
}

///EJ 10 MOSTRAR ARCHIVO INVERTIDO
/////////////////////////////////////////////////////////////////////

void arAbrirMostrar(char archivo[])
{
    FILE *Buffer = fopen(archivo, "rb");

    if(Buffer)
    {
        arMostrar(Buffer);

        fclose(Buffer);
    }
    else
    {
        printf("\nError al abrir el archivo.\n");
    }
}

void arMostrar(FILE *Buffer)
{
    int dato;

    if(fread(&dato, sizeof(int),1,Buffer) > 0)
    {
        arMostrar(Buffer);
        printf("[%d]", dato);
    }
}

///EJ 11 MOSTRAR CHARS INVERTIDOS INGRESADOS POR TECLADO
/////////////////////////////////////////////////////////////////////

void mostrarCharInvertido(char dato)
{
    printf("Ingrese un caracter (* para finalizar): ");
    fflush(stdin);
    scanf("%c", &dato);

    if(dato!='*')
    {
        mostrarCharInvertido(dato);
        printf("[%c]\n", dato);
    }
}
