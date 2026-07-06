#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_PALABRA 31

bool es_vocal(char caracter)
{
    return caracter == 'a' || caracter == 'e' || caracter == 'i'
        || caracter == 'o' || caracter == 'u'
        || caracter == 'A' || caracter == 'E' || caracter == 'I'
        || caracter == 'O' || caracter == 'U';
}

bool es_letra(char caracter)
{
    return (caracter >= 'a' && caracter <= 'z')
        || (caracter >= 'A' && caracter <= 'Z');
}

void analizar_palabra(char palabra[], int *longitud, int *silabas)
{
    int i;
    bool venia_vocal;
    *longitud = 0;
    *silabas = 0;
    venia_vocal = false;

    i = 0;
    while (palabra[i] != '\0') {
        if (es_letra(palabra[i])) {
            (*longitud)++;
        }
        if (es_vocal(palabra[i]) && !venia_vocal) {
            (*silabas)++;
        }
        venia_vocal = es_vocal(palabra[i]);
        i++;
    }
}

float calcular_promedio(int suma_longitud, int cantidad_palabras)
{
    return (float)suma_longitud / cantidad_palabras;
}

void procesar_texto(FILE *archivo, int *cantidad_palabras, int *suma_longitud, int *cantidad_monosilabos)
{
    char palabra[MAX_PALABRA];
    int longitud, silabas;
    *cantidad_palabras = 0;
    *suma_longitud = 0;
    *cantidad_monosilabos = 0;

    fscanf(archivo, "%30s", palabra);
    while (feof(archivo) == 0) {
        analizar_palabra(palabra, &longitud, &silabas);
        *suma_longitud += longitud;
        (*cantidad_palabras)++;
        if (silabas == 1) {
            (*cantidad_monosilabos)++;
        }
        fscanf(archivo, "%30s", palabra);
    }
}

int main(void)
{
    FILE *archivo;
    int cantidad_palabras, suma_longitud, cantidad_monosilabos;
    float promedio_longitud;

    archivo = fopen("oraciones.txt", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo\n");
    }
    else {
        procesar_texto(archivo, &cantidad_palabras, &suma_longitud, &cantidad_monosilabos);
        fclose(archivo);
        if (cantidad_palabras == 0) {
            printf("El archivo no contiene palabras.\n");
        }
        else {
            promedio_longitud = calcular_promedio(suma_longitud, cantidad_palabras);
            printf("Cantidad de palabras: %d\n", cantidad_palabras);
            printf("Longitud promedio: %.2f\n", promedio_longitud);
            printf("Cantidad de monosilabos: %d\n", cantidad_monosilabos);
        }
    }
    return 0;
}