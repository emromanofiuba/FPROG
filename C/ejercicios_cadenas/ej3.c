#include <stdio.h>
#include <string.h>
#include <stdbool.h>
# define BYTES 50

typedef char t_cadena[BYTES];

int cantidad_palabras(t_cadena cadena)
{
    int i, contador_palabras;
    bool anterior_fue_blanco;
    anterior_fue_blanco = true;
    contador_palabras = 0;

    for (i = 1; i < strlen(cadena); i++) {
        if (cadena[i] == ' ' && !anterior_fue_blanco)
            contador_palabras++;
        anterior_fue_blanco = (cadena[i] == ' ');
    }

    if (cadena[i-1] != ' ')
        contador_palabras++;

    return contador_palabras;
}

void main()
{
    t_cadena cadena = " El precio   es  $2000.-   ";

    printf("La cantidad de palabras de (%s) es %i\n", cadena, cantidad_palabras(cadena));
}