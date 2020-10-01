#include "listaEnlazada.h"

///INICIALIZAR LA LISTA
////////////////////////////////////////////////////////

void inicLista(nodo **pLista)
{
    //Se asigna a la lista NULL porque no apunta a ningun nodo
    *pLista=NULL;
}

///CREAR UN NODO Y RETORNARLO
////////////////////////////////////////////////////////

nodo *crearNodo(persona dato)
{
    //Crear un puntero de tipo nodo
    nodo *nuevo = (nodo*)malloc(sizeof(nodo));

    //Se le asigna el nuevo dato
    nuevo->dato = dato;

    //Y como es un unico nodo el siguiente es NULL
    nuevo->siguiente = NULL;

    //Se retorna
    return nuevo;
}

///AGREGAR NODOS AL PRINCIPIO
////////////////////////////////////////////////////////

void agregarPpio(nodo **pLista, nodo *nuevoNodo)
{
    //Verificamos que la lista este vacia para agregar el nuevo nodo al principio
    if(*pLista == NULL)
    {
        *pLista = nuevoNodo;
    }
    else
    {
        //Se enlaza por siguiente el nodo que estaba al principio
        nuevoNodo->siguiente = *pLista;

        //Se le asigna a la lista el nuevo nodo para que se posicione al principio
        *pLista = nuevoNodo;
    }
}

///MOSTRAR UN NODO
////////////////////////////////////////////////////////

void mostrarNodo(nodo *aux)
{
    //printf("\n%p ---> Siguiente: %p\n", aux, aux->siguiente);
    mostrarPersona(aux->dato);
}

///MOSTRAR UNA LISTA
////////////////////////////////////////////////////////

void mostrarLista(nodo **pLista)
{
    nodo *seg = *pLista;
    while(seg !=NULL)
    {
        mostrarNodo(seg);
        seg=seg->siguiente;
    }
}

///BUSCAR ULTIMO
////////////////////////////////////////////////////////

nodo *buscarUltimo(nodo *pLista)
{
    //En caso de puntero doble se baja a otra variable para no modificar la lista
    nodo *seg=pLista;

    //Se trabaja si hay nodos en la lista
    if(seg!=NULL)
    {
        //se recorre la lista mientras que el nodo no apunte a NULL, cuando el nodo apunte a NULL corta porque es el ultimo nodo de la lista
        while(seg->siguiente !=NULL)
        {
            //Se recorre de esta manera
            seg=seg->siguiente;
        }
    }

    //Retornamos el ultimo nodo
    return seg;
}

///AGREGAR AL FINAL (UTILIZA BUSCAR ULTIMO)
////////////////////////////////////////////////////////

void agregarFinal(nodo **pLista, nodo *nuevonodo)
{
    //Si la lista esta vacia, el nodo se enlaza con la lista
    if(*pLista == NULL)
    {
        *pLista = nuevonodo;
    }
    else
    {
        //se busca al ultimo nodo
        nodo *ultimo=buscarUltimo(*pLista);

        //y se enlaza al ultimo nodo por siguiente al nuevo nodo.
        ultimo->siguiente=nuevonodo;
    }

}

///BUSCAR NODO
////////////////////////////////////////////////////////

nodo *buscarNodo(nodo **pLista, char nombre[])
{
    nodo *seg=*pLista;

    //Se recorre la lista mientras esta no este vacia, o el dato no coincida, cuando quede vacia o encontremos el dato, corta
    while((seg !=NULL) && (strcmp(nombre, seg->dato.nombre) !=0))
    {
        seg=seg->siguiente;
    }

    //Retornamos el nodo buscado
    return seg;
}

///BORRAR NODO
////////////////////////////////////////////////////////

