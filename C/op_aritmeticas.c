#include <stdio.h>

void main()
{
    int valor1, valor2;         //Ingreso de valores
    printf("ingrese el Valor 1: ");
    scanf("%i", &valor1);
    printf("ingrese el Valor 2: " );
    scanf("%i", &valor2);

    int suma = valor1 + valor2;     //Suma de valores
    printf("la suma es %i\n", suma);

    int resta = valor1 - valor2;    //Resta de valores
    printf("la resta es %i\n", resta);

    int multiplicacion = valor1 * valor2;    //Resta de valores
    printf("la multiplicacion es %i\n", multiplicacion);

    return;
}
