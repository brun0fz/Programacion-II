#include <stdio.h>
#include <stdlib.h>

//************ TRABAJO PRACTICO N° 3 : recursividad ********************************************************************
/*
1. Calcular el factorial de un número en forma recursiva.
2. Calcular la potencia de un número en forma recursiva.
3. Recorrer un arreglo y mostrar sus elementos en forma recursiva.
4. Recorrer un arreglo comenzando desde la posición 0 y mostrar sus elementos en
forma invertida (recursivo).
5. Determinar en forma recursiva si un arreglo es capicúa.
6. Sumar en forma recursiva los elementos de un arreglo de enteros.
7. Buscar el menor elemento de un arreglo en forma recursiva.

// ****************** recursiv con archivos *************************************
8. Buscar el menor elemento de un archivo números de enteros.
9. Invertir los elementos de un archivo de números enteros.
10.Recorrer un archivo y mostrar sus elementos en forma invertida.
11. Ingresar valores a una variable (por teclado) y mostrarlo en el orden inverso
(hasta ingresar un ‘*’). NO usar arreglos.
12.Determinar si un arreglo contiene un determinado elemento*/


/// 1 Calcular el factorial de un número en forma recursiva

int factorialRecursivo (int x) {
    int rta;
    if(x==0){    // corta en 0 en vez de 1 por si quiero calcular factorial de 0
        rta=1;  //ojo! ver en qué casos 0 o 1- suma 0, multiplic 1
    }
    else {
        rta= x * factorialRecursivo(x-1);
    }
    return rta;
}


int factorialPro(int x){
    return (x==0) ? 1 : x*factorialPro(x-1);
}

/// 2 Calcular la potencia de un número en forma recursiva

int potencia(int x, int factor)
{
    int rta;
    if(factor==0)
    {
        rta=1; // devuelve 1 y en el camino de vuelta empieza a multiplicarse y acumularse
    }          // 4*1, 4*4, 4*16, 4*68...
    else
    {
        rta= x*potencia(x,factor-1);
    }
    return rta;
}


/// 3 Recorrer un arreglo y mostrar sus elementos en forma recursiva

// aux cargar arreglo
int cargaarreglo(int A[], int dim)
{
    int i=0;
    for (i=0; i<dim; i++)
    {
        printf("\ningrese un elemento: ");
        scanf("%d", &A[i]);
    }
    return i;
}

// otra:
int cargaArregloIterativaRandomConValidos (int a[],int v, int dim){
    for(;v<dim;v++){
        a[v]=rand()%10;
    }
    return v;
}

// aux iterativa de muestra
void muestraArregloIterativo(int a[], int v){
    for(int i=0;i<v;i++){
        printf("%c %d ", (i%10==0)?'\n':'-', a[i]);
    }
}

void muestraArregloRecursivo1(int A[], int val, int i){
    if(i==val){
        printf("\n");
    }
    else {
        printf(" %d  ", A[i]);
        muestraArregloRecursivo1(A, val, i+1);
        /// printf(" %d  ", A[i]);  /// ojo! es diferente ponerlo arriba o abajo
    }
}


void muestraArregloRecursivo2(int A[], int val, int i){
    if(i==val-1){
        printf(" %d  ", A[i]);
        printf("\n");
    }
    else {
        printf(" %d  ", A[i]);
        muestraArregloRecursivo2(A, val, i+1);
    }
}


void muestraArregloRecursivoSolTrivImplicita(int arreglo[], int validos, int i){
// la condición de corte esta implicita, cuando llega al final del arreglo no hace nada
    if(i<validos){
       printf(" %d  ", arreglo[i]);
       muestraArregloRecursivoSolTrivImplicita (arreglo, validos, i+1);

       printf("\n");
    }
}


int imprimirArregloRecursivoConRetorno(int arreglo[], int validos)
{
// es mejor porq no necesita recibir i por parametro, pero necesita usar retorno
    if(validos!=0){
        imprimirArregloRecursivoConRetorno(arreglo, validos-1);
        return printf("%d ", arreglo[validos-1]); // lo retorna en vez de imprimir
                           //porque si imprime, quedaria de atras hacia adelante
    }
    printf("\n");
}


