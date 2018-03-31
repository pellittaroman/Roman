#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nombre[100];
    int peso;
    int sumaPesos=0;
    float promedio;
    int maximo;
    int minimo;
    int temp;
    int cantBajoCero=0;
    int contador=0;
    int seguir=1;
    int tempPar=0;
    int pesoMax;
    int tempMax;

    while(seguir==1)
    {
        printf("Ingrese nombre del animal:\n");
        gets(nombre);
        printf("Ingrese peso:\n");
        scanf("%d",&peso);
        while(peso<1||peso>1000)
        {
            printf("ERROR\nIngrese peso:\n");
            scanf("%d",&peso);
        }
        printf("Ingrese temperatura del habitat:\n");
        scanf("%d",&temp);
        while(temp<-30||temp>30)
        {
            printf("ERRORIngrese temperatura del habitat:\n");
            scanf("%d",&temp);
        }
        if(temp!=0&&temp%2==0)
        {
            tempPar++;
        }
        if(temp<0)
        {
            cantBajoCero++;
            if(cantBajoCero==1||peso>maximo)
            {
                maximo=peso;
            }
            if(cantBajoCero==1||peso<minimo)
            {
                minimo=peso;
            }
        }
        if(contador==0||peso>pesoMax)
        {
            pesoMax=peso;

            tempMax=temp;
        }
        sumaPesos=sumaPesos+peso;
        contador++;
        printf("Ingrese\n1.para continuar\n2.para terminar\n");
        scanf("%d",&seguir);

    }
    promedio=(float)sumaPesos/contador;
    printf("La cantidad de temperaturas par son %d\n",tempPar);
    printf("El nombre del animal mas pesado es... y la temperatura de habitat es %d\n",tempMax);
    printf("La cantidad de animales que viven a temperaturas bajo cero es: %d\n",cantBajoCero);
    printf("El promedio de pesos es de: %.2f\n",promedio);
    printf("El peso maximo de los animales  que viven a temperaturas bajo cero es %d\nel minimo es %d\n",maximo,minimo);
    return 0;
}
