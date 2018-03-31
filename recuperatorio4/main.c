#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1;
    int num2;
    float div;
    int suma;
    printf("Ingrese numero:\n");
    scanf("%d",&num1);
    printf("Ingrese numero:\n");
    scanf("%d",&num2);

    if (num1==num2)
    {
        printf("%d%d",num1,num2);
    }
    else if (num1>num2&&num2!=0)
    {
        div=(float)num1/num2;
        printf("La division es %.2f",div);
    }
    else if(num1<num2)
    {
           suma=num1+num2;
           printf("La suma da %d",suma);
           if(suma<50)
            {
                printf(" y es menor a 50");
            }
    }
    return 0;
}
