/*
Dado un número entero positivo ingresado por el usuario, procesarlo e indicar:
(realizar un programa diferente para cada caso)
a) La cantidad de dígitos pares e impares que lo componen.
b) El menor y el mayor dígito del número.
*/

# include <stdio.h>

int main()
{
    short contador_par, contador_impar, ultimo_digito;
    int numero;

    printf("Ingrese un numero entero positivo: ");
    scanf("%d", &numero);

    contador_impar = 0;
    contador_par = 0;

    while (numero > 0) {

       ultimo_digito = numero % 10;
       numero = numero / 10;

       if (ultimo_digito % 2 == 0)
            contador_par++;
       else if (ultimo_digito % 2 != 0)
            contador_impar++;
    }

    printf("\n Cantidad de digitos pares: %hd", contador_par);
    printf("\n Cantidad de digitos impares: %hd \n", contador_impar);

    return 0;
}