#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    char nombre[30];
    int edad;
}Persona;


typedef struct nodoL{
    Persona dato;
    struct nodoL* siguiente;
}nodoL;


///***** libreria LISTA SIMPLE ***************************************************************

Persona cargarPersonaL()
{
   Persona aux;

   printf("Ingrese el nombre\n");
   fflush(stdin);
   gets(aux.nombre);
   printf("Ingrese la edad\n");
   scanf("%d", &aux.edad);

   return aux;
}


void mostrarPersonaL(Persona dato)
{
    printf("-----------------------\n");
    printf("Nombre: %s \n", dato.nombre);
    printf("  Edad: %d \n", dato.edad);
    printf("-----------------------\n");
}

nodoL* inicListaL() // no es necesario aca recibir la  lista
{
    //  lista= NULL;
    //  return lista; o mas corto, puedo retornar directamente NULL:
    return NULL;
}


nodoL* crearNodoL(Persona dato)
{
    nodoL* nuevo= (nodoL*) malloc(sizeof(nodoL));

    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    return nuevo;
}

nodoL* agregarAlPpioL(nodoL* lista, nodoL* nuevo)
{
    if(lista==NULL) // si lista esta vacia
    {
        lista= nuevo;
    }
    else // si la lista tenia algo
    {
        nuevo->siguiente= lista;
        lista= nuevo;
    }
 return lista;
}

/* version pro:
nodoL* agregarAlPpioPro(nodoL* lista, nodoL* nuevo)
{
    nuevo->siguiente= lista;
 return nuevo;
}
*/

nodoL* cargarListaL (nodoL* lista)
{
    char control='s';
    Persona aux;
    nodoL* nuevo;

    while (control=='s')
    {
        aux= cargarPersonaL();
        nuevo= crearNodoL(aux);
        lista= agregarAlPpioL(lista, nuevo);

        printf("\nQuiere seguir cargando datos? presione s/n\n");
        fflush(stdin);
        scanf("%c", &control);
    }
   return lista;
}


void mostrarNodoL(nodoL* aMostrar)
{
    mostrarPersonaL(aMostrar->dato);
}


void mostrarListaL(nodoL* lista)
{
    if (lista==NULL){
        printf("\nLa lista esta vacia\n");
    }
    else{
        nodoL* seguidora= lista;

        while(seguidora!=NULL){
            mostrarNodoL(seguidora);
            seguidora= seguidora->siguiente;
        }
    }
}


nodoL* buscarUltimonodoL(nodoL*lista)
{
   nodoL* ultimo=lista;
   if (ultimo != NULL)
   {
      while(ultimo->siguiente != NULL)
       {
            ultimo = ultimo->siguiente;
       }
   }
  return ultimo;
}


nodoL* agregarFinal(nodoL* lista, nodoL* nuevoNodo)
{
    if(lista==NULL)
        lista=nuevoNodo;
    else
    {
        nodoL* ultimo = buscarUltimonodoL(lista);
        ultimo->siguiente = nuevoNodo;
    }
 return lista;
}


nodoL* buscarnodoL(char nombre[], nodoL* lista)
{
    nodoL* seg = lista;

    while ((seg != NULL)&&(strcmp(nombre,seg->dato.nombre)!=0 ))
    {
        seg=seg->siguiente;
    }
    return seg; //retorna dir del nodo buscado o NULL si llegó al final y no lo encontró
}



nodoL* agregarEnOrden(nodoL* lista, nodoL* nuevoNodo)
{           /// Si la lista esta vacia
    if(lista == NULL){
        lista = nuevoNodo;
    }      /// si debe ir 1°:
    else if(strcmp(nuevoNodo->dato.nombre,lista->dato.nombre)<=0){
        lista = agregarAlPpioL (lista, nuevoNodo);
    }      /// en cualquier otro lugar que no sea el 1°
    else{
        nodoL * ante = lista;
        nodoL * seg = lista->siguiente;
        while((seg!=NULL)&&(strcmp(nuevoNodo->dato.nombre,seg->dato.nombre)>0)){
            ante = seg;
            seg = seg->siguiente;
        }
        nuevoNodo->siguiente = seg; /// inserto el nuevo nodo en el lugar indicado
        ante->siguiente = nuevoNodo;
    }
return lista;
}


