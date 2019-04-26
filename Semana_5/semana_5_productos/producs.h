#ifndef PRODUCT_H_INCLUDED
#define PRODUCT_H_INCLUDED
typedef struct
{
    char    exprationDate [ 51 ] ;
    char    provider [ 51 ] ;
    char    barCode [ 13 ] ;
    char    name [ 51 ] ;
    float   price  ;
    int     state ;
}   sProduct  ;

#endif // PRODUCT_H_INCLUDED
sProduct createProduct () ;
void showProduct ( sProduct ) ;
void fillArray ( sProduct [] , int ) ;
void showArray ( sProduct [] , int ) ;
void buildArray ( sProduct [] , int ) ;
int insertProduct ( sProduct , sProduct[] ) ;
int getFreeSpace ( sProduct [] ) ;
int itExist ( sProduct , sProduct[] , int ) ;
int eliminateProduct ( sProduct , sProduct[] , int ) ;
int editProduct ( sProduct , sProduct[] ) ;
