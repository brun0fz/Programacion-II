#include <stdio.h>
#include <stdlib.h>
#include "time.h"  //para incluir libreria de time y poder cargar aleatoriamente

/*
Trabajo Práctico número 1: Funciones y punteros
1. Se tienen un arreglo de números enteros positivos. Se desea obtener el promedio de sus valores.
Para ello se debe:
a. Hacer una función que inicialice las celdas del arreglo en –1.
b. Hacer una función que permita al usuario ingresar los valores. No se conoce la cantidad de antemano.
c. Hacer una función que sume el contenido del arreglo y lo retorne.
d. Hacer una función que cuente la cantidad de valores ingresados.
e. Hacer una función que reciba como parámetro el arreglo ya cargado, calcule y retorne el valor promedio
usando las funciones anteriores (c y d).
f. Hacer la función main correspondiente.

2. Invertir el contenido de un arreglo de caracteres. Para ello se debe modularizar de la siguiente forma:
a. Hacer una función para la carga del arreglo.
b. Hacer una función para invertir el arreglo.
c. Hacer una función para mostrar el contenido del arreglo.
d. Hacer la función main con el menú correspondiente.

3. Hacer una función que reciba como parámetro un arreglo de números enteros y retorne el valor decimal de dicho
número.

4. Hacer una función que retorne la posición del valor máximo de un arreglo de números enteros.

5. Sea una matriz de números enteros, de dimensiones: 12 filas y 31 columnas. Contienen las precipitaciones
correspondientes a un año entero. Las filas corresponden a los meses y las columnas a los dias. Se pide.
a. Hacer una función para cargar la matriz.
b. Hacer una función que retorne el día de máxima precipitación para un mes determinado.
c. Hacer una función que cargue en un arreglo de 12 posiciones el resultado de aplicar la función anterior a cada
mes de año.
d. Hacer la función main con el menú correspondiente.

6. Dada una cadena de caracteres, hacer una función que determine si dicha cadena es capicúa o no.
La función recibe como parámetro la cadena y retorna 1 o 0 según sea la respuesta.

7. Hacer una función que intercambie el contenido de dos variables.

8. Dados dos arreglos de números enteros ordenados de menor a mayor, hacer una función que los reciba como
parámetros y retorne un tercer arreglo que contenga los datos de los arreglos anteriores, también ordenados.
Se los debe intercalar.

9. Dados dos arreglos paralelos, uno con apellidos y otro con edades. Se debe hacer un programa para encontrar
el apellido de la persona de mayor edad. Se debe modularizar.

10. Hacer una función que reciba como parámetro de entrada un arreglo de enteros y tres parámetros de salida,
tres números enteros que representen: valor máximo, valor mínimo y promedio. Se debe usar pasaje de parámetros
por referencia
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// PROTOTIPOS:
void iniciarArregloMenos1 (int A[], int cantidad);
int cargarArrEnterosPorUsuario (int A[], int cantidad);
int sumarContenidoArreglo (int A[], int validos);
float promediarArreglo (int A[], int validos);
void mostrarArrEnt (int A[], int validos);
int cargarArrCharPorUsuario (char A[], int cantidad);
int cargarArrCharAutomatico (char A[], int cantidad);
void invertirArreglo (char A [], int validos);
void mostrarArrChar (char A[], int validos);
int CambiarArregloANroDecimal (int A[], int validos);
int retornarPosicionMayor (int A[], int validos);
void cargarMatrizAutomatico (int M[12][31], int dimF, int dimC);
void mostrarMatriz (int M[12][31], int dimF, int dimC);
int buscarDiaMayorPrecipitacionDelMes (int M[12][31], int dimF, int dimC, int pos);
void cargarArregloAnualConDiasMayoresPrecipitacionesCadaMes (int M[12][31], int dimF, int dimC, int A[12]);
int verSiEsCapicuaArregloChar (char A[], int dim);
void intercambiarContenidoVariables (int *A, int *B);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////// MAIN:

int main()
{
    /*
char arr[20]={'a','s','\0','s'};
printf("\narreglo as espacio s harcodeado\n %s\n",arr);
printf("\n");
puts(arr); ///en ambos casos muestra solo as, porque corta en el caracter de finalizacion de string
printf("\n");
mostrarArrChar(arr, 20); ///si uso la funcion de mostrar y recorro hasta validos muestra todo, porque el caracter de
          ///finalizacion lo toma como un espacio
printf("\n ahora por usuario...\n");
char arr2[20];
printf("\n ingrese una palabra\n");///si uso scanf %s para ingressar por user pasa lo mismo
fflush(stdin);
scanf("%s", &arr2);
puts(arr2);
mostrarArrChar(arr2,20);
printf("\n ahora por user con gets\n");
char arr3[20]; ///si uso gets SI toma el espacio
printf("\n Ingrese una palabra con gets\n");
fflush(stdin);
gets(arr3);
puts(arr3);
mostrarArrChar(arr3,20);
*/

