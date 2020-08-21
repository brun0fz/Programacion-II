#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <strings.h>

///EJ 01
//////////////////////////////////////////////////////////////

void inicArray(int array[], int dim);
int cargarArrayInt(int array[], int dim);
int sumarArray(int array[], int dim);
int contarArray(int array[], int dim);
float promedioArray(int array[], int dim);

///EJ 02
//////////////////////////////////////////////////////////////

int cargarArrayChar(char array[], int dim);
void invertirArrayChar(char array[], int validos);
void mostrarArrayChar(char array[], int validos);

///EJ 03
//////////////////////////////////////////////////////////////

int convDecimal (int array[], int validos);
void mostrarArrayInt(int array[], int validos);

///EJ 04
//////////////////////////////////////////////////////////////
int posMayor (int array[], int validos);


///EJ 05
//////////////////////////////////////////////////////////////
void cargarMatrizInt (int filas, int columnas, int matriz[filas][columnas]);
int mayorPreci (int mes, int matriz[mes][31]);
void maxMeses(int matriz[12][31], int array[]);
void MostrarMatrizInt(int filas, int columnas, int matriz[filas][columnas]);

///EJ 06
//////////////////////////////////////////////////////////////


///EJ 07
//////////////////////////////////////////////////////////////


///EJ 08
//////////////////////////////////////////////////////////////

///EJ 09
//////////////////////////////////////////////////////////////


///EJ 10
//////////////////////////////////////////////////////////////


int main()
{
    ///Variables
//////////////////////////////////////////////////////////////

    ///EJ 01
    int array[10];
    float promedio=0;

    ///EJ 02
    char arrayChar[100];

    ///EJ 05
    int matriz[12][31];
    int meses[12];

//////////////////////////////////////////////////////////////

    int opt=0;;

    do
    {
        system("cls");

        printf("Seleccione un ejercicio\n\n");

        printf("1.  Ejercicio 01\n");
        printf("2.  Ejercicio 02\n");
        printf("3.  Ejercicio 03\n");
        printf("4.  Ejercicio 04\n");
        printf("5.  Ejercicio 05\n");
        printf("6.  Ejercicio 06\n");
        printf("7.  Ejercicio 07\n");
        printf("8.  Ejercicio 08\n");
        printf("9.  Ejercicio 09\n");
        printf("10. Ejercicio 10\n\n");

        printf("0.  Salir\n");

        fflush(stdin);
        scanf("%d", &opt);

        switch(opt)
        {

        case 1:
            system("cls");

            inicArray(array, 10);

            cargarArrayInt(array, 10);

            promedio=promedioArray(array, 10);

            printf("\nEl promedio es: %f\n", promedio);

            system("pause");
            break;


        case 2:
            system("cls");

            int validos=cargarArrayChar(arrayChar, 100);
            invertirArrayChar(arrayChar, validos);
            mostrarArrayChar(arrayChar, validos);

            system("pause");
            break;

        case 3:
            system("cls");

            validos=cargarArrayInt(array, 10);
            mostrarArrayInt(array, validos);
            int decimal=convDecimal(array, validos);
            printf("\nNumero: %d\n\n", decimal);

            system("pause");
            break;

        case 4:
            system("cls");


            validos=cargarArrayInt(array, 10);
            mostrarArrayInt(array, validos);
            int posmayor=posMayor(array, validos);
            printf("\nPos mayor = %d\n\n", posmayor);

            system("pause");
            break;

        case 5:
            system("cls");

            cargarMatrizInt(12,31,matriz);
            MostrarMatrizInt(12,31,matriz);
            maxMeses(matriz,meses);
            mostrarArrayInt(meses,12);

            system("pause");
            break;

        case 6:

            break;

        case 7:
            system("cls");
            int a=1;
            int b=2;

            intercambio(&a, &b);

            printf("\na = %d b = %d\n",a,b);

            system("pause");
            break;

        case 8:

            break;

        case 9:

            break;

        case 10:

            break;
        }
    }
    while(opt!=0);

    return 0;
}

///EJ 01
//////////////////////////////////////////////////////////////

void inicArray(int array[], int dim)
{
    for (int i=0; i<dim; i++)
    {
        array[i]=-1;
    }
}

int cargarArrayInt(int array[], int dim)
{
    int i=0;
    char com='s';

    while(i<dim && com=='s')
    {
        printf("Ingrese un dato: ");
        scanf("%d", &array[i]);

        printf("Desea cargar otro dato? [s/n]: ");
        fflush(stdin);
        scanf("%c", &com);
        i++;
    }
    return i;
}

int sumarArray(int array[], int dim)
{
    int suma=0;

    for(int i=0; i<dim; i++)
    {
        if(array[i] != -1)
        {
            suma+=array[i];
        }
    }

    return suma;
}

