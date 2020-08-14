///Trabajo Práctico N° 6: Estructuras de Datos. Algoritmos sobre arreglos de estructuras.
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <locale.h>

///Estructuras
///////////////////////////////////////////////////////////////////////////////

typedef struct
{
    int matricula;
    char nombre[30];
    char genero; //m, f, o
} stAlumno;

///Cabeceras
///////////////////////////////////////////////////////////////////////////////

int CargarArrayAlumnos(stAlumno ArrayAlumnos[], int dimension);
void MostrarArrayAlumnos(stAlumno ArrayAlumnos[], int validos);
stAlumno CargarAlumno();
void MostrarAlumno(stAlumno alumno);
int PosMatricula(stAlumno ArrayAlumnos[],int validos,int matricula);
void MostrarPorMatricula(stAlumno ArrayAlumnos[],int validos,int matricula);
int PosMatriculaMenor(stAlumno ArrayAlumnos[],int validos,int pos);
void OrdSelecAlumno(stAlumno ArrayAlumnos[],int validos);
int InstertarAlumnoNuevo(stAlumno ArrayAlumnos[],int validos,stAlumno alumnonuevo);
void InstertarAlumno(stAlumno ArrayAlumnos[],int pos,stAlumno alumno);
void OrdInsercionAlumnos(stAlumno ArrayAlumnos[],int validos);
void MostrarGenF(stAlumno ArrayAlumnos[],int validos, char genero);
void MostrarGenM(stAlumno ArrayAlumnos[],int validos, char genero);
void MostrarGenO(stAlumno ArrayAlumnos[],int validos, char genero);
void MostrarAlumnosGen(stAlumno ArrayAlumnos[],int validos, char genero);
int ContarGenF(stAlumno ArrayAlumnos[],int validos, char genero);
int ContarGenM(stAlumno ArrayAlumnos[],int validos, char genero);
int ContarGenO(stAlumno ArrayAlumnos[],int validos, char genero);
int ContarAlumnosGen(stAlumno ArrayAlumnos[],int validos, char genero);

///Main
///////////////////////////////////////////////////////////////////////////////

