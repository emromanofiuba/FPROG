# include <stdio.h>
# include <stdbool.h>
# define MAX 20
typedef int t_vec[MAX];

void seleccion(t_vec vector, int ml)
{
    int i, j, aux, posicion_min;

    for (i = 0; i < ml -1; i++) {
        posicion_min = i;
        
        for (j = i+1; j < ml; j++) {
            if (vector[j] < vector[i]) 
                posicion_min = j;

        aux = vector[posicion_min];
        vector[posicion_min] = vector[i];
        vector[i] = aux;
        }
    }

}