# include <stdio.h>
# include <stdbool.h>

void copiar_sin_espacios_superfluos(FILE *oracion_espacios, FILE *oracion_sin)
{
    char caracter;
    bool anterior_fue_espacio = true;
    
    fscanf(oracion_espacios, "%c", &caracter);
    while(feof(oracion_espacios) == 0) {
        if (caracter != ' ' || !anterior_fue_espacio)
            fprintf(oracion_sin, "%c", &caracter);
        
        anterior_fue_espacio = (caracter == ' ');
        fscanf(oracion_espacios, "%c", &caracter);
    }
}

int main(void) {
    FILE *oracion_espacios, *oracion_sin;

    oracion_espacios = fopen("oracion_espacios.txt", "rt");
    oracion_sin = fopen("oracion_sin.txt", "wt");

    if (oracion_espacios == NULL || oracion_sin == NULL)
        printf("No se pudieron abrir los archivos");
    else 
        copiar_sin_espacios_superfluos(oracion_espacios, oracion_sin);

    if (oracion_espacios != NULL)
        fclose(oracion_espacios);
    if (oracion_sin != NULL)
        fclose(oracion_sin);
}