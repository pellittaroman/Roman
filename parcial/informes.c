#include "libreria.h"

void informar(ePantalla pan[],int tam,ePublicacion pub[],int tamP ,eCliente cli[],int tamC)
{
    float cantidad;
    int i;
    int j;
    int k;
    float acumulador;
    float max;
    int flag=0;
    for(i=0;i<tamC;i++)
    {
        acumulador=0;
        if(cli[i].cuit!=0)
        {
            printf("C.U.I.T: %d\n",cli[i].cuit);
            for(j=0;j<tamP;j++)
            {
                if(pub[j].cuit==cli[i].cuit)
                {
                    for(k=0;k<tam;k++)
                    {
                        if(pub[j].idPan=pan[k].id)
                        {
                            cantidad=pan[k].precio*pub[j].cantidad;
                            printf("ID: %d Total por publicacion: %f",pan[k].id,cantidad);
                            acumulador=acumulador+cantidad;
                        }
                    }
                }
            }
        }
        if(acumulador>max||flag==0)
        {
            max=acumulador;
            flag=1;
        }
    }
    for(i=0;i<tamC;i++)
    {
        acumulador=0;
        if(cli[i].cuit!=0)
        {

            for(j=0;j<tamP;j++)
            {
                if(pub[j].cuit==cli[i].cuit)
                {
                    for(k=0;k<tam;k++)
                    {
                        if(pub[j].idPan=pan[k].id)
                        {
                            cantidad=pan[k].precio*pub[j].cantidad;
                            acumulador=acumulador+cantidad;
                        }
                    }
                }
            }
        }
        if(acumulador==max)
        {
            printf("C.U.I.T: %d Total a pagar: %d",cli[i].cuit,acumulador);
            break;
        }
}
}
