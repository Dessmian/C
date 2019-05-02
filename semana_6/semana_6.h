#ifndef SEMANA_6_H_INCLUDED
#define SEMANA_6_H_INCLUDED
typedef struct
{
    int  id ;
    char description [51] ;
    char location [51] ;
    char cuit [51] ;
    //char mail [51] ;
    char owner [51] ;

} sProvider ;
typedef struct
{
    char  barCode [ 13 ] ;
    char  exprationDate [ 51 ] ;
    char  name [ 51 ] ;
    float price  ;
    int   state ;
    int   idProvider ;
}   sProduct  ;



#endif // SEMANA_6_H_INCLUDED
//sProduct createProduct () ;
void showProduct ( sProduct data , char* ) ;
//void fillProductArray ( sProduct [] , int ) ;
void showProductsArray ( sProduct* , sProvider* , int , int ) ;
//void buildProductArray ( sProduct [] , int ) ;
//int insertProduct ( sProduct , sProduct* , int ) ;
//int getFreeSpace ( sProduct [] , int ) ;
//int itExist ( sProduct , sProduct[] , int ) ;
//int eliminateProduct ( sProduct , sProduct[] , int ) ;
//int editProduct ( sProduct , sProduct[] ) ;
void createTestProducts ( sProduct [] ) ;
void createTestProvider ( sProvider* ) ;
char* getProvider ( sProvider [] , int , int ) ;
void showProviders ( sProvider* , int ) ;
void printProviider ( sProvider ) ;
