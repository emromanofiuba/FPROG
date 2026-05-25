# include <stdio.h>
# include <stdbool.h>
# define MAX 20
typedef int t_vec[MAX];

void burbujeo_optimizado (t_vec vector, int ml)
{
    int i, j, aux;
    bool hubo_intercambio;
    i = 1;
    hubo_intercambio = true;

    while (i < ml && hubo_intercambio) {
        hubo_intercambio = false;

        for (j = 0; j < ml -i; j++)
            if (vector[j+1] < vector[j]) {
                aux = vector[i];
                vector[j] = vector[j+1];
                vector[j+1] = aux;
                hubo_intercambio = true;
            }
        i++;
    }
}