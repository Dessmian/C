#include <stdio.h>
#include <stdlib.h>

/* se ingresan numeros enteros (no se sabe cuantos). Los numeros tiene que estar comprendidos entre -500 y 500.
Determinar:
1- Cuantos numeros pares. --
2- Cuantos positivos. --
3- Cuantos negativos. --
4- Cuantas veces se ingreso el 0. --
5- Promedio de numeros positivos. --
6- Maximo y minimo (En que orden o lugar se ingreso) (Utilizar flags). --
7- La suma de los negativos. --
8- La diferencia entre positivos y negativos. --
9- Cuantos numeros estan entre -239 y 5.  -- */

int main()
{
    int numeroIngresado ;
    int sumaDePositivos = 0 ;
    int cantidadDePositivos = 0 ;
    int sumaDeNegativos = 0 ;
    int cantidadDeNegativos = 0 ;
    int cantidadDeCeros = 0 ;
    int cantidadDePares = 0 ;
    int cantidadQueEstaEnElConjuntoIndicado = 0 ;
    int numeroMaximo = 0 ;
    int numeroMinimo = 0 ;
    int flagMaximo ;
    int flagMinimo ;
    int posicionDeIngreso = 0 ;
    float promedioDePositivos ;
    int diferenciaEntrePositivosYNegativos ;
    char deseaContinuar ;
    do {
        printf ( "Ingrese un numero entero entre -500 y 500\n" ) ;
        scanf ( "%d" , &numeroIngresado ) ;
        fflush ( stdin ) ;
        while ( numeroIngresado < -500 || numeroIngresado > 500 ) {
            printf ( "Error, dato invalido. Ingrese un numero entero entre -500 y 500\n" ) ;
            scanf ( "%d" , &numeroIngresado ) ;
            fflush ( stdin ) ;
        }
        posicionDeIngreso ++ ;
        if ( numeroIngresado > 0 ) {
            cantidadDePositivos ++ ;
            sumaDePositivos = sumaDePositivos + numeroIngresado ;
        } else if ( numeroIngresado < 0 ) {
            cantidadDeNegativos ++ ;
            sumaDeNegativos = sumaDeNegativos + numeroIngresado ;
        } else if ( numeroIngresado == 0 ) {
            cantidadDeCeros ++ ;
        }
        if ( (numeroIngresado % 2) == 0 ) {
            cantidadDePares ++ ;
        }
        if ( numeroIngresado >= -239 && numeroIngresado <= 5 ) {
            cantidadQueEstaEnElConjuntoIndicado ++ ;
        }
        if ( posicionDeIngreso == 1 ) {
            numeroMaximo = numeroIngresado ;
            numeroMinimo = numeroIngresado ;
            flagMaximo = posicionDeIngreso ;
            flagMinimo = posicionDeIngreso ;
        } else {
            if ( numeroIngresado < numeroMinimo ) {
                numeroMinimo = numeroIngresado ;
                flagMinimo = posicionDeIngreso ;
            }
            if ( numeroIngresado > numeroMaximo ) {
                numeroMaximo = numeroIngresado ;
                flagMaximo = posicionDeIngreso ;
            }
        }
        printf ( "Desea continuar? S o N\n" ) ;
        scanf ( "%c" , &deseaContinuar ) ;
        fflush ( stdin ) ;
        while ( deseaContinuar != 'S' && deseaContinuar != 'N') {
            printf ( "Error, dato invalido. Desea continuar? S o N\n" ) ;
            scanf ( "%c" , &deseaContinuar ) ;
            fflush ( stdin ) ;
        }
    } while ( deseaContinuar == 'S' ) ;
    promedioDePositivos = sumaDePositivos / cantidadDePositivos ;
    diferenciaEntrePositivosYNegativos = sumaDePositivos - sumaDeNegativos ;
    printf ( "1 - La cantidad de numeros pares es: %d" , cantidadDePares ) ;
    printf ( "\n2 - La cantidad de positivos es: %d" , cantidadDePositivos ) ;
    printf ( "\n3 - La cantidad de negativos es %d" , cantidadDeNegativos ) ;
    printf ( "\n4 - La cantidad de 0 es: %d" , cantidadDeCeros ) ;
    printf ( "\n5 - El promedio de los positivos es: %.02f" , promedioDePositivos ) ;
    printf ( "\n6- El numero maximo es: %d" , numeroMaximo ) ;
    printf ( " y fue ingresado en la iteracion %d" , flagMaximo ) ;
    printf ( ". El numero minino es: %d" , numeroMinimo ) ;
    printf ( " y fue ingresado en la iteracion %d" , flagMinimo ) ;
    printf ( "\n7- La suma de los negativos es: %d" , sumaDeNegativos ) ;
    printf ( "\n8- La diferencia entre positivos y negativos es: %d" , diferenciaEntrePositivosYNegativos ) ;
    printf ( "\n9- La cantidad de numeros entre -239 y 5 es: %d" , cantidadQueEstaEnElConjuntoIndicado ) ;
    return 0;
}
