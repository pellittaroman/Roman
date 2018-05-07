#include <stdio.h>
#include <stdlib.h>
#include "libreria.h"
void iniciaPan(ePantalla vec[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
    vec[i].ocupado = 1;
    vec[i].id=1000+i;
    }
}
int menu()
{
    system("cls");
    int opcion;

    printf("1.Alta de pantalla\n2.Modificacion datos de pantalla\n3.Baja pantalla\n4.Contratar publicacion\n5.Modificacion condiciones de publicacion\n6.Cancelar contratacion\n7.Consulta de facturacion\n8.Listar contrataciones\n9.Listar pantallas\n10.Informes\n11.salir\nElija opcion: ");
    scanf("%d",&opcion);

    return opcion;
}
void alta(ePantalla vec[],int  tam)
{

    int indice;
    indice=buscarLugar(vec,tam);

    if(indice ==-1)
    {
        printf("No hay lugar para mas pantallas\n\n");

    }
    else
    {
            ePantalla nueva;
            printf("ID: %d\n",vec[indice].id);
            nueva.id=vec[indice].id;
            nueva.ocupado=0;
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nueva.nombre);
            printf("Ingrese calle: ");
            fflush(stdin);
            gets(nueva.calle);
            printf("Ingrese altura: ");
            scanf("%d",&nueva.altura);
            printf("Ingrese tipo:\n1.LCD\n2.LED\n");
            scanf("%d", &nueva.tipo   );
            printf("Ingrese precio por dia: ");
            scanf(" %f", &nueva.precio);
            printf("alta exitosa!");
            printf("\n");
            vec[indice]=nueva;
    }

}
int buscarLugar(ePantalla vec[], int tam)
{
    int indice = -1;
    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
void iniciaPub(ePublicacion vec[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
    vec[i].estado = 1;

    }
}
void mostrarPanta(ePantalla vec[],int indice)

{

    char tipo[4];
    if(vec[indice].tipo==1)
    {
        strcpy(tipo,"LCD");
    }
    else
    {
        strcpy(tipo,"LED");
    }

    printf("%4d %8s    %8s     %4d  %.2f %s\n", vec[indice].id, vec[indice].nombre,vec[indice].calle,vec[indice].altura,vec[indice].precio,tipo);
}
void modificar(ePantalla vec[],int tam)
{
    int id;
    int i;
    char confirmar;

    printf("Ingrese id: ");
    scanf("%d",&id);
    i=buscarId(vec,tam,id);
    if(i==-1)
    {
        printf("no se encontro id");
    }
    else
    {
            mostrarPanta(vec,i);
            printf("Desea modificar la publicacion(s/n): ");
            scanf("%s",&confirmar);
            if(confirmar=='s')
            {
                ePantalla nueva;
                nueva.id=vec[i].id;
                nueva.ocupado=0;
                printf("Ingrese nombre: ");
                fflush(stdin);
                gets(nueva.nombre);
                printf("Ingrese calle: ");
                fflush(stdin);
                gets(nueva.calle);
                printf("Ingrese altura: ");
                scanf("%d",&nueva.altura);
                printf("Ingrese tipo:\n1.LCD\n2.LED\n");
                scanf("%d", &nueva.tipo   );
                printf("Ingrese precio por dia: ");
                scanf(" %f", &nueva.precio);
                printf("Se modificaron datos!\n");

                vec[i]=nueva;
            }
            else
            {
                printf("Se cancelo operacion");
            }
        }


}

int buscarId(ePantalla vec[],int tam,int id)
{
    int i;
    int indice=-1;
    for(i=0;i<tam;i++)
    {
        if (id==vec[i].id&&vec[i].ocupado==0 )
        {
            indice=i;
        }
    }
    return indice;
}
void listarPantallas(ePantalla vec[],int tam)
{
    int i;
    system("cls");
    for(i=0;i<tam;i++)
    {
        if(vec[i].ocupado==0)
        {
            printf(" ID    Nombre      Calle      Altura  Precio  Tipo\n");
            printf(" --    ------      -----      ------  ------  ----\n");
            mostrarPanta(vec,i);
        }
    }

}
void bajaPantalla(ePantalla vec[],int tam)
{
    int id;
    int i;
    char confirma;
    printf("Ingrese id: ");
    scanf("%d",&id);
    i=buscarId(vec,tam,id);
    if(i!=-1)
    {
        mostrarPanta(vec,i);
        printf("Confirma baja(s/n): ");
        scanf(" %c",&confirma);
        if(confirma=='s')
        {
            vec[i].ocupado=1;
            printf("Baja exitosa!\n");
        }
        else
        {
            printf("Operacion cancelada\n");
        }
    }
    else
    {
        printf("No se encuentra ID");
    }
}
void contratarPublicidad(ePantalla vec[],int tam,ePublicacion pub[],int tamP,eCliente cli[],int tamC)
{
    int id;
    int i;
    char confirma;
    int indiceP;
    int indice;
    listarPantallas(vec,tam);
    printf("Ingrese ID de la pantalla que quiere: ");
    scanf("%d",&id);
    i=buscarId(vec,tam,id);
    mostrarPanta(vec,i);
    printf("Confirma la pantalla(s/n): ");
    scanf("%c",&confirma);
    if(confirma=='s')
    {
        indice=buscarlugarCliente(cli,tamC);
        indiceP=buscarLugarPublicidad(pub,tamP);
        if(indiceP==-1||indice==-1)
        {
            printf("No hay lugar para realizar la operacion");
        }
        else
        {
            eCliente nuevoCli;
            ePublicacion nuevaPub;
            printf("Ingrese CUIT");
            scanf("%d",&nuevoCli.cuit);
            indice=buscarCuit(cli,tamC,nuevoCli.cuit,indice);
            nuevaPub.cuit=nuevoCli.cuit;
            printf("Ingrese cantidad de dias que quiere publicar: ");
            scanf("%d",&nuevaPub.cantidad);
            printf("Ingrese nombre de archivo a reproducir: ");
            fflush(stdin);
            gets(nuevaPub.nombre);
            nuevaPub.estado=0;
            nuevaPub.idPan=id;
            pub[indiceP]=nuevaPub;
            cli[indice]=nuevoCli;
        }
    }
    else
    {
        printf("Se cancelo publicacion!\n");
    }


}
int buscarLugarPublicidad(ePublicacion vec[], int tam)
{
    int indice = -1;
    for(int i=0; i < tam; i++)
    {
        if(vec[i].cuit== 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
void iniciaCli(eCliente vec[],int tam)
{
  int i;

  for(i=0;i<tam;i++)
  {
      vec[i].cuit=0;
  }

}
int buscarlugarCliente(eCliente vec[], int tam)
{
    int indice = -1;
    int i;
    for(int i=0; i < tam; i++)
    {
        if(vec[i].cuit == 0)
        {
            indice = i;
            break;
        }

    }
    return indice;
}
int buscarCuit(eCliente vec[],int tam,int cuit,int indice)
{
    int nuevoIndice=indice;
    int i;

    for(i=0;i<tam;i++)
    {
        if(vec[i].cuit==cuit)
        {
            nuevoIndice=i;
        }
    }
    return nuevoIndice;
}
void ModificarPublicacion(ePantalla pan[],int tam,ePublicacion pub[],int tamP ,eCliente cli[],int tamC)
{
    int cuit;
    int id;
    int error;
    char confirma;
    int indice;
    printf("Ingrese CUIT: ");
    scanf("%d",&cuit);
    error=coincidencia(pub,tamP,cuit);
    if(error==0)
    {
        coincidencia2(pan,tam,pub,tamP,cli,tamC,cuit);
        printf("Ingrese ID de pantalla: ");
        scanf("%d",&id);
        printf("Confirma modificar(s/n): ");
        scanf("%c",&confirma);
        if(confirma=='s')
        {
            indice=buscarIdPub(pub,tamP,id);
            printf("Ingrese cantidad de dias");
            scanf("%d",&pub[indice].cantidad);
        }
        else
        {
            printf("Operacion cancelada");
        }
    }
    else
    {
        printf("No se encontro CUIT");
    }
}
void coincidencia2(ePantalla pan[],int tam,ePublicacion pub[],int tamP ,eCliente cli[],int tamC,int cuit)
{
    int i;

    for(i=0;i<tamP;i++)
    {
        printf(" ID    Nombre      Calle      Altura  Precio  Tipo\n");
        printf(" --    ------      -----      ------  ------  ----\n");
        if(cuit==pub[i].cuit)
        {
            mostrarPanta(pan,i);
        }

    }
}
int coincidencia(ePublicacion pub[],int tamP,int cuit)
{
    int i;
    int error=1;
    for(i=0;i<tamP;i++)
    {

        if(cuit==pub[i].cuit)
        {
            error=0;
            break;
        }

    }
    return error;
}
int  buscarIdPub(ePublicacion vec[],int tam,int id)
{
    int i;
    int indice=-1;
    for(i=0;i<tam;i++)
    {
        if (vec[i].idPan==id)
        {
            indice=i;
        }
    }
    return indice;
}
void cancelarPublicacion(ePantalla pan[],int tam,ePublicacion pub[],int tamP ,eCliente cli[],int tamC)
{
    int cuit;
    int id;
    int error;
    char confirma;
    int indice;
    printf("Ingrese CUIT: ");
    scanf("%d",&cuit);
    error=coincidencia(pub,tamP,cuit);
    if(error==0)
    {
        coincidencia2(pan,tam,pub,tamP,cli,tamC,cuit);
        printf("Ingrese ID de pantalla: ");
        scanf("%d",&id);
        printf("Confirma modificar(s/n): ");
        scanf("%c",&confirma);
        if(confirma=='s')
        {
            indice=buscarIdPub(pub,tamP,id);
            pub[indice].estado=1;
            printf("Publicaion dada de baja!");
        }
        else
        {
            printf("Operacion cancelada");
        }
    }
    else
    {
        printf("No se encontro CUIT");
    }
}
void consultaFacturacion(ePantalla pan[],int tam,ePublicacion pub[],int tamP ,eCliente cli[],int tamC)
{
    int cuit;
    int error;
    printf("Ingrese CUIT: ");
    scanf("%d",&cuit);
    error=coincidencia(pub,tamP,cuit);
    if(error==0)
    {
        sumar(pan,tam,pub,tamP,cli,tamC,cuit);
    }
    else
    {
        printf("No se encontro CUIT");
    }
}
void sumar(ePantalla pan[],int tam,ePublicacion pub[],int tamP ,eCliente cli[],int tamC,int cuit)
{
    float cantidad;
    int i;
    int j;
    for(i=0;i<tamP;i++)
    {
        if(pub[i].cuit==cuit)
        {
            for(j=0;j<tam;j++)
            {
                if(pub[i].idPan==pan[j].id)
                    printf(" ID");
                    cantidad=(float)pan[j].precio*pub[i].cantidad;
                    printf("%d   %f",pan[j].id,cantidad);
            }
        }
    }
}
void ListarContraciones (ePantalla pan[],int tam,ePublicacion pub[],int tamP ,eCliente cli[],int tamC)
{
    int cuit;
    int error;
    printf("Ingrese CUIT: ");
    scanf("%d",&cuit);
    error=coincidencia(pub,tamP,cuit);
    if(error==0)
    {
        Listar(pan,tam,pub,tamP,cuit);
    }
    else
    {
        printf("No se encontro CUIT");
    }

}
void Listar (ePantalla pan[],int tam,ePublicacion pub[],int tamP,int cuit)
{
    int i;
    int j;
    printf("PANTALLA  ARCHIVO  DURACION C.U.I.T ");
    for(i=0;i<tamP;i++)
    {
        if(cuit==pub[i].cuit&&pub[i].estado==0)
        {
            for(j=0;j<tam;j++)
            {
                if(pub[i].idPan==pan[j].id)
                {
                    printf("%8s %7s %d     %d",pan[j].nombre,pub[i].nombre,pub[i].cantidad,pub[i].idPan);
                }
            }
        }
    }

}
