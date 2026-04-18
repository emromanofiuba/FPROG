/*
Escribir una función que dados a y b ambos de tipo entero devuelva a ^ b de
tipo double para los siguientes casos (no se puede utilizar ninguna biblioteca
de funciones matemáticas). Implementar una solución iterativa.​
​
En las pruebas debe invocar a la función para los siguientes 5 casos:​
i) a > 0 y b > 0
ii) a > 0 y b < 0
iii) a < 0 y b > 0
iv) a < 0 y b < 0
v) a > 0 y b = 0
*/

# include <stdio.h>

double potenciación(int base, int exp)
{
    int i;
    double resultado_potencia = 1;

    if (exp >= 0){
        for (i = 1; i <= exp; i++)
            resultado_potencia *= base;
    }

    else{
        for (i = -1; i >= exp; i--)
            resultado_potencia *= (double)1 / base;
    }

    return resultado_potencia;
}

void main()
{
    printf("3 ^ 1 = %.2lf\n", potenciación(3, 1));
    printf("4 ^ -3 = %.5lf\n", potenciación(4, -3));
    printf("-4 ^ -3 = %.5lf\n", potenciación(-4, -3));
    printf("-4 ^ 3 = %.2lf\n", potenciación(-4, 3));
    printf("4 ^ 0 = %.2lf\n", potenciación(4, 0));
}