/// EJERC 1

int arrEnteros[20];
iniciarArregloMenos1 (arrEnteros, 20);
printf ("Arreglo -1:\n");
mostrarArrEnt (arrEnteros, 20);

int arrEnteros2[100];
int validos = cargarArrEnterosPorUsuario (arrEnteros2, 100);
printf ("\nArreglo enteros\n");
mostrarArrEnt (arrEnteros2, validos);

int suma = sumarContenidoArreglo(arrEnteros2, validos);
printf ("\nLa suma del contenido del arreglo es  %d\n",   suma);

float promedio = promediarArreglo (arrEnteros2, validos);
printf ("\nEl promedio del contenido del arreglo es  %f\n", promedio);

// EJERC 2
char arrChar2 [20];
int validosChar2 = cargarArrCharPorUsuario(arrChar2, 20);
printf ("\nArreglo char ingresado por usuario\n");
mostrarArrChar (arrChar2, validosChar2);

char arrChar [10];
int validosChar = cargarArrCharAutomatico (arrChar, 10);
printf ("\nArreglo char cargado automaticamente\n");
mostrarArrChar (arrChar, validosChar);

invertirArreglo (arrChar, validosChar);
printf ("\nArreglo char invertido\n");
mostrarArrChar (arrChar, validosChar);
// EJERC 3
int decimal = CambiarArregloANroDecimal (arrEnteros2, validos);
printf("\nEl arreglo transformado en Nro decimal es: %d\n", decimal);
// EJERC 4
int posEnteroMayor = retornarPosicionMayor (arrEnteros2, validos);
printf("\nLa posicion del entero mayor del arreglo es:  %d\n", posEnteroMayor);
// EJERC 5
int matrizEnt [12][31];
cargarMatrizAutomatico (matrizEnt, 12, 31);
printf("\nMatriz de precipitaciones del año\n");
mostrarMatriz (matrizEnt, 12, 31);
int mesBuscado;
printf("\nIngrese el mes (en numeros) del cual desea saber el dia de mayor precipitacion \n");
scanf("%d", &mesBuscado);
int pos = mesBuscado -1; //resto 1 para la posicion porq las filas de la matriz arrancan en 0
int diaMayorPrec = buscarDiaMayorPrecipitacionDelMes (matrizEnt, 12, 31, pos);
printf("\nEl dia de mayor precipitacion del mes ingresado fue  %d\n", diaMayorPrec);
int arregloMayoresPrecip[12];
cargarArregloAnualConDiasMayoresPrecipitacionesCadaMes (matrizEnt, 12, 31, arregloMayoresPrecip);
printf("\nArreglo con los dias de mayor precipitacion de cada mes\n");
mostrarArrEnt(arregloMayoresPrecip, 12);
// EJERC 6
int flag = verSiEsCapicuaArregloChar (arrChar2, validosChar2);
if (flag == 0) //0 ERAN TODOS IGUALES
    {
        printf("\nEl arreglo es capicua\n");
    }
else // 1 HABIA ALGUNO DISTINTO
    {
        printf("\nEl arreglo no es capicua\n");
    }

