#include <stdio.h>
#include <stdlib.h>
void mostrarVector(int[],int);
int mostrarMaximo(int[],int);
int mostrarMin(int[], int);
int buscar(int [], int ,int );
void acomodar(int[],int);
int main()
{   int vec[]={3,1,5,6,8,4};
    int busc;
    printf("Ingrese el num q desea buscar");
    scanf("%d",&busc);
    mostrarVector(vec,6);
    printf("\n");
    printf("%d\n",mostrarMaximo(vec,6));
    printf("%d\n",mostrarMin(vec,6));
    printf("%d\n",buscar(vec,6,busc));
    acomodar(vec,6);
    return 0;

}
void mostrarVector(int vec[],int i)
{

    int c;
    for(c=0;c<i;c++)
    {
        printf("%d ",vec[c]);

    }
}
int mostrarMaximo(int vec[], int i)
{
    int c;
    int flag=0;
    int max;
    for(c=0;c<i;c++)
    {
        if(flag==0 || vec[c]>max)
        {
            max=vec[c];
            flag=1;
        }

    }
    return max;
}
int mostrarMin(int vec[], int i)
{
    int c;
    int flag=0;
    int min;
    for(c=0;c<i;c++)
    {
        if(flag==0 || vec[c]<min)
        {
            min=vec[c];
            flag=1;
        }

    }
    return min;
}
int buscar(int vec[], int i,int a)
{
    int c;
    int indice;


    for(c=0;c<i;c++)
    {   indice=-1;
        if(vec[c]==a)
        {
          indice=c;
          break;

        }

          return indice;
}
void acomodar(int vec[],int i)
{
    int c;
    int aux;
    int t;

    for(c=0;c<i-1;c++)
        {
            for(t=c+1;t<i;t++)
            {
                if(vec[i]>vec[t])
                {
                    aux=vec[t];
                    vec[t]=vec[i];
                    vec[i]=aux;
                }
            }

        }
        for(c=0;c<i;c++)
    {
        printf("%d ",vec[c]);

    }

}
