#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* vector;
    int i;
    int* aux;
    vector= (int*) malloc(sizeof(int) *5);

    if(vector==NULL)
    {
        printf("No se pudo asignaqr memoria\n");
        exit(1);
    }

    for(i=0;i<5; i++)
        {
            printf("ingrese numero: ");
            scanf("%d", vector + i);
        }

        for(i=0;i<5;i++)
        {
            printf("%d ", *(vector+i));
        }
        printf("\n\n");
        aux=(int*) realloc(vector,10 * sizeof(int));

        if(aux!=NULL)
        {
            vector=aux;
        }
        else
        {
            printf("no se puede agrandar el programa\n");
        }

        for(i=5;i<10; i++)
        {
            printf("ingrese numero: ");
            scanf("%d", vector + i);
        }
                for(i=0;i<10;i++)
        {
            printf("%d ", *(vector+i));
        }

        return 0;
}
