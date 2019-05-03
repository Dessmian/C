#ifndef SEMANA_6_H_INCLUDED
#define SEMANA_6_H_INCLUDED
typedef struct
{
    int  id ; //Primary key
    char description [51] ;
    char location [51] ;
    char cuit [51] ;
    char owner [51] ;
    int state ;

} sProvider ;
typedef struct
{
    char  barCode [ 13 ] ; //Primary key
    char  exprationDate [ 51 ] ;
    char  name [ 51 ] ;
    float price  ;
    int   state ;
    int   idProvider ; //Foreign key
}   sProduct  ;



#endif // SEMANA_6_H_INCLUDED
//sProduct createProduct () ;
void showProductAndProvider ( sProduct , char* ) ;
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
void getProvider ( sProvider [] , int , int , char* ) ;
void showProviders ( sProvider* , int ) ;
void printProviider ( sProvider ) ;
void showProduct ( sProduct data ) ;
void prodHeader () ;
void prProvHeader () ;
void prProvHeader () ;
void printProvidersAndProducts ( sProduct* , sProvider* , int , int ) ;
void prodHeaderNoProv () ;
