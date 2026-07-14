#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_CHAR 31
typedef char* t_palabra;
typedef t_palabra *t_vec;

void cargar_palabras(t_vec palabras, int *n)
{
    bool seguir;
    char c;
    char palabra[MAX_CHAR];
    t_vec aux;

    printf("Desea ingresar una palabra (s o n): ");
    scanf(" %c", &c);
    seguir = true;
    *n = 0;
    palabras = NULL;

    while (seguir && c == 's') {
        printf("Palabra: ");
        scanf("%s", palabra);

        aux = realloc(palabras, (*n + 1) * sizeof(t_palabra));
        if (aux == NULL) {
            printf("No se pudo expandir la lista de palabras\n");
            seguir = false;
        }
        else {
            palabras[*n] = malloc(strlen(palabras[*n]) * sizeof(char) + 1);
            if (palabras[*n] == NULL) {
                printf("No se pudo reservar el espacio para la palabra\n");
            }
            else {
                strcpy(palabras[*n], palabra);
                (*n)++;
            }
            printf("Desea ingresar otra palabra (s o n): ");
            scanf(" %c", &c);
        }
    }
}

void liberar_memoria(t_vec palabras, int n)
{
    int i;
    for (i = 0; i < n; i++) {
        free(palabras[i]);
    }
    free(palabras);
}

