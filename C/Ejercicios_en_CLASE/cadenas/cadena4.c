/*
Escribir un programa en C, que:
- declare una cadena para almacenar como máximo 40 caracteres y como valor inicial le asigne tu nombre y apellido
- recorra la cadena e imprima sólo las consonantes, una debajo de la otra
- indique cuantas consonantes hay en tu nombre y apellido
*/

#include <stdio.h>
# define MF 40

void main()
{
    char nombre_completo[MF] = "Emiliano Romano";
    char vocales[] = "aeiou";
    int contador_consonantes = 0;

    for (int i = 0; i < sizeof(nombre_completo); i++){
        for (int j = 0; j < sizeof(vocales); j++){
            if(nombre_completo[i] != vocales[j]){
                printf("%c \n", nombre_completo[i]);
                contador_consonantes++;
            }
        }
    }
    printf("Contador consonantes: %i\n", contador_consonantes);   
}