// EJERC 7
int A=4;
int B=6;

printf("\nA= %d, B=  %d", A, B);
intercambiarContenidoVariables (&A, &B);
printf("\nA= %d, B=  %d", A, B);



return 0;

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// FUNCIONES:

/* EJERC 1.
Se tienen un arreglo de números enteros positivos. Se desea obtener el promedio de sus valores. Para ello se debe:
a. Hacer una función que inicialice las celdas del arreglo en –1.
b. Hacer una función que permita al usuario ingresar los valores. No se conoce la cantidad de antemano.
c. Hacer una función que sume el contenido del arreglo y lo retorne.
d. Hacer una función que cuente la cantidad de valores ingresados.
e. Hacer una función que reciba como parámetro el arreglo ya cargado, calcule y retorne el valor promedio
usando las funciones anteriores (c y d).
f. Hacer la función main correspondiente.*/

void iniciarArregloMenos1 (int A[], int cantidad)
{
    int i=0;
    for (i=0; i<cantidad; i++)
    {
       A[i]=-1  ;
    }
}

int cargarArrEnterosPorUsuario (int A[], int cantidad)
{
    char control='s';
    int i=0;

    while ((control=='s') && (i<cantidad))
        {
           printf ("\nIngrese un Nro entero para ser cargado en el arreglo\n");
           scanf("%d", &A[i]);
           printf ("\nDesea seguir cargando Nros en el arreglo? Presione s/n\n");
           fflush (stdin);
           scanf("%c", &control);
           i++;
        }
    return i;
}

int sumarContenidoArreglo (int A[], int validos)
{
    int i;
    int suma=0;

    for (i=0; i<validos; i++)
        {
          suma=suma + A[i];
        }
    return suma;
}

float promediarArreglo (int A[], int validos)
{
  int suma =  sumarContenidoArreglo (A, validos);
  float prom = (float)suma / (float)validos;
  return prom;
}

void mostrarArrEnt (int A[], int validos)
{
    int i;

    for (i=0; i<validos; i++)
        {
            printf ("| %d |", A[i]);
        }
}

/* EJERC 2.
Invertir el contenido de un arreglo de caracteres. Para ello se debe modularizar de la siguiente forma:
a. Hacer una función para la carga del arreglo.
b. Hacer una función para invertir el arreglo.
c. Hacer una función para mostrar el contenido del arreglo.
d. Hacer la función main con el menú correspondiente*/

int cargarArrCharPorUsuario (char A[], int cantidad)
{
    char control='s';
    int i=0;

    while ((control=='s') && (i<cantidad))
        {
           printf ("\nIngrese una letra para ser cargada en el arreglo\n");
           fflush(stdin);
           scanf("%c", &A[i]);
           printf ("\nDesea seguir cargando letras en el arreglo? Presione s/n\n");
           fflush (stdin);
           scanf("%c", &control);
           i++;
        }
    return i;
}

int cargarArrCharAutomatico (char A[], int cantidad)
{
    int i;

    for (i=0; i<cantidad; i++)
        {
           A[i] = 97+i;
        }
    return i;
}

void invertirArreglo (char A [], int validos) //lo invierte sobre el mismo arreglo usando un pivot
{
    int i = 0; //es la posicion 0 del arreglo, que luego se va incrementando, es un contador
    int u = validos-1; //es la ultima psicion del arreglo, que luego va decreciendo, contador
    char aux; //UNA VARIABLE AUXILIAR PARA PIVOTEAR
    int tope = validos/2;

    while (i<tope)
    {
        aux = A[u]; //lo que está en la ult posicion  pasa a la variable auxiliar
        A[u]= A[i]; //lo que está en la 1ra posicion pasa a la ultima pos
        A[i]= aux;  //lo que esta en aux (que era lo de la ult posicion) pasa a la 1ra posicion
        i++; //aumenta el contador avanzando una posicion mas desde la 1ra
        u--;  //decrece el contador retrocediendo una posicion mas desde la ultima
    }
}

