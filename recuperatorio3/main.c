#include <stdio.h>
#include <stdlib.h>

int main()
{   int precio;
    int des;
    float descuento;
    float iva;
    float precioConDes;
    float precioFinal;
    printf("Ingrese precio:\n");
    scanf("%d", &precio);
    printf("Ingrese descuento:\n");
    scanf("%d", &des);
    descuento=(des/100.0)*precio;
    precioConDes=precio-descuento;
    iva=precioConDes*0.21;
    precioFinal=precioConDes+iva;
    printf("El descuento es de %.2f\nEl precio con descuento es de %.2f\nEl IVA es de %.2f\nPrecio final a pagar: %.2f",descuento,precioConDes,iva,precioFinal);

    return 0;
}
