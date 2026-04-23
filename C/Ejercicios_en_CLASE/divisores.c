# include <stdio.h>

int main()
{
    int divisor, N, i;

    divisor = 0;

    printf("Ingrese un numero: ");
    scanf("%i", &N);

    for (i = 1; i <= N; i++)
        if (N % i == 0)
            divisor++;

    if (divisor == 2)
        printf("El numero %i es primo\n", N);
    else
        printf("El numero %i no es primo\n", N);

    return 0;
}