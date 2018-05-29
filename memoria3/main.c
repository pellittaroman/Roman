#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int legajo;
    char nombre[20];
    float sueldo;
    int estado;
}eEmpleado;
eEmpleado* new_Empleado();
eEmpleado* new_Empleado_Param(int, char*,float);
int main()
{
   eEmpleado* unEmpleado;
    unEmpleado=new_Empleado_Param(1235,"juan",20000);
    printf("%d   %5s   %.2f", unEmpleado->legajo,unEmpleado->nombre,unEmpleado->sueldo);
    return 0;
}
eEmpleado* new_Empleado_Param(int legajo, char* nombre, float sueldo)
{
    eEmpleado* nuevo;

    nuevo = (eEmpleado*) malloc(sizeof(int));
    if(nuevo!=NULL)
    {
        nuevo->estado=1;
        nuevo->legajo=legajo;
        strcpy(nuevo->nombre,nombre);
        nuevo->sueldo=sueldo;
    }
    return nuevo;
}
