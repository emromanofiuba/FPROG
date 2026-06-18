# include <stdio.h>

int factorial_iterativo(int num)
{
    int i, factorial = 1;
    for (i = 1; i <= num; i++)
        factorial *= i;
    return factorial;
}

int factorial_recursivo(int num)
{
    if (num == 0)
        return 1;
    return num * factorial_recursivo(num - 1); //cada llamado se apila en la pila
}

void main()
{
    printf("factorial iterativo: %i\n", factorial_iterativo(4));
    printf("factorial recursivo: %i\n", factorial_recursivo(4));
}