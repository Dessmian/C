#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleoyeeFunctions.h"
#include "validations.h"

void initializeEmpleoyeeArray ( sEmployee list[], int len )
{
    int i ;
    for ( i = 0 ; i < len ; i++ )
    {
        list[i].id = 0 ;
        list[i].isEmpty = 1 ;
        list[i].salary = 0 ;
        list[i].sector = 0 ;
        strcpy ( list[i].name, "" ) ;
        strcpy ( list[i].lastName, "" ) ;
    }

}
int initEmployees( sEmployee list[], int len )
{
    int i ;
    int itsDone = 0 ;
    for ( i = 0 ; i < len ; i++ )
    {
        list[i].isEmpty = 1 ;
    }
    for ( i = 0 ; i < len ; i++ )
    {
        if ( list[i].id != 1 )
        {
            itsDone = -1 ;
        }
    }
    return itsDone ;
}
int addEmployee( sEmployee list [], int len, int id, char name [], char lastName [], double salary, int sector, int index )
{
    int itsDone ;
    if ( index < 0 )
    {
        itsDone = -1 ;
    }
    else
    {
        list[index].id = id ;
        list[index].isEmpty = 0 ;
        list[index].salary = salary ;
        list[index].sector = sector ;
        strcpy ( list[index].name, name ) ;
        strcpy ( list[index].lastName, lastName ) ;
        itsDone = 0 ;
    }
    return itsDone ;
}
int findEmployeeById ( sEmployee list [], int len, int id )
{
    int i ;
    int index = -1 ;
    for ( i = 0 ; i < len ; i++ )
    {
        if ( list[i].id == id )
        {
            index = i ;
            break ;
        }
    }
    return index ;
}
int removeEmployee ( sEmployee list [], int len, int id )
{
    int index ;
    int itsDone = -1 ;
    index = findEmployeeById ( list, len, id ) ;
    if ( index >= 0 )
    {
        list[index].isEmpty = 1 ;
        itsDone = 0 ;
    }
    return itsDone ;
}
int sortEmployees( sEmployee list [], int len, int order )
{
    int i ;
    int j ;
    sEmployee aux ;
    int comparison ;
    //menor a mayor
    if ( order )
    {
        for ( i = 0 ; i < ( len - 1 ) ; i++ )
        {
            if ( list[i].isEmpty == 0 )
            {
                for ( j = i+1 ; j < len ; j++ )
                {
                    if ( list[j].isEmpty == 0 )
                    {
                        if ( list[i].sector > list[j].sector )
                        {
                            aux = list[i] ;
                            list[i] = list[j] ;
                            list[j] = aux;
                        }
                        else if ( list[i].sector == list[j].sector )
                        {
                            comparison = strcasecmp ( list[i].lastName, list[j].lastName ) ;
                            if ( comparison > 0 )
                            {
                                aux = list[i] ;
                                list[i] = list[j] ;
                                list[j] = aux;
                            }
                            else if ( comparison == 0 )
                            {
                                comparison = strcasecmp ( list[i].name, list[j].name ) ;
                                if ( comparison > 0 )
                                {
                                    aux = list[i] ;
                                    list[i] = list[j] ;
                                    list[j] = aux;
                                }
                                else if ( comparison == 0 )
                                {
                                    if ( list[i].id > list[j].id )
                                    {
                                        aux = list[i] ;
                                        list[i] = list[j] ;
                                        list[j] = aux;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else //mayor a menor
    {
        for ( i = 0 ; i < ( len - 1 ) ; i++ )
        {
            if ( list[i].isEmpty == 0 )
            {
                for ( j = i+1 ; j < len ; j++ )
                {
                    if ( list[j].isEmpty == 0 )
                    {
                        if ( list[i].sector < list[j].sector )
                        {
                            aux = list[i] ;
                            list[i] = list[j] ;
                            list[j] = aux;
                        }
                        else if ( list[i].sector == list[j].sector )
                        {
                            comparison = strcasecmp ( list[i].lastName, list[j].lastName ) ;
                            if ( comparison < 0 )
                            {
                                aux = list[i] ;
                                list[i] = list[j] ;
                                list[j] = aux;
                            }
                            else if ( comparison == 0 )
                            {
                                comparison = strcasecmp ( list[i].name, list[j].name ) ;
                                if ( comparison < 0 )
                                {
                                    aux = list[i] ;
                                    list[i] = list[j] ;
                                    list[j] = aux;
                                }
                                else if ( comparison == 0 )
                                {
                                    if ( list[i].id < list[j].id )
                                    {
                                        aux = list[i] ;
                                        list[i] = list[j] ;
                                        list[j] = aux;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
int printEmployees ( sEmployee list [], int len )
{
    int i ;
    system ( "cls" ) ;
    printf ( "____________________________\n" ) ;
    printf ( " ID | Last Name | Name | Sector | Salary |\n" ) ;
    for ( i = 0 ; i < len ; i++ )
    {
        printOneEmployee( list[i] ) ;
    }
    printf ( "_____________________________\n" ) ;
}
int getEmptySpace ( sEmployee list [], int len )
{
    int i ;
    int index = -1 ;
    for ( i = 0 ; i < len ; i++ )
    {
        if ( list[i].isEmpty )
        {
            index = i ;
            break ;
        }
    }
    return index ;
}
void printOneEmployee ( sEmployee employee )
{
    if ( employee.isEmpty == 0 )
    {
        printf ( "|\t" ) ;
        printf ( "%d\t", employee.id ) ;
        printf ( "%s\t", employee.lastName ) ;
        printf ( "%s\t", employee.name ) ;
        printf ( "%d\t", employee.sector ) ;
        printf ( "%f\t", employee.salary ) ;
        printf ( "\t|\n" )
    }
}
int printMenuGetOption ()
{
    int option ;
    char input [51] ;
    do
    {
        system ( "cls" ) ;
        printf ( "1. ALTAS\n" ) ;
        printf ( "2. BAJAS\n" ) ;
        printf ( "3. MODIFICAR\n" ) ;
        printf ( "4. INFORME\n" ) ;
        printf ( "5. SALIR\n\n" ) ;
        printf ( "Ingrese una opcion:  " ) ;
        fflush ( stdin ) ;
        gets ( input ) ;
        if ( itsInteger(input) == 0 )
        {
            printf ( "Error. Dato Invalido." ) ;
        }
    }
    while ( itsInteger( input ) == 0 ) ;
    option = atoi( input ) ;
    return option ;

}
int thereIsData ( sEmployee list [], int len )
{
    int i;
    int thereIs = 0 ;
    for ( i = 0 ; i < len ; i++)
    {
        if ( list[i].isEmpty == 0 )
        {
            thereIs = 1 ;
            break;
        }
    }
    return thereIs ;
}
void getData ( sEmployee list [], int len )
{
    int canDo ;
    char name [51] ;
    char lastName [51] ;
    double salary ;
    int sector ;
    int id ;
    int itsDone = -1 ;
    canDo = getEmptySpace( list, len ) ;
    if ( canDo > -1 )
    {
        id = getNewID( list, len ) ;
        strcpy ( lastName , getLastName() ) ;
        strcpy ( name , getName() ) ;
        salary = getSalary() ;
        sector = getSector() ;
        itsDone = addEmployee( list, len, id, name, lastName, salary, sector, canDo ) ;
    }
    else
    {
        system ( "cls" ) ;
        printf ( "Error. No hay espacio libre." ) ;
    }
    return itsDone ;
}
int getNewID ( sEmployee list [], int len )
{
    int i ;
    int maxID = 0 ;
    for ( i = 0 ; i < len ; i++ )
    {
        if ( list[i].id > maxID )
        {
            maxID = list[i].id ;
        }
    }
    return maxID ;
}
int modifyEmployee ( sEmployee list [], int index )
{
    int option ;
    do
    {
        system ( "cls" ) ;
        printf ( "____________________________\n" ) ;
        printf ( " ID | Last Name | Name | Sector | Salary |\n" ) ;
        printOneEmployee ( list[index] ) ;
        printf ( "\n\nIngrese parametro a modificar:\n" ) ;
        printf ( "1. Apellido\n" ) ;
        printf ( "2. Nombre\n" ) ;
        printf ( "3. Sector\n" ) ;
        printf ( "4. Salario\n" ) ;
        printf ( "5. Salir\n" ) ;
        fflush ( stdin ) ;
        scanf ( "%d" &option ) ;
        switch ( option )
        case 1:
        strcpy ( list[index].lastName, getLastName() ) ;
break:
    case 2:
        strcpy ( list[index].name, getName() ) ;
break:
    case 3:
        list[index].sector = getSector() ;
break:
    case 4:
        list[index].salary = getSalary() ;
break:
    default:
        system ( "cls" ) ;
        printf ( "Opcion invalida" ) ;
        system ( "pause" ) ;
break:
    }
    while ( option != 5 ) ;
}
const char* getLastName ()
{
    char lastName [51] ;
    printf ( "Ingrese el apellido:  " ) ;
    fflush ( stdin ) ;
    gets ( lastName ) ;
    while ( itsName ( lastName ) == 0 )
    {
        system ( "cls" ) ;
        printf ( "Error. Dato Invalido.\n" ) ;
        printf ( "Ingrese el apellido:  " ) ;
        fflush ( stdin ) ;
        gets ( lastName ) ;
    }
    return lastName ;
}
const char* getName ()
{
    char name [51] ;
    system ( "cls" ) ;
    printf ( "Ingrese el nombre:  " ) ;
    fflush ( stdin ) ;
    gets ( name ) ;
    while ( itsName ( name ) == 0 )
    {
        system ( "cls" ) ;
        printf ( "Error. Dato Invalido.\n" ) ;
        printf ( "Ingrese el nombre:  " ) ;
        fflush ( stdin ) ;
        gets ( name ) ;
    }
    return name ;
}
double getSalary ()
{
    double salary ;
    char salaryInput [51] ;
    system ( "cls" ) ;
    printf ( "Ingrese el salario:  " ) ;
    fflush ( stdin ) ;
    gets ( salaryInput ) ;
    while ( itsFloat ( salaryInput ) == 0 )
    {
        system ( "cls" ) ;
        printf ( "Error. Dato Invalido\n" ) ;
        printf ( "Ingrese el salario:  " ) ;
        fflush ( stdin ) ;
        gets ( salaryInput ) ;
    }
    salary = atof ( salaryInput ) ;
    return salary ;
}
int getSector ()
{
    system ( "cls" ) ;
    printf ( "Ingrese el sector:  " ) ;
    fflush ( stdin ) ;
    gets ( sectorInput ) ;
    while ( itsInteger ( sectorInput ) == 0 )
    {
        system ( "cls" ) ;
        printf ( "Error. Dato Invalido. \n" ) ;
        printf ( "Ingrese el sector:  " ) ;
        fflush ( stdin ) ;
        gets ( sectorInput ) ;
    }
    sector = atoi ( sectorInput ) ;
    return sector ;
}
