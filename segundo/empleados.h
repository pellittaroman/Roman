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
void printEmpleadoAll(ArrayList* );
void printEmpleado(eEmpleado*);
int guardarArchivo (ArrayList* , char*);
int parserEmpleados(ArrayList* );
int getSalary(eEmpleado*);
int setSalary(eEmpleado* ,int );
int getHours(eEmpleado*);
int setHours(eEmpleado* ,int);
char* getAdress(eEmpleado* );



#endif // EMPLEADOS_H_INCLUDED
