#include <stdio.h>

void base_altura(int *base, int *altura)
{
    printf("Base: ");
    scanf("%i", base);
    printf("Altura: ");
    scanf("%i", altura);

    if (*base < 0)
        *base = -(*base);
    if (*altura < 0)
        *altura = -(*altura);
}

void imprimir_fila(int base)
{
    if (base > 0) {
        printf("*");
        imprimir_fila(base - 1);
    }
}

void imprimir_rectangulo(int base, int altura)
{
    if (altura > 0) {
        imprimir_fila(base);
        printf("\n");
        imprimir_rectangulo(base, altura - 1);
    }
}

int main() {
    int base, altura;
    base_altura(&base, &altura);
    imprimir_rectangulo(base, altura);

    return 0;
}