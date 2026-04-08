/*
Dado un número n, informar los n primeros términos de la sucesión geométrica de
razón 3 (1, 3, 9, 27, etc.).
*/

# include <stdio.h>

void main()
{
    int i, n, num_actual;

    printf("Ingrese un numero n: ");
    scanf("%i", &n);

    while (n <= 0)
    {
        printf("\nDebe ingresar un numero mayor a cero: ");
        scanf("%i", &n);
    }

    printf("\nEstamos listos para generar la sucesion de %i terminos de razon ", n);

    num_actual = 1;

    for (i = 1; i <= n; i++) {
        num_actual *= 3;
        printf("%i\n", num_actual);
    }
}