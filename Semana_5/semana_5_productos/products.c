#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "producs.h"
sProduct createProduct ()
{
    sProduct returningValue  ;
    fflush  ( stdin )  ;
    printf  ( "Ingrese el nombre del producto:  \n" )  ;
    gets  ( returningValue.name )  ;
    fflush  ( stdin )  ;
    printf  ( "Ingrese el codigo de barras:  \n" )  ;
    gets  ( returningValue.barCode )  ;
    fflush  ( stdin )  ;
    printf  ( "Ingrese el precio del producto:  \n" )  ;
    scanf  ( "%f" , &returningValue.price )  ;
    fflush  ( stdin )  ;
    printf  ( "Ingrese la fecha de vencimiento del producto:  \n" )  ;
    gets  ( returningValue.exprationDate )  ;
    fflush  ( stdin )  ;
    printf  ( "Ingrese el ombre del proveedor:  \n" )  ;
    gets  ( returningValue.provider )  ;
    fflush  ( stdin )  ;


    return returningValue  ;
}
void showProduct ( sProduct incomingProduct )
{
    printf  ( "\n\nCampo \t Valor\n" ) ;
    printf  ( "----------------------\n" ) ;
    printf  ( "Nombre: \t\t %s \n", incomingProduct.name )  ;
    printf  ( "Codigo de barras: \t %s \n", incomingProduct.barCode )  ;
    printf  ( "Fecha de vencimiento: \t %s \n", incomingProduct.exprationDate )  ;
    printf  ( "Proveedor: \t\t %s \n", incomingProduct.provider )  ;
    printf  ( "Precio: \t\t %f \n", incomingProduct.price )  ;
}
void fillArray ( sProduct productList [] , int arraySize )
{
    int i ;
    for ( i = 0 ; i < arraySize ; i++ )
    {
        productList [i] = createProduct() ;
        system ( "pause" ) ;
        system ( "cls" ) ;
    }
}
void showArray ( sProduct productList [] , int arraySize )
{
    int i ;
    for ( i = 0 ; i < arraySize ; i++ )
    {
        showProduct ( productList[i] ) ;
    }
}
void buildArray ( sProduct productList [] , int arraySize )
{
    int i ;
    for ( i = 0 ; i < arraySize ; i++ )
    {
        productList[i].state = 0 ;
        productList[i].price = 0 ;
        strcpy(productList[i].barCode , "" ) ;
        strcpy(productList[i].exprationDate , "" ) ;
        strcpy(productList[i].name , "" ) ;
        strcpy(productList[i].provider , "" ) ;
    }
}
int insertProduct ( sProduct incomingProduct , sProduct incomingList [] )
{
    int index ;
    int returningValue = 0 ;
    index = getFreeSpace ( incomingList ) ;
    if ( index != -1 )
    {
        incomingList[index] = incomingProduct ;
        returningValue = 1 ;
    }
    return returningValue ;
}
int getFreeSpace ( sProduct productList [] , int arraySize )
{
    int i ;
    int returnungValue = -1 ;
    for ( i = 0 ; i < arraySize ; i++ )
    {
        if ( productList[i].state != 1 )
        {
            returnungValue = i ;
        }
    }
    return returnungValue ;
}
int itExist ( sProduct incomingProduct , sProduct productList [] , int listSize )
{
    int i ;
    int returningValue = -1 ;
    for ( i = 0 ; i < listSize ; i++ )
    {
        if ( incomingProduct == productList[i] )
        {
            returningValue = i ;
        }
    }
    return returningValue ;
}
int eliminateProduct ( sProduct , sProduct[] )
{

}
int editProduct ( sProduct , sProduct[] ) ;
