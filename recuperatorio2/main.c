#include <stdio.h>
#include <stdlib.h>

int main()
{   char nombre[20];
    char localidad[20];
    printf("Ingrese nombre:\n");
    gets(nombre);
    printf("ingrese localidad:\n");
    gets(localidad);
    printf("Su nombre es %s y vive en %s",nombre,localidad);
    return 0;
}