nodoL* borrarnodoL (char nombre[20], nodoL* lista){
    if(lista != NULL)
    {              /// Si el buscado es el 1°:
       if (strcmp(nombre, lista->dato.nombre)==0){
            nodoL* aBorrar = lista;
            lista = lista->siguiente;
            free(aBorrar);
        }
        else{     /// Si lo buscado no está en el 1er nodo
            nodoL* ante = lista;
            nodoL* seg = lista->siguiente;
            while( (seg != NULL) && (strcmp(nombre, seg->dato.nombre)!=0) ){
                ante = seg;
                seg = seg->siguiente;
            }
            if( seg!= NULL){
                ante->siguiente = seg->siguiente; /// bypass
                free(seg);
            }
        }
    }
    return lista;
}


nodoL* borrarTodaLaLista (nodoL* lista)
{
    nodoL* aBorrar;

    while(lista != NULL)
    {
        aBorrar = lista;
        lista = lista->siguiente;
        free(aBorrar);
    }
    return lista;
}


nodoL* eliminaUltimonodoL(nodoL* lista)
{
    nodoL* aux;
    nodoL* ante;

    if(lista) // 1ro chequeo q la lista no esté vacía
    {
        if(lista->siguiente==NULL) /// la lista tiene un solo nodo
        {
            aux= lista;
            lista= lista->siguiente; // lista->siguiente era NULL, asi que a lista le asigna NULL
            free(aux);
        }
        else  /// la lista tiene mas de un nodo
        {
            aux=lista;
            while(aux->siguiente!=NULL)
            {
                ante=aux;
                aux=aux->siguiente;
            }   // corta cuando llega al ultimo nodo, y ahi hace el free del ultimo
                  // y luego le asigna NULL al anteultimo->siguiente, para cortar el enlace con el ultimo que ya liberé
            free(aux);
            ante->siguiente=NULL;
        }
    }
    return lista;
}



nodoL* eliminaPrimernodoL(nodoL* lista)
{
    if(lista != NULL)
    {
        nodoL* aBorrar = lista;
        lista = lista->siguiente;
        free(aBorrar);
    }
    return lista;
}


Persona retornarPrimerDato(nodoL * lista)
{
    Persona rta;
    if (lista)
    {
        rta=lista->dato;
    }
    return rta; // si está vacia la lista retorna basura
               // (si es lista de enteros uedo retornar -1)
}


///************* funciones del TP 4 de lista simple ****************************************************************************************


nodoL * intercalarListas(nodoL*lista_A, nodoL*lista_B, nodoL*lista_C) /// c TAMBIEN PUEDO CREARLA E INICIALIZARLA DENTRO DE LA FUNCIO
{
    nodoL * aux;

    while((lista_A!=NULL)&&(lista_B!=NULL)) {
        if(lista_A->dato.edad < lista_B->dato.edad)
        {
            aux=lista_A; // preparo el nodo q voy a desvincular y agregar a la intercalada
            lista_A = lista_A->siguiente;
        }
        else
        {
            aux=lista_B;
            lista_B=lista_B->siguiente;
        }
        aux->siguiente = NULL; // rompo el enlace de aux al siguiente p/ agregar a la lista C solo el nodo y no todo el tren
        lista_C = agregarFinal(lista_C, aux); // agrego al final en lista C (agrego al final porq al agregarse luego los
    }                 // q queden remanentes en alguna de las 2 listas, se agregan al final p/ poder agregar todo el tren)

    if(lista_A != NULL) {
        lista_C = agregarFinal(lista_C, lista_A);
    }
    if(lista_B!=NULL) {
        lista_C = agregarFinal(lista_C, lista_B);
    }
return lista_C;
}


nodoL * invertirListaConDosListas(nodoL * lista)
// la idea es extraer el primero de la lista original y luego agregarlo al principio de la nueva lista
// retornamos el puntero al inicio de la nueva lista para pisar la referencia del main
// si lo cambio en una nueva lista, en el main hago "lista = invertir (lista);", y en lista queda alojada la nueva
// LISTA invertida, cambia solamente la referencia al 1º elemento
{
    nodoL * listaInvertida = NULL;
    nodoL * aux;
    while(lista!=NULL)
    {
        aux=lista; // EXTRAIGO EL 1º NODO (todo esto q se hace en el while se podria modularizar)
        lista=lista->siguiente;
        aux->siguiente=NULL; // rompo el enganche con el resto de la lista
        listaInvertida = agregarAlPpioL (listaInvertida, aux); // agregamos el 1º nodo extraido (aux) al principio de la nueva lista
                               // invertida, y al ir agregando todos los q siguen al ppio, el 1ro va a terminar quedando ultimo
                               // el 2do anteultimo, y asi siguiendo, y asi toda la lista va a quedar invertida
    }
    return listaInvertida;
}