/* version usando un arreglo auxiliar:
void invertirArreglo (char A [], char C [], int validos) //esta lo invierte pasándolo a otro arreglo
{
    int iA = 0;           //i es el indice de A y arranca en la 1er posicion valida, que es 0
    int iC = validos-1;  //para la pila C pongo un indice inverso al indice i, que es de la pila A. arranca en la ultima posicon de C (q es validos-1)
    for (iA=0; iA<validos; iA++)
        {
        C[iC] = A [iA];
        iC --;         //el indice de C decrece de a 1 al = tiempo que el de A aumenta de a 1
        }
}                    //no retorna nada porq trabaja con los arrays como pilas */

void mostrarArrChar (char A[], int validos)
{
    int i;

    for (i=0; i<validos; i++)
        {
            printf ("| %c |", A[i]);
        }
}

// EJERC 3: Hacer una función que reciba como parámetro un arreglo de nros enteros y retorne el valor decimal de dicho número

int CambiarArregloANroDecimal (int A[], int validos)
{
    int i;
    int decimal=0;

    for (i=0; i<validos; i++)
    {
        decimal = (decimal*10) + A[i];
    }
return decimal;
}

// EJERC 4: Hacer una función que retorne la posición del valor máximo de un arreglo de números enteros

int retornarPosicionMayor (int A[], int validos)
{
   int i;
   int miMayor = A[0];
   int posMayor = 0;

   for (i=0; i<validos; i++)
    {
        if (miMayor<A[i])
        {
            miMayor = A[i];
            posMayor = i;
        }
    }
   return posMayor;
}

/* otra forma de hacerlo:

int retornarPosicionMayor (int A[], int validos)
{
   int i;
   int miMayor = A[0];

   for (i=0; i<validos; i++)
    {
        if (miMayor<A[i])
        {
            miMayor = A[i];
        }
    }
   return i-1; // devuelvo i-1 porque en la ultima vuelta i se incrementa una vez mas antes de cortar la condicion del validos -1
}
*/

/* EJERC 5. Sea una matriz de números enteros, de dimensiones: 12 filas y 31 columnas. Contienen las precipitaciones
correspondientes a un año entero. Las filas corresponden a los meses y las columnas a los dias. Se pide.
a. Hacer una función para cargar la matriz.
b. Hacer una función que retorne el día de máxima precipitación para un mes determinado.
c. Hacer una función que cargue en un arreglo de 12 posiciones el resultado de aplicar la función anterior a cada
mes de año.
d. Hacer la función main con el menú correspondiente.*/

// a //
void cargarMatrizAutomatico (int M[12][31], int dimF, int dimC)
{
    int f, c;
    srand(time(NULL)); //planto semilla. elige una hora del día para ir cambiando los nros aleatorios

    for(f=0; f<dimF; f++)
    {
        for(c=0; c<dimC; c++)
        {
            M[f][c] = rand()%10; // o: int aleatorio=rand()%10; M[indF][indC] = aleatorio; CARGA DEL 0 AL 9
        }
    }
}

void mostrarMatriz (int M[12][31], int dimF, int dimC)
{
    int f, c;

    for (f=0; f<dimF; f++)
    {
        for (c=0; c<dimC; c++)
        {
            printf("| %d ", M[f][c]);
        }
        printf("\n\n\n");
    }
}

// b //
int buscarDiaMayorPrecipitacionDelMes (int M[12][31], int dimF, int dimC, int pos)
{
   int c;
   int f = pos;
   int mayorPrec = M[0][0];
   int posMayorPrec = 0;

   for (c=0; c<dimC; c++)
    {
        if (mayorPrec < M[f][c])
            {
                mayorPrec = M[f][c];
                posMayorPrec = c;
            }
    }
return posMayorPrec+1; // +1 porque la pos arranca de 0 que corresponde al dia 1
}

// c //
void cargarArregloAnualConDiasMayoresPrecipitacionesCadaMes (int M[12][31], int dimF, int dimC, int A[12])
{
    int i;

    for (i=0; i<12; i++)
        {
           A[i] =  buscarDiaMayorPrecipitacionDelMes (M, 12, 31, i);
        }
}

