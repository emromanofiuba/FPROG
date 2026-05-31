# include <stdio.h>
# include <string.h>

int cantidad_no_alfa(char *cadena)
{
   int i, j, no_alfa;
    no_alfa = 0;
   char letras[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

   for (i = 0; i < strlen(cadena); i++) {
        j = 0;
        while ((cadena[i] != letras[j]) && (j < strlen(letras)))
            j++;
         if (letras[j] == '\0')
                no_alfa++;
   }

    return no_alfa;
}

void main()
{
    char cadena[] = "14_Hola";

    printf("La cantidad de caracteres no alfa que tiene la cadena %s es %i\n", cadena, cantidad_no_alfa(cadena));
}