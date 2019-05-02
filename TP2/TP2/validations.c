#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validations.h"
int itsFloat ( char data [] )
{
    int i ;
    int len ;
    int commas = 0 ;
    int invalid = 0 ;
    int negative = 0 ;
    int isValid ;
    len = sizeof ( data ) ;
    for ( i = 0 ; i < len ; i++ )]
    {
        if ( i == 0 )
        {
            if ( data [i] < '0' || data [i] > '9' )
            {
                if ( data [i] == '-' )
                {
                    negative = 1 ;
                }
                else
                {
                    invalid = 1 ;
                    break ;
                }
            }
        }
        else if ( i == 1 && negative )
        {
            if ( data [i] == '.' )
            {
                invalid = 1 ;
            }
        }
        else
        {
            if ( data [i] < '0' || data [i] > '9' )
            {
                if ( data [i] == '.' )
                {
                    commas ++ ;
                }
                else
                {
                    invalid = 1 ;
                    break ;
                }
            }
        }
    }
    if ( invalid || commas > 1 )
    {
        isValid = 0 ;
    }
    else
    {
        isValid = 1 ;
    }
    return isValid ;
}
int itsInteger ( char data [] )
{
    int i ;
    int len ;
    int isValid = 1 ;
    len = sizeof ( data ) ;
    for ( i = 0 ; i < len ; i++  )
    {
        if ( data [i] < '0' || data [i] > '9' )
        {
            isValid = 0 ;
            break ;
        }
    }
    return isValid ;
}
int itsName ( char data [] )
{
    int i;
    int len ;
    int isValid ;
    len = sizeof ( data ) ;
    for ( i = 0 ; i < len ; i++ )
    {
        if ( ( data [i] < 'a' || data [i] > 'z' ) && ( data [i] < 'A' || data [i] > 'Z' ) && data [i] != ' ' )
        {
            isValid = 0 ;
            break ;
        }
        else
        {
            isValid = 1 ;
        }
    }
    if ( len < 3 || len > 50 )
    {
        isValid = 0 ;
    }
    return isValid ;
}