// EJERC 6: Dada 1 cadena de caracteres, hacer 1 función que determine si dicha cadena es capicúa o no. La función recibe
// como parámetro la cadena y retorna 1 o 0 según sea la respuesta.

int verSiEsCapicuaArregloChar (char A[], int dim)
{
    int flag=0;
    int i;
    int u;
    int tope = dim/2;

    while ((i<tope) && (flag == 0))
        {
           if (A[i]!=A[u])
               {
                   flag=1; // 0 SI SON IGUALES Y 1 SI SON DISTINTOS
               }
           i++;
           u--;
        }

    return flag;
}

// EJERC 7: Hacer una función que intercambie el contenido de dos variables.

void intercambiarContenidoVariables (int*A, int*B)
{
   int pivot;

   pivot=*A;
   *A=*B;
   *B=pivot;
}

/* EJERC 8: Dados dos arreglos de números enteros ordenados de menor a mayor, hacer una función que los reciba como
parámetros y retorne un tercer arreglo que contenga los datos de los arreglos anteriores, también ordenados. Se los
debe intercalar.*/
// EJERC 9. Dados 2 arreglos paralelos, 1 c/ apellidos y otro c/ edades, se debe hacer 1 programa para encontrar el apellido de la persona de mayor edad.
// Se debe modularizar.

/* EJERC 10: Hacer una función que reciba como parámetro de entrada un arreglo de enteros y tres parámetros de salida, tres
números enteros que representen: valor máximo, valor mínimo y promedio. Se debe usar pasaje de parámetros por
referencia*/


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* SOLUCIONES:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// prototipado de funciones

// ejercicio 1
void inicializaArregloInt(int A[], int dim);
int cargaArregloInt (int A[], int val);
int sumaContenidoArreglo(int A[], int val);
int cuentaContenidoArreglo(int A[]); // aca le envio la cantidad de elementos validos???
int promedioArreglo(int A[]);
// auxiliar
void mostrarArreglo(int A[], int val);

// ejercicio 2
int cargaArregloChar(char C[], int dim);
void invierteCaracteres(char C[], int val);
void muestraArregloChar(char C[], int val);

// ejercicio 3
int convierteArregloIntDecimal(int A[], int val);

// ejercicio 4
int posicionMaximoValorArregloEnteros(int A[], int val);

// ejercicio 5
void muestraMeses(int M[12][31]);
void cargaMatriz(int M[12][31]);
int maximaPrecipitacion(int M[12][31], int mes);
void maximaPrecipitacionPorMes(int Mes[], int Meses[12][31]);

// ejercicio 6
int capicuaSIoNo (char C[], int val);

// ejercicio 7
void intercambio(int *a, int *b);

// ejercicio 8
int intercalarArreglosChar (char A[], int cantA, char B[], int cantB, char C[]);

// ejercicio 9

/// mostrar en clase

// ejercicio 10

void calculaMaximoMinimoPromedioDeArreglo(int A[], int validos, int * maximo, int * minimo, float * promedio);
// realizo funciones auxiliares para calcular lo que se pide
float promedioEnArreglo (int A[], int validos);
int maximoEnArreglo (int A[], int validos);
int minimoEnArreglo (int A[], int validos);

