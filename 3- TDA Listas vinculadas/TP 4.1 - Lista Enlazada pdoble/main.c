#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <conio.h>

#include "listaEnlazada.h"

////////////////////////////////////////////////////////

void SubProgramaAgregarNodosPpio(nodo **lista);
void SubProgramaAgregarNodosFinal(nodo **lista);
void subprogramaBusqeudaDeUnNodo(nodo **lista);
void subprogramaBorrarUnNodo(nodo **lista);
void subprogramaCrearListaOrdenada(nodo **lista);
int SubProgramaSumarEdades(nodo *lista);

///TP 4.1
///01
void subProgramaAgregarPersona(nodo **lista, persona p);
void InsertarDesdeArchivo(char fileName[], nodo **lista);
///02
void subProgramaAgregarPersonaOrd(nodo **lista, persona p);
void InsertarDesdeArchivoOrd(char fileName[], nodo **lista);
///03
int BuscarEnLista(nodo **lista, char nombre[]);
///04
void intercalarEnOrden(nodo **listaA, nodo **listaB, nodo **listaC);

void invertirLista(nodo **pLista);
nodo * invertirLista2(nodo * lista);



////////////////////////////////////////////////////////

int main()
{

////////////////////////////////////////////////////////

    char opcion;
    char nombre[20];
    int flag;

    nodo *listaA;
    nodo *listaB;
    nodo *listaC;

    inicLista(&listaA);
    inicLista(&listaB);
    inicLista(&listaC);

////////////////////////////////////////////////////////

    do
    {

        system("cls");

        printf("MENU:\n\n");

        printf("1. Leer de un archivo datos e insertar en una lista.\n");
        printf("2. Leer de un archivo datos e insertar en una lista de forma ordenada.\n");
        printf("3. Ver si existe un elemento determinado en una lista dada.\n");
        printf("4. Intercalar en orden los elementos de dos listas ordenadas para generar una nueva lista.\n");
        printf("5. Invertir los elementos de una lista.\n");

        printf("\nESC. SALIR\n");

        printf("\nIngrese el numero de opcion que desea seleccionar.\n\n");

        fflush(stdin);
        opcion=getch();

        switch(opcion)
        {

        case 49:
            system("cls");

            InsertarDesdeArchivo("personas.dat", &listaA);
            mostrarLista(&listaA);

            system("pause");
            break;

        case 50:
            system("cls");

            InsertarDesdeArchivoOrd("personas.dat", &listaA);
            mostrarLista(&listaA);

            system("pause");

            break;

        case 51:
            system("cls");


            printf("Ingrese el nombre a buscar: ");
            gets(nombre);

            flag=BuscarEnLista(&listaA, nombre);

            if(flag)
            {
                printf("\nSe ha encontrado a la persona.\n\n");
            }
            else
            {
                printf("\nNo se ha encontrado a la persona.\n\n");

            }

            system("pause");
            break;

        case 52:
            system("cls");

            printf("\nCargue la primer lista:\n");
            subprogramaCrearListaOrdenada(&listaA);

            system("cls");

            printf("\nCargue la segunda lista lista:\n");
            subprogramaCrearListaOrdenada(&listaB);

            system("cls");

            intercalarEnOrden(&listaA,&listaB,&listaC);

            printf("\nTercer lista ordenada con los elementos de la primera y la segunda lista:\n");
            mostrarLista(&listaC);

            system("pause");
            break;

        case 53:
            system("cls");

            printf("Cargue la lista: \n");
            SubProgramaAgregarNodosFinal(&listaA);
            system("cls");
            printf("lista: \n");
            mostrarLista(&listaA);
            system("pause");
            system("cls");
            printf("lista Invertida: \n");
            invertirLista(&listaA);
            mostrarLista(&listaA);

            system("pause");
            break;

        case 54:

            break;

        case 55:

            break;

        case 27:
            break;

        default:
            printf("\nERROR: Esa opcion no existe. ");
            system("pause");
        }
    }
    while(opcion !=27);


    return 0;
}

///AGREGAR NODOS AL PRINCIPIO
////////////////////////////////////////////////////////

void SubProgramaAgregarNodosPpio(nodo **pLista)
{
    char com='s';

    while(com=='s')
    {
        agregarPpio(pLista, crearNodo(cargarPersona()));
        printf("\nDesea cargar otra persona? [s/n]: ");
        fflush(stdin);
        scanf("%c", &com);
    }
}

///AGREGAR NODOS AL FINAL
////////////////////////////////////////////////////////

void SubProgramaAgregarNodosFinal(nodo **pLista)
{
    char com='s';

    while(com=='s')
    {
        agregarFinal(pLista, crearNodo(cargarPersona()));
        printf("\nDesea cargar otra persona? [s/n]: ");
        fflush(stdin);
        scanf("%c", &com);
    }
}

