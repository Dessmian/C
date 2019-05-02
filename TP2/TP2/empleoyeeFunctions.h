#ifndef EMPLEOYEEFUNCTIONS_H_INCLUDED
#define EMPLEOYEEFUNCTIONS_H_INCLUDED
typedef struct
{
    int id ;
    char name [51] ;
    char lastName [51] ;
    double salary ;
    int sector ;
    int isEmpty ;
} sEmployee ;


#endif // EMPLEOYEEFUNCTIONS_H_INCLUDED
void initializeEmpleoyeeArray ( sEmpleoyee [] , int ) ;
int initEmployees( sEmployee [] , int ) ;
int addEmployee( sEmployee [] , int , int , char [] , char [] , double , int ) ;
int findEmployeeById ( sEmployee [] , int , int ) ;
int removeEmployee ( sEmployee [] , int , int ) ;
int sortEmployees( sEmployee [] , int , int ) ;
int printEmployees ( sEmployee [] , int ) ;
int thereIsData ( sEmployee [] , int ) ;
int printMenuGetOption () ;
