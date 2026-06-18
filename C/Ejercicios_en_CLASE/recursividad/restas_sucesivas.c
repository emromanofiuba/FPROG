/*
implementar la division como restas sucesivas de manera recursiva
*/
# include <stdio.h>

int division_restas_sucesivas(int dividendo, int divisor)
{
    if (dividendo < divisor)
        return 0;
     return 1 + division_restas_sucesivas(dividendo-divisor, divisor);
}

void main()
{
    printf("El resultado de 20 / 5 es: %i\n", division_restas_sucesivas(20, 5));
}