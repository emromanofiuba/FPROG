# include <stdio.h>

void main()
{
    char cadena[] = "Hola";

    for (int i = 0; i < sizeof(cadena); i++){
        printf("posicion %i: %c \n", i, cadena[i]);
    }
}