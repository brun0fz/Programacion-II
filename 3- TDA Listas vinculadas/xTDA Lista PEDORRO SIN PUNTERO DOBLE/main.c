#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <conio.h>

#include "listaEnlazada.h"

////////////////////////////////////////////////////////

nodo *SubProgramaAgregarNodosPpio(nodo *lista);
nodo *SubProgramaAgregarNodosFinal(nodo *lista);
void subprogramaBusqeudaDeUnNodo(nodo *lista);
nodo *subprogramaBorrarUnNodo(nodo *lista);
nodo *subprogramaCrearListaOrdenada(nodo *lista);
int SubProgramaSumarEdades(nodo *lista);

///TP 4.1
///01
nodo *subProgramaAgregarPersona(nodo *lista, persona p);
nodo *InsertarDesdeArchivo(char fileName[], nodo* lista);
///02
nodo *subProgramaAgregarPersonaOrd(nodo *lista, persona p);
nodo *InsertarDesdeArchivoOrd(char fileName[], nodo* lista);
///03
int BuscarEnLista(nodo *lista, char nombre[]);
///04
nodo *intercalarEnOrden(nodo *listaA, nodo* listaB, nodo *listaC);


////////////////////////////////////////////////////////

int main()
{

////////////////////////////////////////////////////////

    char opcion;
    char nombre[20];
    int flag;

    nodo *listaA=inicLista();
    nodo *listaB=inicLista();
    nodo *listaC=inicLista();

////////////////////////////////////////////////////////

    do
    {

        system("cls");

        printf("MENU:\n\n");

        printf("1. Leer de un archivo datos e insertar en una lista.\n");
        printf("2. Leer de un archivo datos e insertar en una lista de forma ordenada.\n");
        printf("3. Ver si existe un elemento determinado en una lista dada.\n");
        printf("4. \n");

        printf("\nESC. SALIR\n");

        printf("\nIngrese el numero de opcion que desea seleccionar.\n\n");

        fflush(stdin);
        opcion=getch();

        switch(opcion)
        {

        case 49:
            system("cls");

            listaA=InsertarDesdeArchivo("personas.dat", listaA);
            recorrerYmostrar(listaA);

            system("pause");
            break;

        case 50:
            system("cls");

            listaA=InsertarDesdeArchivoOrd("personas.dat", listaA);
            recorrerYmostrar(listaA);

            system("pause");

            break;

        case 51:
            system("cls");


            printf("Ingrese el nombre a buscar: ");
            gets(nombre);

            flag=BuscarEnLista(listaA, nombre);

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
            listaA=subprogramaCrearListaOrdenada(listaA);

            system("cls");

            printf("\nCargue la segunda lista lista:\n");
            listaB=subprogramaCrearListaOrdenada(listaB);

            system("cls");

            listaC=intercalarEnOrden(listaA,listaB,listaC);

            printf("\nTercer lista ordenada con los elementos de la primera y la segunda lista:\n");
            recorrerYmostrar(listaC);

            listaA=inicLista();
            listaB=inicLista();

            system("pause");
            break;

        case 53:

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

////////////////////////////////////////////////////////

nodo *SubProgramaAgregarNodosPpio(nodo *lista)
{
    char com='s';

    while(com=='s')
    {
        lista=agregarPpio(lista, crearNodo(cargarPersona()));
        fflush(stdin);
        printf("\nDesea cargar otra persona? [s/n]: ");
        scanf("%c", &com);
    }
    return lista;
}

////////////////////////////////////////////////////////

nodo *SubProgramaAgregarNodosFinal(nodo *lista)
{
    char com='s';

    while(com=='s')
    {
        lista=agregarFinal(lista, crearNodo(cargarPersona()));
        fflush(stdin);
        printf("\nDesea cargar otra persona? [s/n]: ");
        scanf("%c", &com);
    }
    return lista;
}

////////////////////////////////////////////////////////

void subprogramaBusqeudaDeUnNodo(nodo *lista)
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

////////////////////////////////////////////////////////

nodo *subprogramaBorrarUnNodo(nodo *lista)
{
    char nombre[20];

    printf("Ingrese nombre a eliminar: ");
    fflush(stdin);
    gets(nombre);

    lista=buscarNodo(lista, nombre);

    return lista;
}

////////////////////////////////////////////////////////

nodo *subprogramaCrearListaOrdenada(nodo *lista)
{
    char com='s';

    while(com=='s')
    {
        lista=agregarEnOrden(lista, crearNodo(cargarPersona()));
        fflush(stdin);
        printf("\nDesea cargar otra persona? [s/n]: ");
        scanf("%c", &com);
    }

    return lista;
}

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

nodo *subProgramaAgregarPersona(nodo *lista, persona p)
{
    lista=agregarPpio(lista, crearNodo(p));

    return lista;

}


nodo *InsertarDesdeArchivo(char fileName[], nodo* lista)
{
    FILE *buffer = fopen(fileName, "rb");

    persona aux;

    if(buffer)
    {
        while(fread(&aux, sizeof(persona), 1, buffer)>0)
        {
            lista=subProgramaAgregarPersona(lista, aux);
        }
        fclose(buffer);
    }

    return lista;
}

///02 - Hacer un programa que lea de un archivo datos y los inserte en una lista en forma ordenada.

nodo *subProgramaAgregarPersonaOrd(nodo *lista, persona p)
{
    lista=agregarEnOrden(lista, crearNodo(p));

    return lista;

}

nodo *InsertarDesdeArchivoOrd(char fileName[], nodo* lista)
{
    FILE *buffer = fopen(fileName, "rb");

    persona aux;

    if(buffer)
    {
        while(fread(&aux, sizeof(persona), 1, buffer)>0)
        {
            lista=subProgramaAgregarPersonaOrd(lista, aux);
        }
        fclose(buffer);
    }

    return lista;
}

///03 - Hacer una función que retorne un 1 (uno) o 0 (cero) si existe un determinado elemento en una lista dada.

int BuscarEnLista(nodo *lista, char nombre[])
{
    nodo *nodobuscado;
    int flag;

    nodobuscado=buscarNodo(lista, nombre);

    if(nodobuscado)
    {
        flag=1;
    }
    else
    {
        flag=0;
    }

    return flag;
}

///04 - Hacer una función que intercale en orden los elementos de dos listas ordenadas generando una nueva lista.
///     Se deben redireccionar los punteros, no se deben crear nuevos nodos.

nodo *intercalarEnOrden(nodo *listaA, nodo* listaB, nodo *listaC)
{
    nodo *aux;

    while((listaA!=NULL) && (listaB!=NULL))
    {
        if(listaA->dato.edad < listaB->dato.edad)
        {
            aux=listaA;

            listaA=listaA->siguiente; ///Avanzo en lista A
        }
        else
        {
            aux=listaB;

            listaB=listaB->siguiente; ///Avanzo en lista B
        }

        aux->siguiente=NULL; ///Desvinculo el nodo

        listaC=agregarFinal(listaC,aux); ///Agrego al final de la lista C
    }

    if(listaA!=NULL) ///Vacio la lista que quedo con datos
    {
        listaC=agregarFinal(listaC, listaA);
    }
    else
    {
        listaC=agregarFinal(listaC, listaB);
    }

    return listaC;
}

void desvincularPrimero(nodo **pLista)
{
    nodo *primero=NULL;

    if(*pLista)
    {
        primero=*pLista;

        *pLista=(*pLista)->siguiente;

        primero->siguiente=NULL;
    }
}
