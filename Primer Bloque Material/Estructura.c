
///CARGAR UNA ESTRUCTURA
////////////////////////////////////////////////////////
persona cargarPersona()
{
    persona p;

    printf("\n---------------\n");
    printf("NOMBRE: ");
    fflush(stdin);
    gets(p.nombre);
    printf("  EDAD: ");
    scanf("%d", &p.edad);
    printf("---------------\n");

    return p;
}

///MOSTRAR UNA ESTRUCTURA
////////////////////////////////////////////////////////
void mostrarPersona(persona dato)
{
    printf("---------------\n");
    printf("NOMBRE: %s\n", dato.nombre);
    printf("  EDAD: %d", dato.edad);
    printf("\n---------------\n");
}

///GUARDAR UNA ESTRUCTURA EN UN ARCHIVO
////////////////////////////////////////////////////////
void arGuardarUnaPersona(char fileName[], persona p)
{

    FILE *buffer=fopen(fileName, "ab");

    if(buffer)
    {
        fwrite(&p, sizeof(persona),1,buffer);
        fclose(buffer);
    }
}

///GUARDAR MUCHAS ESTRUCTURAS EN UN ARCHIVO
void arGuardarPersonas(char fileName[])
{
    char com='s';

    while(com=='s')
    {
        arGuardarUnaPersona(fileName, cargarPersona());
        printf("Desea cargar otra persona? [s/n]: ");
        fflush(stdin);
        scanf("%c", &com);
    }
}

///MOSTRAR ESTRUCTURAS DE UN ARCHIVO
void arMostrarPersonas(char fileName[])
{
    FILE *buffer=fopen(fileName, "rb");
    persona aux;

    if(buffer)
    {
        while(fread(&aux, sizeof(persona), 1,buffer)>0)
        {
            mostrarPersona(aux);
        }
        fclose(buffer);
    }
}
