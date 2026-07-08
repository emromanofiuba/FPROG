# include <stdio.h>
# include <string.h>

int cantidad_numeros(char *cadena)
{
   int i, digitos_numericos;
   digitos_numericos = 0;
  
   for (i = 0; i < strlen(cadena); i++)
        if (cadena[i] >= '0' && cadena[i] <= '9')
            digitos_numericos++;

    return digitos_numericos;
}

void main()
{
    char cadena[] = "143Hola";

    printf("La cantidad de digitos numericos que tiene la cadena %s es %i\n", cadena, cantidad_numeros(cadena));
}