#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHAR 21
typedef char t_cadena[MAX_CHAR];

void carga_palabra(t_cadena cadena_aux)
{
    printf("Ingrese una palabra: ");
    fgets(cadena_aux, MAX_CHAR, stdin);
    cadena_aux[strcspn(cadena_aux, "\n")] = '\0';
}

char* reservar_memoria(t_cadena cadena_aux)
{
    char* cadena;
    cadena = malloc(strlen(cadena_aux) * sizeof(char)+ 1);

    return cadena;
}

int main() {
    t_cadena cadena_aux;
    char* cadena;

    carga_palabra(cadena_aux);
    cadena = reservar_memoria(cadena_aux);

    if (cadena == NULL)
        printf("No se pudo almacenar la palabra ingresada. Memoria no reservada\n");
    else {
        strcpy(cadena, cadena_aux);
        printf("Memoria reservada con exito. Palabra almacenada\n");
        free(cadena);
    }

    return 0;
}

