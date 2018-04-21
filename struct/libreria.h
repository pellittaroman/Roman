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
}eEmpleado;

void mostrarEmp(eEmpleado[],int tam);

eEmpleado cargardatos();



#endif // LIBRERIA_H_INCLUDED
