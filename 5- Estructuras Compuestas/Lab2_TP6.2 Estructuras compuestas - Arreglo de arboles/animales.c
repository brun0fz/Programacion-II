#include "animales.h"

////////////////////////////////////////////////////////

animal cargarAnimal()
{
    animal p;

    printf("\n---------------\n");
    printf("  NOMBRE: ");
    fflush(stdin);
    gets(p.nombreAnimal);

    printf("CANTIDAD: ");
    scanf("%d", &p.cantidad);

    printf(" HABITAT: ");
    scanf("%d", &p.habitat);
    printf("---------------\n");

    return p;
}

////////////////////////////////////////////////////////

void mostraranimal(animal dato)
{
    printf("---------------\n");
    printf("  NOMBRE: %s\n", dato.nombreAnimal);
    printf("CANTIDAD: %d\n", dato.cantidad);
    switch(dato.habitat)
    {
    case 1:
        printf(" HABITAT: Selva");
        break;
    case 2:
        printf(" HABITAT: Savana");
        break;
    case 3:
        printf(" HABITAT: Bosque");
        break;
    case 4:
        printf(" HABITAT: Mar");
        break;
    }


printf("\n---------------\n");
}


////////////////////////////////////////////////////////

void arGuardarUnaanimal(char fileName[], animal p)
{

    FILE *buffer=fopen(fileName, "ab");

    if(buffer)
    {
        fwrite(&p, sizeof(animal),1,buffer);
        fclose(buffer);
    }
}

void arGuardaranimals(char fileName[])
{
    char com='s';

    while(com=='s')
    {
        arGuardarUnaanimal(fileName, cargarAnimal());
        printf("Desea cargar otra animal? [s/n]: ");
        fflush(stdin);
        scanf("%c", &com);
    }
}

void arMostraranimals(char fileName[])
{
    FILE *buffer=fopen(fileName, "rb");
    animal aux;

    if(buffer)
    {
        while(fread(&aux, sizeof(animal), 1,buffer)>0)
        {
            mostraranimal(aux);
        }
        fclose(buffer);
    }
}
