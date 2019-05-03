#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semana_6.h"
int main()
{
    sProduct    productsList [100] ;
    sProvider   providerList [10] ;
    createTestProvider( providerList ) ;
    createTestProducts( productsList ) ;
    //showProductsArray( productsList , providerList , 100 , 10 ) ;
    printProvidersAndProducts( productsList , providerList , 100 , 10 ) ;


    return 0;
}