/// 4. Recorrer un arreglo comenzando desde la posición 0 y mostrar sus elementos
/// en forma invertida (recursivo).

void muestraArregloInvertido(int A[], int i, int cant)
{
    if(i==cant-1)
        printf(" %d", A[i]);
    else {
        muestraArregloInvertido(A, i+1, cant);
        printf(" %d", A[i]);
    }
}

/// 5 Determinar en forma recursiva si un arreglo es capicúa

/* VERSION CON SOL TRIVIAL EXPRESA, PERO MAS FEA :
int capicuaFeo (int A[], int i, int validos)
{
    int rta;
    if(i<validos-1)
    {
        if(A[i]==A[validos-1]){
            rta= capicuaFeo(A,i+1,validos-1);
        }
        else{
            rta=0;  /// otra sol trivial
        }
    }
    else{
        rta=1; ///sol trivial: si llegó a que i no es < que validos-1 es porque todo era capicua
    }
    return rta;
}
*/

// CON SOL TRIVIAL IMPLICITA (si i no es < u no hace nada)
int capicua(int A[], int i, int validos)
{
    int rta=1;
    if(i<validos-1)
    {
        if(A[i]==A[validos-1])
        {
            rta=capicua(A,i+1,validos-1);
        }
        else
        {
         rta=0; // en cuanto encuentre un par distinto corta la recursion y devuelve 0
        }
    }
    return rta;
}



/// 6 Sumar en forma recursiva los elementos de un arreglo de enteros

int sumaArrayRecursiva1(int arreglo[], int validos, int i) ///ojo! el i va fuera!!
{
    int suma=0;
    if(i==validos-1){  //ver en qué casos llegar hasta validos o hasta 1 menos que validos
        suma = arreglo[i];
    }
    else{
        suma = arreglo[i] + sumaArrayRecursiva1(arreglo, validos, i+1);
    }
    return suma;
}

int sumaArrayRecursiva2(int arreglo[], int validos, int i) ///ojo! el i va fuera!!
{
    int suma=0;
    if(i==validos){  //ver en qué casos llegar hasta validos o hasta 1 menos que validos
        suma = 0;
    }
    else{
        suma = arreglo[i] + sumaArrayRecursiva2(arreglo, validos, i+1);
    }
    return suma;
}


int sumarRecursivoMejorada (int arr[], int validos)
{   // va de atras hacia adelante p/ no tener que usar i por parametro
    int rta;
    if(validos==0){
       rta=0;
    }
    else {
        rta= arr[validos-1] + sumarRecursivoMejorada (arr, validos-1);
    }
  return rta;
}


int sumaArregloRecursivoSolTrivImplicita (int a[], int v, int i){
    int suma=0;
    if(i<v){
        suma= a[i] + sumaArregloRecursivoSolTrivImplicita (a,v,i+1);
    }
    return suma;
}


int sumaArregloRecursivoPro(int a[], int v, int i){
    return (i<v) ? a[i]+sumaArregloRecursivoPro(a,v,i+1) : 0;
}



/// 7 Buscar el menor elemento de un arreglo en forma recursiva

int buscarMenorArregloSolTrivExpresa (int arr[], int validos, int i)
{
    int menor;
    if (i==validos-1){
        menor=arr[i]; // cuando llego al final del arreglo, retorno ese valor
    }                 // para comparar con los de las etapas recursivas anteriores
    else {
       menor= buscarMenorArregloSolTrivExpresa (arr, validos, i+1);
       if(menor>arr[i]){   // en esta compara en el camino de vuelta
            menor=arr[i];
       }
    }
 return menor;
}


int buscarMenorArraySolTrivImplicita(int array[],int validos,int i,int menor){
    if(i<validos){
        if(array[i] <= menor){  // en esta compara en el camino de ida
            menor = array[i];
        }
        menor = buscarMenorArraySolTrivImplicita (array,validos,i+1,menor);
    }
    return menor;
}


int buscaMenorPro(int a[], int v, int i){
    return (i==v-1) ? a[i] : int menor(buscaMenorPro(a,v,i+1), a[i]);
}


