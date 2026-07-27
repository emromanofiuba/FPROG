#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ingreso_cadena(char* cadena_aux)
{
    printf("Cadena: ");
    scanf("%99[^\n]%*c", cadena_aux);
}

char* almacenar_cadena(char* cadena_aux)
{
    char* cadena;
    cadena = malloc(strlen(cadena_aux) * sizeof(char) + 1);
    return cadena;
}

int main() {
    char* cadena;
    char cadena_aux[100];
    ingreso_cadena(cadena_aux);
    
    cadena = almacenar_cadena(cadena_aux);
    if (cadena == NULL)
        printf("No se pudo almacenar la cadena\n");
    else {
        strcpy(cadena, cadena_aux);
        printf("Cadena ingresada: %s\n", cadena);
        free(cadena);
    }

    return 0;
}
