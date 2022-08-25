#include "LDLTrenes.h"

///ARCHIVO TO LDL
void pasarArchivoToLDL(nodoTren **LDLTrenes)
{
    FILE *buffer = fopen("arCajones.bin", "rb");
    Cajon aux;

    if(buffer)
    {
        while(fread(&aux, sizeof(Cajon), 1, buffer)>0)
        {
            altaLDLTrenesFiltrado(LDLTrenes, aux.categoria, aux.peso);
        }

        fclose(buffer);
    }
}

///INIC LDL
void inicLDLTrenes(nodoTren **LDLTrenes)
{
    *LDLTrenes=NULL;
}

///CREAR NODO LDL
nodoTren *crearNodoLDLTrenes(int nroTren, char categoria[])
{
    nodoTren *nuevoTren = (nodoTren*)malloc(sizeof(nodoTren));

    strcpy(nuevoTren->categoria, categoria);
    nuevoTren->nroTren=nroTren;

    nuevoTren->sig=NULL;
    inicListaVagones(&nuevoTren->listaVagones);

    return nuevoTren;
}

///AGREGAR AL PPIO LDL
void agregarPPioLDLTrenes(nodoTren **LDLTrenes, nodoTren *nuevoTren)
{
    if(!*LDLTrenes)
    {
        *LDLTrenes=nuevoTren;
    }
    else
    {
        nuevoTren->sig=*LDLTrenes;
        *LDLTrenes=nuevoTren;
    }
}

///ALTA LDL
void altaLDLTrenes(nodoTren **LDLTrenes, char categoriaCaja[], float pesoCaja)
{
    int nroTren=0;
    nodoTren *trenBuscado = buscarTrenes(*LDLTrenes, categoriaCaja);

    if(!trenBuscado)
    {
        vagon vag1;
        vag1.pesoIngresado=pesoCaja;

        agregarPPioLDLTrenes(LDLTrenes, crearNodoLDLTrenes(nroTren, categoriaCaja));
        agregarFinalListaVagones(&(*LDLTrenes)->listaVagones, crearNodoListaVagones(vag1));

    }
    else
    {
        vagon vag2;
        vag2.pesoIngresado=pesoCaja;
        agregarFinalListaVagones(&trenBuscado->listaVagones, crearNodoListaVagones(vag2));
    }
}

///BUSCAR SI EXISTE LA CELDA
nodoTren *buscarTrenes(nodoTren *LDLTrenes, char categoria[])
{
    nodoTren *buscado=NULL;
    nodoTren *seg=LDLTrenes;
    int flag=0;

    while(seg && flag==0)
    {
        if(strcmpi(seg->categoria, categoria)==0)
        {
            buscado=seg;
            flag=1;
        }

        seg=seg->sig;
    }

    return buscado;
}

///MOSTRAR LDL
void mostrarLDLTrens(nodoTren *LDLTrenes)
{
    while(LDLTrenes)
    {
        printf("\n  N. Tren: %d\n", LDLTrenes->nroTren);
        printf("Categoria: %s\n", LDLTrenes->categoria);

        printf("\nVagones:\n");

        if(LDLTrenes->listaVagones)
        {
            mostrarListaVagones(LDLTrenes->listaVagones);
        }

        LDLTrenes=LDLTrenes->sig;
    }
}


void mostrarPesoCategoria(nodoTren *LDLTrenes, char categoria[])
{
    float suma=sumarPesoCategoria(LDLTrenes, categoria);
    printf("Peso total de la categoria %s es: %g", categoria, suma);
}


float sumarPesoCategoria(nodoTren *LDLTrenes, char categoria[])
{
    nodoTren *seg=LDLTrenes;

    float suma=0;

    while(seg)
    {
        if(strcmpi(seg->categoria, categoria)==0)
        {

            suma+=sumarVagones(seg->listaVagones);
        }

        seg=seg->sig;
    }

    return suma;
}

float pesoTotalCategoria(nodoTren *LDLTrenes,char categoria[])
{
    nodoTren *seg=LDLTrenes;

    float pesoTotal=0;

    while(seg)
    {
        if(strcmpi(seg->categoria, categoria)==0)
        {
            pesoTotal+=1400;
        }

        seg=seg->sig;
    }

    return pesoTotal;
}

void porcentajeCargadoCategoria(nodoTren *LDLTrenes, char categoria[])
{
    float pesoParcial=sumarPesoCategoria(LDLTrenes, categoria);
    float pesoTotal=pesoTotalCategoria(LDLTrenes, categoria);

    float promedio=(pesoParcial/pesoTotal) *100;

    printf("\nPorcentaje cargado de la categoria %s: %%%g", categoria, promedio);
}

float trenMenorPeso(nodoTren *LDLTrenes,char categoria[])
{
    nodoTren *seg=LDLTrenes;

    float menor=0;

    while(seg)
    {
       sumarVagones(seg->listaVagones);

        seg=seg->sig;
    }

    return menor;
}

