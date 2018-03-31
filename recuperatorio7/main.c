#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nota;
    int edad;
    char sexo;
    int flag=0;
    int sumaDeNotas=0;
    float promedio;
    int notaMasBaja;
    int sexoNotaBaja;
    int cantidadVarones=0;
    int notaMujer;
    int edadMujer;
    int masJoven;
    int masJovenNota;
    int masJovenSexo;
    int contadorMujer=0;
    int flagM=0;
    int i;
    for(i=0;i<5;i++)
    {


    printf("Ingrese nota: ");
    scanf("%d", &nota);
    while(nota<0 || nota>10)
    {
        printf("ERROR\nIngrese nota: ");
        scanf("%d",&nota);
    }

    printf("Ingrese edad: ");
    scanf("%d",&edad);
    while(edad<6)
    {
        printf("ERROR\nIngrese edad: ");
        scanf("%d", &edad);

    }

    printf("Ingrese sexo 'm' o 'f': ");
    scanf(" %c", &sexo);
    while(sexo!='m'&& sexo!='f')
    {
        printf("ERROR");
        printf("Ingrese sexo 'm' o 'f'\n");
        scanf(" %c", &sexo);
    }



    sumaDeNotas=sumaDeNotas+nota;

    if (flag==0 || nota<notaMasBaja)
    {
        notaMasBaja=nota;
        sexoNotaBaja=sexo;
    }
    if (sexo== 'm' && nota>=6)
    {
        cantidadVarones++;
    }
    if(flag==0 || edad<masJoven)
    {
        masJoven=edad;
        masJovenNota=nota;
        masJovenSexo=sexo;
        flag=1;
    }
    if(sexo=='f' && flagM==0)
    {
        notaMujer=nota;
        edadMujer=edad;
        flagM=1;
    }
    if(sexo=='f')
    {
        contadorMujer++;
    }



    }
    promedio=sumaDeNotas/5.0;
    printf("El promedio de las notas es: %.2f\n",promedio);
    printf("La nota mas baja es de %d y el sexo %c\n",notaMasBaja,sexoNotaBaja);
    printf("La cantidad de varones mayores a 18 que su nota a sido igual o mayor que 6 es: %d",cantidadVarones);
    printf("La nota de la persona mas joven es %d y su sexo es %c\n",masJovenNota,masJovenSexo);
    if(contadorMujer==0)
    {
        printf("No hubo ninguna mujer");
    }
    else
    {
        printf("La edad de la primera mujer ingresada es %d y su nota es %d",edadMujer,notaMujer);
    }


    return 0;
}
