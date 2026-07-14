#include <stdio.h>
#include <stdlib.h>

int main() {
    int *enteros, *temporal;
    int n;
    n = pedir_n();

    enteros = NULL;
    enteros = malloc(n * sizeof(int));

    if (enteros == NULL)
        printf("No se pudo reservar la memoria\n");
    else {
        temporal = realloc(enteros, 2 * n * sizeof(int));
        if (temporal == NULL)
            printf("No se pudo agrandar la reserva\n");
        else {
            enteros = temporal;
            printf("Memoria expandida exitosamente\n");
        }

        free(enteros);
    }
}