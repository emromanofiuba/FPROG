#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef char* t_palabra;
typedef t_palabra *t_vec;

void ingreso_palabras(t_vec *palabras, int *n)
{
    *n = 0;
    char c;
    printf("Desea ingresar una palabra (s o n): ");
    scanf("%c", &c);
    while (c == 's') {
        printf("Palabra: ");
        scanf("%s", palabras[*n]);
        (*n)++;

        printf("Desea ingresar otra palabra (s o n): ");
        scanf("%c", &c);
    }
}


void mostrar_palabras(t_vec *palabras, int n)
{
    int i;
    for (i = 0; i < n; i++) {
        printf("Palabra %i: %s\n", i+1, palabras[i]);
    }
}

void almacenar_palabras(t_vec *palabras, int n)
{
    ingreso_palabras(palabras, &n);
    palabras = malloc(n * sizeof(t_palabra));

    if (palabras == NULL)
        printf("No se pudo reservar la memoria");
    else {
        mostrar_palabras(palabras, n);
        free(palabras);
    }
}