// funcion principal
int main()
{
    printf("Hello guia number one!!\n");
    // ejer 1

    int unArreglo[20];
    inicializaArregloInt(unArreglo, 20);
    mostrarArreglo(unArreglo,20);
    int validos=cargaArregloInt(unArreglo, 20);
    mostrarArreglo(unArreglo,validos);
    printf("\nEl promedio del arreglo es %d", promedioArreglo(unArreglo));
    // ejer 2

    char otroArregloChar[20];
    int validosChar=cargaArregloChar(otroArregloChar, 20);
    muestraArregloChar(otroArregloChar, validosChar);
    invierteCaracteres(otroArregloChar, validosChar);
    muestraArregloChar(otroArregloChar, validosChar);


    // ejer 3

    int unArreglo[20];

    int validos=cargaArregloInt(unArreglo, 20);
    mostrarArreglo(unArreglo,validos);

    int decimal = convierteArregloIntDecimal(unArreglo, validos);
    printf("\nEl valor decimal del arreglo es %d", decimal);

    // ejer 4

    int posmayor= posicionMaximoValorArregloEnteros(unArreglo, validos);

    printf("\nLa posicion del valor maximo en el arreglo es %d", posmayor);


    // ejer 5
    int Meses[12][31];

    cargaMatriz(Meses);
    muestraMeses(Meses);

    int maxPrecipXmes[12];

    maximaPrecipitacionPorMes(maxPrecipXmes, Meses);

    printf("\n\n\nDias con mayor precipitaciones por mes\n");

    mostrarArreglo(maxPrecipXmes, 12);

    // ejer 6

    char caracteres[10];

    int validos = cargaArregloChar(caracteres, 10);

    int bandera = capicuaSIoNo(caracteres, validos);

    if(bandera==1)
        puts("El arreglo es capicua...");
    else
        puts("El arreglo NO es capicua...");


    // ejer 7

    int var1=10;
    int var2=23;
    printf("\Antes del intercambio: ");
    printf("\nVariable 1: %d", var1);
    printf("\nVariable 2: %d", var2);

    intercambio(&var1, &var2);

    printf("\nDespues del intercambio: ");
    printf("\nVariable 1: %d", var1);
    printf("\nVariable 2: %d", var2);


    // ejer 8
        char unArreglo[10];
        int cantA;
        char otroArreglo[10];
        int cantB;
        char final[20];

        printf("Cargamos el primer arreglo:\n ");
        cantA = cargaArregloChar(unArreglo,10);

        printf("Cargamos el segundo arreglo:\n ");
        cantB = cargaArregloChar(otroArreglo,10);

        printf("\nContenido del primer arreglo: ");
        muestraArregloChar(unArreglo, cantA);

        printf("\nContenido del segundo arreglo: ");
        muestraArregloChar(otroArreglo, cantB);


        int f = intercalarArreglosChar(unArreglo, cantA, otroArreglo, cantB, final);


        printf("\nContenido final: ");
        muestraArregloChar(final, f);


    // ejercicio 10
    int ArregloDeNumeros[10]={4, 2,7,3,99,22,5,23,97,12};
    int mayor=0;
    int menor=0;
    float prom=0;

    printf("\n Arreglo para el punto 10: ");
    mostrarArreglo(ArregloDeNumeros, 10);
    calculaMaximoMinimoPromedioDeArreglo(ArregloDeNumeros, 10, &mayor, &menor, &prom);
    printf("\nInfo del arreglo: \n Mayor= %d\n Menor= %d\n Promedio=%.2f", mayor,menor, prom);
    return 0;
}

/*1.
Se tienen un arreglo de números enteros positivos. Se desea obtener el promedio
de sus valores. Para ello se debe:
a. Hacer una función que inicialice las celdas del arreglo en –1.
b. Hacer una función que permita al usuario ingresar los valores. No se conoce
la cantidad de antemano.
c. Hacer una función que sume el contenido del arreglo y lo retorne.
d. Hacer una función que cuente la cantidad de valores ingresados.
e. Hacer una función que reciba como parámetro el arreglo ya cargado, calcule y retorne el valor promedio
usando las funciones anteriores (c y d).
f. Hacer la función main correspondiente.
*/
void mostrarArreglo(int A[], int val)
{
    int i=0;
    printf("\nContenido del arreglo: ");
    for(i=0; i<val; i++)
    {
        printf("| %d", A[i]);
    }
    printf("|");
}

void inicializaArregloInt(int A[], int dim)
{
    int i=0;
    for(i=0; i<dim; i++)
    {
        A[i]=-1;
    }
}

int cargaArregloInt (int A[], int val)
{
    int i=0;
    char control='s';

    printf("\nCarga de arreglo de enteros:");

    while(i<val&&control=='s')
    {
        printf("\nIngrese un valor: ");
        scanf("%d", &A[i]);

        printf("\nDesea continuar?");
        fflush(stdin);
        scanf("%c", &control);

        i++;
    }
    return i;
}

