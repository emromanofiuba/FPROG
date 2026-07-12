#include <stdio.h>

typedef struct {
    char nombre[20];
    int anio;
    int division;
    float promedio_gral;
}t_alumno;


t_alumno mejor_promedio_escuela(FILE *alumnos)
{
    t_alumno alumno;
    t_alumno mejor;
    float mejor_promedio;
    mejor_promedio = -1;

    fread(&alumno, sizeof(t_alumno), 1, alumnos);
    while (!feof(alumnos)) {
        if (alumno.promedio_gral > mejor_promedio)
            mejor = alumno;
        fread(&alumno, sizeof(t_alumno), 1, alumnos);
    }
    
    return mejor;
}

void listar_datos_curso(FILE *alumnos)
{
    t_alumno alumno;
    int anio_actual, division_actual;;

    anio_actual = -1;
    division_actual = -1;

    fread(&alumno, sizeof(t_alumno), 1, alumnos);

    while(!feof(alumnos)) {
        if (alumno.anio != anio_actual || alumno.division != division_actual) {
            anio_actual = alumno.anio;
            division_actual = division_actual;
            printf("\n--AÑO %i | DIVISION %i--\n", anio_actual, division_actual);
        }
        printf("Nombre: %s | Promedio: %.2f", alumno.nombre, alumno.promedio_gral);
        
        fread(&alumno, sizeof(t_alumno), 1, alumnos);
    }
}

void cargar_datos_cursos(FILE *alumnos, FILE *cursos)
{
    t_alumno alumno;
    int anio_actual, division_actual, cantidad_alumnos;

    anio_actual = -1;
    division_actual = -1;
    cantidad_alumnos = 0;

    fread(&alumno, sizeof(t_alumno), 1, alumnos);

    while(!feof(alumnos)) {
        if (alumno.anio != anio_actual || alumno.division != division_actual) {
            if (cantidad_alumnos > 0) {
                fwrite(&anio_actual, sizeof(int), 1, cursos);
                fwrite(&division_actual, sizeof(int), 1, cursos);
                fwrite(&cantidad_alumnos, sizeof(int), 1, cursos);
            }

            anio_actual = alumno.anio; //CAMBIO DE AÑO
            division_actual = alumno.division; //CAMBIO DE DIVISION
            cantidad_alumnos = 0;
        }
        cantidad_alumnos++;
        
        fread(&alumno, sizeof(t_alumno), 1, alumnos);
    }

    if (cantidad_alumnos > 0){ //ESCRIBO EL ULTIMO CURSO QUE EL FEOF CANCELA
        fwrite(&anio_actual, sizeof(int), 1, cursos);
        fwrite(&division_actual, sizeof(int), 1, cursos);
        fwrite(&cantidad_alumnos, sizeof(int), 1, cursos);
    }   
}



