#include <stdio.h>
#include <stdlib.h>
#include "libreria.h"
#include "libreria.c"

int main()
{
    /*eEmpleado unEmpleado={"jose",3434,'m',26734.50};
    eEmpleado otroEmpleado;
    eEmpleado Emp3;
    otroEmpleado.legajo= 3232;
    strcpy  (otroEmpleado.nombre,"javier");
    otroEmpleado.sexo='m';
    otroEmpleado.sueldo=21729.45;
    Emp3= cargardatos();
    mostrarEmp(otroEmpleado);
    mostrarEmp(unEmpleado);
    mostrarEmp(Emp3);*/
    eEmpleado plantilla[4];
    int i;
    for(i=0;i<4;i++)
    {
        plantilla [i]=cargardatos();
    }

        mostrarEmp(plantilla,4);

    return 0;
}
