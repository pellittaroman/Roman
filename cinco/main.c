#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nota;
    printf("Ingrese nota de 0 a 10... ");
    scanf("%d",&nota);

    switch(nota)
    {
            case 0:
            case 1:
            case 2:
            case 3:
            printf("La proxima se puede");
            break;
            case 4:
            printf("Raspando, debes preocuparte mas");
            break;
            case 5:
            case 6:
            printf("Raspando");
            break;
            case 7:
            case 8:
            printf("Aprobo");
            break;
            case 9:
            case 10:
            printf("Aprobo, Muy bien");
            break;
            default:
            printf("Nota no valida");




    }
    return 0;
}
