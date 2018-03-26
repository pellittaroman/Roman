#include <stdio.h>
#include <stdlib.h>
int sumar(int numero);
int main()
{
    int variable;
    int resultado;

    printf("Ingrese numero ");
    scanf("%d", &variable);

    resultado= sumar(variable);

    printf("El resultado es: %d\n", resultado);
    return 0;
}

int sumar(int numero)
{
    int retorno;

    retorno=numero+5;

    return retorno;
}
