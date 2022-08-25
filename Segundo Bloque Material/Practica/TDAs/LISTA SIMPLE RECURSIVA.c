///Recursivo

///MOSTRAR LISTA INVERTIDA RECURSIVO
////////////////////////////////////////////////////////
void mostrarListaInvertidaRecursivo(nodo *lista)
{
    if(lista!=NULL)
    {
        mostrarListaInvertidaRecursivo(lista->siguiente);
        mostrarNodo(lista);
    }
}


///SUMAR LISTA RECURSIVO
////////////////////////////////////////////////////////
int sumarListaRecursivo(nodo *lista)
{
    int suma;

    if(lista==NULL)
    {
        suma=0;
    }
    else
    {
        suma=lista->dato.edad+sumarListaRecursivo(lista->siguiente);
    }

    return suma;
}

///SUMAR FILTRADO
////////////////////////////////////////////////////////
int sumaPersonaXedadPARyMAYORde18 (nodoDoble *lista)
{
    int suma=0;
	
    if(lista!=NULL)
	{
        if((lista->dato.edad %2==0) && (lista->dato.edad>18))     //%2!=0 para impar
       {

            suma = lista->dato.edad + sumaPersonaXedadPARyMAYORde18(lista->siguiente);
       }
	   else
	   {
		   suma = sumaPersonaXedadPARyMAYORde18(lista->sigiuente);
	   }
	} 
	
    return suma;
}

///MOSTRAR POSICION PAR RECURSIVO
////////////////////////////////////////////////////////
void MostrarPosParRecursivo(nodo * lista)
{
    if(lista!=NULL)
    {
        lista= lista->siguiente;

        if(lista!=NULL)
        {
            mostrarNodo(lista);
            MostrarPosParRecursivo(lista->siguiente);
        }
    }
}


///MOSTRAR POSICION PAR RECURSIVO PEDORRO
void otroMuestraPosParRecursivo(nodo *lista, int pos)
{
    if(lista!=NULL)
    {
        if(pos%2==0)
        {
            mostrarNodo(lista);
        }
       otroMuestraPosParRecursivo(lista->siguiente, pos+1);
    }
}


///INVERTIR UNA LISTA RECURSIVO
////////////////////////////////////////////////////////
nodo * invertirListaRecursivo (nodo * lista)
{
    nodo * primero=NULL;

    if(lista!=NULL)
    {
        primero=lista;  // guardo el primero nodo

        lista=lista->siguiente;   // avanzo en la lista

        primero->siguiente=NULL;  // desvinculo el primero nodo

        lista=agregarFinalpSimple(invertirListaRecursivo(lista),primero);
    }

    return lista;
}

///BORRAR NODO RECURSIVO
////////////////////////////////////////////////////////
nodo *borrarNodoRecursivo(nodo *lista, char nombre[])
{
    nodo *aBorrar=NULL;

    if(lista!=NULL)
    {
        if(strcmp(lista->dato.nombre, nombre)==0)
        {
            aBorrar=lista;
            lista=lista->siguiente;
            free(aBorrar);
        }
        else
        {
            lista->siguiente=borrarNodoRecursivo(lista->siguiente, nombre);
        }
    }

    return lista;
}

///INSERTAR NODO EN ORDEN RECURSIVO
////////////////////////////////////////////////////////
nodo* insertarEnOrdenRecursivo(nodo *lista, nodo *nuevo)
{
    if(lista == NULL)
    {
        lista=nuevo;
    }
    else
    {
        if(nuevo->dato.edad < lista->dato.edad)
        {
            nuevo->siguiente = lista;
            lista = nuevo;
        }
        else
        {
            lista->siguiente = insertarEnOrdenRecursivo(lista->siguiente, nuevo);
        }
    }

    return lista;
}

///BUSCAR MENOR Y RETORNARLO
////////////////////////////////////////////////////////
nodoDoble * ENCONTRARmenorxEDAD (nodoDoble *lista)
{
    nodoDoble * menor;
	
    if(lista->siguiente==NULL)
    {
        menor = lista;
    }
    else
    {
        menor = ENCONTRARmenorxEDAD(lista->siguiente);
        if(lista->dato.edad < menor->dato.edad)
        {
            menor=lista;
        }
    }
	
   return menor;
}

///BUSCAR MENOR Y RETORNARLO SRTCOMP
////////////////////////////////////////////////////////
nodoDoble * ENCONTRARmenorxEDAD (nodoDoble *lista)
{
    nodoDoble * menor;
	
    if(lista->siguiente==NULL)
    {
        menor = lista;
    }
    else
    {
        menor = ENCONTRARmenorxEDAD(lista->siguiente);
        if(strcmpi(lista->dato.nombre, menor->dato.nombre)<0)
        {
            menor=lista;
        }
    }
	
   return menor;
}