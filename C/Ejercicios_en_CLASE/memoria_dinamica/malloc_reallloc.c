#include <stdio.h>
#include <stdlib.h>

void ejemploRealloc() {
    int *elementos = malloc(2 * sizeof(*elementos));
    
    if (elementos == NULL) {
        printf("Error: No hay memoria suficiente.\n");
    }

    elementos[0] = 10;
    elementos[1] = 20;
    printf("Espacio inicial (2 elementos): %d y %d\n", elementos[0], elementos[1]);

    int *temporal = realloc(elementos, 3 * sizeof(*temporal));

    if (temporal == NULL) {
        printf("Error: No se pudo agrandar la memoria. La original sigue intacta.\n");
        free(elementos); 
    }

    elementos = temporal;

    elementos[2] = 30;

    printf("Nuevo espacio (3 elementos): %d, %d y %d\n", elementos[0], elementos[1], elementos[2]);

    free(elementos);
}

int main() {
    ejemploRealloc();
    return 0;
}