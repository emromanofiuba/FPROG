#include <stdio.h>

void base_exponente(float *a, float *b)
{
    printf("Ingrese la base: ");
    scanf("%f", a);
    printf("Ingrese el exponenete: ");
    scanf("%f", b);
}

//5^4 = 5 * 5^3; = a * potencia(a, b-1)
float potencia(float a, float b)
{
    if (b == 0)
        return 1;
    else 
        return a * potencia(a, b-1);
}

int main(void)
{
    float a, b;
    base_exponente(&a, &b);
    printf("%.2f^%.2f = %.2f\n", a, b, potencia(a, b));
}