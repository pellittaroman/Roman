#ifndef LIBRERIA_H_INCLUDED
#define LIBRERIA_H_INCLUDED
typedef struct
{
int id;
char nombre[20];
}eSector;
typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;
typedef struct
{
    char nombre[20];
    int legajo;
    char sexo;
    float sueldo;
    eFecha fecha;
    int idSector;
    int isEmpty;
}eEmpleado;

void mostrarEmp(eEmpleado[],eSector [],int tam);

eEmpleado cargardatos();

int menu();

void bajaEmpleado(eEmpleado [],eSector [],int);

void modificarEmpleado(eEmpleado[],eSector [],int);

int pedirSector();

int buscarLibre(eEmpleado vec [],int tam);

eSector mostrarSector(eSector [],int );

//void ordenarEmpleados(eEmpleado[],int);


#endif // LIBRERIA_H_INCLUDED
