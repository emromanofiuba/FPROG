/* PROBLEMA
Escribir una función que reciba un valor n, entero, y devuelva la suma de los
valores entre 0 y n.
Ejemplos:​
suma_n(5) = 15
suma_n(120) = 7260
suma_n(120120) = 7214467260
*/

# include <stdio.h>

int calcular_suma(int numero)
{
    int i, suma;
    suma = 0;

    for (i = 0; i <= numero; i++){
        suma += i;
    }

    return suma;
}

void main()
{
    printf("suma_n(20) = %i\n", calcular_suma(20));
}