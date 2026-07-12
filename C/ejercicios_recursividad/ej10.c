#include <stdio.h>

void pedir_enteros(int *dividendo, int *divisor)
{
    printf("Ingrese un numero: ");
    scanf("%i", dividendo);
    printf("Ingrese un numero: ");
    scanf("%i", divisor);
    while (*divisor == 0) {
        printf("Debe ingresar un numero distinto de 0: ");
        scanf("%i", divisor);
    }
}

int mcd(int mayor, int menor)
{
    int resto;
    resto = mayor % menor;
    if (resto > 0){
        return mcd(menor, resto);
    }
    return menor;

}

int main(void) {
    int dividendo, divisor, maximo_comun_div;
    pedir_enteros(&dividendo, &divisor);
    maximo_comun_div = mcd(dividendo, divisor);

    printf("\nMCD(%i, %i) = %i\n", dividendo, divisor, maximo_comun_div);
}