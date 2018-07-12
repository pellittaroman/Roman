#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "empleados.h"
int main()
{
    ArrayList* parcial;
    eEmpleado* aux=newEmpleado();
    parcial=al_newArrayList();
    ArrayList* prueba;
    prueba=al_newArrayList();
    int i,j,ok,mapeo;

    parserEmpleados(parcial);
    int tam=parcial->len();


    printEmpleadoAll(parcial);
    system("pause");
    system("cls");

    j=al_sort(parcial,orden,0);


    printEmpleadoAll(parcial);
    system("pause");
    system("cls");
    mapeo=map(parcial,calcularSalary);
    if(mapeo!=0)
    {
        printf("ERROR");
    }
    prueba=filtrar(parcial,filtrado);
    if(prueba!=NULL)
    {
        parcial=prueba;
        printEmpleadoAll(parcial);
    }



    ok=guardarArchivo(parcial,"fin3.csv");
    if(ok==0)
        printf("\nSe guardo correctamente el archivo");
    return 0;
}


