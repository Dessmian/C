#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
int main()
{

    char nombre [] [10] = {"Jose", "Maria", "Juan", "Asdasd" } ;
    int nota [10] = {8, 5, 2, 4} ;
    int i ;
    int j ;
    int resultado ;

    resultado = strcmp ( "hola" , "hola" ) ;
    printf ( "minusculas %d\n" , resultado ) ;
    resultado = strcmp ( "Hola" , "hola" ) ;
    printf ( "primera %d\n" , resultado ) ;
    resultado = strcmp ( "hola" , "Hola" ) ;
    printf ( "segunda %d\n" , resultado ) ;
    resultado = strcmp ( "Hola" , "Hola" ) ;
    printf ( "mayusculas %d\n" , resultado ) ;


    for ( i = 0 ; i < 4 ; i++ )
    {
        for ( j = 0 ; j < 4 ; j++ )
        {
            //printf ( "%d ==> %d \n" , nota [i] , nota [j] ) ;
            //printf ( "test" ) ;
            if ( strcmp ( nombre [i] , nombre [j] ) == -1 )
            {
                int auxNota = nota [i] ;
                nota [i] = nota [j] ;
                nota [j] = auxNota ;
                char auxNombre [10] ;
                strcpy ( auxNombre, nombre [i] ) ;
                strcpy ( nombre [i], nombre [j] ) ;
                strcpy ( nombre [j], auxNombre ) ;

            }
        }
    }
    for ( i = 0 ; i < 4 ; i++ )
    {
        printf ( "alumno: %s nota: %d \n", nombre [i] , nota [i] ) ;
        //printf ( "nota : %d  \n", nota [i] ) ;
    }
    //ordenar en paralelo por numero
    /*for ( i = 0 ; i < 4 ; i++ )
    {
        for ( j = 0 ; j < 4 ; j++ )
        {
            //printf ( "%d ==> %d \n" , nota [i] , nota [j] ) ;
            printf ( "test" ) ;
            if ( nota [i] < nota [j] )
            {
                int auxNota = nota [i] ;
                nota [i] = nota [j] ;
                nota [j] = auxNota ;
                char auxNombre [10] ;
                strcpy ( auxNombre, nombre [i] ) ;
                strcpy ( nombre [i], nombre [j] ) ;
                strcpy ( nombre [j], auxNombre ) ;

            }
        }
    }*/

    //inicializacion de aray
    /*for ( i = 0 ; i < 10 ; i++ )
    {
        strcpy ( nombre [i] , "0" ) ;


    }*/
    //Carga de arrays en paralelo
    /*for ( i = 0 ; i < 2 ; i++ )
    {
        printf ( "Ingrese el nombre #%d \n" , i+1 ) ;
        scanf ( "%s" , nombre [i] ) ;
        fflush ( stdin ) ;
        printf ( "Ingrese la nota #%d \n" , i+1 ) ;
        scanf ( "%d" , nota [i] ) ;
        fflush ( stdin ) ;
    }*/
    /*for ( i = 0 ; i < 4 ; i++ )
    {
        printf ( "nombre #%d es: %s \n" , i + 1 , nombre [i] ) ;
        printf ( "nota #%d es: %d \n" , i + 1 , nota [i] ) ;
    }*/



    /*for ( i = 0 ; i < 10 ; i++ )
    {
    strcpy ( nombre [i] , "0" ) ;
    }
    for ( i = 0 ; i < 10 ; i++ )
    {
    printf ( "test %s \n" , nombre [i] ) ;
    }*/
    //printf ( "test %s \n" , nombre [1] ) ;





    /*for ( i = 0 ; i < 10 ; i++ )
    {
        for ( a = 0 ; a < 10 ; a++ )
        {
            nombre [i][a] = " " ;
        }
    }*/
    /*for ( i = 0 ; i < 10 ; i++ )
    {
        printf ( "hola %s \n" , nombre [i] ) ;
    }*/


    /* printf ( "Ingrese su nombre\n" ) ;
     scanf ( "%s" , nombre [0] ) ;
     fflush ( stdin ) ;
     printf ( "Ingrese su apellido\n" ) ;
     scanf ( "%s" , nombre [1] ) ;
     fflush ( stdin ) ;
     int tamano = strlen ( nombre [8] ) ;
     printf ( "%d" , tamano ) ; */












    /*char cadena [10] ;
    scanf ( "%s" , cadena ) ;
    fflush ( stdin ) ;
    if ( esUnNumero( *cadena ) == 0 )
    {
        printf ( "No es un numero." ) ;
    } else*/


    /*scanf ( "%c" , &letra ) ;
    fflush ( stdin ) ;
    printf ( "\ncaracter %c " , letra ) ;


    scanf ( "%d" , &numero ) ;
    fflush ( stdin ) ;
    printf ( "\nentero %d " , numero ) ;*/


    /*int miDato = 333 ;
    printf ( "\n%d" , miDato ) ;
    cambiarValorReferencia(&miDato) ;
    printf ( "\n%d" , miDato ) ;*/

    /*int numeroIngresado ;
    int resultado ;
    int unFactor ;

    saludar () ;
    printf ( "Ingrese un numero entero: \n" ) ;
    scanf ( "%d", &numeroIngresado ) ;
    if ( esDivisible ( numeroIngresado ) == 1 )
    {
        resultado = dividir ( numeroIngresado ) ;
    }
    unFactor = factorial ( numeroIngresado ) ;
    printf ( "%d" , unFactor ) ;
    printf ( "%d" , resultado ) ;*/

    return 0;
}

