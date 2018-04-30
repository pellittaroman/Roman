#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 20
#define TSEC 5
typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;
typedef struct
{
    int idSector;
    char nombreSector[20];

}eSector;
typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    int vacio;
    eFecha fechaDeIngreso;
    int idSector;
}eEmpleado;
int  menu();
int i;
void inicializarEmp(eEmpleado [],int);
void altas(eEmpleado[],int,eSector[],int);
int main()
{
    eEmpleado empleados[TAM]={{1234,"roman",'m',25000.0,1,{21,12,2010},5},{2222,"ariana",'f',33000.0,1,{12,4,2004},5},{1244,"juan",'m',33000.0,1,{21,12,2013},1},{1235,"xiomara",'f',28000.0,1,{21,12,2013},2},};
    eSector sectores[]={{1,"Ventas"},{2,"Compras"},{3,"Comercial"},{4,"RRHH"},{5,"Sistemas"}};
    inicializarEmp(empleados,TAM);
    for(i=0;i<4;i++)
    {
        empleados[i].vacio=0;
    }

    int salir=0;
    do
    {

        switch(menu())
        {
        case 1:
            altas(empleados,TAM,sectores,TSEC);
            system("PAUSE");
            break;
        case 2:
            bajas(empleados,TAM,sectores,TSEC);
            system("PAUSE");
            break;
        case 4:
            listar(empleados,TAM,sectores);
            system("pause");
            break;
        case 3:
            modificar(empleados,TAM,sectores);
            system("pause");
            break;
        case 5:
            ordenar(empleados,TAM);
            system("Pause");
            break;
        case 6:
            totalSueldo(empleados,TAM);
            system("pause");
            break;
        case 7:
            maxSueldo(empleados,TAM,sectores);
            system("pause");
            break;
        case 8:
            mostrarPorSector(empleados,TAM,sectores,TSEC);
            system("pause");
            break;
        case 9:
            contarPorSector(empleados,TAM,sectores,TSEC);
            system("pause");
            break;
        case 10:
             sueldosPorSector(empleados,TAM,sectores,TSEC);
             system("pause");
             break;
        case 11:
            salir=1;
            break;
        default:
            printf("Opcion incorrecta!\n\n");
            system("pause");
        }
    }while(salir!=1);

    return 0;
}
int  menu()
{
    int opcion;

    system("cls");
    printf("      ---Empleados---\n\n");
    printf("1- Alta\n");
    printf("2- Baja\n");
    printf("3- Modificar\n");
    printf("4- Listar\n");
    printf("5- Ordenar\n");
    printf("6- Total sueldos\n");
    printf("7- Empleados que mas ganan\n");
    printf("8- Mostrar empleados x sector\n");
    printf("9- Informar cuantos empleados hay en cada sector\n");
    printf("10-Informar total de sueldos x Sector\n");
    printf("11-Salir\n");

    printf("\nIndique opcion: ");
    scanf("%d", &opcion);
    return opcion;
}
void inicializarEmp(eEmpleado vec[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        vec[i].vacio=1;
    }
}
void altas(eEmpleado vec[],int tamE,eSector sec[],int tamS)
{

    eEmpleado nuevoEmp;
    int libre;
    int legajo;
    int coincidencia;
    system("cls");
    printf("----Altas-----\n\n\n");
    libre=buscarLugar(vec,tamE);
    if(libre==-1)
    {
        printf("no hay lugar para agregar nuevos empleados\n");
    }
    else
    {
        printf("Ingrese legajo: ");
        scanf("%d",&legajo);
        coincidencia=buscarLegajo(vec,tamE,legajo);
        if(coincidencia==-1)
        {
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nuevoEmp.nombre);
            printf("Ingrese sexo(f/m): ");
            fflush(stdin);
            scanf("%c",&nuevoEmp.sexo);
            printf("Ingrese sueldo: ");
            scanf("%f",&nuevoEmp.sueldo);
            printf("Ingrese dia de ingreso: ");
            scanf("%d",&nuevoEmp.fechaDeIngreso.dia);
            printf("Ingrese mes de ingreso: ");
            scanf("%d",&nuevoEmp.fechaDeIngreso.mes);
            printf("Ingrese anio de ingreso: ");
            scanf("%d",&nuevoEmp.fechaDeIngreso.anio);
            nuevoEmp.idSector=menuSector(sec,tamS);
            nuevoEmp.vacio=0;
            nuevoEmp.legajo=legajo;
            vec[libre]=nuevoEmp;
            printf("\nAlta dada con exito\n");
        }
        else
        {
            printf("Ya esta inscrito ese legajo!!\n\n\n");
            printf("Legajo  Nombre  Sexo  Sueldo    Fecha de ingreso   Sector\n");
            printf("------  ------  ----  ------    ----------------   ------\n");
            mostrarEmpleado(vec,coincidencia,sec,vec[coincidencia].idSector);
        }
    }
}
int buscarLugar(eEmpleado vec[],int tam)
{
    int i;
    int indice=-1;
    for(i=0;i<tam;i++)
    {
        if (vec[i].vacio==1)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
int buscarLegajo (eEmpleado vec[],int tam,int legajo)
{
    int i;
    int indice=-1;
    for(i=0;i<tam;i++)
    {
        if(legajo==vec[i].legajo)
        {
            indice=i;
        }
    }
    return indice;
}
int menuSector(eSector sec[], int tam)
{
    int eleccion;
    int i;
    printf("Elija el id del sector: \n");
    for(i=0;i<tam;i++)
    {

        printf("%d-%s\n",sec[i].idSector,sec[i].nombreSector);
    }
       printf("\n");
       scanf("%d", &eleccion);
       return eleccion;
}
void mostrarEmpleado (eEmpleado vec[],int indice, eSector sec[],int secid)
{
    printf(" %4d  %7s   %c   %.2f      %02d/%02d/%4d     %7s\n\n\n",vec[indice].legajo,vec[indice].nombre,vec[indice].sexo,vec[indice].sueldo,vec[indice].fechaDeIngreso.dia,vec[indice].fechaDeIngreso.mes,vec[indice].fechaDeIngreso.anio,sec[secid-1].nombreSector);

}
void listar(eEmpleado vec[],int tam,eSector sec[])
{
    int i;
    system("cls");
    printf("\n               Lista de Empleados\n");
    printf("               ------------------\n\n\n");
    printf("Legajo  Nombre  Sexo  Sueldo    Fecha de ingreso   Sector\n");
    printf("------  ------  ----  ------    ----------------   ------\n");
    for(i=0;i<tam;i++)
    {
        if(vec[i].vacio ==0)
        {
            mostrarEmpleado(vec,i,sec,vec[i].idSector);
        }
    }
}
void bajas(eEmpleado vec[],int tam,eSector sec[])
{
    int legajo;
    int posicion;
    char conf;
    system("cls");
    printf("     -----Baja-----\n\n");
    printf("Ingrese legajo: ");
    scanf("%d", &legajo);
    posicion =buscarLegajo(vec,tam,legajo);
    if(posicion==-1)
    {
        printf("No se encontro legajo");
    }
    else
    {
        printf("Legajo  Nombre  Sexo  Sueldo    Fecha de ingreso   Sector\n");
        printf("------  ------  ----  ------    ----------------   ------\n");
        mostrarEmpleado(vec,posicion,sec,vec[posicion].idSector);
        printf("\nConfirma baja(s/n):");
        fflush(stdin);
        scanf("%c",&conf);
        if(conf=='s')
        {
            vec[posicion].vacio=1;
            printf("Baja se realizo con exito!\n\n");
        }
    }

}
void modificar(eEmpleado vec[],int tam,eSector sec[])
{
    char confirmar;
    int legajo;
    int buscar;

    system("cls");
    printf("              Modificacion de sueldo\n");
    printf("              -----------------------\n");
    printf("Ingrese legajo: ");
    scanf("%d",&legajo);
    buscar=buscarLegajo(vec,tam,legajo);
    if(buscar==-1)
    {
        printf("No se encontro legajo");

    }
    else
    {
        printf("Legajo  Nombre  Sexo  Sueldo    Fecha de ingreso   Sector\n");
        printf("------  ------  ----  ------    ----------------   ------\n");
        mostrarEmpleado(vec,buscar,sec,vec[buscar].idSector);
        printf("\nConfirma modificacion(s/n):");
        fflush(stdin);
        scanf("%c",&confirmar);
        if(confirmar=='s')
        {
            printf("Ingrese nuevo sueldo: ");
            scanf("%f",&vec[buscar].sueldo);
            printf("La modificacion se realizo con exito!\n\n");
        }
    }

}
void ordenar(eEmpleado vec[],int tam)
{
    eEmpleado nuevo;
    int i;
    int j;
    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(vec[i].sexo>vec[j].sexo)
            {
                nuevo=vec[i];
                vec[i]=vec[j];
                vec[j]=nuevo;
            }
            else
            {
                if(vec[i].sexo==vec[j].sexo)
                {
                    if(strcmp (vec[i].nombre,vec[j].nombre)>0)
                    {
                        nuevo=vec[i];
                        vec[i]=vec[j];
                        vec[j]=nuevo;
                    }

                }
            }
        }
    }

}
void totalSueldo(eEmpleado vec[],int tam)
{
    float total=0;
    int i;
    for(i=0;i<tam;i++)
    {
        if(vec[i].vacio==0)
        {
            total=total+vec[i].sueldo;
        }
    }
    printf("El total de los sueldos es: %.2f\n\n",total);
}
void maxSueldo(eEmpleado vec[],int tam,eSector sec[])
{
    int max=0;
    int i;



    for(i=0;i<tam;i++)
    {
        if(max<vec[i].sueldo&&vec[i].vacio==0)
        {
            max=vec[i].sueldo;
        }
    }
    for(i=0;i<tam-1;i++)
    {
        if(vec[i].sueldo==max)
        {
            mostrarEmpleado(vec,i,sec,vec[i].idSector);
        }

    }

}
void mostrarPorSector(eEmpleado vec[],int tam, eSector sec[],int tamS)
{
    int i;
    int j;
    system("cls");
    for(i=0;i<tamS;i++)
    {
       printf("   ----%s----\n\n\n",sec[i].nombreSector);
        for(j=0;j<tam;j++)
        {
            if(sec[i].idSector==vec[j].idSector&&vec[j].vacio==0)
            {
                mostrarEmpleado(vec,j,sec,vec[j].idSector);
            }
        }


    }
}
void contarPorSector(eEmpleado vec[],int tam, eSector sec[],int tamS)
{
    int i;
    int j;

    system("cls");
    for(i=0;i<tamS;i++)
    {
        int acumulador=0;
        printf("   ----%s----\n\n",sec[i].nombreSector);
        for(j=0;j<tam;j++)
        {
            if(sec[i].idSector==vec[j].idSector&&vec[j].vacio==0)
            {
                acumulador++;
            }
        }

        printf("Cantidad de empleados: %d\n\n",acumulador);
    }
}
void sueldosPorSector(eEmpleado vec[],int tam, eSector sec[],int tamS)
{
    int i;
    int j;

    system("cls");
    for(i=0;i<tamS;i++)
    {
        float acumulador=0;
        printf("   ----%s----\n\n",sec[i].nombreSector);
        for(j=0;j<tam;j++)
        {
            if(sec[i].idSector==vec[j].idSector&&vec[j].vacio==0)
            {
                acumulador=vec[j].sueldo+acumulador;
            }
        }

        printf("Sueldo por sector: %.2f\n\n",acumulador);
    }
}
