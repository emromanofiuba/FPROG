# include <stdio.h>
# define MAX 30

void leer_txt(FILE *archivo)
{
    char cadena[MAX];
    fscanf(archivo, "%s", cadena);

    while (feof(archivo) == 0) {
        printf("%s\n", cadena);
        fscanf(archivo, "%s", cadena);
    }
}

void main()
{
    FILE *archivo;

    archivo = fopen("funda.txt", "r");

    if (archivo == NULL)
        printf("No se pudo leer el archivo");
    else {
        leer_txt(archivo);
        fclose(archivo);
    }
}