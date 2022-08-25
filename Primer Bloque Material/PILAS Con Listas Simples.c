///INICIALIZAR PILA
/////////////////////////////////////////////////////
void inicPila(nodo **pila)
{
    InicLista(pila);
}

///PILA VACIA
/////////////////////////////////////////////////////
int pilavacia(nodo **pila)
{
    int flag=1;

    if(*pila!=NULL)
    {
        flag=0;
    }

    return flag;
}

///TOPE DE LA PILA
/////////////////////////////////////////////////////
int tope(nodo **pila)
{
    int tope;

    if(*pila)
    {
        tope=(*pila)->dato;
    }

    return tope;
}

///DESAPILAR
/////////////////////////////////////////////////////
int desapilar(nodo **pila)
{
   nodo *aux=DesvincularPrimero(pila);
   tope=aux->dato;
   
   return tope;
}

///APILAR
/////////////////////////////////////////////////////
void apilar(nodo **pila, int dato)
{
    AgregarPpio(pila, CrearNodo(dato));
}

///LEER
/////////////////////////////////////////////////////
void leer(nodo **pila)
{
    int dato;

    printf("Ingrese un dato: ");
    scanf("%d", &dato);

    apilar(pila, dato);
}

///MOSTRAR
/////////////////////////////////////////////////////
void mostrar(nodo **pila)
{
    printf("\nTope\n");
    MostrarLista(pila);
    printf("Base\n");
}

/////////////////////////////////////////////////////
///Funciones con PILAS
/////////////////////////////////////////////////////

///CARGAR PILA
/////////////////////////////////////////////////////
void cargarPila(Pila *pPila)
{
    char com='s';

    while(com=='s')
    {
        leer(pPila);

        printf("Desea agregar otro dato? [s/n]: ");
        fflush(stdin);
        scanf("%c", &com);
    }
}

///PASAR DE PILA A LISTA FILTRADO
void pilaToLista(Pila *p, nodo **lista)
{
    Pila aux;
	
    inicPila(&aux);
	
    int dato;
	
    while(!pilavacia(p))
    {
        dato=tope(p);

        if(dato%2==0)
        {
            agregarFinal(lista, crearNodo(dato));
        }
        apilar(&aux, desapilar(p));
    }
	
    while(!pilavacia(&aux))
    {
        apilar(p,desapilar(&aux));
    }
}


