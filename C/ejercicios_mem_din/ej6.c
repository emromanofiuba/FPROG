#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int padron;
    char nombre[30];
    char apellido[30];
}t_alumno;

t_alumno* crear_alumno()
{
    t_alumno* alumno;
    alumno = NULL;
    alumno = malloc(sizeof(t_alumno));

    return alumno;
}

int main() {
    t_alumno *alumno;
    alumno = crear_alumno();
    if (alumno == NULL)
        printf("No se pudo reservar la memoria\n");
    else {
        printf("Reservaste memoria exitosamente\n");
        free(alumno);
    }
    
    return 0;
}