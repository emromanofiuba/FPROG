# include <stdio.h>
# include <stdlib.h>

typedef struct 
{
    int padron;
    char nombre[30];
    char apellido[30];
}t_alumno;

void cargar_alumnos(t_alumno *ptr) {
        printf("Padron: ");
        scanf("%i", &ptr->padron);

        printf("Nombre: ");
        scanf("%s", ptr->nombre);

        printf("Apellido: ");
        scanf("%s", ptr->apellido);
}

void validar_asignacion_de_memoria(t_alumno *ptr)
{
    ptr = malloc(sizeof(t_alumno));

    if (ptr == NULL)
        printf("No se pudo reservar el espacio en memoria");
    else {
        cargar_alumnos(ptr);
    }
}

void mostrar_datos_alumno(t_alumno *ptr)
{
    if (ptr != NULL)
        printf("Padron: %i | Nombre: %s | Apellido: %s", ptr->padron, ptr->nombre, ptr->apellido);
    else 
        printf("No hay datos disponibles para mostrar");
}

int main (void)
{
    t_alumno *ptr;
    validar_asignacion_de_memoria(ptr);
    mostrar_datos_alumno(ptr);

    free(ptr);

    return 0;
}

