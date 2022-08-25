///Cargar un alumno
stAlumno CargarUnAlumno()
{
    stAlumno alumno;

    printf("--------------\n");
    printf("LEGAJO: ");
    scanf("%d", &alumno.legajo);

    printf("NOMBRE Y APELLIDO: ");
    fflush(stdin);
    gets(alumno.nombreYapellido);

    printf("EDAD: ");
    scanf("%d", &alumno.edad);

    printf("ANIO: ");
    scanf("%d", &alumno.anio);
    printf("--------------\n");

    return alumno;
}

///Guardar un alumno en un archivo
void GuardarUnAlumno(stAlumno alumno)
{
    FILE *BufferAlumno = fopen(arAlumnos, "ab");

    if(BufferAlumno)
    {
        fwrite(&alumno, sizeof(stAlumno), 1, BufferAlumno);
        fclose(BufferAlumno);
    }
}

///Guardar alumnos en un archivo
void GuardarAlumnos()
{
    char com='s';

    while(com=='s')
    {
        GuardarUnAlumno(CargarUnAlumno());
        printf("Desea cargar otro alumno? [s/n]: ");
        fflush(stdin);
        scanf("%c", &com);
    }
}

///Mostrar un alumno
void MostrarUnAlumno(stAlumno alumno)
{
    printf("--------------\n");
    printf("LEGAJO: %d", alumno.legajo);
    printf("\nNOMBRE: %s", alumno.nombreYapellido);
    printf("\nEDAD: %d", alumno.edad);
    printf("\nANIO: %d", alumno.anio);
    printf("\n--------------\n");
}

///Mostrar alumnos de un archivo
void MostrarAlumnos()
{
    stAlumno alumno;

    FILE *BufferAlumnos = fopen(arAlumnos, "rb");

    if(BufferAlumnos)
    {
        while(fread(&alumno,sizeof(stAlumno),1,BufferAlumnos)>0)
        {
            MostrarUnAlumno(alumno);
        }
        fclose(BufferAlumnos);
    }
}

///Pasar a una pila el legajo de los alumnos mayores de edad
void AlumnosToPilaME(Pila *pilita)
{
    stAlumno alumno;

    FILE *BufferAlumnos = fopen(arAlumnos, "rb");

    if(BufferAlumnos)
    {
        while(fread(&alumno,sizeof(stAlumno),1,BufferAlumnos)>0)
        {
            if(alumno.edad >= 18)
            {
                apilar(pilita, alumno.legajo);
            }
        }
        fclose(BufferAlumnos);
    }
}

///Contar alumnos mayores a una edad
int ContarAlumnosMayoresAEdad(int edad)
{
    stAlumno alumno;
    int cant=0;

    FILE *BuffferAlumno = fopen(arAlumnos, "rb");

    if(BuffferAlumno)
    {
        while(fread(&alumno, sizeof(stAlumno), 1, BuffferAlumno)>0)
        {
            if(alumno.edad > edad)
            {
                cant++;
            }
        }
        fclose(BuffferAlumno);
    }

    return cant;
}

///Mostrar alumnos de un rango de edad
void MostrarPorRangoEdad(int desde, int hasta)
{
    stAlumno alumno;

    FILE *BufferAlumnos = fopen(arAlumnos, "rb");

    if(BufferAlumnos)
    {
        while(fread(&alumno, sizeof(stAlumno),1,BufferAlumnos)>0)
        {
            if(alumno.edad>desde && alumno.edad<hasta)
            {
                printf("%s\n", alumno.nombreYapellido);
            }
        }
        fclose(BufferAlumnos);
    }
}

///Mostrar alumno de mayor edad
void MostrarMayor()
{
    stAlumno mayor, aux;

    FILE *BufferAlumno = fopen(arAlumnos, "rb");

    if(BufferAlumno)
    {
        fread(&mayor, sizeof(stAlumno), 1,BufferAlumno);

        while(fread(&aux, sizeof(stAlumno), 1, BufferAlumno)>0)
        {
            if(aux.edad > mayor.edad)
            {
                mayor=aux;
            }
        }

        MostrarUnAlumno(mayor);

        fclose(BufferAlumno);
    }
}

