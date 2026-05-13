# include <stdio.h>

int ingreso_numero()
{
    int numero;

    printf("Ingrese un numero entero: ");
    scanf("%i", &numero);

    return numero;
}

void calculos_pares(int numero, int *cantidad_pares, int *producto_pares)
{
    *producto_pares = 1;
    *cantidad_pares = 0;

    int digito;

    while (numero > 0) {
        digito = numero % 10;
        if (digito % 2 == 0) {
            (*producto_pares) *= digito;
            (*cantidad_pares)++;
        }
        numero = numero / 10;
    }
}

int main(void)
{
    int cantidad_pares;
    int producto_pares;
    int numero;

    numero = ingreso_numero();

    calculos_pares(numero, &cantidad_pares, &producto_pares);

    printf("\nEl numero %i tiene %i digitos pares y su producto es: %i\n", numero, cantidad_pares, producto_pares);

    return 0;
}