#include <stdio.h>
#include <stdlib.h>
typedef struct {
int padron;
char nombre[30];
char apellido[30];
} t_alumno;

int pedir_n()
{
    int n;
    printf("n: ");
    scanf("%i", &n);
    return n;
}

t_alumno* crear_alumnos(int n)
{
    t_alumno* alumnos = NULL;
    alumnos = malloc(n * sizeof(t_alumno));
    return alumnos;
}

void ingresar_alumnos(t_alumno *alumnos, int n)
{
    int i;
    for (i = 0; i < n; i++) {
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

t_alumno* agrandar_alumnos(t_alumno *alumnos, int n)
{
    t_alumno* nuevos;
    nuevos = realloc(alumnos, (n + 2) * sizeof(t_alumno));
    return nuevos;
}

int main() {
    int n; t_alumno* alumnos; t_alumno* nuevos;
    n = pedir_n();
    alumnos = crear_alumnos(n);

    if (alumnos == NULL)
        printf("No tenes memoria pa\n");
    else {
        ingresar_alumnos(alumnos, n);
        mostrar_alumnos(alumnos, n);

        nuevos = agrandar_alumnos(alumnos, n);
        if (nuevos == NULL)
            printf("No podes reservar mas memoria\n");
        else {
            alumnos = nuevos;
            ingresar_alumnos(alumnos + n, 2);
            mostrar_alumnos(nuevos, n + 2);
        }

        free(alumnos);
    }

}
