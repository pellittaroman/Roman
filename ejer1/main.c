#include <stdio.h>
#include <stdlib.h>
//1.	Ingresar 5 números y calcular su media
int main()
{
    int num1;
    int num2;
    int num3;
    int num4;
    int num5;
    int suma;
    float promedio;
    printf("Ingrese numero: ");
    scanf("%d",&num1);
    printf("Ingrese numero: ");
    scanf("%d",&num2);
    printf("Ingrese numero: ");
    scanf("%d",&num3);
    printf("Ingrese numero: ");
    scanf("%d",&num4);
    printf("Ingrese numero: ");
    scanf("%d",&num5);
    suma=num1+num2+num3+num4+num5;
    promedio=suma/5.0;
    printf("La media de los numeros ingresados es: %.3f",promedio);
    return 0;
}
