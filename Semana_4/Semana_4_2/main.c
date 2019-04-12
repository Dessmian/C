#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 4
void getString ( char [] , char [] ) ;
int getStringLetras ( char [] , char [] ) ;
int esSoloLetras ( char [] ) ;
//printf ( "%10s\t%10s\t%10d-%d" ) ;

int main()
{
    char nombres [TAM] [50] = { "Fredie" , "Ron" , "Erik" , "Tom" } ;
    char apellidos [TAM] [50] = { "Merury" , "Swanson" , "Marshall" , "Hardy" } ;
    int nota [TAM] = { 1 , 4 , 7 , 10 } ;
    int edad [TAM] = { 21 , 22 , 23 , 24 } ;
    return 0;
}
void getString ( char mensaje [] , char input [] )
{
    printf ( mensaje ) ;
    scanf ( input ) ;
}
int getStringLetras ( char mensaje [] , char input [] )
{
    int esValido ;
    int devolucion = 0 ;
    getString( mensaje , input ) ;
    esValido = esSoloLetras ( input ) ;
    if ( esValido == 1 )
    {
        devolucion = 1 ;
    }
    return devolucion ;

}
int esSoloLetras ( char input [] )
{
    int largo ;
    int i ;
    int esValido = 1 ;
    largo = sizeof ( input ) ;
    for ( i = 0 ; i >= largo ; i++ )
    {
        if ( i > 0 && input [i] == '\n' )
        {
            break ;
        }
        if ( (input [i] > 'z' && input [i] < 'a') && (input [i] > 'Z' && input [i] < 'A') )
        {
            esValido = 0 ;
        }
    }
    return esValido ;
}
int obtenerOpcion ( char mensaje [] , char mensajeError [] , int min , int max )
{
    int opcion ;
    printf ( mensaje ) ;
    scanf ( "%d" , &opcion ) ;
    while ( opcion )
}
void ordenarNumerosMayorAMenor ( int numeros [] , int largo )
{
    int i , j ;
    int auxiliar ;
    for ( i = 0 ; i < ( largo - 1 ) ; i++ )
    {
        for ( j = i + 1 ; j < largo ; j ++ )
        {
            if ( numeros [i] < numeros [j] )
            {
                auxiliar = numeros [i] ;
                numeros [i] = numeros [j] ;
                numeros [j] = auxiliar ;
            }
        }
    }
}
int obtenerEntero ( int *numero )
{
    char auxiliar [8] ;
    scanf( "%s" , auxiliar ) ;
}
int esUnInteger ( char numero [] )
{
    int largo ;
    int i ;
    int esValido = 1 ;
    largo = strlen ( numero ) ;
    for ( i = 0 ; i < largo ; i++ )
    {
        if ( numero [i] > '9' || numero [i] < '0' )
        {
            esValido = 0 ;
        }
    }

}
