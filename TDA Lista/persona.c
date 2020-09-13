#include "persona.h"

////////////////////////////////////////////////////////

persona cargarPersona()
{
    persona p;

    printf("\n---------------\n");
    printf("NOMBRE: ");
    fflush(stdin);
    gets(p.nombre);
    printf("EDAD: ");
    scanf("%d", &p.edad);
    printf("\n---------------\n");

    return p;
}

////////////////////////////////////////////////////////

void mostrarPersona(persona dato)
{
    printf("---------------\n");
    printf("NOMBRE: %s\n", dato.nombre);
    printf("EDAD: %d", dato.edad);
    printf("\n---------------\n");
}

////////////////////////////////////////////////////////
