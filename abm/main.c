#include <stdio.h>
#include <stdlib.h>
#include "libreria.h"
#define TAM 50


int main()
{
    int i;
    int salir=0;
    eEmpleado gente[TAM]={{"roman",1112,'m',35000,{21,12,2000},5,0},{"carla",1144,'f',25000,{21,12,2011},4,0},{"franco",2112,'m',45000,{21,12,2010},5,0},{"romina",1212,'f',15000,{21,12,2003},3,0},{"juan",1132,'m',32000,{21,12,2001},4,0}};
    eSector Sectores[]={{1,"Ventas"},{2,"Compras"},{3,"Comercial"},{4,"RRHH"},{5,"Sistemas"}};
    inicializarEmpleados(gente,TAM);
    for(i=0;i<5;i++)
    {
        gente[i].isEmpty=0;
    }
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
            bajaEmpleado(gente,Sectores,TAM);
            system("pause");
            break;
        case 3:
            modificarEmpleado(gente,Sectores,TAM);
            system("pause");
            break;
        case 4:
            mostrarEmp(gente,Sectores,TAM);
            system("pause");
            break;
        case 5:
            //OrdenarEmpleados(gente,TAM);
            system("pause");
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
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

    printf("1.Alta\n2.Baja\n3.Modificacion\n4.Listar\n5.Ordenar\n6.Mostrar Empleados por sector\n7.Cantidad de empleados por sector\n8.Salir\nElija opcion: ");
    scanf("%d",&opcion);
    return opcion;
}
void mostrarEmp(eEmpleado Empl[],eSector sec[],int tam)
{
    int i;
    eSector sector;
    eEmpleado Emp;
   for(i=0;i<tam;i++)
    {
        Emp = Empl[i];
        if(Emp.isEmpty==0)

        {
            printf("  Legajo   Nombre   Sexo   Sueldo   Fecha Ingreso   Sector  \n");
            sector = mostrarSector(sec,Emp.idSector);
            printf("%2d%10s%3c%7.2f  %02d%02d%4d%8s \n",Emp.legajo,Emp.nombre,Emp.sexo,Emp.sueldo,Emp.fecha.dia,Emp.fecha.mes,Emp.fecha.anio,sector.nombre);


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
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nuevoEmpleado.nombre);
            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c",&nuevoEmpleado.sexo);
            nuevoEmpleado.idSector= pedirSector();
            printf("Ingrese sueldo: ");
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
      void mostrarSector(eSector vec[],int id,eSector sal[])
{      mostrarEmp1(vec,esta);
        }
    }

}
void mostrarEmp1(eEmpleado Emp[],eSector sec[],int indice)
{


        printf("Legajo: %d\n",Emp[indice].legajo );
        printf("Nombre: %s\n",Emp[indice].nombre);
        printf("Sexo: %c\n",Emp[indice].sexo);
        mostrarSector(sec,Emp[indice].idSector);
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
void bajaEmpleado(eEmpleado vec[],eSector sec[],int tam)
{

    int legajo;
    int esta;
    char confirma;
    printf("Ingrese legajo: ");
    scanf("%d", &legajo);
    esta=buscarEmpleado(vec,tam,legajo);
    if (esta==-1)
    {
        printf("No se encontro legajo");
    }
    else
    {
            mostrarEmp1(vec,sec,esta);
    }
    printf("Confirma operacion s/n: ");
    scanf(" %c",&confirma);
    if (confirma=='s')
    {
        vec[esta].isEmpty=1;
        printf("Baja exitosa\n");
    }
}
void modificarEmpleado(eEmpleado vec[],eSector sec[],int tam)
{

    int legajo;
    int esta;
    char confirma;
    float nuevoSueldo;
    printf("Ingrese legajo: ");
    scanf("%d", &legajo);
    esta=buscarEmpleado(vec,tam,legajo);
    if (esta==-1)
    {
        printf("No se encontro legajo");
    }
    else
    {
            mostrarEmp1(vec,sec,esta);
    }
    printf("Confirma operacion s/n: ");
    scanf(" %c",&confirma);
    if (confirma=='s')
    {
        printf("Ingrese nuevo sueldo: ");
        scanf("%f",&nuevoSueldo);
        vec[esta].sueldo=nuevoSueldo;
        printf("Modificacion exitosa!\n");

    }
}
int pedirSector()
{
    int r;
    printf("Ingrese sector:\n1.Ventas\n2.Compras\n3.Contabilidad\n4.RRHH\n5.Sistemas\nId: ");
    scanf("%d", &r);
    return r;

}
eSector mostrarSector(eSector vec[],int id)
{
    int i;
    eSector aux;
    for(i=1;i<6;i++)
    {
        if(i==id)
        {
            aux=vec[i];
            break;
        }
    }
    return aux;
}
/*void ordenarEmpleados(eEmpleado vec[],int tam)
{
    int i;
    eEmpleado aux;
    for(i=0;i<tam;i++)
    {

    }

}*/

