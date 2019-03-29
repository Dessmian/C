#include <stdio.h>
#include <stdlib.h>
#include "Calculadora_Biblioteca.h"

int menuDeOpciones ( char textoOpciones [] , int cantidadDeOpciones )
{
    int opcion ;

    do {
        system ( "cls" ) ;
        printf ( "%s" , textoOpciones ) ;
        scanf ( "%d" , &opcion ) ;
        fflush ( stdin ) ;
    } while ( opcion > cantidadDeOpciones || opcion < 1 ) ;
    return opcion ;
}
int tomarPrimerOperando ()
{
    char primerOperando [32] ;
    printf ( "case 1" ) ;
    scanf ( "%s" , &primerOperando ) ;
    fflush ( stdin ) ;
    validarQueSeaUnNumero ( primerOperando ) ;
    return 0 ;
}
int validarQueSeaUnNumero ( char *primerOperando [] )
{


    //printf ( "%s" , primerOperando ) ;
    return 0 ;

}
