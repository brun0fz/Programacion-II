#include <stdio.h>
#include <stdlib.h>

void inicArray(int array[], int dim);
void cargarArray(int array[], int dim);
int sumarArray(int array[], int dim);
int contarArray(int array[], int dim);
float promedioArray(int array[], int dim);

int main()
{
    int array[10];

    inicArray(array, 10);

    cargarArray(array, 10);

    float promedio=promedioArray(array, 10);

    printf("El promedio es: %g", promedio);

    return 0;
}

void inicArray(int array[], int dim)
{
    for (int i=0; i<dim; i++)
    {
        array[i]=-1;
    }
}

void cargarArray(int array[], int dim)
{
    int i=0;
    char com='s';

    while(i<dim && com=='s')
    {
        printf("Ingrese un dato: ");
        scanf("%d", &array[i]);

        printf("Desea cargar otro dato? [s/n]: ");
        fflush(stdin);
        scanf("%c", &com);
        i++;
    }
}

int sumarArray(int array[], int dim)
{
    int suma=0;

    for(int i=0; i<dim; i++)
    {
        if(array[i] != -1)
        {
            suma+=array[i];
        }
    }

    return suma;
}

int contarArray(int array[], int dim)
{
    int cant=0;

    for (int i=0; i<dim; i++)
    {
        if(array[i] != -1)
        {
            cant++;
        }
    }
    return cant;
}

float promedioArray(int array[], int dim)
{
    int suma = sumarArray(array, dim);
    int cant = contarArray(array, dim);

    float promedio = (float)suma / (float)cant;

    return promedio;
}
