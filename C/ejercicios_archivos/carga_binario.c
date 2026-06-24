/*
para una validacion de datos, por ejemplo, que el nombre este 
compuesto solo por letras y que la nota este entre 2 valores,
seria conveniente declarar otra funcion e invocarla en la carga
de datos a medida que se van pidiendo dichos campos.
*/
# include <stdio.h>

typedef struct{
	int padron;
	char ape_nom[30];
	float nota;
}t_alumno;


void cargar_archivo (FILE *ar_alumnos)
{
    t_alumno r_alumnos;

    printf("Padron: ");
    scanf("%i", &r_alumnos.padron);

    while (r_alumnos.padron != 0) {
        while (getchar() != '\n'); 

        printf("Nombre completo: ");
        fgets(r_alumnos.ape_nom, 30, stdin);

        printf("Nota: ");
        scanf("%f", &r_alumnos.nota);

        fwrite(&r_alumnos, sizeof(r_alumnos), 1, ar_alumnos);

        printf("Padron: ");
        scanf("%i", &r_alumnos.padron);
    }
}

void main()
{
    FILE *archivo;
    archivo = fopen("alumnos.dat", "wb");

    if (archivo == NULL)
        printf("El archivo no pudo ser creado");
    else {
        cargar_archivo(archivo);
        fclose(archivo);
    }
}