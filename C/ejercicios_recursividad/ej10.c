#include <stdio.h>

void pedir_enteros(int *dividendo, int *divisor)
{
    printf("Ingrese un numero: ");
    scanf("%i", dividendo);
    printf("Ingrese un numero: ");
    scanf("%i", divisor);
}

int mcd(int mayor, int menor)
{
    if (menor == 0)
        return mayor;

    return mcd(menor, mayor % menor);
}

int main(void) {
    int dividendo, divisor, maximo_comun_div;
    pedir_enteros(&dividendo, &divisor);
    maximo_comun_div = mcd(dividendo, divisor);

    printf("\nMCD(%i, %i) = %i\n", dividendo, divisor, maximo_comun_div);
}