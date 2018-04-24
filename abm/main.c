#include <stdio.h>
#include <stdlib.h>
#include "../Roman-master/struct/libreria.h"
#include "../Roman-master/struct/libreria.c"

#define TAM 50

int menu();
int main()
{
    int salir=0;
    eEmpleado gente[TAM];
    inicializarEmpleados(gente,TAM);
    do
    {
        switch(menu())
        {
        case 1:
            altaEmpleado(gente, TAM);
            printf("Alta exitosa!\n");
            system("pause");
            break;
        case 2:
            printf("Baja\n");
            system("pause");
            break;
        case 3:
            printf("Modificar\n");
            system("pause");
            break;
        case 4:
            mostrarEmp(gente,TAM);
            system("pause");
            break;
        case 5:
            printf("Ordenar\n");
            system("pause");
            break;
        case 6:
            printf("Salir\n");
            salir=1;
            break;
        default:
            printf("opcion incorrecta\n\n");
            system("pause");
            break;

        }

    }while (salir!=1);

    return 0;
}
int menu()
{
    system("cls");
    int opcion;

    printf("1.Alta\n2.Baja\n3.Modificacion\n4.Listar\n5.Ordenar\n6.Salir\nElija opcion: ");
    scanf("%d",&opcion);
    return opcion;
}
void mostrarEmp(eEmpleado Empl[] ,int tam)
{
    int i;
    eEmpleado Emp;
   for(i=0;i<tam;i++)
    {
        Emp = Empl[i];
        if(Emp.isEmpty==0)

        {
            printf("Legajo: %d\n",Emp.legajo );
            printf("Nombre: %s\n",Emp.nombre);
            printf("Sexo: %c\n",Emp.sexo);
            printf("Sueldo: %.2f\n",Emp.sueldo);
            printf("Fecha de ingreso %d/%d/%d\n",Emp.fecha.dia,Emp.fecha.mes,Emp.fecha.anio);
            printf("\n");
        }
    }

}
eEmpleado cargardatos()
{
    eEmpleado emp;

    printf("Ingrese Legajo: ");
    scanf("%d",&emp.legajo);
    printf("Ingrese Nombre: ");
    fflush(stdin);
    gets( emp.nombre);
    printf("Ingrese sexo: ");
    scanf(" %c",&emp.sexo);
    printf("Ingrese sueldo: ");
    scanf("%f", &emp.sueldo);
    printf("Ingrese dia de ingreso: ");
    scanf(" %d", &emp.fecha.dia   );
    printf("Ingrese mes de ingreso: ");
    scanf(" %d", &emp.fecha.mes);
    printf("Ingrese anio de ingreso: ");
    scanf(" %d", &emp.fecha.anio);
    printf("\n");


    return emp;

}
void inicializarEmpleados(eEmpleado vec[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
    vec[i].isEmpty=1;
    }
}
void altaEmpleado(eEmpleado vec[], int tam)
{
    int indice;
    int esta;
    int legajo;

    indice=buscarLibre(vec,tam);

    if(indice ==-1)
    {
        printf("No hay lugar para ingresar empleados nuevos\n\n");

    }
    else
    {
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);
        esta= buscarEmpleado(vec,tam,legajo);
        if(esta==-1)
        {
            eEmpleado nuevoEmpleado;
            nuevoEmpleado.legajo=legajo;
            nuevoEmpleado.isEmpty=0;
            printf("Ingrese nombre ");
            fflush(stdin);
            gets(nuevoEmpleado.nombre);
            printf("Ingrese sexo ");
            fflush(stdin);
            scanf("%c",&nuevoEmpleado.sexo);
            printf("Ingrese sueldo ");
            scanf("%f",&nuevoEmpleado.sueldo);
            printf("Ingrese dia de ingreso: ");
            scanf("%d", &nuevoEmpleado.fecha.dia   );
            printf("Ingrese mes de ingreso: ");
            scanf(" %d", &nuevoEmpleado.fecha.mes);
            printf("Ingrese anio de ingreso: ");
            scanf(" %d", &nuevoEmpleado.fecha.anio);
            vec[indice]=nuevoEmpleado;

        }
        else
        {
            mostrarEmp1(vec,esta);
        }
    }

}
void mostrarEmp1(eEmpleado Emp[],int indice)
{


        printf("Legajo: %d\n",Emp[indice].legajo );
        printf("Nombre: %s\n",Emp[indice].nombre);
        printf("Sexo: %c\n",Emp[indice].sexo);
        printf("Sueldo: %.2f\n",Emp[indice].sueldo);
        printf("Fecha de ingreso %d/%d/%d\n",Emp[indice].fecha.dia,Emp[indice].fecha.mes,Emp[indice].fecha.anio);
        printf("\n");

}
int buscarEmpleado(eEmpleado vec[],int tam,int legajo)
{
    int i;
    int indice=-1;
    for(i=0;i<tam;i++)
    {
        if(legajo==vec[i].legajo&&vec[i].isEmpty==0)
        {
        indice=i;
        break;
        }
    }

    return indice;
}
int buscarLibre(eEmpleado vec [],int tam)
{
    int i;
    int indice=-1;
    for(i=0;i<tam;i++)
    {
        if(vec[i].isEmpty==1)
        {
            indice=i;
        }
    }
    return indice;
}