int main()
{
    setlocale(LC_ALL, "spanish");

    //stAlumno alumno1;
    //CargarAlumno(&alumno1);
    //MostrarAlumno(alumno1);

    int validos=0;

    int matricula=0;

    char genero;

    int cantgenero=0;

    stAlumno ArrayAlumnos[100];



    int menu=0;

    do
    {
        system("color f0");
        system("cls");

        printf("Seleccione una opcion:\n\n");

        printf(" 1. Cargar alumnos.\n");
        printf(" 2. Mostrar alumnos.\n");
        printf(" 3. Buscar alumno por matricula.\n");
        printf(" 4. Ordenar alumnos por matricula\n");
        printf(" 5. Mostrar alumnos segun genero.\n");
        printf(" 6. Ordernar alumnos alfabeticamente.\n");
        printf("\n7. Salir.\n\n");

        scanf("%d", &menu);

        switch(menu)
        {

        case 1:
            ///cargar array de alumnos

            system("cls");

            printf("Se va a realizar la carga de alumnos.\n\n");

            validos=CargarArrayAlumnos(ArrayAlumnos, 100);

            break;

        case 2:
            ///Mostrar array de alumnos

            system("cls");

            if(validos>0)
            {
                printf("Alumnos cargados.\n");
                MostrarArrayAlumnos(ArrayAlumnos, validos);
            }
            else
            {
                printf("No se cargaron alumnos. ");
            }

            system("pause");
            break;

        case 3:
            ///Mostrar por numero de matricula

            system("cls");

            char com;

            if(validos>0)
            {
                do
                {
                    printf("Ingrese numero de matricula: ");
                    scanf("%d", &matricula);

                    printf("\n");

                    MostrarPorMatricula(ArrayAlumnos, validos, matricula);

                    printf("\n¿Desea buscar otro alumno? [s/n]");
                    fflush(stdin);
                    scanf("%c", &com);

                    system("cls");

                }
                while(com=='s');

            }
            else
            {
                printf("No se cargaron alumnos. ");
            }

            break;

        case 4:
            ///Ordenacion por seleccion (Criterio: Matricula)

            system("cls");

            if(validos>0)
            {
                printf("Alumnos ordenados de menor a mayor segun su matricula.\n");

                OrdSelecAlumno(ArrayAlumnos, validos);
                MostrarArrayAlumnos(ArrayAlumnos, validos);
            }
            else
            {
                printf("No se cargaron alumnos.");
            }


            system("pause");
            break;

        case 5:
            ///Contar y mostrar alumnos de un genero determinado

            system("cls");

            char com2;

            if(validos>0)
            {

                do
                {
                    printf("Ingrese genero [f/m/o]: ");

                    fflush(stdin);
                    scanf("%c", &genero);

                    cantgenero=ContarAlumnosGen(ArrayAlumnos, validos, genero);

                    printf("\nSe encontraron %d alumnos de genero %c.\n\n", cantgenero, genero);

                    MostrarAlumnosGen(ArrayAlumnos, validos, genero);

                    printf("\n¿Desea mostrar otro genero? [s/n]");
                    fflush(stdin);
                    scanf("%c", &com2);

                    system("cls");

                }
                while(com2=='s');
            }
            else
            {
                printf("No se cargaron alumnos. ");
            }

            break;

        case 6:
            ///Ordenacion por insercion (Criterio:Nombre)
            system("cls");

            if(validos>0)
            {
                printf("Alumnos ordenados alfabeticamente.\n");

                OrdInsercionAlumnos(ArrayAlumnos, validos);
                MostrarArrayAlumnos(ArrayAlumnos, validos);
            }
            else
            {
                printf("No se cargaron alumnos.");
            }

            system("pause");
            break;

        case 7:
            break;

        default:
            printf("\nOpcion Inconrrecta. ");
            system("pause");
        }
    }
    while(menu !=7);

    system("cls");
    printf("Gracias, vuelva prontos!\n");
    system("pause");

    return 0;
}

///Funciones
///////////////////////////////////////////////////////////////////////////////

///Cargar alumno
stAlumno CargarAlumno()
{
    stAlumno alumno;

    printf("Ingrese N°Matricula: ");
    scanf("%d",&alumno.matricula);

    printf("Ingrese Nombre: ");
    fflush(stdin);
    gets(alumno.nombre);

    printf("Ingrese Genero [m/f/o]: ");
    fflush(stdin);
    scanf("%c", &alumno.genero);

    return alumno;
}

///Mostrar alumno
void MostrarAlumno(stAlumno alumno)
{
    printf("--------------------------\n");
    printf("Matricula N°: ");
    printf("%d",alumno.matricula);

    printf("\nNombre: ");
    printf("%s",alumno.nombre);

    printf("\nGenero: ");
    printf("%c",alumno.genero);
    printf("\n--------------------------\n");
}

///////////////////////////////////////////////////////////////////////////////

///Cargar array de alumnos
int CargarArrayAlumnos(stAlumno ArrayAlumnos[], int dimension)
{
    int i=0;
    char com='s';

    int nmatricula=0;
    char genero;

    int validoint=0;
    int flag=0;


    while(i<dimension && com=='s')
    {
        flag=0;

        printf("Alumno %d:", i+1);
        printf("\n--------------------------\n");

        printf("Ingrese N°Matricula: ");

        while(flag==0)
        {
            fflush(stdin);
            validoint=scanf("%d", &nmatricula);
            if(validoint !=0)
            {
                ArrayAlumnos[i].matricula=nmatricula;
                flag=1;
            }
            else
            {
                printf("\nDato invalido. La matricula debe ser de numeros enteros.\n\n");
                printf("Ingrese N°Matricula: ");
            }
        }

        flag=0;

        printf("Ingrese Nombre: ");
        fflush(stdin);
        gets(ArrayAlumnos[i].nombre);

        printf("Ingrese Genero [m/f/o]: ");

        while(flag==0)
        {
            fflush(stdin);
            scanf("%c", &genero);
            if(genero=='f'||genero=='m'||genero=='o')
            {
                ArrayAlumnos[i].genero=genero;
                flag=1;
            }
            else
            {
                printf("\nDato invalido. Generos [f/m/o].\n\n");
                printf("Ingrese Genero: ");
            }
        }
        printf("\n--------------------------\n");

        printf("\n¿Desea cargar otro alumno? [s/n]: ");
        fflush(stdin);
        scanf("%c", &com);

        printf("\n");

        i++;
    }

    return i;
}

