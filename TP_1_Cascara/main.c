#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
    char seguir='s';
    int opcion=0;
    float x=0;
    float y=0;
    float resultado;
    char fac;



    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (A=%.2f)\n",x);
        printf("2- Ingresar 2do operando (B=%.2f)\n",y);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                x =pedirNum();
                seguir='s';
                break;
            case 2:
                y =pedirNum();
                seguir='s';
                break;
            case 3:
                resultado=suma(x,y);
                printf("La suma da: %.3f\n\n",resultado);
                break;
            case 4:
                resultado=resta(x,y);
                printf("La resta da: %.3f\n\n",resultado);
                seguir='s';
                break;
            case 5:
                dividir(x,y);
                seguir='s';
                break;
            case 6:
                resultado=multiplica(x,y);
                printf("La multiplicacion da: %.3f\n\n",resultado);
                seguir='s';
                break;
            case 7:
                printf("Seleccion operando a factorear: 'x' o 'y':\n");
                scanf(" %c",&fac);
                switch(fac)
                {   case 'x':
                    printf("El factorial de %c es: %lu\n\n",fac,fact(x));
                    break;
                    case 'y':
                    printf("El factorial de %c es: %lu\n\n",fac,fact(y));
                    break;
                    default:
                    printf("ERROR\n");
                    printf("Seleccion operando a factorear: 'x' o 'y'\n");
                    scanf(" %c",&fac);
                }
                seguir='s';
                break;
            case 8:

                printf("La suma da: %.2f\n\n",suma(x,y));
                printf("La resta da: %.2f\n\n",resta(x,y));
                dividir(x,y);
                printf("La multiplicacion da: %.3f\n\n",multiplica(x,y));
                printf("El factorial de x da:%lu\n\n",fact(x));
                printf("El factorial de y da:%lu\n\n\n",fact(y));
                seguir='s';
                break;
            case 9:
                seguir = 'n';
                break;
        }
    }


    return 0;
}
