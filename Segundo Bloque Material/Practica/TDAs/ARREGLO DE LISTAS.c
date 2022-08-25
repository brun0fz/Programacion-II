typedef struct
{
    int nota;
    int legajo;
    char nombreApe[30];
    char materia[30];
    int idMateria;
} registroArchivo;

typedef struct
{
    int idMateria;
    char materia[30];
    nodo * listaDeNotas;
} celda;

///registroArchivo
///////////////////////////////////////////////////////////

registroArchivo cargarRegistroArchivo()
{
    registroArchivo r;

    printf("\n---------------\n");
    printf("NOTA: ");
    scanf("%d", &r.nota);

    printf("LEGAJO: ");
    scanf("%d", &r.legajo);

    printf("NOMBRE Y APELLIDO: ");
    fflush(stdin);
    gets(r.nombreApe);

    printf("MATERIA: ");
    fflush(stdin);
    gets(r.materia);

    printf("ID MATERIA: ");
    scanf("%d", &r.idMateria);
    printf("---------------\n");

    return r;
}

void mostrarRegistroArchivo(registroArchivo dato)
{
    printf("---------------\n");
    printf("   NOTA: %d\n", dato.nota);
    printf(" LEGAJO: %d\n", dato.legajo);
    printf(" NOMBRE: %s\n", dato.nombreApe);
    printf("METERIA: %s\n", dato.materia);
    printf("     ID: %d", dato.idMateria);
    printf("\n---------------\n");
}

void arGuardarUnRegistroArchivo(char fileName[], registroArchivo r)
{

    FILE *buffer=fopen(fileName, "ab");

    if(buffer)
    {
        fwrite(&r, sizeof(registroArchivo),1,buffer);
        fclose(buffer);
    }
}

void arGuardarRegistroArchivo(char fileName[])
{
    char com='s';

    while(com=='s')
    {
        arGuardarUnRegistroArchivo(fileName, cargarRegistroArchivo());
        printf("Desea cargar otro registro? [s/n]: ");
        fflush(stdin);
        scanf("%c", &com);
    }
}

void arMostrarRegistroArchivo(char fileName[])
{
    FILE *buffer=fopen(fileName, "rb");
    registroArchivo aux;

    if(buffer)
    {
        while(fread(&aux, sizeof(registroArchivo), 1,buffer)>0)
        {
            mostrarRegistroArchivo(aux);
        }
        fclose(buffer);
    }
}

///Funciones ADL
///////////////////////////////////////////////////////////

///CARGAR ADL
int cargarADL(celda ADL[], int dim) //llega el ADL y la dimension
{
    registroArchivo nuevo; //cargamos un registro para mandarlo al ADL

    char com='s';

    int validos=0; //se inicializan los validos en 0

    while(com=='s' && validos < dim)
    {
        nuevo=cargarRegistroArchivo();

        validos=alta(ADL, nuevo, validos);

        printf("Desea cargar otro dato? [s/n]:");
        fflush(stdin);
        scanf("%c", &com);
    }

    return validos;
}

///BUSCAR POS MATERIA
int buscaPosMateriaADL(celda ADL[], char materia[], int validos)
{
    int pos=-1;
    int i=0;

    while(i<validos && pos==-1)
    {
        if(strcmpi(ADL[i].materia, materia)==0)
        {
            pos=i;
        }

        i++;
    }

    return pos;
}

///AGREGAR NUEVA CELDA, MATERIA
int agregarCeldaADL(celda ADL[], int idMateria, char materia[], int validos)
{
    ADL[validos].idMateria=idMateria;
    strcpy(ADL[validos].materia,materia);

    inicLista(&ADL[validos].listaDeNotas);

    validos++;

    return validos;

}

///ALTA ADL
int alta(celda ADL[], registroArchivo nuevo, int validos)
{
    notaAlumno alumno;

    alumno.legajo=nuevo.legajo;
    alumno.nota=nuevo.nota;
    strcpy(alumno.nombreApe, nuevo.nombreApe);

    nodo *aux=crearNodo(alumno);

    int pos=buscaPosMateriaADL(ADL, nuevo.materia, validos);

    if(pos==-1)
    {
        validos=agregarCeldaADL(ADL, nuevo.idMateria, nuevo.materia, validos);
        pos=validos-1;
    }

    agregarPpio(&ADL[pos].listaDeNotas, aux);

    return validos;
}

