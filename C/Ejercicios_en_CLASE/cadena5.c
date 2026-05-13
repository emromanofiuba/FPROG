/* PROBLEMA
Escribir un programa modular que solicite el ingreso de dos palabras y 
luego muestre las mismas según la longitud de cada una de ellas, mostrando primero la de menor longitud.
A igualdad de longitud, mostrar primero la menor de las dos, en términos de orden alfabético.
Las palabras tienen una longitud máxima de 15 caracteres. 
*/

# include <stdio.h>
# include <string.h>
# define MF 15


void ingreso_palabras(char palabra_1[], char palabra_2[])
{
    printf("Ingrese la primera palabra: ");
    fgets(palabra_1, MF, stdin);

    fflush(stdin);

    printf("Ingrese la segunda palabra: ");
    fgets(palabra_2, MF, stdin);

    fflush(stdin);
}

void longitud_palabras(char palabra_1[], char palabra_2[])
{
    if (strlen(palabra_1) < strlen(palabra_2))
        printf("%s \n", palabra_1);

    else if (strlen(palabra_2) < strlen(palabra_1))
        printf("%s \n", palabra_2);

    else if (strlen(palabra_1) == strlen(palabra_2))
        if(strcmp(palabra_1, palabra_2) < 0)
            printf("%s \n", palabra_1);
        else
            printf("%s \n", palabra_2);
}


int main(void)
{
    char palabra_1[MF];
    char palabra_2[MF];

    ingreso_palabras(palabra_1, palabra_2);

    longitud_palabras(palabra_1, palabra_2);

    return 0;

}