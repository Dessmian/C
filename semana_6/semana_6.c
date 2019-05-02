#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semana_6.h"
/*sProduct createProduct ()
{
    //USAR FUNCIONES!!
    fflush  ( stdin )  ;
    sProduct returningValue  ;
    printf  ( "Ingrese el nombre del producto:  \n" )  ;
    fflush  ( stdin )  ;
    gets  ( returningValue.name )  ;
    printf  ( "Ingrese el codigo de barras:  \n" )  ;
    fflush  ( stdin )  ;
    gets  ( returningValue.barCode )  ;
    printf  ( "Ingrese el precio del producto:  \n" )  ;
    fflush  ( stdin )  ;
    scanf  ( "%f" , &returningValue.price )  ;
    printf  ( "Ingrese la fecha de vencimiento del producto:  \n" )  ;
    fflush  ( stdin )  ;
    gets  ( returningValue.exprationDate )  ;
    returningValue.state = 1 ;


    return returningValue  ;
}*/
void showProduct ( sProduct data , char* provider )
{
    int len ;
    len = strlen ( data.name ) ;
    if ( len > 11 )
    {
        printf ( "|  %s  | %s \t| %s\t| %f | %s\t|\n" , data.barCode , data.name , data.exprationDate , data.price , provider ) ;
    }
    else
    {
        printf ( "|  %s  | %s\t\t| %s\t| %f | %s\t|\n" , data.barCode , data.name , data.exprationDate , data.price , provider ) ;
    }
}
/*void fillProductArray ( sProduct productList [] , int arraySize )
{
    int i ;
    for ( i = 0 ; i < arraySize ; i++ )
    {
        productList [i] = createProduct() ;
        system ( "pause" ) ;
        system ( "cls" ) ;
    }
}*/
void showProductsArray ( sProduct productList[] , sProvider providerList[] , int productSize , int providerSize  )
{
    int i ;
    int id;
    char provider [51] ;
    printf ( " _______________________________________________________________________\n" ) ;
    printf ( "| Codigo |   Producto\t\t|  Vencimiento  | Precio    | Proveedor |\n" ) ;
    printf ( " _______________________________________________________________________\n" ) ;
    for ( i = 0 ; i < productSize ; i++ )
    {
        id = productList[i].idProvider ;
        strcpy ( provider , getProvider( providerList , id , providerSize ) ) ;
        showProduct ( productList[i] , provider ) ;
    }
    printf ( " _______________________________________________________________________" ) ;
    showProviders( providerList , providerSize ) ;
}
/*void buildProductArray ( sProduct productList [] , int arraySize )
{
    int i ;
    for ( i = 0 ; i < arraySize ; i++ )
    {
        productList[i].state = 0 ;
        productList[i].price = 0 ;
        strcpy(productList[i].barCode , "" ) ;
        strcpy(productList[i].exprationDate , "" ) ;
        strcpy(productList[i].name , "" ) ;
        productList[i].idProvider = 0 ;
    }
}*/
/*int insertProduct ( sProduct incomingProduct , sProduct* list , int listSize )
{
    int index ;
    int returningValue = 0 ;
    index = getFreeSpace ( list , listSize ) ;
    if ( index != -1 )
    {
        list[index] = incomingProduct ;
        returningValue = 1 ;
    }
    return returningValue ;
}*/
/*int getFreeSpace ( sProduct productList [] , int arraySize )
{
    int i ;
    int returnungValue = -1 ;
    for ( i = 0 ; i < arraySize ; i++ )
    {
        if ( productList[i].state == 0 )
        {
            returnungValue = i ;
        }
    }
    return returnungValue ;
}*/
/*int itExist ( sProduct incomingProduct , sProduct productList [] , int listSize )
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
}*/
/*int eliminateProduct ( sProduct incomingProduct , sProduct productList [] , int listSize )
{
    int index ;
    int returningValue = 0 ;
    index = itExist( incomingProduct , productList , listSize ) ;
    if ( index != -1 )
    {
        productList[i].state = -1 ;
        returningValue = 1 ;
    }
    return returningValue ;
}*/
//int editProduct ( sProduct , sProduct[] ) ;
void createTestProducts ( sProduct list [] )
{
    int i ;
    float price [10] = { 40 , 45 , 50 , 38 , 35 , 43 , 44 , 39 , 42 , 34 } ;
    char barCode [10] [51] = { "1111" , "2222" , "3333" , "4444" , "5555" , "6666" , "7777" , "8888" , "9999" , "1010" } ;
    char name [10] [51] = { "infinia" , "action power" , "v-power" , "infinia diesel" , "axion diesel" , "v-power diesel" , "super" , "axion super" , "normal" , "kerosene" } ;
    char expirationDate [10] [21] = { "1/1/2020" , "1/2/2020" , "1/3/2020" , "1/4/2020" , "1/5/2020" , "1/6/2020" , "1/7/2020" , "1/8/2020" , "1/9/2020" , "1/10/2020" } ;
    int idProvider [10] = { 1 , 2 , 3 , 1 , 2 , 3 , 1 , 2 , 3 , 1 } ;
    for ( i = 0 ; i < 10 ; i++ )
    {
        strcpy ( list[i].barCode , barCode[i] ) ;
        strcpy ( list[i].exprationDate , expirationDate[i] ) ;
        strcpy ( list[i].name , name[i] ) ;
        list[i].idProvider = idProvider[i] ;
        list[i].price = price[i] ;
        list[i].state = 1 ;
    }
}
void createTestProvider ( sProvider* prov )
{
    int i ;
    int id [3] = { 1 , 2 ,3 } ;
    char location [3] [51] = { "Avellaneda" , "Bahia Blanca" , "Rio Negro" } ;
    char owner [3] [51] = { "YPF" , "Axion" , "Shell" } ;
    char cuit [3] [51] = { "444" , "555" , "666" } ;
    char description [3] [51] = { "Petrolera" , "Petrolera" , "Petrolera" } ;
    for ( i = 0 ; i < 3 ; i++ )
    {
        prov[i].id = id[i] ;
        strcpy ( prov[i].description , description[i] ) ;
        strcpy ( prov[i].cuit , cuit[i] ) ;
        strcpy ( prov[i].location , location[i] ) ;
        strcpy ( prov[i].owner , owner[i] ) ;
    }
}
char* getProvider ( sProvider list[] , int identification , int len )
{
    int i ;
    char providerName [51] = " " ;
    for ( i = 0 ; i < len ; i++ )
    {
        if ( list[i].id == identification )
        {
            strcpy ( providerName , list[i].owner ) ;
            break;
        }
    }
    return providerName ;
}
void showProviders ( sProvider* list , int len )
{
    int i ;
    printf ( "\n _______________________________________________________\n" ) ;
    printf ( "|  Dueño  |  Descripcion  |  ID  |   Ubucacion\t| Cuit\t|\n" ) ;
    printf ( " _______________________________________________________\n" ) ;
    for ( i = 0 ; i < len ; i++ )
    {
        printProviider ( list[i] ) ;
    }
    printf ( " _______________________________________________________\n" ) ;
}
void printProviider ( sProvider data )
{
    printf( "| %s\t  | %s\t  | %d    | %s\t| %s\t|\n" , data.owner , data.description , data.id , data.location , data.cuit ) ;
}
void printProvidersAndProducts ( sProduct* productList , sProvider* providerList , int productLen , int providerLen  )
{
    int i ;
    for ( i = 0 ; i < productLen ; i++ )
    {

    }
}
