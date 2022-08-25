#include "arboles.h"

///Estructura de un arbol
typedef struct nodoArbol
{
    persona dato;
    struct nodoArbol * izq;
    struct nodoArbol * der;
} nodoArbol;

///INICIALIZAR ARBOL
void inicArbol(nodoArbol **arbolito)
{
    *arbolito=NULL;
}

///CREAR NODO ARBOL
nodoArbol* crearNodoArbol(persona dato)
{
    nodoArbol *aux=(nodoArbol *)malloc(sizeof(nodoArbol));

    aux->dato=dato;

    aux->der=NULL;
    aux->izq=NULL;

    return aux;
}

///INSERTAR EN ARBOL ORNEDANO (No inserta nodos iguales)
////////////////////////////////////////////////
nodoArbol* insertarArbolOrdenado(nodoArbol *arbolito, persona dato)
{
    if(!arbolito) //si el arbol es NULL lo inserta, el arbol puede estar vacio o encontro donde va el dato a insertar en la etapa recursiva correspondiente
    {
        arbolito=crearNodoArbol(dato);
    }
    else
    {
        if(dato.legajo < arbolito->dato.legajo) //si el dato es menor se va por la izquierda
        {
            arbolito->izq=insertarArbolOrdenado(arbolito->izq, dato);
        }
        else if(dato.legajo > arbolito->dato.legajo) //si el dato es mayor se va por derecha
        {
            arbolito->der=insertarArbolOrdenado(arbolito->der, dato);
        }
    }

    return arbolito;
}

///MOSTRAR POR PREORDER R - I - D
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

///MOSTRAR POR INORDER I - R - D
////////////////////////////////////////////////
void inorder(nodoArbol *arbolito)
{
    if(arbolito)
    {
        inorder(arbolito->izq);
        mostrarPersona(arbolito->dato);
        inorder(arbolito->der);
    }
}

///MOSTRAR POR POSTORDER I - D - R
////////////////////////////////////////////////
void postorder(nodoArbol *arbolito)
{
    if(arbolito)
    {
        postorder(arbolito->izq);
        postorder(arbolito->der);
        mostrarPersona(arbolito->dato);
    }
}

///PASAR DE ARBOL A LISTA
////////////////////////////////////////////////
nodo *arbolToLista(nodoArbol* arbolito, nodo *lista)
{
    nodo *aux=NULL;

    if(arbolito)
    {
        aux=crearNodo(arbolito->dato);

        agregarPpio(&lista, aux);

        lista=arbolToLista(arbolito->izq, lista);

        lista=arbolToLista(arbolito->der, lista);
    }

    return lista;
}

///PASAR DE ARBOL A LISTA FILTRADO
////////////////////////////////////////////////
nodo *arbolToListaFiltrado(nodoArbol* arbolito, nodo *lista)
{
    nodo *aux=NULL;

    if(arbolito)
    {
        if(arbolito->dato.edad>18)
        {
            aux=crearNodo(arbolito->dato);

            agregarPpio(&lista, aux);
        }

        lista=arbolToLista(arbolito->izq, lista);

        lista=arbolToLista(arbolito->der, lista);
    }

    return lista;
}

///PASAR DE ARBOL A LISTA FILTRADO
////////////////////////////////////////////////
void arbolToListaFiltrado(nodoArbol* arbolito, FILE *buffer)
{
    if(arbolito)
    {

        frwite(&arbolito->dato, sizeof(estructura), 1, buffer)

        arbolToLista(arbolito->izq);

        arbolToLista(arbolito->der);
    }
}

///PASAR DE ARBOL Al ARREGLO
////////////////////////////////////////////////
int arbolToArreglo(nodoArbol* arbolito, persona aPersona[], int i, int dim)
{
    if(arbolito && i<dim)
    {
        aPersona[i]=arbolito->dato;

        i=arbolToArreglo(arbolito->izq, aPersona, i+1, dim);

        i=arbolToArreglo(arbolito->der, aPersona, i+1, dim);
    }

    return i;
}


///BUSCAR NODO Y RETORNARLO
////////////////////////////////////////////////
nodoArbol *buscarNodoArbol(nodoArbol *arbolito, int legajo)
{
    nodoArbol *encontrado=NULL;

    if(arbolito) //trabaja si hay arbol, sino retorna NULL
    {
        if(legajo == arbolito->dato.legajo) //si la raiz es igual al dato, retorna la raiz
        {
            encontrado=arbolito;
        }
        else //si el primer nodo no es igual..
        {
            if(legajo > arbolito->dato.legajo) //si mi dato es mayor que la raiz, se va por la derecha
            {
                encontrado=buscarNodoArbol(arbolito->der, legajo); //se iguala a "encontrado" porque el dato tiene que ir volviendo a la primer etapa recursiva
            }
            else //si mi dato es menor que la raiz, se va por la izquierda
            {
                encontrado=buscarNodoArbol(arbolito->izq, legajo);
            }
        }
    }

    return encontrado;
}

///Hacer una función que busque un nodo por nombre. Cuidado, el árbol está ordenado por legajo.
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

///CALCULAR ALTURA DEL ARBOL
////////////////////////////////////////////////
int mayor (int izquierdo, int derecho)
{
    int rta =0;
    if (izquierdo>derecho)
    {
        rta = izquierdo;
    }
    else
    {
        rta=derecho;
    }
    return rta;
}

