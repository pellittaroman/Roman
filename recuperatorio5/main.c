#include <stdio.h>
#include <stdlib.h>

int main()
{   int dia;
    printf("Ingrese dia de la semana;\n1.Domingo\n2.Lunes\n3.Martes\n4.Miercoles\n5.Jueves\n6.Viernes\n7.Sabado\n");
    scanf("%d",&dia);
    switch(dia)
    {
        case 1:
        case 7:
        printf("Buen finde");
        break;
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        printf("A trabajar");
        break;
        default:
        printf("ERROR");
        break;
    }
    return 0;
}
