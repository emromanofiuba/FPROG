#include <stdio.h>

int suma_pos_pares(int vec[], int ml)
{
    if (ml <= 0)
        return 0;
    if ((ml-1) % 2 == 0)
        return vec[ml-1] + suma_pos_pares(vec, ml - 2);

    return suma_pos_pares(vec, ml - 1);
}

int main() {
    int vec[] = {1, 2, 3, 4, 5};
    int ml = 5;
    if (ml == 0)
        printf("No se pueden sumar los elementos de un vector vacio\n");
    else 
        printf("La suma es: %i\n", suma_pos_pares(vec, 5));
}