///BUSCAR UN NODO
////////////////////////////////////////////////////////

void subprogramaBusqeudaDeUnNodo(nodo **lista)
{
    char nombre[20];
    nodo *nodobuscado;

    printf("Ingrese nombre a buscar: ");
    fflush(stdin);
    gets(nombre);

    nodobuscado=buscarNodo(lista, nombre);

    if(nodobuscado != NULL)
    {
        mostrarNodo(nodobuscado);
    }
    else
    {
        printf("No se ha encontrado a la persona.");
    }
}

///BORRAR UN NODO
////////////////////////////////////////////////////////

void subprogramaBorrarUnNodo(nodo **lista)
{
    char nombre[20];

    printf("Ingrese nombre a eliminar: ");
    fflush(stdin);
    gets(nombre);

    borrarNodo(lista, nombre);
}

///CREAR LISTA ORDENADA
////////////////////////////////////////////////////////

void subprogramaCrearListaOrdenada(nodo **lista)
{
    char com='s';

    while(com=='s')
    {
        agregarEnOrden(lista, crearNodo(cargarPersona()));
        printf("\nDesea cargar otra persona? [s/n]: ");
        fflush(stdin);
        scanf("%c", &com);
    }
}

///SUMAR DATOS EN UNA LISTA
////////////////////////////////////////////////////////

int SubProgramaSumarEdades(nodo *lista)
{
    nodo *seg = lista;
    int suma=0;

    while(seg !=NULL)
    {
        suma+=seg->dato.edad;
        seg=seg->siguiente;
    }
    return suma;
}

////////////////////////////////////////////////////////

///TP 4.1
////////////////////////////////////////////////////////

///01 - Hacer un programa que lea de un archivo datos y los inserte en una lista.
/*
void subProgramaAgregarPersona(nodo **lista, persona p)
{
    agregarPpio(lista, crearNodo(p));
}
*/
void InsertarDesdeArchivo(char fileName[], nodo **lista)
{
    FILE *buffer = fopen(fileName, "rb");

    persona aux;

    if(buffer)
    {
        while(fread(&aux, sizeof(persona), 1, buffer)>0)
        {
            agregarPpio(lista, crearNodo(aux));
            //subProgramaAgregarPersona(lista, aux);
        }

        fclose(buffer);
    }
}

///02 - Hacer un programa que lea de un archivo datos y los inserte en una lista en forma ordenada.

void subProgramaAgregarPersonaOrd(nodo **lista, persona p)
{
    agregarEnOrden(lista, crearNodo(p));
}

void InsertarDesdeArchivoOrd(char fileName[], nodo **lista)
{
    FILE *buffer = fopen(fileName, "rb");

    persona aux;

    if(buffer)
    {
        while(fread(&aux, sizeof(persona), 1, buffer)>0)
        {
            subProgramaAgregarPersonaOrd(lista, aux);
        }

        fclose(buffer);
    }
}

///03 - Hacer una función que retorne un 1 (uno) o 0 (cero) si existe un determinado elemento en una lista dada.

int BuscarEnLista(nodo **pLista, char nombre[])
{
    int flag=0;

    if(buscarNodo(pLista, nombre))
    {
        flag=1;
    }

    return flag;
}

///04 - Hacer una función que intercale en orden los elementos de dos listas ordenadas generando una nueva lista.
///     Se deben redireccionar los punteros, no se deben crear nuevos nodos.

void intercalarEnOrden(nodo **listaA, nodo **listaB, nodo **listaC)
{
    nodo *aux;

    while((*listaA!=NULL) && (*listaB!=NULL))
    {
        if((*listaA)->dato.edad < (*listaB)->dato.edad)
        {
            aux=*listaA;

            *listaA=(*listaA)->siguiente; ///Avanzo en lista A
        }
        else
        {
            aux=*listaB;

            *listaB=(*listaB)->siguiente; ///Avanzo en lista B
        }

        aux->siguiente=NULL; ///Desvinculo el nodo

        agregarFinal(listaC,aux); ///Agrego al final de la lista C
    }

    if(*listaA!=NULL) ///Vacio la lista que quedo con datos
    {
        agregarFinal(listaC, *listaA);
    }
    else
    {
        agregarFinal(listaC, *listaB);
    }
    inicLista(listaA);
    inicLista(listaB);
}

///06 Invertir los elementos de una lista redireccionando solamente los punteros. (No se deben crear nuevos nodos)

void invertirLista(nodo ** pLista)
{
    nodo * aux;

    while(*pLista!=NULL)
    {
        aux=desvincularPrimerNodo(pLista);

        agregarPpio(pLista, aux);
    }
}
