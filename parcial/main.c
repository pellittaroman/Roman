#include <stdio.h>
#include <stdlib.h>
#include "libreria.h"
#define TAM 100
#define TAMP 1000

int main()
{
    int  salir=0;
    ePantalla LCDLED[TAM];
    eCliente clientes[TAM];
    ePublicacion publica [TAMP];
    iniciaPan(LCDLED,TAM);
    iniciaPub(publica,TAMP);
    iniciaCli(clientes,TAM);

     do
    {
        switch(menu())
        {
        case 1:
            alta(LCDLED, TAM);
            system("pause");
            break;
        case 2:
            modificar(LCDLED,TAM);
            system("pause");
            break;
        case 3:
           bajaPantalla(LCDLED,TAM);
            system("pause");
            break;
        case 4:
            contratarPublicidad(LCDLED,TAM,publica,TAMP,clientes,TAM);
            system("pause");
            break;
        case 5:
            ModificarPublicacion(LCDLED,TAM,publica,TAMP,clientes,TAM);
            system("pause");
            break;
        case 6:
            cancelarPublicacion(LCDLED,TAM,publica,TAMP,clientes,TAM);
            system("pause");
            break;
        case 7:
            consultaFacturacion(LCDLED,TAM,publica,TAMP,clientes,TAM);
            system("pause");
            break;
        case 8:
            ListarContraciones(LCDLED,TAM,publica,TAMP,clientes,TAM);
            system("pause");
            break;
        case 9:
            listarPantallas(LCDLED,TAM);
            system("pause");
            break;
        case 10:
            informar (LCDLED,TAM,publica,TAMP,clientes,TAM);
            system("pause");
            break;
        case 11:
            printf("Salir\n");
            salir=1;
            break;
        default:
            printf("opcion incorrecta\n\n");
            fflush(stdin);
            system("pause");
            break;

        }

    }while (salir!=1);

    return 0;
}
