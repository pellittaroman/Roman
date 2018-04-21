

void mostrarEmp(eEmpleado Empl[] ,int tam)
{
    int i;
    eEmpleado Emp;
   for(i=0;i<tam;i++)
    {
        Emp = Empl[i];

        printf("Legajo: %d\n",Emp.legajo );
        printf("Nombre: %s\n",Emp.nombre);
        printf("Sexo: %c\n",Emp.sexo);
        printf("Sueldo: %.2f\n",Emp.sueldo);
        printf("Fecha de ingreso %d/%d/%d\n",Emp.fecha.dia,Emp.fecha.mes,Emp.fecha.anio);
        printf("\n");
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
