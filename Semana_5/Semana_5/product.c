#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "product.h"
sProduct createProduct ()
{
    sProduct returningValue  ;

    printf  ( "Ingrese el nombre del producto:  \n" )  ;
    gests  ( returningValue.name )  ;
    fflush  ( "stdin" )  ;
    printf  ( "Ingrese el codigo de barras:  \n" )  ;
    gets  ( returningValue.barCode )  ;
    fflush  ( "stdin" )  ;
    printf  ( "Ingrese el precio del producto:  \n" )  ;
    scanf  ( &returningValue.price )  ;
    fflush  ( "stdin" )  ;
    printf  ( "Ingrese la fecha de vencimiento del producto:  \n" )  ;
    gets  ( returningValue.exprationDate )  ;
    fflush  ( "stdin" )  ;
    printf  ( "Ingrese el ombre del proveedor:  \n" )  ;
    gets  ( returningValue.provider )  ;
    fflush  ( "stdin" )  ;


    return returningValue  ;
}
void showProduct ( sProduct )
{
    printf  ( "%s", cocaCola.name )  ;
    printf  ( "%s", cocaCola.barCode )  ;
    printf  ( "%s", cocaCola.exprationDate )  ;
    printf  ( "%s", cocaCola.provider )  ;
    printf  ( "%d", cocaCola.price )  ;
}
