#include <stdio.h>
#include <stdlib.h>

/*
Trabajo Práctico n 2: Estructuras de Datos Estáticas y Dinámicas
1. Dada la estructura struct persona{ char nombre[30]; int sexo; int edad;};.
a. Crear un arreglo de 30 elementos de esta estructura y cargarlo mediante una función.
b. Hacer una función que cuente la cantidad de varones o mujeres que hay.
c. Hacer una función que copie los datos de todos los varones del arreglo anterior en otro arreglo del tamaño
justo. Usar malloc dentro de la función y retornarlo o usar dos parámetros de tipo arreglo y crear el arreglo
dinamico antes de la invocación.
2. codificar el algoritmo de ordenamiento por selección, sobre la estructura anterior teniendo en cuenta la edad.
3. simular el uso de una pila de enteros a partir de la siguiente estructura:
a. struct Pila
{ int valores[100];
int posTope; //posición de nuevo tope, o sea, lugar en donde se
almacenará el nuevo valor
}
b. implementar las siguientes funciones:
void apilar(Pila *p; int valor);
int desapilar(Pila *p);
int tope(Pila p);
int pilavacia(Pila p);
void mostrar(Pila p);
void inicPila(Pila *p);
4. Dadas dos pilas (como las anteriores) que se supone que tienen sus datos ordenados, generar una tercer pila que
contenga los datos de las dos anteriores intercalados, de forma tal que queden ordenados.
5. Función insertar en orden en un arreglo.
6. Algoritmo de ordenamiento por inserción.
7. Función eliminar un elemento de un arreglo.
8. Sistema de notas. Se tiene que administrar un sistema para un curso con 20 alumnos que cursan 5 materias
diferentes. Se deben almacenar los datos de los alumnos y las notas que obtuvieron en el examen final de cada
materia. Para ello se utilizarán las siguientes estructuras:
struct Alumno
{
int matricula;
char nombre[30];
};
struct Materia
{
int codigo;
char nombreMat[20];
};
struct Nota
{
int matricula;
int codigo;
int nota;
};
Y las siguientes variables:
Alumno alus[20]; // para almacenar los datos de los 20 alumnos.
Materia mats[5]; // para almacenar los códigos y nombres de las 5 materias.
Nota notas[100]; // para almacenar todas las notas de los alumnos.
Las notas se almacenan en forma desordenada para todos los alumnos.
Se deben hacer las siguientes funciones:
1. Cargar el arreglo de Materia
2. Agregar un Alumno
3. Agregar una Nota, validando que exista “matricula” y “código”. La función debe retornar 1 si la operación
fue exitosa y 0 (cero) en caso contrario.
4. Hacer una función que muestre por pantalla el nombre del alumno y la lista de materias con sus
respectivas notas. La función debe recibir como parámetro el nombre del alumno. Estrategia: con el
nombre del alumno se busca su matricula en el arreglo alus, luego se recorre el arreglo notas filtrándolo
por matricula, y con el código se accede al nombre de la materia revisando el arreglo mats.
*/



//////////////////////////////////////////////////////////////////////////////////////////
/* SOLUCIONES:

/*
1. Dada la estructura struct persona{ char nombre[30]; int sexo; int edad;};.
a. Crear un arreglo de 30 elementos de esta estructura y cargarlo mediante una función.
b. Hacer una función que cuente la cantidad de varones o mujeres que hay.
c. Hacer una función que copie los datos de todos los varones del arreglo anterior
en otro arreglo del tamaño justo. Usar malloc dentro de la función y retornarlo o
usar dos parámetros de tipo arreglo y crear el arreglo dinamico antes de la invocación.
*/
typedef struct
{
    char nombre[30];
    char sexo;
    int edad;
} persona;

int cargarArregloPersonas(persona A[], int dim)
{
    int i=0;
    char control='s';

    printf("\nCargar el arreglo de personas:");

    while(i<dim&&control=='s')
    {
        printf("\nIngrese nombre: ");
        fflush(stdin);
        scanf("%s",&A[i].nombre);

        printf("\nIngrese sexo (m/f): ");
        fflush(stdin);
        scanf("%c",&A[i].sexo);

        printf("\nIngrese edad: ");
        scanf("%d",&A[i].edad);

        i++;

        printf("\nDesea continuar? ");
        fflush(stdin);
        scanf("%c",&control);
    }
    return i;
}

