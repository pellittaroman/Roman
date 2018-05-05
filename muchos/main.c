#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int legajo;
    char nombre[20];
}eAlumno;
typedef struct
{
    int codigo;
    char descripcion[20];
}eMateria;
typedef struct
{
    int legAlumno;
    int codMateria;
}eInscripcion;

void mostrarAlumnosConMaterias (eAlumno [],int , eMateria[],int, eInscripcion[],int);

int main()
{
    eAlumno alumnos [20]={{12,"Roman"},{22,"Juan"},{33,"Valentino"},{44,"Liliana"}};
    eMateria mat[20]={{1,"Ingles"},{2,"matematicas"},{3,"programacion"},{4,"laboratorio"}};
    eInscripcion insc[]={{12,1},{12,2},{22,2},{33,3},{33,4},{33,2},{12,1},{44,3},{12,3},{12,4}};
    mostrarAlumnosConMaterias(alumnos,4,mat,4,insc,12);
    system ("Pause");
    cipm(mat,4,insc,12);
    system ("Pause");
    return 0;

}
void mostrarAlumnosConMaterias (eAlumno alm[],int tam, eMateria mat[],int tamm,eInscripcion Ins[],int tami)
{
    int i;
    int j;
    int z;
    for(i=0;i<tam;i++)
    {
        printf("Alumno\n");
        printf("------\n\n");
        printf ("%s\n\n",alm[i].nombre);
        printf("materias\n");
        printf("--------\n");

        for(j=0;j<tami;j++)
        {
            if(alm[i].legajo==Ins[j].legAlumno)
            {
                for(z=0;z<tamm;z++)
                {
                    if(Ins[j].codMateria==mat[z].codigo)
                    {
                        printf("%s\n\n\n",mat[z].descripcion);
                    }
                }
            }

        }

    }
}
void cipm(eMateria mat[],int tamm,eInscripcion I[], int tami)
{
    int i;
    int j;
    int contador;

    printf("\n\nMaterias\n");
    printf("--------\n\n");
    for(i=0;i<tamm;i++)
    {
        contador=0;
        printf("%s: ",mat[i].descripcion);
        for(j=0;j<tami;j++)
        {
            if(mat[i].codigo==I[j].codMateria)
            {
                contador++;
            }
        }
    printf("%d\n\n\n",contador);
    }

}
void maxI(eMaterira mat[],int tamM,eInscripcion I[],int tamI)
{

}
void mostrarAluPorMat(eAlumno alm[],int tamA,eInscripcion I[], int tamI,eMateria mat[], int mat)
{

}
