#include <stdio.h>
#include <string.h>
#define MAX_CHAR 30
typedef char t_cadena[MAX_CHAR];


void borrar_blancos(t_cadena cadena)
{
    int i, destino;
    destino = 0;
    for (i = 0; i < strlen(cadena); i++) {
        if (cadena[i] != ' ') {
            cadena[destino] = cadena[i];
            destino++;
        }
    }
}

void invertir_cadena(t_cadena cadena)
{
    int i, largo;
    char aux;
    largo = strlen(cadena);
    for (i = 0; i < largo / 2; i++) {
            aux = cadena[i];
            cadena[i] = cadena[largo-1-i];
            cadena[largo-1-i] = aux;
        }
    cadena[largo] = '\0';
}


int main() {
   
    t_cadena cadena = "Hola, me llamo Ana";
    borrar_blancos(cadena);
    invertir_cadena(cadena);
    printf("%s\n", cadena);

    return 0;
}