nodoL* invertirListaConUnaLista(nodoL* lista)
{
    nodoL*seg=lista;
    nodoL*listaVieja=lista;
    nodoL*ante;
    int ultNodo=0;
    while(lista->siguiente != NULL) ///corta en el ultimo nodo
    {
        ante=lista;
        lista=lista->siguiente;
        ultNodo++; ///el 1° nodo es el 0,arranca en 1 a partir del 2 y cuenta hasta el ultimo inclusive
    }
    lista->siguiente=ante;///reenlazo el ultimo
    while(ultNodo>0)///ARRANCA EN EL ULT NODO Y DECRECE. 0 es el 1° nodo, corta en el 2° nodo
    {
        for(int i=0;i<ultNodo;i++) ///llego hasta el anteultimo, lo reenlazo, y en cada vuelta del while
        {                         /// el ultNodo decrece y va reenlazando todos hasta llegar al 2° q deja apuntando al 1°
            ante=seg;
            seg=seg->siguiente;
        }
        seg->siguiente=ante;
        ultNodo--;
        seg=listaVieja;///vuelvo seguidora al 1°
    }
    seg->siguiente=NULL; ///apunto el 1° a NUll
    return lista; /// que quedó apuntando al ultimo
}


///************ libreria LISTA SIMPLE USANDO PUNTERO DOBLE*************************************


void inicListaPDoble (nodoL**lista){
    *lista= NULL;
}


void crearNodoPDoble(Persona dato, nodoL** aux)
{
    *aux= (nodoL*) malloc(sizeof(nodoL));

    (*aux)->dato= dato;
    (*aux)->siguiente= NULL;
}


void agregarPrimeroPDoble(nodoL** lista, nodoL* nuevoNodo)
{
    if(*lista==NULL)
    {
        *lista= nuevoNodo;
    }
    else
    {
        nuevoNodo->siguiente= *lista;
        *lista= nuevoNodo;
    }
}


void cargarListaPDoble (nodoL** lista)
{
   Persona aux;
   char control='s';
   nodoL* nuevoNodo;

   while(control=='s')
   {
        aux= cargarPersonaL();
        crearNodoPDoble(aux,&nuevoNodo);
        agregarPrimeroPDoble(lista, nuevoNodo);

        printf("\n Quiere seguir ingresando datos a la lista? presione s para seguir \n");
        fflush(stdin),
        scanf("%s", &control);
   }
}


void mostrarListaPDoble(nodoL* lista)
{
   if (lista == NULL)
    printf("\nLa lista esta vacia\n");
   else{
       nodoL* seguidora= lista;
       while(seguidora != NULL)
       {
          mostrarPersonaL(seguidora->dato);
          seguidora= seguidora->siguiente;
       }
   }
}


void buscarUltimoNodoPDoble(nodoL*lista, nodoL**ultimo)
{
   *ultimo= lista;
   if (*ultimo != NULL)
   {
      while( (*ultimo)->siguiente != NULL)
       {
            *ultimo= (*ultimo)->siguiente;
       }
   }
}



void agregarFinalPDoble(nodoL**lista, nodoL* nuevoNodo)
{
   if(*lista==NULL)
        *lista= nuevoNodo;
   else{
        nodoL* ultimo;
        buscarUltimoNodoPDoble(*lista, &ultimo);
        ultimo->siguiente= nuevoNodo;
   }
}


void buscarNodoPDoble(char nombre[], nodoL* lista, nodoL** aBuscar)
{
    *aBuscar= lista;

    while ((*aBuscar != NULL)&&( strcmp(nombre,(*aBuscar)->dato.nombre)!=0))
    {
        *aBuscar= (*aBuscar)->siguiente;
    } // aBuscar apuntara al encontrado, o si no lo encuentra, a NULL
}


