#include <stdio.h>

void base_exponente(int *a, int *b)
{
    printf("Ingrese la base: ");
    scanf("%i", a);
    printf("Ingrese el exponenete: ");
    scanf("%i", b);
}

double exponenciacion_binaria(int base, int exp)
{
    double mitad;

    if (exp == 0)
        return 1.0;
    if (exp < 0)
        return 1.0 / exponenciacion_binaria(base, -exp);
    mitad = exponenciacion_binaria(base, exp / 2);
    if (exp % 2 == 0)
        return mitad * mitad;
    return base * mitad * mitad;
}

int main() {
    int x, n;
    base_exponente(&x, &n);
    printf("%i^%i = %.2f\n", x, n, exponenciacion_binaria(x, n));
}
