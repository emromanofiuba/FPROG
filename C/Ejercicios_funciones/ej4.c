/* PROBLEMA
Escribir una función que dados 2 números, calcule el porcentaje que el
primero representa respecto del segundo.
*/

# include <stdio.h>

float calcular_porcentaje(int num_1, int num_2)
{
    return ((float)num_1 / num_2) * 100;
}

void ingreso_datos(int *num_1, int *num_2)
{
    printf("Num 1: ");
    scanf("%i", num_1);

    printf("Num 2: ");
    scanf("%i", num_2);
}


int main(void)
{
    int num_1, num_2;

    ingreso_datos(&num_1, &num_2);

    if (num_2 == 0)
        printf("Porcentaje no realizable, el numero 2 es 0");
    else
        printf("El porcentaje que representa %i sobre %i es %.3f\n", num_1, num_2, calcular_porcentaje(num_1, num_2));

    return 0;
}