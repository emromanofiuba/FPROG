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
    int n;

    n = pedir_n();
    enteros = malloc(n * sizeof(int));

    if (enteros == NULL)
        printf("No se pudo reservar la memoria para los %i enteros", n);
    else {
        ingreso_enteros(enteros, n);
        mostrar_enteros(enteros, n);

        free(enteros);
    }

    return 0;
}