int sumaContenidoArreglo(int A[], int val)
{
    int i=0;
    int suma=0;

    for (i=0; i<val; i++)
    {
        suma+=A[i];
    }
    return suma;
}

int cuentaContenidoArreglo(int A[]) // aca le envio la cantidad de elementos validos???
{
    int i=0;
    while(A[i]!=-1)
    {
        i++;
    }
    return i;
}

int promedioArreglo(int A[])
{
    int cantidad=0;
    int suma=0;
    int promedio=0;

    cantidad= cuentaContenidoArreglo(A);
    suma=sumaContenidoArreglo(A,cantidad);
    promedio=suma/cantidad;

    return promedio;
}

/*2. Invertir el contenido de un arreglo de caracteres. Para ello se debe
modularizar de la siguiente forma:
a. Hacer una función para la carga del arreglo.
b. Hacer una función para invertir el arreglo.
c. Hacer una función para mostrar el contenido del arreglo.
d. Hacer la función main con el menú correspondiente.*/

int cargaArregloChar(char C[], int dim)
{
    int i=0;
    char control='s';

    printf("\nCarga de arreglo de caracteres:");

    while(i<dim&&control=='s')
    {
        printf("\nIngrese un valor: ");
        fflush(stdin);
        scanf("%c", &C[i]);

        printf("\nDesea continuar?");
        fflush(stdin);
        scanf("%c", &control);

        i++;
    }
    return i;
}

void invierteCaracteres(char C[], int val)
{
    int i=0;
    int u=val-1;
    int aux=0;

    while(i<u)
    {
        aux=C[i];
        C[i]=C[u];
        C[u]=aux;

        i++;
        u--;
    }
}

void muestraArregloChar(char C[], int val)
{
    int i=0;
    printf("\nContenido del arreglo de caracteres: ");
    for(i=0; i<val; i++)
    {
        printf("| %c ", C[i]);
    }
    printf("|");
}

/*3. Hacer una función que reciba como parámetro un arreglo de números enteros
y retorne el valor decimal de dicho número.*/
int convierteArregloIntDecimal(int A[], int val)
{
    int u=val-1;
    int multiplicador=1;
    int aux=0;
    int decimal=0;

    while(u>=0)
    {
        aux=A[u]*multiplicador;

        decimal=decimal+aux;

        multiplicador=multiplicador*10;

        u--;
    }
    return decimal;
}

//4. Hacer una función que retorne la posición del valor máximo de
//un arreglo de números enteros.

int posicionMaximoValorArregloEnteros(int A[], int val)
{
    int i=0;
    int mayor=0;
    int posMayor=0;

    if(val>0) // valido que el arreglo tenga algo ...
    {
        mayor=A[i];
        posMayor=i;
        i++;

        while(i<val)
        {
            if(mayor<A[i])
            {
                mayor=A[i];
                posMayor=i;
            }
            i++;
        }
    }
    return posMayor;
}

/*
5. Sea una matriz de números enteros, de dimensiones: 12 filas y 31 columnas.
Contienen las precipitaciones correspondientes a un año entero.
Las filas corresponden a los meses y las columnas a los años. Se pide:
a. Hacer una función para cargar la matriz.
b. Hacer una función que retorne el día de máxima precipitación para un mes determinado.
c. Hacer una función que cargue en un arreglo de 12 posiciones el resultado de aplicar
la función anterior a cada mes de año.
d. Hacer la función main con el menú correspondiente.
*/
void muestraMeses(int M[12][31])
{
    int x=0;
    int y=0;

    for(x=0; x<12; x++)
    {
        printf("\n\nPrecipitaciones para el mes %d", x+1);
        for(y=0; y<31; y++)
        {
            printf("\nDia %d: %d", y+1, M[x][y]);
        }
    }
}

