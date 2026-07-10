#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int padron;
    char nombre[30];
    char apellido[30];
}t_alumno;

void ingreso_alumnos(t_alumno *alumnos)
{
    printf("Ingresa padron porfa: ");
    scanf("%d", &alumnos->padron);

    printf("Ingresa el nombre piorfa: ");
    scanf("%s", alumnos->nombre);

    printf("Ingresa el apellido piorfa: ");
    scanf("%s", alumnos->apellido);
}

void mostrar_alumnos(t_alumno *alumnos)
{
    printf("Padron: %d | Nombre: %s | Apellido: %s\n", alumnos->padron, alumnos->nombre, alumnos->apellido);
}

int main() {
    t_alumno *alumnos = NULL;
    alumnos = malloc(sizeof(t_alumno));
    
    if (alumnos == NULL)
        printf("Sos un rata. Comprate mas memoria\n");
    else {
        ingreso_alumnos(alumnos);
        mostrar_alumnos(alumnos);

        free(alumnos);
    }
    return 0;
}
