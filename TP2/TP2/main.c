#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleoyeeFunctions.h"

int main()
{
    sEmployee employeeList [1000] ;
    initializeEmpleoyeeArray( employeeList , 1000 ) ;
    int option ;
    int itsDone ;
    int id ;
    int itsPosible = 0 ;
    do
    {
        option = printMenuGetOption();
        switch ( option )
        {
        case 1:
            itsDone = getData ( employeeList , 1000 ) ;
            if ( itsDone == 0 )
            {
                system ( "cls" ) ;
                printf ( "Datos cargados exitosamente.\n" ) ;
            }
            else
            {
                system ( "cls" ) ;
                printf ( "No se pudo cargar datos. Vuelva a intentar.\n" ) ;
            }
            break ;
        case 2:
            itsPosible = thereIsData ( employeeList , 1000 ) ;
            if ( itsPosible )
            {
                printf ( "Ingrese el ID del empleado a modificar: " ) ;
                fflush ( stdin ) ;
                scanf ( "%d" &id ) ;
            }
            else
            {
                system ( "cls" ) ;
                printf ( "No hay datos cargados." ) ;
            }
            break ;
        case 3:
            break ;
        case 4:
            break ;
        default:
            system ( "cls" ) ;
            printf ( "Opcion invalida." ) ;
            system ( "pause" ) ;
            break ;
        }
    } while ( option != 5 ) ;
    return 0;
}
