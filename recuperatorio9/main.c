#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    char nombrePesado[100];
    int contador=0;
    char seguir='s';
    int tempPar=0;
    int pesoMax;
    int tempMax;

    while(seguir=='s')
    {
        printf("Ingrese nombre del animal: ");
        gets(nombre);
        printf("Ingrese peso: ");
        scanf("%d",&peso);
        while(peso<1||peso>1000)
        {
            printf("ERROR\nIngrese peso: ");
            scanf("%d",&peso);
        }
        printf("Ingrese temperatura del habitat: ");
        scanf("%d",&temp);
        while(temp<-30||temp>30)
        {
            printf("ERROR\nIngrese temperatura del habitat: ");
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
            strcpy(nombrePesado,nombre);



        }
        sumaPesos=sumaPesos+peso;
        contador++;

        printf("Desea continuar [s/n]\n");
        scanf(" %c",&seguir);
        getchar();

    }
    promedio=(float)sumaPesos/contador;
    printf("La cantidad de temperaturas par son %d\n",tempPar);
    printf("El nombre del animal mas pesado es el %s y la temperatura de habitat es %d\n",nombrePesado,tempMax);
    printf("La cantidad de animales que viven a temperaturas bajo cero es: %d\n",cantBajoCero);
    printf("El promedio de pesos es de: %.2f\n",promedio);
    printf("El peso maximo de los animales  que viven a temperaturas bajo cero es %dkg\nel minimo es %dkg\n",maximo,minimo);
    return 0;
}
