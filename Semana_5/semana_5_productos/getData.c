#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int isaBarCode ( char lst [] , int sz )
{
    int i ;
    int rtrnvl = 1 ;
    for ( i = 0 ; i < sz ; i++ )
    {
        if ( i == 0 )
        {
            if ( lst [i] == '\n' || lst [i] == '\0' )
            {
                rtrnvl == 0 ;
                break;
            }
        }
        if ( lst [i] < '0' && lst [i] > '9' )
        {
            if ( lst [i] == '\n' || lst [i] == '\0' )
            {
                break;
            }
            rtrnvl = 0 ;
        }
    }
}