int contarArray(int array[], int dim)
{
    int cant=0;

    for (int i=0; i<dim; i++)
    {
        if(array[i] != -1)
        {
            cant++;
        }
    }
    return cant;
}

float promedioArray(int array[], int dim)
{
    int suma = sumarArray(array, dim);
    int cant = contarArray(array, dim);

    float promedio = (float)suma / (float)cant;

    return promedio;
}

///EJ 02
//////////////////////////////////////////////////////////////

int cargarArrayChar(char array[], int dim)
{
    char com='s';
    int i=0;

    while(i < dim && com=='s')
    {
        printf("Ingrese caracter: ");
        fflush(stdin);
        scanf("%c", &array[i]);

        i++;

        printf("Desea cargar otro caracter? [s/n]: ");
        fflush(stdin);
        scanf("%c", &com);
    }

    return i;
}

void invertirArrayChar(char array[], int validos)
{
    int i=0;
    int index = validos -1;
    char aux;

    while(i < validos/2)
    {
        aux=array[index];
        array[index]=array[i];
        array[i]=aux;

        i++;
        index --;
    }
}

void mostrarArrayChar(char array[], int validos)
{
    for(int i=0; i<validos; i++)
    {
        printf("[%d]= %c\n", i, array[i]);
    }
}

///EJ 03
//////////////////////////////////////////////////////////////

int convDecimal (int array[], int validos)
{
    int decimal=0;
    int multi=1;

    for(int i=validos-1; i>=0; i--)
    {
        decimal+=array[i]*multi;
        multi=10*multi;
    }
    return decimal;
}

void mostrarArrayInt(int array[], int validos)
{
    for(int i=0; i<validos; i++)
    {
        printf("[%d]= %d\n", i, array[i]);
    }
}

///EJ 04
//////////////////////////////////////////////////////////////

int posMayor (int array[], int validos)
{
    int i=0;
    int mayor=array[i];
    int posmayor=0;

    for (i=1; i < validos; i++)
    {
        if(array[i]>mayor)
        {
            mayor=array[i];
            posmayor = i;
        }
    }

    return posmayor;
}


///EJ 05
//////////////////////////////////////////////////////////////

void cargarMatrizInt (int filas, int columnas, int matriz[filas][columnas])
{
    srand(time(NULL));

    for(int i=0; i<filas; i++)
    {
        for(int j=0; j<columnas; j++)
        {
            matriz[i][j]=rand()%90+10;
        }
    }
}

int mayorPreci (int mes, int matriz[mes][31])
{
    int j=0;
    int mayor=matriz[mes][j];

    for (j=1; j < 31; j++)
    {
        if(matriz[mes][j]>mayor)
        {
            mayor=matriz[mes][j];
        }
    }
    return mayor;
}

void maxMeses(int matriz[12][31], int array[])
{
    int mes=0;
    int i=0;

    while (mes < 12)
    {
        array[i]=mayorPreci(mes, matriz);
        mes++;
        i++;
    }
}

void MostrarMatrizInt(int filas, int columnas, int matriz[filas][columnas])
{
    printf("Elementos de la Matriz:\n\n");

    for(int i=0; i<filas; i++)
    {
        for(int j=0; j<columnas; j++)
        {
            printf("[%d] ", matriz[i][j]);
        }
        printf("\n");
    }
}

///EJ 06
//////////////////////////////////////////////////////////////

///09 Capicua
int capicua (char array[], int validos)
{
    int flag=1;
    int u=cantvalidos-1;

    for (int i=0; i<(cantvalidos/2); i++)
    {
        if (array[i] != array[u-i])
        {
            flag=0;
        }
    }

    return flag;
}

///EJ 07
//////////////////////////////////////////////////////////////
void intercambio (int *a, int *b)
{
    int aux;

    aux=*a;
    *a=*b;
    *b=aux;
}

///EJ 08
//////////////////////////////////////////////////////////////
int ordenarennuevo(char array[], int cantvalidos1, char array2[], int cantvalidos2, char destino[])
{
    int x = 0;
    int y = 0;
    int i = 0;

    while(x < cantvalidos1 && y < cantvalidos2)
    {

        if (array[x] <= array2[y])
        {
            destino[i] = array[x];
            x++;
        }
        else
        {
            destino[i] = array2[y];
            y++;
        }
        i++;
    }

    while(x < cantvalidos1)
    {
        destino[i] = array[x];
        x++;
        i++;
    }
    while(y < cantvalidos2)
    {
        destino[i] = array2[y];
        y++;
        i++;
    }

    int cantvalidosdestino=i;

    return cantvalidosdestino;
}

///EJ 09
//////////////////////////////////////////////////////////////

///EJ 10
//////////////////////////////////////////////////////////////




