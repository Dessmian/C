#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* se ingresan numeros enteros (no se sabe cuantos). Los numeros tiene que estar comprendidos entre -500 y 500.
Determinar:
1- Cuantos numeros pares.
2- Cuantos positivos.
3- Cuantos negativos.
4- Cuantas veces se ingreso el 0.
5- Promedio de numeros positivos.
6- Maximo y minimo (En que orden o lugar se ingreso) (Utilizar flags).
7- La suma de los negativos.
8- La diferencia entre positivos y negativos.
9- Cuantos numeros estan entre -239 y 5. */ //github.com/german2017


int contarPositivos ( int numeroIngresado );
int contarPositivos ( int numeroIngresado ) ;
int contarNegativos ( int numeroIngresado ) ;
int contarPares ( int numeroIngresado ) ;
int contarCeros ( int numeroIngresado ) ;
int sumarPositivos ( int numeroIngresado ) ;
void encuentraMaximo ( int numeroIngresado , int numeroMaximo , int flagMaximo ) ;
void encuentraMinimo ( int numeroIngresado , int numeroMinimo , int flagMinimo ) ;
int sumarNegativos ( int numeroIngresado ) ;
int contarCuantosPertenecenAlConjunto ( int numeroIngresado ) ;
void inmprimirValores ( int cantidadPositivos , int cantidadNegatios , int cantidadPares , int cantidadCeros , int promedioDePositivos , int numeroMaximo , int flagMaximo , int numeroMinimo , int flagMinimo , int sumaDeNegativos , int diferenciaEntreSumas , int cuantosPertenecen ) ;

