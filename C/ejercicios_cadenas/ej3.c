# include <stdio.h>
# include <string.h>
# define BYTES 50
typedef char t_cadena[BYTES];

int cantidad_palabras(t_cadena cadena)
{
    int i, contador_palabras;
    contador_palabras = 0;

    for (i = 1; i < strlen(cadena); i++)
        if ((cadena[i-1] != ' ') && (cadena[i] == ' '))
            contador_palabras++;

    if (cadena[i-1] != ' ')
        contador_palabras++;

    return contador_palabras;
}

void main()
{
    t_cadena cadena = " Hoy es  30 de Junio de  2021 ";

    printf("La cantidad de palabras de (%s) es %i\n", cadena, cantidad_palabras(cadena));
}