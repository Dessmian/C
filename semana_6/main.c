#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semana_6.h"
int main()
{
    sProduct    productsList [10] ;
    sProvider   providerList [3] ;
    createTestProvider( providerList ) ;
    createTestProducts( productsList ) ;
    showProductsArray( productsList , providerList , 10 , 3 ) ;



    return 0;
}
