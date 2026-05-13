# include <stdio.h>
# define MF 8

int main(void)
{
    char cadena[MF] = "Hola";

    printf("%s \n", cadena);

    //Imprimo todas las componentes del vector cadena (hasta MF) 
    for (int i = 0; i < MF; i++){
        printf("caracter en la posicion %i: %c \n", i, cadena[i]);
    }

    //Imprimo la cadena hasta el ML (donde esta el '\0')
    int i = 0;
    while (cadena[i] != '\0'){
        printf("posicion %i: %c \n", i, cadena[i]);
        i++;
    }

    printf("Capacidad de la cadena: %i bytes\n", sizeof(cadena));
}