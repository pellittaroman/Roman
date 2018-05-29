#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int legajo;
    char nombre[20];
    float sueldo;
    int estado;
}eEmpleado;
int main()
{
    eEmpleado* unEmpleado;

    unEmpleado = (eEmpleado*) malloc(sizeof(eEmpleado));
    if(unEmpleado==NULL)
    {
        printf("no se pudo reservar lugar en memoria\n");
        exit(1);
    }

    unEmpleado->legajo= 1234;
    strcpy (unEmpleado->nombre, "juan");
    unEmpleado->sueldo=20000;
    unEmpleado->estado=1;

    printf("%d   %5s   %.2f", unEmpleado->legajo,unEmpleado->nombre,unEmpleado->sueldo);

    free(unEmpleado);

    return 0;
}
