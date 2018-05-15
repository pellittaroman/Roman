#include <stdio.h>
#include <stdlib.h>

int main()
{
   int vec[]={3,4,9,6,8};
   mostrar(vec,5);
   mostrar1(vec,5);
   mostrar2(vec,5);
   mostrar3(vec,5);



    return 0;
}
void mostrar(int vec[],int tam){

    int i;
    for(i=0;i<tam;i++)
    {
        printf("%d",vec[i]);

    }
     printf("\n\n\n");
}




void mostrar1(int vec[],int tam)
{

    int i;
    for(i=0;i<tam;i++)
    {
        printf("%d",*(vec+i));

    }

         printf("\n\n\n");
}



void mostrar2(int* vec, int tam)
{

    int i;
    for(i=0;i<tam;i++)
    {
        printf("%d",vec[i]);

    }
        printf("\n\n\n");
}


void mostrar3(int* vec, int tam)
{

    int i;
    for(i=0;i<tam;i++)
    {
        printf("%d",*(vec+i));

    }
     printf("\n\n\n");

}
