#include <stdio.h>
#include <stdlib.h>
//2.	Escribir el programa necesario para calcular la suma de dos números. Mostrar el resultado
int main()
{
    int num1;
    int num2;
    int suma;

    printf("Ingrese numero: ");
    scanf("%d",&num1);
    printf("Ingrese numero: ");
    scanf("%d",&num2);
    suma=num1+num2;
    system("cls");
    printf("El resultado de la suma los numeros es: %d\n",suma);

    return 0;
}
