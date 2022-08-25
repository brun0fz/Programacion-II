typedef struct
{
    char animal[30];
    int cant;
    int habitat;
    int idEspecie;
    char especie[20];
} registroArchivo;

typedef struct
{
    int idEspecie;
    char especie [20];
    // "Mamiferos", "Aves"
    // "Reptiles", "Peces"
    nodoArbol *arbolDeAnimales;
} celda;

///registroArchivo
///////////////////////////////////////////////////////////

registroArchivo cargarRegistroArchivo()
{
    registroArchivo r;

    printf("\n---------------\n");
    printf("    ANIMAL: ");
    gets(r.animal);

    printf("  CANTIDAD: ");
    scanf("%d", &r.cant);

    printf("   HABITAT: ");
    scanf("%d", &r.habitat);


    printf("ID ESPECIE: ");
    scanf("%d", &r.idEspecie);

    printf("   ESPECIE: ");
    fflush(stdin);
    gets(r.especie);
    printf("---------------\n");

    return r;
}

void mostrarRegistroArchivo(registroArchivo dato)
{
    printf("---------------\n");
    printf("      ANIMAL: %s\n", dato.animal);
    printf("    CANTIDAD: %d\n", dato.cant);
    printf("     HABITAT: %d\n", dato.habitat);
    printf("  ID ESPECIE: %d\n", dato.idEspecie);
    printf("     ESPECIE: %s", dato.especie);
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

///Funciones ADA
///////////////////////////////////////////////////////////

///CARGAR ADA
int cargarADA(celda ADA[], int dim)
{
    registroArchivo nuevo;

    char com='s';
    int validos=0;

    while(com=='s' && validos < dim)
    {
        nuevo=cargarRegistroArchivo();

        validos=alta(ADA, nuevo, validos);

        printf("Desea cargar otro dato? [s/n]:");
        fflush(stdin);
        scanf("%c", &com);
    }

    return validos;
}

///BUSCAR POS EN ARREGLO
int buscaPosEspecieADA(celda ADA[], char especie[], int validos)
{
    int pos=-1;
    int i=0;

    while(i<validos && pos==-1)
    {
        if(strcmpi(ADA[i].especie, especie)==0)
        {
            pos=i;
        }

        i++;
    }

    return pos;
}

///AGREGAR CELDA ARREGLO
int agregarCeldaADA(celda ADA[], int idEspecie, char especie[], int validos)
{
    ADA[validos].idEspecie=idEspecie;
    strcpy(ADA[validos].especie,especie);

    inicArbol(&ADA[validos].arbolDeAnimales);

    validos++;

    return validos;

}

///ALTA DE DATOS EN ADA
int alta(celda ADA[], registroArchivo nuevo, int validos)
{
    int pos=buscaPosEspecieADA(ADA, nuevo.especie, validos);

    if(pos==-1)
    {
        validos=agregarCeldaADA(ADA, nuevo.idEspecie, nuevo.especie, validos);
        pos=validos-1;
    }

    animal animalArbol;

    animalArbol.cantidad=nuevo.cant;
    animalArbol.habitat=nuevo.habitat;
    strcpy(animalArbol.nombreAnimal, nuevo.animal);

    ADA[pos].arbolDeAnimales=insertarArbolOrdenado(ADA[pos].arbolDeAnimales, animalArbol);

    return validos;
}

///MOSTRAR ADA
void mostrarADA(celda ADA[], int validos)
{
    int i=0;

    while(i < validos)
    {
        printf("\nID ESPECIE: %d\n", ADA[i].idEspecie);
        printf("ESPECIE: %s\n", ADA[i].especie);

        printf("\nAnimales: \n\n");
        preorder(ADA[i].arbolDeAnimales);

        i++;
    }
}

///PASAR DE ARCHIVO TO ADA
///////////////////////////////////////////////////////////
int pasarDeArchivoToADA(celda ADA[], int dim)
{
    FILE *buffer = fopen("animales.dat", "rb");

    registroArchivo aux;

    int validos=0;

    if(buffer)
    {
        while(fread(&aux, sizeof(registroArchivo),1,buffer)>0 && validos<dim)
        {
            validos=alta(ADA, aux, validos);
        }

        fclose(buffer);
    }

    return validos;
}

///PASAR DE ADA TO ARCHIVO
void pasarDeADAToArchivo(celda ADA[], int validos)
{
    registroArchivo aux;

    for(int i=0; i<validos; i++)
    {
        aux.idEspecie = ADA[i].idEspecie;
        strcpy(aux.especie, ADA[i].especie);

        arbolToArchivo(ADA[i].arbolDeAnimales,aux);

    }
}

///ARBOL TO ARCHIVO
void arbolToArchivo(nodoArbol* arbolito, registroArchivo aux)
{
    if(arbolito)
    {
        strcpy(aux.animal,arbolito->dato.nombreAnimal);
        aux.cant=arbolito->dato.cantidad;
        aux.habitat=arbolito->dato.habitat;

        if(strcmpi(aux.especie, "mamiferos"))
        {
            arGuardarUnRegistroArchivo("arMamiferos.dat", aux);
        }
        else if(strcmpi(aux.especie, "aves"))
        {
            arGuardarUnRegistroArchivo("arAves.dat", aux);

        }
        else if(strcmpi(aux.especie, "reptiles"))
        {
            arGuardarUnRegistroArchivo("arPeces.dat", aux);

        }
        else
        {
            arGuardarUnRegistroArchivo("arReptiles.dat", aux);
        }

        arbolToArchivo(arbolito->izq, aux);

        arbolToArchivo(arbolito->der, aux);
    }
}
