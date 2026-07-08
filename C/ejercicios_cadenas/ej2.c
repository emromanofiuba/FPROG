# include <stdio.h>
# include <string.h>
#include <stdbool.h>

int cantidad_no_alfa(char *cadena)
{
    int i, cantidad;
    bool alfa;
    cantidad = 0;

   for (i = 0; i < strlen(cadena); i++) {
        alfa = ((cadena[i] >= 'a' && cadena[i] <= 'z') || (cadena[i] >= 'A' && cadena[i] <= 'Z'));
        if (!alfa)
            cantidad++;
   }

    return cantidad;
}

void main()
{
    char cadena[] = "14_Hola";

    printf("La cantidad de caracteres no alfa que tiene la cadena %s es %i\n", cadena, cantidad_no_alfa(cadena));
}