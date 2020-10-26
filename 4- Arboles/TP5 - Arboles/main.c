#include <stdio.h>
#include <stdlib.h>

#include "listaEnlazada.h"

typedef struct nodoArbol
{
    persona dato;
    struct nodoArbol * izq;
    struct nodoArbol * der;
} nodoArbol;

int main()
{

    nodo *listita;
    inicLista(&listita);

    return 0;
}

void mostrarPersona(persona dato)
{
    printf("---------------\n");
    printf("LEGAJO: %d\n", dato.legajo);
    printf("NOMBRE: %s\n", dato.nombre);
    printf("  EDAD: %d", dato.edad);
    printf("\n---------------\n");
}

void inicArbol(nodoArbol **arbolito)
{
    *arbolito=NULL;
}

nodoArbol* crearNodoArbol(persona dato)
{
    nodoArbol *aux= (nodoArbol *) malloc(sizeof(nodoArbol));

    aux->dato=dato;
    aux->der=NULL;
    aux->izq=NULL;

    return aux;
}

///01 Hacer una función que permita ingresar nuevos nodos manteniendo el árbol ordenado (por legajo).
////////////////////////////////////////////////
nodoArbol* insertar(nodoArbol *arbolito, persona dato)
{
    if(!arbolito)
    {
        arbolito=crearNodoArbol(dato);
    }
    else
    {
        if(dato.legajo > arbolito->dato.legajo)
        {
            arbolito->der=insertar(arbolito->der, dato);
        }
        else if(dato.legajo < arbolito->dato.legajo)
        {
            arbolito->izq=insertar(arbolito->izq, dato);
        }
    }

    return arbolito;
}

///02 Hacer tres funciones, una función que recorra el árbol y muestre su contenido en orden.
////////////////////////////////////////////////
void preorder(nodoArbol *arbolito)
{
    if(arbolito)
    {
        mostrarPersona(arbolito->dato);
        preorder(arbolito->izq);
        preorder(arbolito->der);
    }

}

void inorder(nodoArbol *arbolito)
{
    if(arbolito)
    {
        inorder(arbolito->izq);
        mostrarPersona(arbolito->dato);
        inorder(arbolito->der);
    }
}

void postorder(nodoArbol *arbolito)
{
    if(arbolito)
    {
        postorder(arbolito->izq);
        postorder(arbolito->der);
        mostrarPersona(arbolito->dato);
    }
}

///03 Hacer una función que copie el contenido del árbol en una lista vinculada.
////////////////////////////////////////////////
nodo *arbolToLista(nodoArbol* arbolito, nodo *lista)
{
    nodo *aux=NULL;

    if(arbolito)
    {
        lista=arbolToLista(arbolito->izq, lista);

        aux=crearNodo(arbolito->dato);

        agregarPpio(&lista, aux);

        lista=arbolToLista(arbolito->der, lista);
    }

    return lista;
}


///04 Hacer una función que busque un nodo por legajo y lo retorne.
////////////////////////////////////////////////

nodoArbol *buscar(nodoArbol *arbolito, int legajo)
{
    nodoArbol *rta=NULL;

    if(arbolito)
    {
        if(legajo == arbolito->dato.legajo)
        {
            rta=arbolito;
        }
        else
        {
            if(legajo > arbolito->dato.legajo)
            {
                rta=buscar(arbolito->der, legajo);
            }
            else
            {
                rta=buscar(arbolito->izq, legajo);
            }
        }
    }

    return rta;
}

///05 Hacer una función que busque un nodo por nombre. Cuidado, el árbol está ordenado por legajo.
////////////////////////////////////////////////
nodoArbol *buscarNombre(nodoArbol *arbolito, char nombre[])
{
    nodoArbol *buscado=NULL;

    if(arbolito)
    {
        if(strcmpi(nombre, arbolito->dato.nombre)==0) //proceso raiz
        {
            buscado=arbolito;
        }
        else
        {
            buscado=buscarNombre(arbolito->izq, nombre); //me voy por izquierda

            if(!buscado) //si no lo encontre por izquierda...
            {
                buscado=buscarNombre(arbolito->der, nombre); //me voy por derecha
            }
        }
    }

    return buscado;
}

///06 Hacer una función que calcule la altura que tiene el árbol.
////////////////////////////////////////////////



///07 Hacer una función que calcule la cantidad de nodos del árbol.
////////////////////////////////////////////////
int cantidadDeNodos(nodoArbol *arbolito)
{
    int cant;

    if(!arbolito)
    {
        cant=0;
    }
    else
    {
        cant= 1 + cantidadDeNodos(arbolito->izq) + cantidadDeNodos(arbolito->der);
    }

    return cant;
}

///Filtrado
int cantidadDeNodosFiltrado(nodoArbol *arbolito)
{
    int cant;

    if(!arbolito)
    {
        cant=0;
    }
    else
    {
        if(arbolito->dato.edad > 18)
        {
            cant= 1 + cantidadDeNodosFiltrado(arbolito->izq) + cantidadDeNodos(arbolito->der);
        }
        else
        {
            cant= cantidadDeNodosFiltrado(arbolito->izq) + cantidadDeNodos(arbolito->der);
        }
    }

    return cant;
}

///08 Hacer una función que calcule la cantidad de hojas del árbol.
////////////////////////////////////////////////
int cuentaHojas(nodoArbol *arbolito)
{
    int rta;

    if(!arbolito)
    {
        rta=0;
    }
    else
    {
        if(!arbolito->izq && !arbolito->der)
        {
            rta=1;
        }
        else
        {
            rta=cuentaHojas(arbolito->izq) + cuentaHojas(arbolito->der);
        }
    }

    return rta;
}


///09 Hacer una función que borre un nodo de un árbol.
////////////////////////////////////////////////




///Sumar Arbol
////////////////////////////////////////////////
int sumaRecursivaArbol(nodoArbol *arbolito)
{
    int suma;

    if(!arbolito)
    {
        suma=0;
    }
    else
    {
        if(!arbolito->izq && !arbolito->der)
        {
            suma=arbolito->dato.edad;
        }
        else
        {
            suma=arbolito->dato.edad + sumaRecursivaArbol(arbolito->izq) + sumaRecursivaArbol(arbolito->der);
        }
    }

    return suma;
}

///Sumar Arbol Filtrado
////////////////////////////////////////////////
int sumaRecursivaArbolPares(nodoArbol *arbolito)
{
    int suma;

    if(!arbolito)
    {
        suma=0;
    }
    else
    {
        if(arbolito->dato.edad%2 == 0)
        {
            suma=arbolito->dato.edad + sumaRecursivaArbolPares(arbolito->izq) + sumaRecursivaArbolPares(arbolito->der);
        }
        else
        {
            suma=sumaRecursivaArbolPares(arbolito->izq) + sumaRecursivaArbolPares(arbolito->der);
        }
    }

    return suma;
}

