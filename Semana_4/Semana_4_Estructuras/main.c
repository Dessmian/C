#include <stdio.h>
#include <stdlib.h>
/* hacer una funcion que permita modificar el dato de un alumno
    usar estrucutras para guardar los datos de los alumnos */
typedef struct
{
    char nombres [50] ;
    char apellidos [50] ;
    int edad ;
    int nota ;
} sAlumnos ;

int main()
{
    printf ( "%d" , sizeof (sAlumnos) ) ;


    return 0;
}
