#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "products.h"
#include "providers.h"
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
        prov[i].state = 1 ;
    }
}
void showProviders ( sProvider* list , int len )
{
    int i ;
    prProvHeader();
    {
        if ( list[i].state )
        {
        printProviider ( list[i] ) ;
        }
    }
    printf ( " -------------------------------------------------------\n" ) ;
}
void printProviider ( sProvider data )
{
    printf( "| %s\t  | %s\t  | %d    | %s\t| %s\t|\n" , data.owner , data.description , data.id , data.location , data.cuit ) ;
}
void printProvidersAndProducts ( sProduct* productList , sProvider* providerList , int productLen , int providerLen  )
{
    int i ;
    int j ;
    for ( i = 0 ; i < providerLen ; i++ )
    {
        if ( providerList[i].state )
        {
            prProvHeader();
            printProviider( providerList[i] ) ;
            printf ( " -------------------------------------------------------\n" ) ;
            prodHeaderNoProv();
            for ( j = 0 ; j < productLen ; j++ )
            {
                if ( providerList[i].id == productList[j].idProvider )
                {
                    showProduct( productList[j] ) ;
                }
            }
            printf ( " -----------------------------------------------------------\n" ) ;
        }
    }
}
void prProvHeader ()
{
    printf ( "\n _______________________________________________________\n" ) ;
    printf ( "|  Dueño  |  Descripcion  |  ID  |   Ubucacion\t| Cuit\t|\n" ) ;
    printf ( " -------------------------------------------------------\n" ) ;
}