void agregarEnOrdenPDoble(nodoL** lista, nodoL* nuevoNodo)
{            /// Si la lista esta vacia
    if(*lista == NULL) {
        *lista = nuevoNodo;
    }        /// si debe ir 1°
    else if(strcmp(nuevoNodo->dato.nombre,(*lista)->dato.nombre)<=0){
        agregarPrimeroPDoble(lista, nuevoNodo);
    }        /// en cualquier otro lugar que no sea el 1°
    else {
        nodoL* ante = *lista;
        nodoL* seg = (*lista)->siguiente;
        while((seg!=NULL)&&(strcmp(nuevoNodo->dato.nombre,seg->dato.nombre)>0)){
            ante=  seg;
            seg= seg->siguiente;
        }
        nuevoNodo->siguiente = seg; // inserto el nuevo nodo en el lugar indicado
        ante->siguiente = nuevoNodo;
    }
}


void borrarNodoPDoble(char nombre[], nodoL** lista)
{
    if(*lista != NULL)
    {              /// Si el buscado es el 1°:
       if (strcmp(nombre, (*lista)->dato.nombre)==0 )
       {
            nodoL* aBorrar = *lista;
            *lista = (*lista)->siguiente;
            free(aBorrar);
        }         /// Si lo buscado no está en el 1er nodo
        else
        {
            nodoL* ante = *lista;
            nodoL* seg = (*lista)->siguiente;
            while((seg!=NULL)&&(strcmp(nombre, seg->dato.nombre)!=0)){
                ante = seg;
                seg = seg->siguiente;
            }
            if( seg!= NULL)
            {
                ante->siguiente = seg->siguiente; /// bypass
                free(seg);
            }
        }
    }
}


void borrarTodaLaListaPDoble(nodoL** lista)
{
    nodoL* aBorrar;

    while(*lista != NULL)
    {
        aBorrar = *lista;
        *lista = (*lista)->siguiente;
        free(aBorrar);
    }
}




///*********** MAIN **************************************************************

int main()
{
    /*
    nodoL* lista1;
    lista1= inicListaL();
    lista1= cargarListaL(lista1);
    mostrarListaL(lista1);
*/

    nodoL* lista;
    inicListaPDoble(&lista);
    cargarListaPDoble(&lista);
    printf("\nMostrando lista cargada con puntero doble\n");
    mostrarListaPDoble(lista);

    nodoL* ultimo;
    buscarUltimoNodoPDoble(lista, &ultimo);
    printf("\mostrando ultimo nodo de la lista\n");
    mostrarNodoL(ultimo);

    printf("\ncargamos una persona para crear un nodo y agregarlo al final de la lista");
    Persona pers = cargarPersonaL();
    nodoL* nuevoNodo;
    crearNodoPDoble(pers, &nuevoNodo);
    agregarFinalPDoble(&lista, nuevoNodo);
    mostrarListaPDoble(lista);

    nodoL*aBuscar;
    buscarNodoPDoble("caro", lista,&aBuscar);
    printf("\nmostramos el nodo que tiene el nombre caro\n");
    mostrarNodoL(aBuscar);

    printf("\ncargamos 3 personas para crear un nodo y agregarlo a una lista en orden");
    nodoL* lista3;
    inicListaPDoble(&lista3);
    nodoL* nuevito;
    Persona pers1;
    for (int i=0;i<3;i++){
        pers1 = cargarPersonaL();
        crearNodoPDoble(pers1, &nuevito);
        agregarEnOrdenPDoble(&lista3, nuevito);
    }
    mostrarListaPDoble(lista3);

    printf("\nBorramos de la lista el nodo con el nombre caro\n");
    borrarNodoPDoble("caro", &lista3);
    mostrarListaPDoble(lista3);
    printf("\nY ahora borramos toda la lista\n");
    borrarTodaLaListaPDoble(&lista3);
    mostrarListaPDoble(lista3);

/*
    nodoL* lista4;
    inicListaPDoble(&lista4);
    cargarListaPDoble(&lista4);
    nodoL* lista5;
    inicListaPDoble(&lista5);
    cargarListaPDoble(&lista5);
    nodoL* lista6;
    inicListaPDoble(&lista6);

    lista3 = intercalarListas(lista4, lista5, lista6);
    printf("Lista A");
    mostrarListaPDoble(lista4);
    printf("Lista B");
    mostrarListaPDoble(lista5);
    printf("Lista intercalada");
    mostrarListaPDoble(lista6);
    */

    return 0;
}