int alturaDelArbol(nodoArbol* arbol)
{
    int resp;

    if(!arbol)
    {
        resp=0;
    }
    else
    {
        if(!arbol->izq && !arbol->der)
        {
            resp=1;
        }
        else
        {
            resp=1 + mayor(alturaDelArbol(arbol->izq), alturaDelArbol(arbol->der));
        }
    }
    return resp;
}

///CONTAR NODOS DEL ARBOL
////////////////////////////////////////////////
int contarNodos(nodoArbol *arbolito)
{
    int cant;

    if(!arbolito)
    {
        cant=0;
    }
    else
    {
        cant= 1 + contarNodos(arbolito->izq) + contarNodos(arbolito->der);
    }

    return cant;
}

///CONTAR NODOS DEL ARBOL FILTRADO
////////////////////////////////////////////////
int contarNodosFiltrado(nodoArbol *arbolito)
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
            cant= 1 + contarNodosFiltrado(arbolito->izq) + contarNodosFiltrado(arbolito->der);
        }
        else
        {
            cant= contarNodosFiltrado(arbolito->izq) + contarNodosFiltrado(arbolito->der);
        }
    }

    return cant;
}

///CONTAR HOJAS DEL ARBOL
////////////////////////////////////////////////
int contarHojas(nodoArbol *arbolito)
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
            rta=contarHojas(arbolito->izq) + contarHojas(arbolito->der);
        }
    }

    return rta;
}


///BORRAR NODO DE UN ARBOL
////////////////////////////////////////////////
nodoArbol *nodoMasDerecha(nodoArbol *arbol)
{
    nodoArbol *aux;

    if(arbol->der==NULL)
    {
        aux=arbol;
    }
    else
    {
        aux=nodoMasDerecha(arbol->der);
    }

    return aux;
}

nodoArbol *nodoMasIzquierda(nodoArbol *arbol)
{
    nodoArbol *aux;

    if(arbol->izq==NULL)
    {
        aux=arbol;
    }
    else
    {
        aux=nodoMasIzquierda(arbol->izq);
    }
    return aux;
}

nodoArbol *borrarNodoArbol(nodoArbol *arbol, int dato)
{
    if(arbol)
    {
        if (dato == arbol->dato)//en caso de que sea igual
        {
            if(arbol->izq)
            {
                nodoArbol *masDer=nodoMasDerecha(arbol->izq);
                arbol->dato=masDer->dato;
                arbol->izq=borrarNodoArbol(arbol->izq, masDer->dato);
            }
            else if(arbol->der)
            {
                nodoArbol *masIzq=nodoMasIzquierda(arbol->der);
                arbol->dato=masIzq->dato;
                arbol->der=borrarNodoArbol(arbol->der, masIzq->dato);
            }
            else //si el dato es una hoja
            {
                free(arbol);
                arbol=NULL;
            }
        }
        else if(dato>arbol->dato.legajo) //si el dato es mayor que el primer dato, se va por derecha
        {
            arbol->der=borrarNodoArbol(arbol->der,dato);
        }
        else//sino se va por izquierda
        {
            arbol->izq=borrarNodoArbol(arbol->izq, dato);
        }
    }

    return arbol;
}

///SUMAR ARBOL
////////////////////////////////////////////////
int sumarArbol(nodoArbol *arbolito)
{
    int suma;

    if(!arbolito) //si no hay arbol
    {
        suma=0; //la suma es igual a 0
    }
    else //si hay arbol
    {
        suma=arbolito->dato.edad + sumarArbol(arbolito->izq) + sumarArbol(arbolito->der);
    }

    return suma;
}

///SUMAR ARBOL
////////////////////////////////////////////////
int sumarArbolFiltrado(nodoArbol *arbolito)
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
            suma=arbolito->dato.edad + sumarArbolFiltrado(arbolito->izq) + sumarArbolFiltrado(arbolito->der);
        }
        else
        {
            suma=sumarArbolFiltrado(arbolito->izq) + sumarArbolFiltrado(arbolito->der);
        }
    }

    return suma;
}

///BUSCAR MENOR ARBOL
nodoArbol *buscarMenorArbol(nodoArbol *arbol)
{
    nodoArbol *menor;

    if(arbol)
    {
        if(!arbol->der && !arbol->izq)
        {
            menor=arbol;
        }
        else
        {
            nodoArbol *izquierda=buscarMenorArbol(arbol->izq);

            nodoArbol *derecha=buscarMenorArbol(arbol->der);

            if(izquierda->dato.edad < derecha->dato.edad)
            {
                menor=izquierda;
            }
            else
            {
                menor=derecha;
            }
        }
    }

    return menor;
}

///arreglo to arbol
nodoArbolUsuario* pasarDeArregloToArbolUsuario(nodoArbolUsuario *arbolUsuario, stUsuario arregloUsuario[], int ini, int fin)
{
    int medio;

    if(ini <= fin)
    {
        medio=(ini+fin)/2;

        arbolUsuario=insertarArbolUsuario(arbolUsuario, arregloUsuario[medio]);

        arbolUsuario=pasarDeArregloToArbolUsuario(arbolUsuario, arregloUsuario, ini, medio-1);
        arbolUsuario=pasarDeArregloToArbolUsuario(arbolUsuario, arregloUsuario, medio+1, fin);
    }

    return arbolUsuario;
}