int buscaPosicionDelMenorEnArreglo(int Arr[],int Validos,int i,int PosMenor)
{
    if(i<Validos)
    {
        if(Arr[i]<Arr[PosMenor])
        {
            PosMenor=i;

        }
        PosMenor= buscaPosicionDelMenorEnArreglo(Arr,Validos,i+1,PosMenor);
    }
    return PosMenor;
}

/// ********************************** recursiv con archivos ****************************************

/// 8  Buscar el menor elemento de un archivo en forma recursiva

// funcion aux cargar archivos
void Cargar_Archivo(char Nombre[])
{
    FILE * archi=NULL;
    int Numeros=0;
    char control='s';

    archi=fopen(Nombre, "wb");
    if(archi != NULL)
    {
        while (control!='n')
        {
            printf("Ingrese un numero por favor: ");
            scanf("%d",&Numeros);
            fwrite(&Numeros,sizeof(int),1,archi);
            printf("Desea ingresar otro numero al archivo?? ");
            fflush(stdin);
            scanf("%c",&control);
        }
        fclose(archi);
    }
}

// funcion aux mostrar archivos
void Mostrar_Archivo(char Nombre[])
{
    FILE * archi=NULL;
    int Numeros=0;

    archi=fopen(Nombre, "rb");
    if(archi != NULL)
    {
        printf("\n\nContenido del archivo: ");
        while (fread(&Numeros,sizeof(int),1,archi)>0)
        {
            printf(" %d", Numeros);
        }
        fclose(archi);
    }
}


int buscarMenorArchivoPpalIterativa(char nombreArchivo[]){

     FILE * arch = fopen(nombreArchivo, "rb");
     int menor;
     if(arch){
       menor= buscarMenorArchivoAux(arch);
       fclose (arch);
     }
     return menor;
}


int buscarMenorArchivoAuxRecurs (FILE * arch){
    int menor;
    int valor;
//como lee y luego evalua, en cada llamada quedó guardado en valor lo leido
    if(fread(&valor,sizeof(int),1,arch)==0) // COND CORTE: no leyó nada, cuando llego al final del archivo
    {
        fseek(arch, -1*sizeof(int), SEEK_END); // me muevo uno para atras p poder leer
        fread(&menor, sizeof(int),1,arch); // leo el ultimo elemento para retornarlo
    }
    else {
        menor= buscarMenorArchivoAuxRecurs(arch);

        if(menor>valor){
            menor=valor;
        }
    }
    return menor;
}


/// 9  Invertir los elementos de un archivo

// funcion aux de la ppal
int cuentaRegistroArchivo(FILE * arch) {
    int cant=0;

    fseek(arch, 0, SEEK_END);
    cant=ftell(arch)/sizeof(int);

    return cant;
}

void invertirArchivoPpalIterativa(char nombreArchivo[]){

    FILE * arch = fopen(nombreArchivo, "r+b");

    if(arch){
        int cantidad=cuentaRegistroArchivo(arch);
        invertirArchivoAux(arch, cantidad, 0);
     }
     else {
        printf("Fallo la apertura del archivo...");
     }
     fclose(arch);
}


void invertirArchivoAuxRecurs(FILE * FP, int cantidad, int i)
{
    int ppio,fin;

    if(i<cantidad) // cond de corte implícita. va invirtiendo en el camino de ida
    {
    // leemos el 1° y el ultimo dato del archivo
            fseek(FP,sizeof(int)*(cantidad-1),0); // posiciono el cursor en el extremo final del archivo
            fread(&fin,sizeof(int),1,FP); // leemos el ultimo dato

            fseek(FP,sizeof(int)*i,0); // posiciono el cursor en el extremo inicial del archivo
            fread(&ppio,sizeof(int),1,FP); // leemos el primer dato
    // y ahora hacemos el intercambio
            fseek(FP,sizeof(int)*i,0);  // posiciono el cursor otra vez en el extremo inicial del archivo
            fwrite(&fin,sizeof(int),1,FP); // guardamos el ultimo al ppio

            fseek(FP,sizeof(int)*(cantidad-1),0); // posiciono el cursor otra vez en el extremo final del archivo
            fwrite(&ppio,sizeof(int),1,FP); // guardamos el 1° al final

            invertirArchivoAuxRecurs(FP, cantidad-1, i+1); // ahora hacemos la llamada recursiva
                                                    // con la aproximacion a la condicion de corte
    }
}