void muestraArregloPersonas(persona A[], int val)
{
    int i=0;

    printf("\nContenido del arreglo de personas: \n");
    for(i=0; i<val; i++)
    {
        printf("\nNombre: %s", A[i].nombre);
        printf("\nSexo: %c", A[i].sexo);
        printf("\nEdad: %d", A[i].edad);
    }
}

int cuentaPorSexo(persona A[], int val, char sexo)
{
    int i=0;
    int cantidad=0;

    for(i=0; i<val; i++)
    {
        if(sexo==A[i].sexo)
        {
            cantidad++;
        }
    }
    return cantidad;
}

void pasaPorSexo(persona A[], int validosA, persona PorSexo[], char sexo)
{
    int i=0; // uno para el arreglo completo
    int x=0; // uno para el arreglo por sexo

    for(i=0; i<validosA; i++)
    {
        if(A[i].sexo==sexo)
        {
            PorSexo[x]=A[i]; // se pasa la estructura por completo...
            x++;
        }
    }
}

persona* pasaPorSexoPuntero (persona A[], int validosA, char sexo) //esta no retorna los vaildos, la de abajo si
{
    int cantidadSexo = cuentaPorSexo(A, validosA, sexo);

    persona* arrDin = (persona *) malloc(cantidadSexo * sizeof(persona));

    int i=0;
    int x=0;

    for(i=0; i<validosA; i++)
    {
        if(A[i].sexo==sexo)
        {
            arrDin[x]=A[i]; // se pasa la estructura por completo...
            x++;
        }
    }

    return arrDin;
}

int otra (persona A[], int validosA, char sexo, persona ** varones)
{
    int cantidadSexo = cuentaPorSexo(A, validosA, sexo);

    *varones = (persona *) malloc(cantidadSexo * sizeof(persona));

    int i=0;
    int x=0;

    for(i=0; i<validosA; i++)
    {
        if(A[i].sexo==sexo)
        {
            (*varones)[x]=A[i]; // se pasa la estructura por completo...
            x++;
        }
    }
    return x;
}

/* 2. codificar el algoritmo de ordenamiento por selección, sobre la estructura
anterior teniendo en cuenta la edad. */

int posMenor(persona A[], int validos, int pos)
{
    persona menor=A[pos];
    int posicionMenor=pos;
    int i = pos+1;
    while(i<validos)
    {
        if(menor.edad>A[i].edad)
        {
            menor=A[i];
            posicionMenor=i;
        }
        i++;
    }
    return posicionMenor;
}

void ordenacionPorSeleccion(persona A[], int validos)
{
    int i=0;
    persona aux;
    int pos=0;
    while(i<validos-1)
    {
        pos=posMenor(A, validos, i);
        aux=A[pos];
        A[pos]=A[i];
        A[i]=aux;
        i++;
    }
}

/* 3. simular el uso de una pila de enteros a partir de la siguiente estructura:
a. struct Pila
{ int valores[100];
int posTope; //posición de nuevo tope, o sea, lugar en donde se almacenará el nuevo valor
}
b. implementar las siguientes funciones:
void apilar(Pila *p; int valor);
int desapilar(Pila *p);
int tope(Pila p);
int pilavacia(Pila p);
void mostrar(Pila p);
void inicPila(Pila *p);
*/

//todo esto se puede escribir en archivos .h y .c, para crear la libreria

typedef struct
{
    int valores[100];
    int posTope; //posición de nuevo tope, o sea, lugar en donde se almacenará el nuevo valor
              // es como si fueran los validos del arreglo
} Pila;


void inicPila(Pila *p)
{
    p->posTope=0;
}

void apilar(Pila *p, int valor)
{
    if(p->posTope<100)
    {
        p->valores[p->posTope]=valor;
        p->posTope++;
    }
    else
    {
        printf("\nLa pila esta llena...");
    }

}

int desapilar(Pila *p)
{
    int rta=0;

    rta=p->valores[p->posTope-1];

    p->posTope--;

    return rta;
}

int tope(Pila p)
{
    int rta=0;

    rta=p.valores[p.posTope-1];

    return rta;
}

int pilavacia(Pila p)
{
    int rta=0;

    if(p.posTope==0)
    {
        rta=1;
    }

    return rta;
}
void mostrar(Pila p)
{
    int i=0;

    printf("\nBase..............................................Tope\n");

    while(i<p.posTope)
    {
        printf("| %d ", p.valores[i]);
        i++;
    }

    printf("|\nBase..............................................Tope\n");
}

