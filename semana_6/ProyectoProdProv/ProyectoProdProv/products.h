#ifndef PRODUCTS_H_INCLUDED
#define PRODUCTS_H_INCLUDED
#include "providers.h"
typedef struct
{
    char  barCode [ 13 ] ; //Primary key
    char  exprationDate [ 51 ] ;
    char  name [ 51 ] ;
    float price  ;
    int   state ;
    int   idProvider ; //Foreign key
}   sProduct  ;
#endif // PRODUCTS_H_INCLUDED
void createTestProducts ( sProduct [] ) ;
void showProductAndProvider ( sProduct , char* ) ;
void showProductsArray ( sProduct * , sProvider* , int , int ) ;
void getProvider ( sProvider* , int , int , char* ) ;
void prodHeader () ;
void prodHeaderNoProv () ;
