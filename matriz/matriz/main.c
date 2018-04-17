#include <stdio.h>
#include <stdlib.h>
void mostrarEmpleados(char [],int[],char[],float[],int);
void mostrarEmpleado(char[],int,char,float);
void ordenarEmpleados();
int main()
{
    int i=0;
    char nombre[5][20];
    int legajo[5];
    char sexo[5];
    float sueldo[5];



    for(i=0; i<5; i++)
    {
        printf("Ingrese nombre");
        scanf(" %s",&nombre[i]);
        printf("Ingrese legajo");
        scanf("%d",&legajo[i]);
        printf("Ingrese sexo");
        scanf(" %c",&sexo[i]);
        printf("Ingrese sueldo");
        scanf("%f",&sueldo[i]);
        getchar();
    }
    mostrarEmpleados(nombre,legajo,sexo,sueldo,5);
    return 0;
}
void mostrarEmpleados(char nombre[],int legajo[],char sexo[],float sueldo[],int j)
{
    int i=0;
    for(i=0; i<j; i++)
    {
        mostrarEmpleado(nombre[i],legajo[i],sexo[i],sueldo[i]);
    }
}
void mostrarEmpleado(char nombre[20],int legajo,char sexo,float sueldo)
{
    printf("Nombre: %s\nLegajo: %d\nSexo: %c\nsueldo: %f\n",nombre,legajo,sexo,sueldo);
}
