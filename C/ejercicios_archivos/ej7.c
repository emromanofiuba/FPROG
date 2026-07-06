# include <stdio.h>
# include <stdbool.h>

void copiar_sin_espacios_superfluos(FILE *oracion_espacios, FILE *oracion_sin)
{
    char caracter;
    bool anterior_fue_espacio = true;
    
    fread(caracter, sizeof(char), 1, oracion_espacios);
    while(!feof(oracion_espacios)) {
        if (caracter != ' ' || !anterior_fue_espacio)
            fwrite(caracter, sizeof(char), 1, oracion_sin);
        
        anterior_fue_espacio = (caracter == ' ');
        fread(caracter, sizeof(char), 1, oracion_espacios);
    }
}

int main(void) {
    FILE *oracion_espacios, *oracion_sin;

    oracion_espacios = fopen("oracion_espacios.txt", "r");
    oracion_sin = fopen("oracion_sin.txt", "w");

    if (oracion_espacios == NULL || oracion_sin == NULL)
        printf("No se pudieron abrir los archivos");
    else 
        copiar_sin_espacios_superfluos(oracion_espacios, oracion_sin);

    if (oracion_espacios != NULL)
        fclose(oracion_espacios);
    if (oracion_sin != NULL)
        fclose(oracion_sin);
}