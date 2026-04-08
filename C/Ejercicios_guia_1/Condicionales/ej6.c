/*
Ingresar tres números y hallar el mayor.
*/

#include <stdio.h>

void main(){
    int num_1, num_2, num_3;

    printf("Ingresará 3 numeros en total \n");

    printf("\nIngrese el 1° numero: ");
    scanf("%i", &num_1);

    printf("Ingrese el 2° numero: ");
    scanf("%i", &num_2);

    printf("Ingrese el 3° numero: ");
    scanf("%i", &num_3);

    if (num_1 > num_2 && num_1 > num_3)
        printf("\n el 1° numero ingresado (%i) es el mayor \n", num_1);
    else if (num_2 > num_1 && num_2 > num_3)
        printf("\n el 2° numero ingresado (%i) es el mayor \n", num_2);
    else
         printf("\n el 3° numero ingresado (%i) es el mayor \n", num_3);
}