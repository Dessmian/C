#include <stdio.h>
#include <stdlib.h>
// 5 4 4 4 4
/*Hacer un programa que premita ingresar 5 numeros y devuelva el promedio*/
void saludar (void);
int pideCantidadIteraciones(void);
float calcularPromedio (float,int);

int main()
{
    float numeroIngresado;
    float suma = 0;
    int contador = 0;
    int limite;
    float promedio;

    limite = pideCantidadIteraciones();

    while((int)contador<limite){

        printf("\n Ingrese un numero: _____");
        scanf("%f",&numeroIngresado);
        suma = suma + numeroIngresado;
        contador++;
    }
    promedio = calcularPromedio(suma,contador);
    printf("El promedio es: %f",promedio);
}

void saludar(void)
{
    printf("Hola mundo C!");
}
int pideCantidadIteraciones (void)
{
    int cantidadIteraciones;
    printf("Ingrese la cantida de iteraciones: ___");
    scanf("%d",&cantidadIteraciones);
    return cantidadIteraciones;
}
float calcularPromedio(float suma,int contador)
{
    float calculo;
    calculo = (float)suma / (int)contador;
    return calculo;
}
