#include <stdio.h>
#include <stdlib.h>
#include "Calculadora_Biblioteca.h"
int main ()
{

    int opcionElejida ;
    //float primerOperando ;
    //float segundoOperando ;
    int flag_primerOperando ;
    int flag_segundoOperando ;

    opcionElejida = menuDeOpciones ( "1. Ingresar el primer operando.\n2. Ingresar el segundo operando.\n3. Calcular todas las operacines.\n4. Informar resultados.\n5. Salir.\nIngrese opcion: __", 5 ) ;
    //printf ( "%d", opcionElejida ) ;

    switch ( opcionElejida )
    {
    case 1 :
        tomarPrimerOperando();
        break ;
    case 2 :
        break ;
    case 3 :
        break ;
    case 4 :
        break ;
    case 5 :
        break ;
    }
    return 0 ;
}
