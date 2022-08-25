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

///AGREGAR NODOS EN ORDEN
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

///ARCHIVO TO LISTA EN ORDEN
////////////////////////////////////////////////////////

void pasarArchivoToListaOrden(nodo **pLista, char filename[])
{
    FILE *buffer=fopen(filename, "rb");

    estructura dato;

    if(buffer)
    {
        while(fread(&dato, sizeof(estructura),1,buffer)>0)
        {
		
            agregarEnOrden(pLista, crearNodo(dato));
        }

        fclose(buffer);
    }
}

///LISTA TO ARCHIVO
////////////////////////////////////////////////////////

void pasarListaToArchivo(nodo **pLista, char filename[])
{
    FILE *buffer = fopen(filename, "ab");

    nodo *seg=*pLista;

    userFuerza user;

    if(buffer)
    {
        while(seg!=NULL)
        {
            user=seg->dato;

            fwrite(&user, sizeof(userFuerza), 1, buffer);

            seg=seg->siguiente;
        }

        fclose(buffer);
    }
}

///MOSTRAR UN DATO FILTRADO RECURSIVO
////////////////////////////////////////////////////////
void mostrarFiltradoRecursivo(nodo *lista, char colorSable[])
{
    if(lista!=NULL)
    {
        if(strcmpi(lista->dato.colorSable,colorSable)==0)
        {
            mostrarUnNodo(lista);
        }

        mostrarFiltradoRecursivo(lista->siguiente, colorSable);
    }
}

///LISTA TO DOS ARCHIVOS FILTRADO (se borra la lista)
////////////////////////////////////////////////////////
void pasarListaToArchivosFiltrado(nodo **pLista)
{
    FILE *bufferActivos = fopen("UsersActivos.dat","ab");
    FILE *bufferInactivos = fopen("UsersInactivos.dat","ab");

    userFuerza userActivo;
    userFuerza userInactivo;

    if(bufferActivos && bufferInactivos)
    {
        while(*pLista!=NULL)
        {
            if((*pLista)->dato.activo==1)
            {
                userActivo=(*pLista)->dato;
                fwrite(&userActivo, sizeof(userFuerza),1,bufferActivos);
            }
            else
            {
                userInactivo=(*pLista)->dato;
                fwrite(&userInactivo, sizeof(userFuerza),1,bufferInactivos);
            }

            borrarNodo(pLista, (*pLista)->dato.nombre); //va borrando la lista
        }

        fclose(bufferActivos);
        fclose(bufferInactivos);
    }
}

///INTERCALAR EN ORDEN LOS ELEMENTOS DE DOS LISTAS ORDENADAS GENERANDO UNA NUEVA
////////////////////////////////////////////////////////
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

///DESVINCULAR NODO DE UNA LISTA Y PASARLO A OTRAS FILTRANDO
////////////////////////////////////////////////////////
void dividirBalanceFuerza(nodoDoble **pLista, nodoDoble **jedis, nodoDoble **siths, nodoDoble **grises)
{
    while(*pLista!=NULL)
    {
        if((*pLista)->dato.alineacion==1)
        {
            agregarEnOrdenDoble(jedis, desvincularPrimerNodoDoble(pLista));
        }
        else if((*pLista)->dato.alineacion==2)
        {
            agregarEnOrdenDoble(siths, desvincularPrimerNodoDoble(pLista));
        }
        else
        {
            agregarEnOrdenDoble(grises, desvincularPrimerNodoDoble(pLista));
        }
    }
}

///COPIAR DATOS A OTRA LISTA FILTRADO POR PRIMER LETRA
////////////////////////////////////////////////////////
void copiarAOtraListaFiltradoLetra(nodo *lista, nodo **listaDestino, char letra)
{
    userFuerza aux;

    while(lista!=NULL)
    {
        if(lista->dato.nombre[]==letra)
        {
            aux=lista->dato;

            agregarEnOrdenDoble(listaDestino, crearNodoDoble(aux));
        }

        lista=lista->siguiente;
    }
}

///COPIAR DATOS A OTRA LISTA FILTRADO
////////////////////////////////////////////////////////
void copiarAOtraListaFiltrado(nodoDoble *lista, nodoDoble **listaDestino, int edad)
{
    userFuerza aux;

    while(lista!=NULL)
    {
        if(lista->dato.edad==edad)
        {
            aux=lista->dato;

            agregarEnOrdenDoble(listaDestino, crearNodoDoble(aux));
        }

        lista=lista->siguiente;
    }
}