/* 4. Dadas dos pilas (como las anteriores) que se supone que tienen sus datos ordenados,
 generar una tercer pila que contenga los datos de las dos anteriores intercalados,
 de forma tal que queden ordenados.*/

void intercalarPilas(Pila *a, Pila * b, Pila * destino)
{
     while(!pilavacia(*a)&&!pilavacia(*b))
    {
        if (tope(*a)<tope(*b))
        {
            apilar(destino, desapilar(a));
        }
        else
        {
            apilar(destino, desapilar(b));
        }
    }

    // ahora evaluo si quedo algo en alguna de las dos pilas

    if(!pilavacia(*a))
    {
        while(!pilavacia(*a))
            apilar(destino, desapilar(a));
    }
    else
    {
        while(!pilavacia(*b))
            apilar(destino, desapilar(b));
    }
}

/* 5. Función insertar en orden en un arreglo. */

int agregaEnOrden (int A[], int validos, int dato)
{
    int i = validos-1;
    while (i>=0 && dato<A[i])
    {
        A[i+1]=A[i];
        i--;
    }
    A[i+1]= dato;
    return validos+1;
}

/* 6. Algoritmo de ordenamiento por inserción. */

void insertar(int A[], int u, int dato)
{
    int i = u;
    while(i>=0 && dato <A[i])
    {
        A[i+1]=A[i];
        i--;
    }
    A[i+1]=dato;
}

void ordenacionInsercion (int A[], int c)
{
    int u = 0;
    while (u<c-1)
    {
        insertar(A,u,A[u+1]);
        u++;
    }
}

/* 7. Función eliminar un elemento de un arreglo. */

int eliminaElementoDeArreglo(int A[], int validos, int posAeliminar)
{
    int i=posAeliminar;
    // validamos que la pos ingresada sea valida...
    if(i<validos)
    {
        while(i<validos-1)
        {
            A[i]=A[i+1];/// voy corriendo los elementos
            i++;
        }

        validos--;///por fuera del while!!
    }

    return validos;
}

// Sistema de notas.... plantearlo ...

int main()
{
    printf("Hello practico 2!\n");

    persona Listado[30];
    int validos=0;

    validos=cargarArregloPersonas(Listado,30);
    muestraArregloPersonas(Listado, validos);

    int cantidadSexo= cuentaPorSexo(Listado, validos, 'm'); // voy a pasar los varones
    int cantidadSexoF= cuentaPorSexo(Listado, validos, 'f'); // voy a pasar los

    printf("\nHay %d varones en el listado grande..", cantidadSexo);

    persona * listaVarones = (persona *) malloc(cantidadSexo * sizeof(persona));

    pasaPorSexo(Listado,validos, listaVarones, 'm');

    muestraArregloPersonas(listaVarones, cantidadSexo);

      persona * listaMujeres = pasaPorSexoPuntero(Listado, validos, 'f'); ///esta crea el arr din dentro de la funcion y lo devuelve

      muestraArregloPersonas(listaMujeres, cantidadSexoF);/// pero no devuelve los validos (entonces llamo a la funcion que cuenta por sexo)

      persona * ultimo;/// en esta creo el puntero y lo paso,

      int u = otra(Listado, validos, 'm', &ultimo);///y dentro de la funcion se hace el malloc y se usa punt doble

      muestraArregloPersonas(ultimo, u);///la anterior devolvia los validos

    ordenacionPorSeleccion(Listado, validos);

    muestraArregloPersonas(Listado, validos);

    Pila pilita;

    inicPila(&pilita);
    apilar(&pilita, 10);
    apilar(&pilita, 9);
    apilar(&pilita, 7);
    apilar(&pilita, 5);
    apilar(&pilita, 3);
    apilar(&pilita, 1);

    mostrar(pilita);

     Pila pilota;

    inicPila(&pilota);
    apilar(&pilota, 11);
    apilar(&pilota, 8);
    apilar(&pilota, 6);
    apilar(&pilota, 4);
    apilar(&pilota, 3);
    apilar(&pilota, 2);

    mostrar(pilota);

    Pila requetepilita;
    inicPila(&requetepilita);

    intercalarPilas(&pilita, &pilota, &requetepilita);

   mostrar(pilita);
   mostrar(pilota);
   mostrar(requetepilita);

    return 0;
}

