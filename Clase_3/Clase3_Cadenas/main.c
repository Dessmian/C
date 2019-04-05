#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nombre [25] ;
    int largo ;
    int compara ;
    char saraza [6] ;
    printf ( "Ingrese su nombre: " ) ;
    //fgets ( nombre , 25 , stdin ) ;
    scanf ( "%[^\n]" , nombre ) ;
    //strcpy ( nombre , "saraza" ) ;
    //gets ( nombre ) ;
    fflush ( stdin ) ;
    largo = strlen ( nombre ) ;
    strncpy ( saraza , nombre , 5 ) ;
    printf ( "\nSu nombre es %s\n" , nombre ) ;
    printf ( "\nSaraza es %s\n" , saraza ) ;
    printf ( "El largo es %d \n" , largo ) ;
    compara = stricmp ( nombre , "pepe" ) ;
    printf ( "%d" , compara ) ;
    return 0;
}
