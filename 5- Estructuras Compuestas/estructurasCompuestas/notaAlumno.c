#include "notaAlumno.h"

////////////////////////////////////////////////////////

notaAlumno cargarNotaAlumno()
{
    notaAlumno dato;

    printf("\n---------------\n");
    printf("LEGAJO: ");
    scanf("%d", &dato.legajo);
    printf("NOMBRE: ");
    fflush(stdin);
    gets(dato.nombreApe);
    printf("NOTA: ");
    scanf("%d", &dato.nota);
    printf("---------------\n");

    return dato;
}

////////////////////////////////////////////////////////

void mostrarNotaAlumno(notaAlumno dato)
{
    printf("---------------\n");
    printf("LEGAJO: %d\n", dato.legajo);
    printf("NOMBRE: %s\n", dato.nombreApe);
    printf("  NOTA: %d", dato.nota);
    printf("\n---------------\n");
}

////////////////////////////////////////////////////////

void arGuardarUnaNotaAlumno(char fileName[], notaAlumno p)
{

    FILE *buffer=fopen(fileName, "ab");

    if(buffer)
    {
        fwrite(&p, sizeof(notaAlumno),1,buffer);
        fclose(buffer);
    }
}

void arGuardarNotaAlumno(char fileName[])
{
    char com='s';

    while(com=='s')
    {
        arGuardarUnaNotaAlumno(fileName, cargarNotaAlumno());
        printf("Desea cargar otra notaAlumno? [s/n]: ");
        fflush(stdin);
        scanf("%c", &com);
    }
}

void arMostrarnotaAlumno(char fileName[])
{
    FILE *buffer=fopen(fileName, "rb");
    notaAlumno aux;

    if(buffer)
    {
        while(fread(&aux, sizeof(notaAlumno), 1,buffer)>0)
        {
            mostrarNotaAlumno(aux);
        }
        fclose(buffer);
    }
}