///MOSTRAR ADL
void mostrarADL(celda ADL[], int validos)
{
    int i=0;

    while(i < validos)
    {
        printf("\nID MATERIA: %d\n", ADL[i].idMateria);
        printf("MATERIA: %s\n", ADL[i].materia);

        printf("\nLista de alumnos: \n\n");
        mostrarLista(&ADL[i].listaDeNotas);

        i++;
    }
}

///////////////////////////////////////////////////////////
///PASAR DE ARCHIVO TO ADL
int pasarDeArchivoToADL(char filename[], celda ADL[], int dim)
{
    FILE *buffer = fopen(filename, "rb");

    registroArchivo aux;

    int validos=0;

    if(buffer)
    {
        while(fread(&aux, sizeof(registroArchivo),1,buffer)>0 && validos<dim)
        {
            validos=alta(ADL, aux, validos);
        }

        fclose(buffer);
    }

    return validos;
}

///PASAR ADL TO ARCHIVO
void pasarDeADLToArchivoDeAprobados(celda ADL[], int validos)
{
    registroArchivo aux;

    for(int i=0; i<validos; i++)
    {
        aux.idMateria = ADL[i].idMateria;
        strcpy(aux.materia, ADL[i].materia);

        nodo *seg=ADL[i].listaDeNotas;

        while(seg)
        {
            aux.nota=seg->dato.nota;
            aux.legajo=seg->dato.legajo;
            strcpy(aux.nombreApe, seg->dato.nombreApe);

            if(aux.nota >=6)
            {
                arGuardarUnRegistroArchivo("arAprobados.dat", aux);
            }
            else
            {
                arGuardarUnRegistroArchivo("arDesaprobados.dat", aux);
            }

            seg=seg->siguiente;
        }
    }
}

///CONTAR ALUMNOS POR MATERIA
int contarAlumnosPorMateria(celda ADL[], int validos, char materia[])
{
    int i=0;
    int flag=0;
    int cant=0;

    while(i<validos && flag==0)
    {
        if(strcmpi(ADL[i].materia, materia)==0)
        {
            cant=contarLista(ADL[i].listaDeNotas);
        }
    }
    return cant;
}

///CONTAR UNA LISTA
int contarLista(nodo *lista)
{
    int cont=0;

    while(lista)
    {
        cont++;

        lista=lista->siguiente;
    }

    return cont;
}

///CONTAR ALUMNOS POR MATERIA FILTRO
int contarAlumnosPorMateriaFiltro(celda ADL[], int validos, char materia[])
{
    int i=0;
    int flag=0;
    int cant=0;

    while(i<validos && flag==0)
    {
        if(strcmpi(ADL[i].materia, materia)==0)
        {
            cant=contarListaFiltro(ADL[i].listaDeNotas);
        }
    }
    return cant;
}

///CONTAR LISTA FILTRO
int contarListaFiltro(nodo *lista)
{
    int cont=0;

    while(lista)
    {
        if(lista->dato.nota>6)
        {
            cont++;
        }

        lista=lista->siguiente;
    }

    return cont;
}

///SUMAR LISTA FILTRO
int sumarLista(nodo *lista)
{
    int suma=0;

    while(lista)
    {
        if(lista->dato.nota>6)
        {
        suma+=lista->dato.nota;
        }

        lista=lista->siguiente;
    }

    return suma;
}
















/*
void pasarDeADLToArchivoDeAprobados(celda ADL[], int validos)
{
    stRegistroArchivo r;

    for(int i=0; i<validos; i++)
    {
        r.idMateria = adl[i].m.idMateria;
        strcpy(r.materia,adl[i].m.materia);

        nodo * seg=adl[i].listaDeNotas;

        while(seg)
        {
            r.legajo = seg->n.legajo;
            r.nota = seg->n.nota;
            strcpy(r.apeNom,seg->n.apeNom);

            if(adl[i].seg->n.nota>=6)
            {
                guardaRegistroArchivo(arRegAprob,r);
            }
            else
            {
                guardaRegistroArchivo(arRegDesAp,r);
            }

            seg=seg->siguiente;
        }
    }
}*/


///////////////////////////////////////////////////////////
