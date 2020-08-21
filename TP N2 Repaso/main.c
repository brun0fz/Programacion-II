#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct
{
    char nombre[30];
    char genero;
    int edad;
} stPersona;

stPersona cargarPersona();
int cargarArrayPersonas(stPersona array[], int dim);
stPersona* copiarArreglo(stPersona persona[], int validosp, int *validosg, char genero);
void MostrarArregloPersonas(stPersona arraypersonas[], int validos);
int copiarArregloalt (stPersona persona[], int validosp, stPersona **g, char genero);





int main()
{

    stPersona arraypersonas[30];

    int validos=cargarArrayPersonas(arraypersonas, 30);

    MostrarArregloPersonas(arraypersonas, validos);

    system("pause");

    stPersona *genero = NULL;

    int validosG=0;

    validosG=copiarArregloalt(arraypersonas, validos, genero, 'm');

    MostrarArregloPersonas(genero, validosG);







    return 0;
}

stPersona cargarPersona()
{
    stPersona persona;

    printf("\n----------------\n");
    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(persona.nombre);
    printf("Ingrese genero: ");
    fflush(stdin);
    scanf("%c", &persona.genero);
    printf("Ingrese edad: ");
    scanf("%d", &persona.edad);
    printf("----------------\n");

    return persona;
}

int cargarArrayPersonas(stPersona array[], int dim)
{
    char com='s';
    int i=0;

    while (i < dim && com=='s')
    {
        array[i]=cargarPersona();
        i++;
        printf("\nDesea cargar otra persona? [s/n]: ");
        fflush(stdin);
        scanf("%c", &com);
    }

    return i;
}

///Mostrar una persona
void MostrarPersona(stPersona persona)
{
    printf("---------------\n");
    printf("NOMBRE: %s",persona.nombre);
    printf("\nGenero: %c",persona.genero);
    printf("\nEDAD: [%d]",persona.edad);
    printf("\n---------------\n");
}

///Mostrar arreglo
void MostrarArregloPersonas(stPersona arraypersonas[], int validos)
{
    for(int i=0; i<validos; i++)
    {
        MostrarPersona(arraypersonas[i]);
    }
}

int contarGenero (stPersona array[], int validos, char genero)
{
    int i=0;
    int cont=0;


    while(i<validos)
    {
        if(array[i].genero==genero)
        {
            cont++;
        }
        i++;
    }

    return cont;
}

stPersona* copiarArreglo(stPersona persona[], int validosp, int *validosg, char genero)
{
    *validosg = contarGenero(persona, validosp, genero);

    stPersona *g = malloc(sizeof(stPersona)* (*validosg));

    int i=0;
    int j=0;

    while(i<validosp)
    {
        if(persona[i].genero==genero)
        {
            g[j]=persona[i];
            j++;
        }
        i++;
    }
    return g;
}

int copiarArregloalt (stPersona persona[], int validosp, stPersona **g, char genero)
{
    int validosg = contarGenero(persona, validosp, genero);

    (*g) = (stPersona*) malloc(sizeof(stPersona)* validosg);

    int i=0;
    int j=0;

    while(i<validosp)
    {
        if(persona[i].genero==genero)
        {
            (*g)[j]=persona[i];
            j++;
        }
        i++;
    }
    return validosg;
}











