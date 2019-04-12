#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANTIDAD_DE_ALUMNOS 4
void getString ( char mensaje [] , char input [] ) ;
int getStringLetras ( char mensaje [] , char input [] ) ;
int main()
{
    /*char _nombre [ CANTIDAD_DE_ALUMNOS ] [25] = { "Juan" , "Juandos" , "Juantres" , "Juancuatro" } ;
    char _apellido [ CANTIDAD_DE_ALUMNOS ] [25] = { "uno" , "dos" , "tres" , "cuantro" } ;
    int _edad [ CANTIDAD_DE_ALUMNOS ] = { 21 , 22 , 23 , 24 } ;
    int _nota [ CANTIDAD_DE_ALUMNOS ] = { 2 , 4 , 7 , 10 } ;*/

    char name [25] ;
    /*for ( i = 0 ; i < CANTIDAD_DE_ALUMNOS ; i++ )
    {
        printf ( "Nombre: %s\t  Apellido: %s\t  Edad: %d\t  Nota %d \n" , _nombre [i] , _apellido [i] , _edad [i] , _nota [i] ) ;

    }*/
    getStringLetras( "\n\nIngrese el nombre: " , name ) ;
    return 0;
}
void getString ( char mensaje [] , char input [] )
{
    printf ( mensaje ) ;
    scanf ( "%s" , input ) ;
}
int getStringLetras ( char mensaje [] , char input [] )
{
    int i ;
    char arrayAuxiliar [25] = "\0" ;
    int largo ;
    getString ( mensaje , arrayAuxiliar ) ;
    largo = sizeof ( arrayAuxiliar ) ;
    printf ( "%d" , largo ) ;
    for ( i = 0 ; i > largo ; i++ )
    {

        if ( arrayAuxiliar [ i ] < 'a' && arrayAuxiliar [ i ] > 'z' )
        {
            if ( arrayAuxiliar [ i ] < 'A' && arrayAuxiliar [ i ] > 'Z' )
            {
                return 0 ;
            }
        }
        if ( arrayAuxiliar [ i ] == ' ' )
        {

        }
    }
    return -1 ;
}
