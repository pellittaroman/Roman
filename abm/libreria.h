#ifndef LIBRERIA_H_INCLUDED
#define LIBRERIA_H_INCLUDED

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
    int isEmpty;
}eEmpleado;

void mostrarEmp(eEmpleado[],int tam);

eEmpleado cargardatos();

int menu();

void bajaEmpleado(eEmpleado [],int);

void modificarEmpleado(eEmpleado[],int);


#endif // LIBRERIA_H_INCLUDED
