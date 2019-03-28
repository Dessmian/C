int saludar ()
{
    printf ( "Hola mundo\n" ) ;
}
int esDivisible ( int numeroIngresado )
{
    if ( numeroIngresado != 0 )
    {
        return 1 ;
    }
    return 0 ;
}
int dividir ( int numeroIngresado )
{
    int division ;
    division = numeroIngresado / 2 ;
    return division ;
}
int factorial ( int numeroIngresado )
{
    int respuesta ;
    if ( numeroIngresado == 1 )
    {
        return 1 ;
    }
    respuesta = numeroIngresado * factorial( numeroIngresado - 1 ) ;
    return respuesta ;
}
int cambiarValor ( int miDato )
{
    miDato = 999 ;
    return 1 ;
}
int cambiarValorReferencia ( int *miDato )
{
    //printf ( "el valor es %d " , miDato ) ;
    *miDato = 999 ;
    return 1 ;
}
int dividirPorReferencia ( int datoUno, int datoDos, float *respuesta )
{
    if ( datoUno != 0 )
    {
        *respuesta = (float)datoUno/datoDos ;
        return 1 ;
    }

    return 0 ;
}
int esUnNumero ( char *cadena ) {
    int indice = 0 ;
    while ( cadena [indice] != '\0' )
    {
        if ( cadena [indice] < '0' || cadena [indice] > '9' )
        {
            return 0 ;
        } else {
            indice ++ ;
        }
    }
    return 1 ;
}


