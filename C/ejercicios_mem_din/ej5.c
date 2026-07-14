#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int padron;
    char nombre[30];
    char apellido[30];
}t_alumno;

int pedir_n()
{
    int n;
    printf("N: ");
    scanf("%i", &n);
    return n;
}

void cargar_alumnos(t_alumno *alumnos, int n)
{
    int i;
    for (i = 0; i < n; i++) {
        printf("\n--ALUMNO %i--\n", i+1);

        printf("Padron: ");
        scanf("%i", &(alumnos+i)->padron);
        printf("Nombre: ");
        scanf("%s", (alumnos+i)->nombre);
        printf("Apellido: ");
        scanf("%s", (alumnos+i)->apellido);
    }
}

void mostrar_alumnos(t_alumno *alumnos, int n)
{
    int i;
    for (i = 0; i < n; i++) {
        printf("\n--ALUMNO %i--\n", i+1);
        printf("Padron: %i | Nombre: %s | Apellido: %s\n", (alumnos+i)->padron, (alumnos+i)->nombre, (alumnos+i)->apellido);
    }
}


int main() {
    int n;
    n = pedir_n();
    t_alumno *alumnos = NULL;
    alumnos = malloc(n * sizeof(t_alumno));

    if (alumnos == NULL)
        printf("Comprate mas memoria\n");
    else {
        cargar_alumnos(alumnos, n);
        mostrar_alumnos(alumnos, n);

        free(alumnos);
    }
}