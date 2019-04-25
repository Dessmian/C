#ifndef PRODUCT_H_INCLUDED
#define PRODUCT_H_INCLUDED
typedef struct
{
    char    exprationDate  [  51  ]  ;
    char    provider  [  51  ]  ;
    char    barCode  [  13  ]  ;
    char    name  [  51  ]  ;
    float   price  ;
}   sProduct  ;

#endif // PRODUCT_H_INCLUDED
sProduct createProduct();
void showProduct ( sProduct )  ;