///Mostrar array alumnos
void MostrarArrayAlumnos(stAlumno ArrayAlumnos[], int validos)
{
    for (int i=0; i<validos; i++)
    {
        MostrarAlumno(ArrayAlumnos[i]);
    }
}

///////////////////////////////////////////////////////////////////////////////

///Buscar posicion de una matricula
int PosMatricula(stAlumno ArrayAlumnos[],int validos,int matricula)
{
    int i=0;
    int flag=0;
    int pos=-1;

    while(i<validos && flag==0)
    {
        if(ArrayAlumnos[i].matricula==matricula)
        {
            flag=1;
            pos=i;
        }
        i++;
    }

    return pos;
}

///Mostrar alumno por matricula
void MostrarPorMatricula(stAlumno ArrayAlumnos[],int validos,int matricula)
{
    int pos=0;
    pos=PosMatricula(ArrayAlumnos, validos, matricula);

    if(pos!=-1)
    {
        MostrarAlumno(ArrayAlumnos[pos]);
    }
    else
    {
        printf("No se encontro un alumno con esa matricula.\n");
    }
}

///////////////////////////////////////////////////////////////////////////////

///Ordenacion por seleccion
///Buscar posicion matricula menor
/*int PosMatriculaMenor(stAlumno ArrayAlumnos[],int validos,int pos)
{
    stAlumno menor=ArrayAlumnos[pos];
    int posmenor=pos;
    int index=pos+1;

    for(int i=index;i<validos;i++)
    {
        if(ArrayAlumnos[i].matricula<menor.matricula)
        {
            menor=ArrayAlumnos[i];
            posmenor=i;
        }
    }

    return posmenor;

}*/

int PosMatriculaMenor(stAlumno ArrayAlumnos[],int validos,int pos)
{
    int menor=ArrayAlumnos[pos].matricula;
    int posmenor=pos;
    int index=pos+1;

    for(int i=index; i<validos; i++)
    {
        if(ArrayAlumnos[i].matricula<menor)
        {
            menor=ArrayAlumnos[i].matricula;
            posmenor=i;
        }
    }

    return posmenor;
}

///Ordenacion por seleccion por numero de matricula
void OrdSelecAlumno(stAlumno ArrayAlumnos[],int validos)
{
    stAlumno aux;
    int posmenor=0;

    for(int i=0; i<validos-1; i++)
    {
        posmenor=PosMatriculaMenor(ArrayAlumnos, validos, i);
        ///Intercambio
        aux=ArrayAlumnos[i];
        ArrayAlumnos[i]=ArrayAlumnos[posmenor];
        ArrayAlumnos[posmenor]=aux;
    }
}

///////////////////////////////////////////////////////////////////////////////

///Ordenacion por insercion
///Insertar nuevo alumno
int InstertarAlumnoNuevo(stAlumno ArrayAlumnos[],int validos,stAlumno alumnonuevo)
{
    int i=validos-1;

    while(i>=0 && alumnonuevo.matricula < ArrayAlumnos[i].matricula)
    {
        ArrayAlumnos[i+1]=ArrayAlumnos[i];
        i--;
    }

    ArrayAlumnos[i+1]=alumnonuevo;

    return validos+1;
}

