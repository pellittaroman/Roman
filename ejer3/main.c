#include <stdio.h>
#include <stdlib.h>
/*3.	Escribir  un programa que realice las siguientes acciones
•	Limpie la pantalla
•	Asigne a 2 variables numero1 y numero2 valores distintos de cero
•	Efectúe el producto de dichas variables
•	Muestre el resultado pos pantalla
•	Obtenga el cuadrado de numero1 y lo muestre par pantalla
*/
int main()
{
    int numero;
    int numero1;
    int producto;
    int cuadrado;
    system("cls");
    srand (getpid());
    numero = rand ()%11 +1 ;
    numero1 = rand ()%11 +1 ;
    producto=numero*numero1;
    cuadrado=numero*numero;
    printf("El producto entre %d y %d es igual a %d\n",numero,numero1,producto);
    printf("El cuadrado del primero da: %d\n",cuadrado);
    return 0;
}
