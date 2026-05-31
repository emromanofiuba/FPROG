# include <stdio.h>
# include <string.h>

int cantidad_numeros(char *cadena)
{
   int i, j, digitos_numericos;
   digitos_numericos = 0;
   char numeros[] = "0123456789";

   for (i = 0; i < strlen(cadena); i++) {
        j = 0;
        while ((cadena[i] != numeros[j]) && (j < strlen(numeros)))
            j++;
         if (cadena[i] == numeros[j])
                digitos_numericos++;
   }

    return digitos_numericos;
}

void main()
{
    char cadena[] = "14Hola";

    printf("La cantidad de digitos numericos que tiene la cadena %s es %i\n", cadena, cantidad_numeros(cadena));
}