///Estructura lista doblemente enlazada
typedef struct _nodoDoble
{
    int dato;
    struct _nodoDoble *siguiente;
    struct _nodoDoble *anterior;

}nodoDoble;

///INICIALIZAR LISTA
////////////////////////////////////////////////////////

void inicListaDoble(nodoDoble **listaDoble)
{
    *listaDoble=NULL;
}

///CREAR NODO DOBLE
////////////////////////////////////////////////////////
nodoDoble *crearNodoDoble(estrutura dato)
{
    nodoDoble *nuevo = (nodoDoble*)malloc(sizeof(nodoDoble));
    nuevo->dato=dato;
    nuevo->siguiente=NULL;

    nuevo->anterior=NULL; //Diferencia con lista simple

    return nuevo;
}

///MOSTRAR UN NODO DOBLE
////////////////////////////////////////////////////////
void mostrarUnNodoDoble(nodoDoble *listaDoble)
{
    mostrarUnaEstructura(listaDoble->dato);
}

///RECORRER Y MOSTRAR LA LISTA COMPLETA
////////////////////////////////////////////////////////
void mostrarListaDoble(nodoDoble *listaDoble)
{
    nodoDoble *seg=listaDoble;

    while(seg!=NULL)
    {
        mostrarUnNodoDoble(seg);
        seg=seg->siguiente;
    }
}

///AGREGAR NODO DOBLE AL PRINCIPIO
////////////////////////////////////////////////////////
void agregarPpioDoble(nodoDoble **listaDoble, nodoDoble *nuevo)
{
    //Si la lista esta vacia, lista apunta a nuevo nodo
    if(*listaDoble==NULL)
    {
        *listaDoble=nuevo;
    }
    else
    {
        nuevo->siguiente=*listaDoble; //el nuevo nodo ahora apunta al primero por siguiente

        (*listaDoble)->anterior=nuevo; //el nodo que estaba apunta al nuevo por anterior

        *listaDoble=nuevo; //la lista ahora apunta al nuevo
    }
}

///BUSCAR ULTIMO NODO DOBLE
////////////////////////////////////////////////////////
nodoDoble *buscarUltimoDoble(nodoDoble *listaDoble)
{
    nodoDoble *ultimo=listaDoble;

    if(ultimo!=NULL)
    {
        while(ultimo->siguiente !=NULL)
        {
            ultimo=ultimo->siguiente;
        }
    }
    return ultimo;
}

///AGREGAR NODO DOBLE AL FINAL (UTILIZA BUSCAR ULTIMO)
////////////////////////////////////////////////////////
void agregarFinalDoble(nodoDoble **listaDoble, nodoDoble *nuevo)
{
    nodoDoble *ultimo;

    if(*listaDoble==NULL)
    {
        *listaDoble=nuevo;
    }
    else
    {
        ultimo=buscarUltimoDoble(*listaDoble);

        ultimo->siguiente=nuevo; //Enlaza el ultimo nodo con el nuevo

        nuevo->anterior=ultimo; //Enlaza el nuevo con el anteultimo
    }

}

///AGREGAR NODO DOBLE EN ORDEN
////////////////////////////////////////////////////////
void agregarEnOrdenDoble(nodoDoble **listaDoble, nodoDoble *nuevo)
{
    if(*listaDoble==NULL)//Caso 1: Si la lista esta vacia, se enlaza con el nuevo dato
    {
        *listaDoble=nuevo;
    }
    else
    {

        if(strcmpi(nuevo->dato.planeta, (*listaDoble)->dato.planeta)<0) //Caso  2: Si el dato a insertar es menor que el primer dato, lo agregamos al principio
        {
            agregarPpioDoble(listaDoble, nuevo);
        }
        else
        {
            nodoDoble *seg = (*listaDoble)->siguiente;//bajamos la lista a una variable auxiliar para no modificarla

            while(seg!=NULL && strcmpi(nuevo->dato.planeta, seg->dato.planeta)>0)//Buscamos el dato mientras que la lista no este vacia o el dato a insertar sea mayor que el de la lista
            {
                seg=seg->siguiente;
            }

            if(seg!=NULL) //Caso 3: El dato va entre medio de dos nodos, verificamos que no nos hayamos caido de la lista
            {
                nodoDoble *ante=seg->anterior; //bajamos el nodo anterior a una variable

                ante->siguiente=nuevo; //ante siguiente se enalza con el nuevo nodo

                nuevo->anterior=ante; //el nuevo nodo por anterior se enlaza con ante

                nuevo->siguiente=seg; //nuevo nodo siguiente se enlaza con seg que es el nodo actual

                seg->anterior=nuevo; //seg por anterior se enlaza al nodo nuevo
            }
            else //caso 4: si no encontramos el hueco para ubicar el dato, quiere decir que nos caimos de la lista y el nuevo dato se inserta al final
            {
                agregarFinalDoble(listaDoble, nuevo);
            }
        }
    }
}

///BUSCAR NODO DOBLE
////////////////////////////////////////////////////////
nodoDoble *buscarNodoDoble(nodoDoble **pListaDoble, char nombre[])
{
    nodoDoble *seg=*pListaDoble;

    while(seg !=NULL && strcmpi(seg->dato.nombre,nombre)!=0)
    {
        seg=seg->siguiente;
    }
    return seg;
}

