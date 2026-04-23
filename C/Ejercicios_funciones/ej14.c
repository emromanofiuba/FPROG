/* PROBLEMA
Un número entero positivo se dice perfecto si es igual a la suma de todos
sus divisores excepto él mismo. Ejemplo: los números 6, 28 y 496 son perfectos.
(6 = 1+2+3)
(28 = 1+2+4+7+14)
(496 = 1+2+4+8+16+31+62+124 +248)
*/

# include <stdio.h>
# include <stdbool.h>

bool calcular_perfecto(int num)
{
    int i, suma_divisores;
    bool es_perfecto;

    suma_divisores = 0;
    es_perfecto = false;

    for (i = 1; i < num; i++){
        if (num % i == 0)
            suma_divisores += i;
    }
    if (suma_divisores == num)
        es_perfecto = true;

    return es_perfecto;
}

void main()
{
    int num, suma_divisores;

    printf("Ingrese un numero para ver si es perfecto: ");
    scanf("%i", &num);

    printf("¿El numero %i es perfecto? %d\n", num, calcular_perfecto(num));

}
