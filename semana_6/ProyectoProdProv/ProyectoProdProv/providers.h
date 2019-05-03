#ifndef PROVIDERS_H_INCLUDED
#define PROVIDERS_H_INCLUDED

typedef struct
{
    int  id ; //Primary key
    char description [51] ;
    char location [51] ;
    char cuit [51] ;
    char owner [51] ;
    int state ;

} sProvider ;
#endif // PROVIDERS_H_INCLUDED
void createTestProvider ( sProvider* ) ;
void showProviders ( sProvider* , int ) ;
void printProviider ( sProvider ) ;
void printProvidersAndProducts ( sProduct* , sProvider* , int , int ) ;
void prProvHeader () ;