void InstertarAlumno(stAlumno ArrayAlumnos[],int pos,stAlumno alumno)
{
    int i=pos;

    while(i>=0 && strcmp(alumno.nombre,ArrayAlumnos[i].nombre)<0)
    {
        ArrayAlumnos[i+1]=ArrayAlumnos[i];
        i--;
    }

    ArrayAlumnos[i+1]=alumno;
}

void OrdInsercionAlumnos(stAlumno ArrayAlumnos[],int validos)
{
    int i=0;
    int pos=0;

    for(i=0;i<validos-1;i++)
    {
        pos=i;
        InstertarAlumno(ArrayAlumnos, pos, ArrayAlumnos[i+1]);
    }
}

///////////////////////////////////////////////////////////////////////////////

///Mostrar por genero F
void MostrarGenF(stAlumno ArrayAlumnos[],int validos, char genero)
{
    for(int i=0; i<validos; i++)
    {
        if(ArrayAlumnos[i].genero=='f')
        {
            MostrarAlumno(ArrayAlumnos[i]);
        }
    }
}

///Mostrar por genero M
void MostrarGenM(stAlumno ArrayAlumnos[],int validos, char genero)
{
    for(int i=0; i<validos; i++)
    {
        if(ArrayAlumnos[i].genero=='m')
        {
            MostrarAlumno(ArrayAlumnos[i]);
        }
    }
}

///Mostrar por genero O
void MostrarGenO(stAlumno ArrayAlumnos[],int validos, char genero)
{
    for(int i=0; i<validos; i++)
    {
        if(ArrayAlumnos[i].genero=='o')
        {
            MostrarAlumno(ArrayAlumnos[i]);
        }
    }
}

///Mostrar alumnos segun genero
void MostrarAlumnosGen(stAlumno ArrayAlumnos[],int validos, char genero)
{
    if(genero=='f')
    {
        MostrarGenF(ArrayAlumnos, validos,'f');
    }
    else if(genero=='m')
    {
        MostrarGenM(ArrayAlumnos, validos,'m');
    }
    else if(genero=='o')
    {
        MostrarGenO(ArrayAlumnos, validos,'o');
    }
    else
    {
        printf("Dato invalido. Generos: [f/m/o]\n");
    }
}

///////////////////////////////////////////////////////////////////////////////

///Contar por genero F
int ContarGenF(stAlumno ArrayAlumnos[],int validos, char genero)
{
    int flag=0;

    for(int i=0; i<validos; i++)
    {
        if(ArrayAlumnos[i].genero=='f')
        {
            flag++;
        }
    }

    return flag;
}

///Contar por genero M
int ContarGenM(stAlumno ArrayAlumnos[],int validos, char genero)
{
    int flag=0;

    for(int i=0; i<validos; i++)
    {
        if(ArrayAlumnos[i].genero=='m')
        {
            flag++;
        }
    }

    return flag;
}

///Contar por genero O
int ContarGenO(stAlumno ArrayAlumnos[],int validos, char genero)
{
    int flag=0;

    for(int i=0; i<validos; i++)
    {
        if(ArrayAlumnos[i].genero=='o')
        {
            flag++;
        }
    }

    return flag;
}

///Contar alumnos segun genero
int ContarAlumnosGen(stAlumno ArrayAlumnos[],int validos, char genero)
{
    int cantidad=0;

    if(genero=='f')
    {
        cantidad=ContarGenF(ArrayAlumnos, validos,'f');
    }
    else if(genero=='m')
    {
        cantidad=ContarGenM(ArrayAlumnos, validos,'m');
    }
    else if(genero=='o')
    {
        cantidad=ContarGenO(ArrayAlumnos, validos,'o');
    }
    else
    {
        //printf("Dato invalido. Generos: [f/m/o]\n");
    }

    return cantidad;
}
