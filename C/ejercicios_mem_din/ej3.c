#include <stdio.h>
#include <stdlib.h>

int pedir_n()
{
    int n;
    printf("Ingrese n: ");
    scanf("%i", &n);

    while (n < 1) {
        printf("Debe ingresar un valor de n mayor a 1: ");
        scanf("%i", &n);
    }
    return n;
}

void ingreso_enteros(int *enteros, int n)
{
    int i;
    for (i = 0; i < n; i++) {
        printf("Entero %i: ", i+1);
        scanf("%i", (enteros + i));
    }
}

void ingreso_enteros_extra(int *enteros, int n)
{
    int i;
    for (i = n/2; i < n; i++) {
        printf("Entero %i: ", i+1);
        scanf("%i", (enteros + i));
    }
}

void mostrar_enteros(int *enteros, int n)
{
    int i;
    printf("\n--ENTEROS ALMACENADOS--\n");
    for (i = 0; i < n; i++) {
        printf(" %i", *(enteros + i));
    }
    printf("\n");
}

int main()
{
    int *enteros = NULL;
    int *temporal = NULL;
    int n;

    n = pedir_n();
    enteros = malloc(n * sizeof(int));

    if (enteros == NULL)
        printf("No se pudo reservar la memoria para los %i enteros\n", n);
    else {
        ingreso_enteros(enteros, n);
        mostrar_enteros(enteros, n);

        temporal = realloc(enteros, 2 * n * sizeof(int));

        if (temporal == NULL)
            printf("No se pudo reasignar la memoria para los nuevos enteros");
        else {
            enteros = temporal;
            n = 2 * n;
            printf("\nNUEVOS ENTEROS ENTRANDO EN MEMORIA...\n");
            ingreso_enteros_extra(enteros, n);
            mostrar_enteros(enteros, n);
        }
        free(enteros);
    }

    return 0;
}