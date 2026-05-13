/*
Probar el programa con los siguiente casos:
v1 = [2,8,1,-5,4]​​​-> Negativos: 1Positivos: 4
v2 = [-2,-15,-3]​ ​​​-> Negativos: 3Positivos: 0
v3 = [0,0,10,12,23,55,1]​​-> Negativos: 0Positivos: 5
*/

# include <stdio.h>

void cantidades(int vector[], int cantidad_numeros, int *cantidad_positivos, int *cantidad_negativos)
{
    *cantidad_negativos = *cantidad_positivos = 0;

    for (int i = 0; i < cantidad_numeros; i++) {
        if (vector[i] > 0)
            (*cantidad_positivos)++;
        else if (vector[i] < 0)
            (*cantidad_negativos)++;
    }
}



int main(void)
{
    int vector[] = {0,0,10,12,23,55,1};
    int cantidad_numeros= sizeof(vector) / sizeof(vector[0]);
    int cantidad_positivos;
    int cantidad_negativos;

    cantidades(vector, cantidad_numeros, &cantidad_positivos, &cantidad_negativos);

    printf("\nNegativos: %i\n", cantidad_negativos);
    printf("\nPositivos: %i\n", cantidad_positivos);
}