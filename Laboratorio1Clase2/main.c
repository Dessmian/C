#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
int main()
{
    char cadena [10] ;
    scanf ( "%s" , &cadena ) ;
    fflush ( stdin ) ;
    if ( esUnNumero( *cadena ) == 0 )
    {
        printf ( "No es un numero." ) ;
    } else


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

