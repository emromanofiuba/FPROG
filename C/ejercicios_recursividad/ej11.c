#include <stdio.h>

void base_exponente(int *a, int *b)
{
    printf("Ingrese la base: ");
    scanf("%i", a);
    printf("Ingrese el exponenete: ");
    scanf("%i", b);
}

//5^4 = 5 * 5^3; = a * potencia(a, b-1)
float potencia(int a, int b)
{
    if (b == 0)
        return 1;
    else if (b < 0)
        return 1.0 / potencia(a, -b);
    return a * potencia(a, b-1);
}

int main()
{
    int a, b;
    base_exponente(&a, &b);
    printf("%i^%i = %.2f\n", a, b, potencia(a, b));
    return 0;
}