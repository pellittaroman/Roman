#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED
typedef struct
{
    int id;
    char nombre[20];
    char direccion[30];
    int horas;
    int sueldo;
}eEmpleado;
int orden(void* ,void* );
int calcularSalary(void* );
int filtrado (void* );


#endif // EMPLEADOS_H_INCLUDED
