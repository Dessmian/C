#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "products.h"
#include "providers.h"
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
void showProductAndProvider ( sProduct product , char* provider )
{
    int len ;
    len = strlen ( product.name ) ;
    if ( product.state == 1 )
    {
        if ( len > 11 )
        {
            printf ( "|  %s  | %s \t| %s\t| %f | %s\t|\n" , product.barCode , product.name , product.exprationDate , product.price , provider ) ;
        }
        else
        {
            printf ( "|  %s  | %s\t\t| %s\t| %f | %s\t|\n" , product.barCode , product.name , product.exprationDate , product.price , provider ) ;
        }
    }
}
void showProductsArray ( sProduct* productList , sProvider* providerList , int productSize , int providerSize  )
{
    int i ;
    int id;
    char provider [51] = " " ;
    prodHeader() ;
    for ( i = 0 ; i < productSize ; i++ )
    {
        if ( productList[i].state == 1 )
        {
            id = productList[i].idProvider ;
            getProvider( providerList , id , providerSize , provider ) ;
            showProductAndProvider ( productList[i] , provider ) ;
        }
    }
    printf ( " -----------------------------------------------------------------------\n" ) ;
    showProviders( providerList , providerSize ) ;
}
void getProvider ( sProvider* list , int identification , int len , char* providerName )
{
    int i ;
    for ( i = 0 ; i < len ; i++ )
    {
        if ( list[i].id == identification )
        {
            strcpy ( providerName , list[i].owner ) ;
            break;
        }
    }
}
void prodHeader ()
{
    printf ( " _______________________________________________________________________\n" ) ;
    printf ( "| Codigo |   Producto\t\t|  Vencimiento  | Precio    | Proveedor |\n" ) ;
    printf ( " -----------------------------------------------------------------------\n" ) ;
}
void prodHeaderNoProv ()
{
    printf ( " ___________________________________________________________\n" ) ;
    printf ( "| Codigo |   Producto\t\t|  Vencimiento  | Precio    |\n" ) ;
    printf ( " -----------------------------------------------------------\n" ) ;
}
