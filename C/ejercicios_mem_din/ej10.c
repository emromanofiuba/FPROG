#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_CHAR 31
typedef char* t_palabra;
typedef t_palabra *t_vec;

t_vec cargar_palabras(int *n)
{
    t_vec palabras;
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
            palabras = aux;
            palabras[*n] = malloc(strlen(palabra) * sizeof(char) + 1);
            if (palabras[*n] == NULL) {
                printf("No se pudo reservar el espacio para la palabra\n");
                seguir = false;
            }
            else {
                strcpy(palabras[*n], palabra);
                (*n)++;
                printf("Desea ingresar otra palabra (s o n): ");
                scanf(" %c", &c);
            }
        }
    }
    return palabras;
}

void mostrar_palabras(t_vec palabras, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%s\n", palabras[i]);
}

void liberar_memoria(t_vec palabras, int n)
{
    int i;
    for (i = 0; i < n; i++) {
        free(palabras[i]);
    }
    free(palabras);
}

int main() {
    t_vec palabras;
    int n;
    palabras = cargar_palabras(&n);
    if (palabras == NULL)
        printf("No se pudo cargar ninguna palabra\n");
    else {
        mostrar_palabras(palabras, n);
        liberar_memoria(palabras, n);
    }

    return 0;
}

