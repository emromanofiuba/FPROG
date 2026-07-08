#include <stdio.h>

//SUCESION FIBO -> 0 1 1 2 3 5 8 13 21 34 -> f(0) = 0; f(1) = 1; f(8) = 23;

//f(8) = f(7) + f(6) = 13 + 8

int fibonacci(int num)
{
    if (num <= 1)
        return num;
    else 
        return fibonacci(num - 1) + fibonacci(num - 2);
}

void main() {
    int i, n;
    printf("Numero n: ");
    scanf("%i", &n);

    printf("\nSUCESION FIBO HASTA %i\n", n);
    for (i=0; i <= n; i++)
        printf(" %i", fibonacci(i));
}