/// 10  Recorrer un archivo y mostrar sus elementos en forma invertida

void muestraArchivoInvertidoPpalIterativa(char nombre[])
{
    FILE *arch=fopen(nombre, "rb");

    if(arch!=NULL){
        printf("\n\nContenido del archivo invertido: ");
        muestraArchivoInvertidoAux(arch);
        fclose(arch);
    }
    else{
        printf("Houston... tenemos un problema...");
    }
}


void muestraArchivoInvertidoAuxRecurs (FILE * arch)
{
    int valor;

    if(fread(&valor, sizeof(int),1,arch) == 0 ) { // cond corte explicita: llegué al final del archivo
            printf("\n"); // (solucion trivial)
     }
     else {
            fread(&valor, sizeof(int),1,arch); // leo ese elemento ... y me aproximo a la condicion de corte
            muestraArchivoInvertidoAuxRecurs (arch);    // llamada recursiva
            printf(" %d", valor);           // y muestro el elemento cuando vuelve de la recursion..
     }

    /* otra manera: no queda explicita la condicion de corte con su solucion final... si llegue al final del archivo no hago nada...
    if(fread(&valor, sizeof(int),1,arch)>0)
    {
        muestraArchivoInvertidoAuxRecurs (arch);
        printf(" %d", valor);
    } */
}


/// 11. Ingresar valores a una variable (por teclado) y mostrarla
/// en el orden inverso (hasta ingresar un ‘*’). NO usar arreglos.

void ingresaPorTecladoYMuestraInvertido()
{
    char valor;
    printf("\nIngrese un caracter (corta con *): \n");
    fflush(stdin);
    scanf("%c", &valor);
    /* con cond de corte explicita:
     if(valor=='*')
     {
         printf("\n "); /// O: printf("%c ",valor);
     }
     else
     {
         ingresaPorTecladoYMuestraInvertido();
         printf("%c  ",valor);
     }
     */
    /// con cond de corte implicita:
    if(valor != '*')
    {
        ingresaPorTecladoYMuestraInvertido();
        printf("%c ",valor);
    }
}



/// 12. Determinar si un arreglo contiene un determinado elemento.
/// la funcion retorna 0 si no lo encuentra, 1 si el elemento esta


int ExisteElementoEnArreglo(int A[], int validos, int i, int valor)
{
    int rta=0; // supongo que el elemento no esta
    if(i<validos)
    {
        if(A[i]==valor)
        {
            rta=1;
        }
        else
        {
            rta=ExisteElementoEnArreglo(A, validos, i+1, valor);
        }
    }
    return rta;
}


int determinaElementoEnArregloPro(int A[], int validos, int i, int valor)
{
    int rta=0; // supongo que el elemento no esta
    if(i<validos)
    {
        rta = (A[i]==valor) ? 1 : determinaElementoEnArregloPro(A, validos,i+1, valor);
    }
    return rta;
}



/// RECURSIVIDAD INDIRECTA: FUNCION PAR/IMPAR

int impar (int num)
{
    if (num==0)
    {
        return 0;
    }
    else
    {
        return par(num-1);
    }
}

int par (int num)
{
    if (num==0)
    {
        return 1;
    }
    else
    {
        return impar(num-1);
    }
}

/// Evitando el doble return
int imparPro(int num){
    return (num==0)? 0 : parPro(num-1);
}

int parPro(int num){
    return (num==0)? 1 : imparPro(num-1);
}


///*************************************  MAIN *******************************************////////////////////////////////////////////////


