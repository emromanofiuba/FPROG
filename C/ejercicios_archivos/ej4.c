# include <stdio.h>


void mergear_enteros(FILE *enteros_1, FILE *enteros_2, FILE *enteros_ordenados)
{
    int numero_1, numero_2;
    fread(&numero_1, sizeof(int), 1, enteros_1);
    fread(&numero_2, sizeof(int), 1, enteros_2);

    while (!feof(enteros_1) && !feof(enteros_2)) {
        if (numero_1 < numero_2) {
            fwrite(&numero_1, sizeof(int), 1, enteros_ordenados);
            fread(&numero_1, sizeof(int), 1, enteros_1);
        }
        else {
            fwrite(&numero_2, sizeof(int), 1, enteros_ordenados);
            fread(&numero_2, sizeof(int), 1, enteros_2);
        }
    }

    while (!feof(enteros_1)) {
        fwrite(&numero_1, sizeof(int), 1, enteros_ordenados);
        fread(&numero_1, sizeof(int), 1, enteros_1);
    }

    while (!feof(enteros_2)) {
        fwrite(&numero_2, sizeof(int), 1, enteros_ordenados);
        fread(&numero_2, sizeof(int), 1, enteros_2);
    }
}

void main() {
    FILE *enteros_1, *enteros_2, *enteros_ordenados;

    enteros_1 = fopen("enteros_1.dat", "rb");
    enteros_2 = fopen("enteros_2.dat", "rb");
    enteros_ordenados = fopen("enteros_ordenados.dat", "wb");

    if (enteros_1 == NULL)
        printf("No se pudo abrir enteros_1");
    else if (enteros_2 == NULL)
        printf("No se pudo abrir enteros_2");
    else if (enteros_ordenados == NULL)
        printf("No se pudo abrir enteros_ordenados");
    else {
        mergear_enteros(enteros_1, enteros_2, enteros_ordenados);
        fclose(enteros_1);
        fclose(enteros_2);
        fclose(enteros_ordenados);
    }
}