///Contar alumnos de determinado año
int ContarAlumnosAnio(int anio)
{
    stAlumno alumno;
    int cant=0;

    FILE *BufferAlumno = fopen(arAlumnos, "rb");

    if(BufferAlumno)
    {
        while(fread(&alumno,sizeof(stAlumno),1,BufferAlumno)>0)
        {
            if(alumno.anio==anio)
            {
                cant++;
            }
        }

        fclose(BufferAlumno);
    }

    return cant;
}

///Cargar arreglo de alumnos
int CargarArregloAlumnos(stAlumno arrayalumnos[], int dimension)
{
    int i=0;
    char com='s';

    while(i<dimension && com=='s')
    {
        arrayalumnos[i]=CargarUnAlumno();
        printf("\nDesea cargar otro alumno? [s/n]: ");
        fflush(stdin);
        scanf("%c", &com);
        i++;
    }

    return i;
}

///Mostrar arreglo de alumnos
void MostrarArregloAlumnos(stAlumno arrayalumnos[], int validos)
{
    for(int i=0; i<validos; i++)
    {
        MostrarUnAlumno(arrayalumnos[i]);
    }
}

///Pasar de arreglo al archivo
void ArregloToArchivo(stAlumno arrayalumnos[], int validos)
{
    FILE *BufferAlumno = fopen(arAlumnos, "ab");

    if(BufferAlumno)
    {
        fwrite(arrayalumnos, sizeof(stAlumno), validos, BufferAlumno);

        fclose(BufferAlumno);
    }
}

///Pasar de arreglo al archivo filtro
void ArregloToArchivoFiltro(stAlumno arrayalumnos[], int validos)
{
    FILE *BufferAlumno = fopen(arAlumnos, "ab");

    int i=0;
    if(BufferAlumno)
    {
        while (i<validos)
        {
            if(arrayalumnos[i].edad > 18)
                fwrite(&arrayalumnos[i], sizeof(stAlumno), 1, BufferAlumno);
            i++;
        }

        fclose(BufferAlumno);
    }
}

///Pasar de archivo al arreglo
int ArchivoToArreglo(stAlumno arrayalumnos[], int dimension)
{
    FILE *Bufferalumno = fopen(arAlumnos, "rb");
    int i=0;

    if(Bufferalumno)
    {
        while(i<dimension && fread(&arrayalumnos[i], sizeof(stAlumno), 1, Bufferalumno)>0)
        {
            i++;
        }
        fclose(Bufferalumno);
    }

    return i;
}

///Pasar de archivo al arreglo con filtro de año
int ArchivoToArregloAnio(stAlumno arrayalumnos[], int dimension, int anio)
{
    stAlumno alumno;

    FILE *Bufferalumno = fopen(arAlumnos, "rb");

    int i=0;

    if(Bufferalumno)
    {
        while(i<dimension && fread(&alumno, sizeof(stAlumno), 1, Bufferalumno) > 0)
        {
            if(alumno.anio == anio)
            {
                arrayalumnos[i]=alumno;
                i++;
            }
        }
        fclose(Bufferalumno);
    }
    return i;
}

///Contar registros
int ContarRegistros(char nombrearchivo[], int tstruct)
{
    FILE *Buffer = fopen(nombrearchivo, "rb");

    fseek(Buffer,0,SEEK_END);

    int cant=ftell(Buffer);

    int cantregistros=cant/tstruct;

    fclose(Buffer);

    return cantregistros;
}

///Mostrar por posicion
void MostrarPos(int pos)
{
    int cant=ContarRegistros(arAlumnos, sizeof(stAlumno));

    if(cant>pos)
    {
        stAlumno alumno;
        FILE *bufferalumno = fopen(arAlumnos,"rb");

        if(bufferalumno)
        {
            {
                fseek(bufferalumno, sizeof(stAlumno)*pos,SEEK_SET);

                fread(&alumno, sizeof(alumno),1,bufferalumno);

                MostrarUnAlumno(alumno);
            }
            fclose(bufferalumno);
        }
        else
        {
            printf("No se cargaron datos al archivo");
        }
    }
    else
    {
        printf("No existe la posicion en el archivo");
    }
}