///BORRAR NODO DOBLE
/////////////////////////////////////////////////////////
void borrarNodoDoble(nodoDoble **pListaDoble, char nombre[])
{
    nodoDoble *seg=NULL;

    if(*pListaDoble!=NULL)
    {
        if(strcmpi((*pListaDoble)->dato.nombre,nombre)==0) //Si el nodo a borrar es el primero, bajamos el nodo a una variable, salteamos el nodo y lo borramos
        {
            nodoDoble *aBorrar=*pListaDoble;

            *pListaDoble=(*pListaDoble)->siguiente;

            if(*pListaDoble!=NULL) //si la lista quedo con al menos un dato, tenemos que enlazar por anterior a NULL
            {
                (*pListaDoble)->anterior=NULL;
            }

            free(aBorrar);
        }
        else
        {
            seg=(*pListaDoble)->siguiente;//bajamos la variable a una auxiliar para no modificar la lista

            while((seg !=NULL) && strcmpi(seg->dato.nombre, nombre)!=0) //recorremos la lista mientra que no este vacia y el dato sea distinto
            {
                seg=seg->siguiente;
            }

            if(seg!=NULL)//si encontramos el dato a borrar
            {
                nodoDoble *ante = seg->anterior; //bajamos el nodo anterior a una variable

                ante->siguiente = seg->siguiente; // salteamos el nodo a aborrar

                if(seg->siguiente != NULL)
                {
                    nodoDoble *proximo = seg->siguiente;
                    proximo->anterior=ante;
                }

                free(seg);
            }
        }
    }
}

///BORRAR PRIMER NODO DOBLE
////////////////////////////////////////////////////////
void borrarPrimerNodoDoble(nodoDoble **pListaDoble)
{
    if(*pListaDoble!=NULL)
    {
        nodoDoble *aBorrar=*pListaDoble;

        *pListaDoble=(*pListaDoble)->siguiente;

        if(*pListaDoble!=NULL)
        {
            (*pListaDoble)->anterior=NULL;
        }

        free(aBorrar);
    }
}

///BORRAR ULTIMO NODO DOBLE
////////////////////////////////////////////////////////
void borrarUltimoNodoDoble(nodoDoble **pListaDoble)
{
    nodoDoble *seg=*pListaDoble;

    if(*pListaDoble !=NULL)
    {
        if(seg->siguiente==NULL)
        {
            *pListaDoble=NULL;
            free(seg);
        }
        else
        {
            while(seg->siguiente!=NULL)
            {
                seg=seg->siguiente;
            }
            nodoDoble *ante=seg->anterior;
            ante->siguiente=NULL;
            free(seg);
        }
    }

}

///DESVINCULAR Y RETORNAR PRIMER NODO DOBLE
////////////////////////////////////////////////////////
nodoDoble *desvincularPrimerNodoDoble(nodoDoble **pListaDoble)
{
    nodoDoble *aDesvincular=*pListaDoble;

    if(*pListaDoble!=NULL)
    {
        *pListaDoble=(*pListaDoble)->siguiente;

        aDesvincular->siguiente=NULL;

        if(*pListaDoble!=NULL)
        {
            (*pListaDoble)->anterior=NULL;
        }
    }

    return aDesvincular;
}

///DESVINCULAR NODO DOBLE POR PARAMETRO
/////////////////////////////////////////////////////////
void desvincularNodoDoble(nodoDoble **pListaDoble, char nombre[])
{
    nodoDoble *seg=NULL;
	nodoDoble *aDesvincular=NULL;

    if(*pListaDoble!=NULL)
    {
        if(strcmpi((*pListaDoble)->dato.nombre,nombre)==0) //Si el nodo a borrar es el primero, bajamos el nodo a una variable, salteamos el nodo y lo borramos
        {
            aDesvincular=*pListaDoble;

            *pListaDoble=(*pListaDoble)->siguiente;

			aDesvincular->siguiente=NULL;

            if(*pListaDoble!=NULL) //si la lista quedo con al menos un dato, tenemos que enlazar por anterior a NULL
            {
                (*pListaDoble)->anterior=NULL;
            }
        }
        else
        {
            seg=(*pListaDoble)->siguiente;//bajamos la variable a una auxiliar para no modificar la lista

            while((seg !=NULL) && strcmpi(seg->dato.nombre, nombre)!=0) //recorremos la lista mientra que no este vacia y el dato sea distinto
            {
                seg=seg->siguiente;
            }

            if(seg!=NULL)//si encontramos el dato a borrar
            {
                nodoDoble *ante = seg->anterior; //bajamos el nodo anterior a una variable

                ante->siguiente = seg->siguiente; // salteamos el nodo a aborrar

                if(seg->siguiente != NULL)
                {
                    nodoDoble *proximo = seg->siguiente;
                    proximo->anterior=ante;
                }
				
				aDesvincular=seg;

                aDesvincular->siguiente=NULL;
            }
        }
    }
	
	return aDesvincular;
}


///BORRAR TODA LA LISTA DOBLE
////////////////////////////////////////////////////////

void borrarTodaLaListaDoble(nodoDoble **pLista)
{
    nodoDoble *aux;

    //Se va recorriendo y borrando mientras que la lista no este vacia
    while(*pLista!=NULL)
    {
        //guardo el nodo siguiente al que se va a borrar
        aux = (*pLista)->siguiente;

        //borro el nodo
        free(*pLista);

        //actualizo la lista con el siguiente
        *pLista=aux;
    }
}