void borrarNodo(nodo **pLista, char nombre[])
{
    //Se trabaja si la lista no esta vacia.
    if(*pLista!=NULL)
    {
        ///1.SI EL NODO ES EL PRIMERO: Se compara con el primer nodo de la lista, si es igual al dato a borrar, lo borra y termina.
        if((strcmp(nombre, (*pLista)->dato.nombre)==0))
        {
            //Se baja el nodo a una variable para no perder la direccion de memoria y poder borrarlo
            nodo *aBorrar=*pLista;

            //Se saltea ese nodo, ahora lista apunta al siguiente nodo
            *pLista=(*pLista)->siguiente;

            //Borramos el nodo deseado
            free(aBorrar);
        }
        ///2.SI EL NODO ESTA EN EL MEDIO O ES EL ULTIMO
        else
        {
            //bajamos la lista a una variable para no modificarla
            nodo *seg=*pLista;
            nodo *ante;

            //recorremos la lista mientras que no este vacia y el dato sea dinstino al que queremos borrar
            while((seg !=NULL) && (strcmp(nombre, seg->dato.nombre) !=0))
            {
                //se le asigna a ante el nodo actual
                ante=seg;

                //seg avanza un nodo
                seg=seg->siguiente;
            }

            //verificamos si encontramos el dato
            if(seg!=NULL)
            {
                //ante es el anterior del que queiro borrar y lo apunto al siguiente del que quiero borrar
                //Salteo el nodo que quiero eliminar
                ante->siguiente=seg->siguiente;

                //eliminamos el nodo seg==aborrar
                free(seg);
            }
        }
    }
}

///AGREGAR EN ORDEN
////////////////////////////////////////////////////////
void agregarEnOrden(nodo **pLista, nodo *nuevoNodo)
{
    //Si la lista esta vacia, el nodo se agrega al principio
    if(*pLista==NULL)
    {
        *pLista = nuevoNodo;
    }
    else
    {
        //si el nodo que queremos agregar es menor al primer nodo, lo agregamos al principio
        if(nuevoNodo->dato.edad < (*pLista)->dato.edad)
        {
            agregarPpio(pLista, nuevoNodo);
        }
        else
        {
            nodo *seg = (*pLista)->siguiente;
            nodo *ante = *pLista;

            //buscamos el lugar del dato que queremos insertar, se recorre la lista mientras esta no este vacia yy el dato a insertar sea mayor
            while(seg!=NULL && nuevoNodo->dato.edad > seg->dato.edad)
            {
                //guardamos el actual en una varaible
                ante=seg;

                //avanzamos en la lista
                seg=seg->siguiente;
            }

            //insertamos el nuevo nodo en el lugar indicado

            //el anterior apunta al nuevo nodo
            ante->siguiente = nuevoNodo;

            //el nuevo nodo apunta al siguiente
            nuevoNodo->siguiente = seg;
        }
    }
}

///BORRAR TODA LA LISTA
////////////////////////////////////////////////////////

void borrarTodaLaLista(nodo **pLista)
{
    nodo *aux;

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

///BORRAR PRIMER NODO
////////////////////////////////////////////////////////

void borrarPrimerNodo(nodo **pLista)
{
    nodo *aBorrar;

    //verificamos que la lista no este vacia
    if(*pLista!=NULL)
    {
        //guardamos el primer nodo en una variable
        aBorrar=*pLista;

        //salteamos el primer nodo
        *pLista=(*pLista)->siguiente;

        //lo borramos
        free(aBorrar);
    }
}

///BORRAR ULTIMO NODO
////////////////////////////////////////////////////////

void borrarUltimoNodo(nodo **pLista)
{
    nodo *ante=*pLista;
    nodo *seg=*pLista;

    //verificamos que la lista no este vacia
    if(*pLista!=NULL)
    {
        //Verificamos que el primer nodo sea el ultimo
        if(seg->siguiente==NULL)
        {
            //le asignamos null a la lista porque ahora no apunta a nada
            *pLista=NULL;

            //borramos el primer nodo
            free(seg);
        }
        //si el ultimo nodo no es el primero
        else
        {
            //recorremos la lista hasta encontrar el ultimo nodo
            while(seg->siguiente != NULL)
            {
                //guardamos el nodo actual en una variable
                ante=seg;

                //avanzamos en la lista
                seg=seg->siguiente;

            }

            //el anterior al ultimo, no apunta a nada
            ante->siguiente=NULL;

            //borramos el ultimo
            free(seg);
        }
    }
}

///DESVINCULAR PRIMER NODO
////////////////////////////////////////////////////////

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
