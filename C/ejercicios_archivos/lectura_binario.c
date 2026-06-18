# include <stdio.h>

typedef struct{
	int padron;
	char ape_nom[30];
	float nota;
}t_regAlumno;

void leer_archivo (FILE *ar_alumnos)
{
    t_regAlumno r_alumno;

    printf("\nPadron \t\tNombre Completo \tNota");
    fread(&r_alumno, sizeof(r_alumno), 1, ar_alumnos);

    while (!feof(ar_alumnos)) {
       printf("\n %i \t\t%-30s \t%.2f", r_alumno.padron, r_alumno.ape_nom, r_alumno.nota);
       fread(&r_alumno, sizeof(r_alumno), 1, ar_alumnos);
    }
}

void main()
{
    FILE *archivo;
    archivo = fopen("alumnos.dat", "rb");

    if (archivo == NULL)
        printf("El archivo no pudo ser creado");
    else {
        leer_archivo(archivo);
        fclose(archivo);
    }
}