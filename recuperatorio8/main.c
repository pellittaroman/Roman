#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nombre[100];
    int cantidadDePaginas;
    int cantVentas;
    int tema;
    int respuesta=1;
    int respuesta1;
    int cantPagPar=0;
    int cantPagImp=0;
    int sinVentas=0;
    int sumaVentas=0;
    int sumaPag=0;
    float Promedio;
    int contador=0;

    while(respuesta==1)
    {
        printf("Ingrese nombre del libro: ");
        gets(nombre);
        printf("\nCantidad de paginas: ");
        scanf("%d",&cantidadDePaginas);
        printf("\nCantidad de ventas: ");
        scanf("%d",&cantVentas);
        printf("\nTemas elija una opcion:\n1.Robotica\n2.Programacion\n3.Patrones\n4.Base de datos\n");
        scanf("%d",&tema);
        sumaVentas=sumaVentas+cantVentas;
        if(cantidadDePaginas%2==0)
        {
            cantPagPar++;
        }
        else
        {
            cantPagImp++;
        }
        if(cantVentas==0)
        {
            sinVentas++;
        }
        if(tema==2)
        {
            sumaPag=sumaPag+cantidadDePaginas;
        }

        printf("Desea continuar presione 1.s/2.n");
        scanf("%d", &respuesta1);
        while(respuesta1!=1&&respuesta1!=2)
        {
            printf("ERROR\nPara continuar 1\nPara salir 2\n");
            scanf("%d", &respuesta1);
        }


        contador++;
        if(respuesta1==1)
        {

        }
        else
        {
            respuesta++;
        }
    }
    Promedio=(float)sumaVentas/contador;
    printf("\nLa Cantidad de libros con un total de paginas pares es: %d",cantPagPar);
    printf("\nLa cantidad de libros con un total de paginas impares es: %d",cantPagImp);
    printf("\nLos libro que registran cero ventas son: %d",sinVentas);
    printf("\nEl promedio de ventas es igual a %.2f",Promedio);
    printf("\nLa suma de las paginas de Programacion son: %d",sumaPag);


    return 0;
}