int main()
{
    printf("Hello RECURSIVIDAD!\n");

    int arreglo[5]={1,2,3,4,5};

/// Ej 1: factorial
    int factorial1= factorialIt(5);
    printf("factorial DE 5 iterativo: %d \n", factorial1);

    int factorialRe= factorialRecursivo(5);
    printf("factorial de 5 recursivo: %d \n", factorialRe);
    int factorial3= factorialPro(5);
    printf("factorial de 5 recursivo pro: %d \n\n", factorial3);

/// ej 2: Calcular la potencia de un número en forma recursiva.
    int pot= potencia(2, 3);
    printf("2 al cubo es: %d \n\n", pot);

/// Ej 3. Recorrer un arreglo y mostrar sus elementos en forma recursiva.
    printf("Muestra arreglo en forma recursiva en sus tres variantes: \n");
    muestraArregloRecursivo1 (arreglo, 5, 0);
    muestraArregloRecursivo2 (arreglo, 5, 0);
    muestraArregloRecursivoSolTrivImplicita (arreglo, 5, 0);
    imprimirArregloRecursivoConRetorno(arreglo, 5);
    printf("\n\n");

/// 4. Recorrer un arreglo comenzando desde la posición 0 y mostrar
/// sus elementos en forma invertida (recursivo).
    printf("Muestra arreglo en forma recursiva invertido: \n");
    muestraArregloInvertido(arreglo, 0, 5);
    printf("\n\n");

/// 5. Determinar en forma recursiva si un arreglo es capicúa.
    int arreglo2[5]={1,2,3,2,1];
    int rta5= capicua(arreglo2, 0, 5);
    if (rta5==0)
        printf("\n El arreglo NO es capicua\n");
    else
        printf("\n El arreglo ES capicua\n");

/// 6. Sumar en forma recursiva los elementos de un arreglo de enteros.
    int rta = SumaArrayIterativa(arreglo, 5);
    printf("suma arreglo iterativa: %d \n\n\n\n", rta);

    int rta2 = sumaArrayRecursiva1(arreglo, 5, 0);
    printf("suma arreglo recursiva 1 corta en validos -1: %d \n\n\n\n", rta2);
    int rta3= sumaArrayRecursiva2 (arreglo, 5, 0);
    printf("suma arreglo recursiva 2 corta en validos: %d \n", rta3);
    int rta4= sumaArrayRecursivaMejorada (arreglo, 5);
    printf("suma arreglo recursiva mejorada (no precisa validos por parametro): %d \n", rta4);
    int rta5= sumaArregloRecursivoSolTrivImplicita (arreglo, 5, 0);
    printf("suma arreglo recursiva con solucion trivial implicita: %d \n\n\n\n", rta5);
    int rta6= sumaArregloRecursivoPro(arreglo, 5, 0);
    printf("suma arreglo recursiva pro: %d \n\n\n\n", rta6);

/// 7. Buscar el menor elemento de un arreglo en forma recursiva.
    int posMenor= buscaPosicionDelMenorEnArreglo(arreglo, 5, 0, 0);
    printf("posicion del menor del arreglo: %d \n", posMenor);

    int menor1= buscarMenorArregloSolTrivExpresa(arreglo, 5, 0);
    printf("menor del arreglo funcion con sol trivial expresa: %d \n", menor1);
    int menor2= buscarMenorArraySolTrivImplicita(arreglo, 5, 0);
    printf("menor del arreglo funcion sol trivial implicita: %d \n", menor2);
    int menor= buscaMenorPro(arreglo, 5, 0);
    printf("menor del arreglo funcion pro: %d \n\n\n", menor);

/// ************** recursiv con archivos ***************************

/// 8. Buscar el menor elemento de un archivo números de enteros.
    cargar_Archivo("archivito");
    Mostrar_Archivo("archivito");
    printf("\n\n");
    int menorA= buscarMenorArchivoPpalIterativa("archivito");
    printf("El menor es %d\n", menorA);

/// 9. Invertir los elementos de un archivo de números enteros.
    invertirArchivoPpalIterativa("archivito");
    printf("\nInvierto archivo...");
    Mostrar_Archivo("archivito");

/// 10.Recorrer un archivo y mostrar sus elementos en forma invertida.
    muestraArchivoInvertidoPpalIterativa("archivito");

/// 11. Ingresar valores a una variable (por teclado) y mostrarlo en el orden inverso
/// (hasta ingresar un ‘*’). NO usar arreglos.
    ingresaPorTecladoYMuestraInvertido();

/// 12.Determinar si un arreglo contiene un determinado elemento
    int aBuscar3= 20;
    int rta7= ExisteElementoEnArreglo(arreglo2, 5, 0, aBuscar3);
    if (rta7==0)
        printf("\n El nro buscado %d NO esta en el arreglo\n", aBuscar3);
    else
        printf("\n El nro buscado %d SI esta en el arreglo\n", aBuscar3);


    return 0;
}
