#include <stdio.h>
#include <stdlib.h>

int main()
{
    int     largo   =   10  ;
    int     numero  ;
    char    palabra   [   largo   ]   ;

    printf  (   "Enter a word: "   )   ;
    scanf   (  "%s"  ,  palabra   )  ;

    setbuf  (   stdin   ,   NULL   )   ;

    printf  (   "Enter a number: "   )   ;
    scanf   (  "%d"    ,   &   numero  )   ;

    printf  (   "The word is: %s"   ,   palabra   )   ;
    printf  (   "\nThe number is: %d"    ,   numero  )   ;

    system  (   "pause"  )  ;

    return  0   ;
}
