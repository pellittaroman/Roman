#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "empleados.h"
int main()
{
    ArrayList* parcial;
    eEmpleado* aux=newEmpleado();
    parcial=al_newArrayList();
    int i,j,ok;

    parserEmpleados(parcial);
    int tam=parcial->len();


    for(i=0;i<tam;i++)
    {
        aux=parcial->get(parcial,i);
        printEmpleado(aux);
    }
    system("pause");
    system("cls");

    j=al_sort(parcial,orden,0);


    for(i=0;i<tam;i++)
    {
        aux=parcial->get(parcial,i);
        printEmpleado(aux);
    }
    system("pause");
    system("cls");
    map(parcial,calcularSalary);

    for(i=0;i<tam;i++)
    {
        aux=parcial->get(parcial,i);
        printEmpleado(aux);
    }


    ok=guardarArchivo(parcial,"fin3.csv");
    if(ok==0)
        printf("\nSe guardo correctamente el archivo");
    return 0;
}


