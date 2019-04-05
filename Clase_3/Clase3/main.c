#include <stdio.h>
#include <stdlib.h>
#define TAM 5
void mostrarArray ( int [], int ) ;
void cargarArrayEnteros ( int [], int ) ;
int buscarValor ( int [], int, int ) ;
int main()
{
    int lugar ;
    int array_enteros [TAM] = {} ;
    int deseaSalir = 0 ;
    do
    {
        system ( "cls" ) ;
        cargarArrayEnteros ( array_enteros, TAM ) ;
        lugar = buscarValor ( array_enteros, TAM, 5 ) ;
        if ( lugar != -1 )
        {
            printf ( "El lugar es %d \n", lugar ) ;
        }
        else
        {
            printf ( "El indice no existe.\n" ) ;
        }
        //mostrarArray ( array_enteros , TAM ) ;
        printf ( "Desea salir?  " ) ;
        scanf ( "%d", &deseaSalir ) ;
    }
    while ( deseaSalir == 0 ) ;
    return 0 ;
}
void mostrarArray ( int array [], int indice )
{
    int i ;
    for ( i = 0 ; i < indice ; i++ )
    {
        printf ( "%d \n", array [i] ) ;
    }
}
void cargarArrayEnteros ( int array [], int indice )
{
    int i ;
    for ( i = 0 ; i < indice ; i++ )
    {
        printf ( "Ingrese un numero:  " ) ;
        scanf ( "%d", &array [i] ) ;
        fflush ( stdin ) ;
    }
}
int buscarValor ( int array [], int tam, int valor )
{
    int indice = -1 ;
    int i ;
    for ( i = 0 ; i < tam ; i++ )
    {
        if ( array [i] == valor )
        {
            indice = i + 1 ;
            break ;
        }
    }
    return indice ;
}
