#include "ListaDeArboles.h"

///INICIALIZAR ADA
void inicLDAPersonas(nodoLDA **LDAPersonas)
{
    *LDAPersonas=NULL;
}

///CREAR NODO LDA
nodoLDA *crearNodoLDAPersonas(char nombrePersona[])
{
    nodoLDA *nuevaPersona = (nodoLDA*)malloc(sizeof(nodoLDA));

    strcpy(nuevaPersona->nombrePersona, nombrePersona);

    nuevaPersona->sig=NULL;
    inicArbol(&nuevaPersona->arbol);

    return nuevaPersona;
}

///AGREGAR PPIO LDA
void agregarPPioLDAPersonas(nodoLDA **LDAPersonas, nodoLDA *nuevaPersona)
{
    if(!*LDAPersonas)
    {
        *LDAPersonas=nuevaPersona;
    }
    else
    {
        nuevaPersona->sig=*LDAPersonas;
        *LDAPersonas=nuevaPersona;
    }
}

///ALTA DE LDA
void altaLDAPersonas(nodoLDA **LDAPersonas, registroArchivo archivoPersona)
{
    stLibro nuevoLibro;

    nuevoLibro.cantPaginas=archivoPersona.cantPaginas;
    strcpy(nuevoLibro.genero,archivoPersona.genero);
    strcpy(nuevoLibro.nombreLibro, archivoPersona.nombreLibro);
    nuevoLibro.Puntaje=archivoPersona.Puntaje;

    nodoLDA *personaBuscada = buscarPersonas(*LDAPersonas, archivoPersona.NombrePersona);

    if(personaBuscada)
    {
        personaBuscada->arbol=insertarArbolOrdenado(personaBuscada->arbol, nuevoLibro);
    }
    else
    {
        agregarPPioLDAPersonas(LDAPersonas, crearNodoLDAPersonas(archivoPersona.NombrePersona));
        (*LDAPersonas)->arbol=insertarArbolOrdenado((*LDAPersonas)->arbol,nuevoLibro);
    }
}

///BUSCAR EN LDA
nodoLDA *buscarPersonas(nodoLDA *LDAPersonas, char nombrePersona[])
{
    nodoLDA *buscado=NULL;
    nodoLDA *seg=LDAPersonas;
    int flag=0;

    while(seg && flag==0)
    {
        if(strcmpi(seg->nombrePersona, nombrePersona)==0)
        {
            buscado=seg;
            flag=1;
        }

        seg=seg->sig;
    }

    return buscado;
}

///MOSTRAR LDA
void mostrarLDAPersonas(nodoLDA *LDAPersonas)
{
    while(LDAPersonas)
    {
        printf("\nNombre: %s\n", LDAPersonas->nombrePersona);

        printf("\nLibros:");

        if(LDAPersonas->arbol)
        {
            preorder(LDAPersonas->arbol);
        }

        LDAPersonas=LDAPersonas->sig;
    }
}