///COPIAR A OTRA LISTA SIMPLEMENTE ENLAZADA BORRANDO LA ORIGINAL (LISTA TIMPLE)
////////////////////////////////////////////////////////
void copiarAOtraListaFiltradoBorrando(nodoDoble **lista, nodoDoble **listaDestino, int edad)
{
    userFuerza aux;
    nodoDoble *seg=*lista;

    while(seg!=NULL)
    {
        if(seg->dato.edad==edad)
        {
            aux=seg->dato;

            agregarEnOrdenDoble(listaDestino, crearNodoDoble(aux));

            borrarNodoDoble(lista, seg->dato.nombre);
        }

        seg=seg->siguiente;
    }
}

///COPIAR A OTRA LISTA DOBLEMENTE ENLAZADA BORRANDO LA ORIGINAL (LISTA DOBLEMENTE ENLAZADA)
////////////////////////////////////////////////////////
void copiarAOtraListaFiltradoBorrando(nodoDoble **lista, nodoDoble **listaDestino, int edad)
{
    userFuerza aux;
    nodoDoble *seg=*lista;

    while(seg!=NULL)
    {
        if(seg->dato.edad==edad)
        {
            aux=seg->dato;

            agregarEnOrdenDoble(listaDestino, crearNodoDoble(aux));

            borrarNodoDoble(lista, seg->dato.nombre);

            if((*lista)->anterior==NULL)
            {
                seg=*lista;
            }
            else
            {
               seg=(*lista)->anterior;
            }

        }

        seg=seg->siguiente;
    }
}

///PASAR A OTRA LISTA FILTRADO (LA LISTA ORIGEN QUEDA VACIA) (LISTA DOBLEMENTE ENLAZADA)
////////////////////////////////////////////////////////
void pasarAOtraListaFiltrado(nodoDoble **pListaOrigen, nodoDoble **pListaDestino, int edad)
{
    nodoDoble *aux;
    nodoDoble *seg=*pListaOrigen;

    while(seg!=NULL)
    {
        if(seg->dato.edad==edad)
        {
            aux=desvincularNodoDoble(pListaOrigen, seg->dato.nombre);

            agregarPpioDoble(pListaDestino, aux);

            if((*pListaOrigen)->anterior==NULL)
            {
                seg=*pListaOrigen;
            }
            else
            {
               seg=(*pListaOrigen)->anterior;
            }
        }

        seg=seg->siguiente;
    }
}

///INVERTIR LISTA
////////////////////////////////////////////////////////
void invertirLista(nodo ** pLista)
{
    nodo * aux;

    while(*pLista!=NULL)
    {
        aux=desvincularPrimerNodo(pLista);

        agregarPpio(pLista, aux);
    }
}

///BORRAR NODO DEL MEDIO
////////////////////////////////////////////////////////
nodo* buscarNodoMedio(nodo *lista)
{
    nodo *p=lista;
    nodo *q=lista;

    while(q!=NULL && q->siguiente!=NULL)
    {
        p=p->siguiente;
        q=q->siguiente->siguiente;
    }

    return p;
}

void eliminarNodoMedio(nodoDoble **pLista)
{
    nodo *medio=buscarNodoMedio(*pLista);
    borrarNodo(pLista, medio->dato);
}

///PROMEDIO
//////////////////////////////////////////////

int contarListaFilatrado(nodoDoble *lista)
{
    int cant=0;
    while(lista)
    {
        if(lista->dato.alineacion==1)
        {
            cant++;
        }

        lista=lista->siguiente;
    }
    return cant;
}

int sumarDatosLista(nodo *lista)
{
    int suma=0;

    while(lista)
    {
        suma+=lista->dato.edad;
        lista=lista->siguiente;
    }
    return suma;

}

int sumarDatosListaRecursiva(nodo *lista)
{
    int suma=0;

    if(lista)
    {
        suma=lista->dato.edad+sumarDatosListaRecursiva(lista->siguiente);
    }

    return suma;
}

int promedio(nodo *lista)
{
    float promedio=0;

    int cant=contarJedis(lista);

    int suma=sumarEdadesJedis(lista);

    if(cant!=0)
    {
        promedio=(float)suma/(float)cant;
    }

    return promedio;
}

///Porcentaje
//////////////////////////////////////////////

int contarLista(nodo *lista)
{
    int cant=0;
    while(lista)
    {
        cant++;

        lista=lista->siguiente;
    }
    return cant;
}

int contarListaFiltrado(nodo *lista, char colorSable[])
{
    int cant=0;

    while(lista)
    {
        if(strcmpi(lista->dato.colorSable, colorSable)==0)
        {
            cant++;
        }

        lista=lista->siguiente;
    }

    return cant;
}

int porcentaje(nodo *lista, char colorSable[])
{
    float porcentaje=0;

    int Cfav=contarUsuarios(lista);
    int Cpos=contarUsuariosSable(lista, colorSable);

    if(Cpos!=0)
    {
        porcentaje=((float)Cfav/(float)Cpos)*100;
    }

    return porcentaje;
}
