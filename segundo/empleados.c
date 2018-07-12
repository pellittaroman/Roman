#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "empleados.h"


eEmpleado* newEmpleado()
{
    eEmpleado* aux;
    aux=(eEmpleado*)malloc(sizeof(eEmpleado));
    if(aux!=NULL)
    {
        aux->id=-1;
        strcpy(aux->nombre,"");
        strcpy(aux->direccion,"");
        aux->horas=0;
        aux->sueldo=0;

    }
    else
    {
        printf("no se pudo crear por falta de memoria");

    }
    return aux;
}

int setId(eEmpleado* empleados,int id)
{
    int retorno=-1;
    if(empleados!=NULL&&id>0)
    {
        empleados->id=id;
        retorno=0;
    }
    return retorno;

}


int get_id(eEmpleado* empleados)
{
    int id=-1;
    if(empleados!=NULL)
    {
       id=empleados->id;
    }
    return id;
}


int setName(eEmpleado* empleado, char nombre[20] )
{
    int retorno=-1;

    if(empleado!=NULL)
    {
        strcpy(empleado->nombre,nombre);
        retorno=0;
    }
    return retorno;
}


char* getName(eEmpleado* empleado)
{
    char* aux;
    aux=(char*)malloc(sizeof(char)*20);
    if(empleado!=NULL)
    {
        strcpy(aux,empleado->nombre);
    }
    return aux;

}


int setAdress(eEmpleado* empleado, char direccion[30] )
{
    int retorno=-1;

    if(empleado!=NULL)
    {
        strcpy(empleado->direccion,direccion);
        retorno=0;
    }
    return retorno;
}


char* getAdress(eEmpleado* empleado)
{
    char* aux;
    aux=(char*)malloc(sizeof(char)*30);
    if(empleado!=NULL)
    {
        strcpy(aux,empleado->direccion);
    }
    return aux;

}


int setHours(eEmpleado* empleados,int hora)
{
    int retorno=-1;
    if(empleados!=NULL&&hora>79)
    {
        empleados->horas=hora;
        retorno=0;
    }
    return retorno;

}


int getHours(eEmpleado* empleados)
{
    int hora=0;
    if(empleados!=NULL)
    {
       hora=empleados->horas;
    }
    return hora;
}

int setSalary(eEmpleado* empleados,int sueldo)
{
    int retorno=-1;
    if(empleados!=NULL&&sueldo>0)
    {
        empleados->sueldo=sueldo;
        retorno=0;
    }
    return retorno;

}


int getSalary(eEmpleado* empleados)
{
    int sueldo=-1;
    if(empleados!=NULL)
    {
       sueldo=empleados->sueldo;
    }
    return sueldo;
}


int parserEmpleados(ArrayList* Empleado)
{
    char buffer [10],buffer1 [20],buffer2 [30],buffer3[20];
    int cant,retorno=1;
    FILE* archivo;
    eEmpleado* aux;
    archivo=fopen("Empleados.csv","r");
    if(archivo==NULL||Empleado==NULL)
    {
        printf("ERROR al leer archivo");
        exit(1);
    }
    else
    {
        while(!feof(archivo))
        {
            aux=newEmpleado();
            cant=fscanf(archivo,"%[^;];%[^;];%[^;];%[^\n]",buffer,buffer1,buffer2,buffer3);
            if(cant!=4)
            {
                if(feof(archivo))
                {
                    printf("se realizo lectura\n");
                    retorno=0;
                    break;
                }
                else
                {
                    printf("Error de lectura de archivo");
                    retorno=1;
                    break;

                }
            }

            else
            {
                setId(aux,atoi(buffer));
                setName(aux,buffer1);
                setAdress(aux,buffer2);
                setHours(aux,atoi(buffer3));
                retorno=0;
            }
            al_add(Empleado,aux);

        }
        fclose(archivo);
}
}
int orden(void* a,void* b)
{
    int retorno=0;
    if(strcmp(((eEmpleado*)a)->nombre,((eEmpleado*)b)->nombre)>0)
    {
        retorno=-1;
    }
    if(strcmp(((eEmpleado*)a)->nombre,((eEmpleado*)b)->nombre)<0)
    {
        retorno=1;
    }
    return retorno;
}
int calcularSalary(void* empleado)
{
    int sueldo=0,sueldo2=180*120,sueldo3=40*240;
    int hora=getHours(empleado),retorno=1;
    if(empleado==NULL)
    {
        printf("ERROR");
        exit(1);
    }
    if(((eEmpleado*)empleado)->horas>79&&((eEmpleado*)empleado)->horas<120)
    {
        sueldo=hora*180;
        retorno=0;
    }
    if(((eEmpleado*)empleado)->horas>=120&&((eEmpleado*)empleado)->horas<160)
    {
        hora=hora-120;
        sueldo=sueldo2+hora*240;
        retorno=0;
    }
    if(((eEmpleado*)empleado)->horas>=160&&((eEmpleado*)empleado)->horas<=240)
    {
        hora=hora-160;
        sueldo=sueldo2+sueldo3+hora*350;
        retorno=0;
    }
    if(retorno==0)
    {
        setSalary(empleado,sueldo);
    }

    return retorno;

}
int guardarArchivo (ArrayList* empleados, char* path)
{
    FILE* f;
    eEmpleado* aux;
    int retorno=-1;
    int i;
    int tam=empleados->len(empleados);


    if(empleados!=NULL)
    {
        f= fopen(path,"w");
        if(f!=NULL)
        {
        for(i=0;i<tam;i++)
        {
            aux =empleados->get(empleados, i);
            //fprintf(f,"%d\t  %10s\t   %15s\t%d\t%d\n", get_id(aux),getName(aux),getAdress(aux),getHours(aux),getSalary(aux));
            //fprintf(f,"%d;  %10s;   %15s;%d;%d\n", get_id(aux),getName(aux),getAdress(aux),getHours(aux),getSalary(aux));
            fprintf(f,"%d;", get_id(aux));
                fprintf(f,"%s;", getName(aux));
                fprintf(f,"%s;", getAdress(aux));
                fprintf(f,"%d;", getHours(aux));
                fprintf(f,"%d\n", getSalary(aux));


        }
        retorno=0;
        }
        fclose(f);
    }

    return retorno;
}

void printEmpleado(eEmpleado* empleado)
{
    if(empleado != NULL)
    {

        printf(" %2d      %12s      %15s        %3d       %6d\n", get_id(empleado), getName(empleado), getAdress(empleado), getHours(empleado), getSalary(empleado));

    }
    else
    {
        printf("No se pudo leer el empleado\n");
    }
}

