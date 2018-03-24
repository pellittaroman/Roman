#include <stdio.h>
#include <stdlib.h>

int main()
{   int numeroUno;
    int numeroDos;
    int suma;
    float div;
    printf("ingrese un numero...");
    scanf("%d", &numeroUno);
    printf("\ningrese numero...");
    scanf("%d", &numeroDos);
    if (numeroUno==numeroDos)
    {
        printf("%d%d",numeroUno,numeroDos);

    }else
    {
        if(numeroDos>numeroUno)
        {
            suma= numeroUno+numeroDos;

            printf("la suma es %d",suma);

            if(suma<50)
            {
                printf(" y es menor que 50");
            }
        }else
        {   if (numeroDos!=0)
            {

                div=(float)numeroUno/numeroDos;
                printf("la division da %.2f",div);
            }else
            {
               printf ("no se puede dividir por cero");
            }
        }
    }
    return 0;
}