int main()
{
    int numeroIngresado ;
    char deseaContinuar;
    int cantidadPares ;
    int cantidadPositivos ;
    int cantidadNegativos ;
    int cantidadCeros ;
    int sumaDePositivos ;
    float promedioDePositivos ;
    int numeroMaximo = 0 ;
    int numeroMinimo = 0 ;
    int flagMaximo = 0 ;
    int flagMinimo = 0 ;
    int sumaDeNegativos = 0 ;
    int diferenciaEntreSumas ;
    int cuantosPertenecen ;

    do
    {
        printf ( "Ingrese un numero entre -500 y 500 : \n" ) ;
        scanf ( "%d", &numeroIngresado ) ;
        fflush ( stdin ) ;
        while ( numeroIngresado > 500 || numeroIngresado < -500 )
        {
            printf ( "Error. Ingrese un numero entre -500 y 500 : \n" ) ;
            scanf ( "%d", &numeroIngresado ) ;
        }
        cantidadPositivos = contarPositivos ( numeroIngresado ) ;
        cantidadNegativos = contarNegativos ( numeroIngresado ) ;
        cantidadPares = contarPares ( numeroIngresado ) ;
        cantidadCeros = contarCeros ( numeroIngresado ) ;
        sumaDePositivos = sumarPositivos ( numeroIngresado ) ;
        promedioDePositivos = sumaDePositivos / cantidadPositivos ;
        encuentraMaximo ( numeroIngresado , numeroMaximo , flagMaximo ) ;
        encuentraMinimo ( numeroIngresado , numeroMinimo , flagMinimo ) ;
        sumaDeNegativos = sumarNegativos( numeroIngresado ) ;
        diferenciaEntreSumas = sumaDePositivos - sumaDeNegativos ;
        cuantosPertenecen = contarCuantosPertenecenAlConjunto ( numeroIngresado ) ;


        printf( "Desea continuar? S o N\n" ) ;
        scanf ( "%c", &deseaContinuar ) ;
        fflush ( stdin ) ;
        while ( deseaContinuar != 'S' && deseaContinuar != 'N')        {
            printf ( "Error, caracter invalido. Ingrese S para continuar o N para terminar.\n" ) ;
            scanf ( "%c", &deseaContinuar ) ;
        }
    }
    while ( deseaContinuar == 'S' ) ;
    inmprimirValores ( cantidadPositivos , cantidadNegativos , cantidadPares , cantidadCeros , promedioDePositivos , numeroMaximo , flagMaximo , numeroMinimo , flagMinimo , sumaDeNegativos , diferenciaEntreSumas , cuantosPertenecen ) ;
    return 0 ;
}
int contarPositivos ( int numeroIngresado ){
    int contadorPositivos = 0 ;
    if ( numeroIngresado > 0 )    {
        contadorPositivos ++ ;
    }
    return contadorPositivos ;
}
int contarNegativos ( int numeroIngresado ){
    int contadorNegativos = 0 ;
    if ( numeroIngresado < 0 )    {
        contadorNegativos ++ ;
    }
    return contadorNegativos ;
}
int contarPares ( int numeroIngresado ) {
    int contadorPares = 0 ;
    if ( (numeroIngresado % 2 ) == 0 ) {
        contadorPares ++ ;
    }
    return contadorPares ;
}
int contarCeros ( int numeroIngresado ) {
    int contadorCeros = 0 ;
    if ( numeroIngresado == 0 )    {
        contadorCeros ++ ;
    }
    return contadorCeros ;
}
int sumarPositivos( int numeroIngresado ) {
    int sumaPositivos = 0 ;
    if ( numeroIngresado > 0 ){
        sumaPositivos = sumaPositivos + numeroIngresado ;
    }
    return sumaPositivos ;
}
void encuentraMaximo ( int numeroIngresado , int numeroMaximo , int flagMaximo ) {
    int i = 0 ;
    i ++ ;
    if ( numeroIngresado > numeroMaximo ) {
        numeroMaximo = numeroIngresado ;
        flagMaximo = i ;
    }
    return ;
}
void encuentraMinimo ( int numeroIngresado , int numeroMinimo , int flagMinimo ) {
    int i = 0 ;
    i ++ ;
    if ( numeroIngresado < numeroMinimo ) {
        numeroMinimo = numeroIngresado ;
        flagMinimo = i ;
    }
    return ;
}
int sumarNegativos ( int numeroIngresado ) {
    int negativosSumados = 0 ;
    if ( numeroIngresado < 0 ) {
        negativosSumados = negativosSumados + numeroIngresado ;
    }
    return negativosSumados ;
}
int contarCuantosPertenecenAlConjunto ( int numeroIngresado ) {
    int i = 0 ;
    if ( numeroIngresado >= -239 && numeroIngresado <= 5 ) {
        i ++ ;
    }
    return i ;
}
void inmprimirValores ( int cantidadPositivos , int cantidadNegatios , int cantidadPares , int cantidadCeros , int promedioDePositivos , int numeroMaximo , int flagMaximo , int numeroMinimo , int flagMinimo , int sumaDeNegativos , int diferenciaEntreSumas , int cuantosPertenecen ) {
    printf ( "1 - La cantidad de numeros pares es: %d" , cantidadPares ) ;
    printf ( "\n2 - La cantidad de positivos es: %d" , cantidadPositivos ) ;
    printf ( "\n3 - La cantidad de negativos es %d" , cantidadNegatios ) ;
    printf ( "\n4 - La cantidad de 0 es: %d" , cantidadCeros ) ;
    printf ( "\n5 - El promedio de los positivos es: %d" , promedioDePositivos ) ;
    printf ( "\n6- El numero maximo es: %d" , numeroMaximo ) ;
    printf ( " y fue ingresado en la iteracion %d" , flagMaximo ) ;
    printf ( ". El numero minino es: %d" , numeroMinimo ) ;
    printf ( " y fue ingresado en la iteracion %d" , flagMinimo ) ;
    printf ( "\n7- La suma de los negativos es: %d" , sumaDeNegativos ) ;
    printf ( "\n8- La diferencia entre positivos y negativos es: %d" , diferenciaEntreSumas ) ;
    printf ( "\n9- La cantidad de numeros entre -239 y 5 es: %d" , cuantosPertenecen ) ;
    return ;
}





