void cargaMatriz(int M[12][31]) // se va a cargar por completo la matriz
{
    int x=0;
    int y=0;

    // lo hago random.. si no es un embole...

    for(x=0; x<12; x++)
    {

        for(y=0; y<31; y++)
        {
            M[x][y]=(rand()%100)+1;
        }
    }
}


int maximaPrecipitacion(int M[12][31], int mes)
{
    int i=0;
    int maximoDia=0;
    int maximaPrecip=0;

    if(mes>=0&&mes<=12) // valido que tenga algo
    {
        maximoDia=i+1; // para que no aparezca dia 0 (cero)
        maximaPrecip=M[mes][i];
        i++;

        while(i<31)
        {
            if(maximaPrecip<M[mes][i])
            {
                maximaPrecip=M[mes][i];
                maximoDia=i+1;
            }
            i++;
        }
    }
    return maximoDia;
}

void maximaPrecipitacionPorMes(int Mes[], int Meses[12][31])
{
    int i=0;
    int maxPrecip=0;

    for(i=0; i<12; i++)
    {
        maxPrecip= maximaPrecipitacion(Meses, i);

        Mes[i]=maxPrecip;
    }
}

/*6. Dada una cadena de caracteres, hacer una función que determine si
dicha cadena es capicúa o no. La función recibe como parámetro la cadena y
retorna 1 o 0 según sea la respuesta.
*/

int capicuaSIoNo (char C[], int val)
{
    int flag=1; // si retorna 1, es capicua
    int i=0;
    int u=val-1;

    while(i<u&&flag==1)
    {
        if(C[i]==C[u])
        {
            i++;
            u--;
        }
        else
        {
            flag=0;
        }
    }
    return flag;
}

// 7. Hacer una función que intercambie el contenido de dos variables.
void intercambio(int *a, int *b)
{
    int aux=0;

    aux=*a;
    *a=*b;
    *b=*a;
}

/* 8. Dados dos arreglos de números enteros ordenados de menor a mayor, hacer una
función que los reciba como parámetros y retorne un tercer arreglo que contenga
los datos de los arreglos anteriores, también ordenados. Se los debe intercalar.
*/

int intercalarArreglosChar (char A[], int cantA, char B[], int cantB, char C[])
{

    // indice del arreglo A
    int iA =0;

    // indice del arreglo B
    int iB=0;

    // indice del arreglo C
    int indexC=0;

    while(iA<cantA && iB<cantB)
    {
        if(A[iA]<B[iB])
        {
            C[indexC++]=A[iA];
            iA++;
        }
        else
        {
            C[indexC++]=B[iB];
            iB++;
        }
    }

    while(iA<cantA)
    {
        C[indexC++]=A[iA];
        iA++;
    }

    while(iB<cantB)
    {
        C[indexC++]=B[iB];
        iB++;
    }

    return indexC;
}

/*
10. Hacer una función que reciba como parámetro de entrada un arreglo
de enteros y tres parámetros de salida, tres números enteros que
representen: valor máximo, valor mínimo y promedio. Se debe usar pasaje
de parámetros por referencia.
*/

// realizo funciones auxiliares para calcular lo que se pide
float promedioEnArreglo (int A[], int validos)
{
    int i=0;
    int suma=0;
    for(i=0; i<validos; i++)
    {
        suma+=A[i];
    }

    return (float)suma/(float)validos;
}
int maximoEnArreglo (int A[], int validos)
{
    int i=0;
    int mayor=A[i];
    for(i=1; i<validos; i++)
    {
        if(mayor<A[i])
        {
            mayor=A[i];
        }
    }
    return mayor;
}
int minimoEnArreglo (int A[], int validos)
{
    int i=0;
    int menor=A[i];
    for(i=1; i<validos; i++)
    {
        if(menor>A[i])
        {
            menor=A[i];
        }
    }
    return menor;
}
void calculaMaximoMinimoPromedioDeArreglo(int A[], int validos, int * maximo, int * minimo, float * promedio)
{
    *maximo=maximoEnArreglo(A, validos);
    *minimo=minimoEnArreglo(A, validos);
    *promedio=promedioEnArreglo(A, validos);
}
