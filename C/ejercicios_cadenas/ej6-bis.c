#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_CHAR 50
typedef char t_cadena[MAX_CHAR];

void ingreso_cadena(t_cadena cadena)
{
    printf("Ingrese una cadena: ");
    fgets(cadena, MAX_CHAR, stdin);

    cadena[strcspn(cadena, "\n")] = '\0';
}

bool es_valida(t_cadena cadena)
{
    bool valida, hay_diferente;
    int largo, i;

    valida = true;
    hay_diferente = false;
    largo = strlen(cadena);
    i = 0;

    if (largo < 4 || largo > 8)
        valida = false;

    while (cadena[i+1] != '\0' && valida) {
        if (cadena[i] >= '0' && cadena[i] <= '9') {
            if (cadena[i] != cadena[i+1])
                hay_diferente = true;
        }
        else 
            valida = false;
        i++;
    }

    if (!hay_diferente)
        valida = false;
    
    return valida;
}

int main() {
    t_cadena cadena;
    ingreso_cadena(cadena);
    printf("La cadena (%s) es valida: %d\n", cadena, es_valida(cadena));

    return 0;
}
