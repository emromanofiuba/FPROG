#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHAR 21
typedef char t_cadena[MAX_CHAR];

void ingreso_palabra(t_cadena palabra)
{
    printf("Ingrese una palabra: ");
    fgets(palabra, MAX_CHAR, stdin);
    palabra[strcspn(palabra, "\n")] = '\0';
}

void almacenar_palabra(t_cadena palabra)
{
    t_cadena *cadena = NULL;
    cadena = malloc(strlen(cadena) * sizeof(char) + 1);
    
    if (cadena == NULL)
        printf("Sos un rata. Comprate mas memoria\n");
    else {
        ingreso_palabra(palabra);
        free(cadena);
    }
}

