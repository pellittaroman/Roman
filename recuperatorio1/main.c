#include <stdio.h>
#include <stdlib.h>

int main()
{   int base;
    int alt;
    int per;
    float sup;
    printf("Ingrese base:\n");
    scanf("%d", &base);
    printf("Ingrese altura:\n");
    scanf("%d", &alt);
    per=base*3;
    sup=base*alt/2.0;
    printf("La superficie es igual a %.2f cm y el perimetro es de %d cm" ,sup,per);
    return 0;
}
