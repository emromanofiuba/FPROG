#include <stdio.h>
#include <string.h>
#define MAX_CHAR 50
typedef char t_cadena[MAX_CHAR];

void invertir_cadena(t_cadena cadena, t_cadena cadena_inv)
{
    int i, nueva_pos, largo;
    largo = strlen(cadena);
    nueva_pos = 0;

    for (i = largo - 1; i >= 0; i--) {
        if (cadena[i] != ' ') {
            cadena_inv[nueva_pos] = cadena[i];
            nueva_pos++;
        }
    }
    cadena_inv[nueva_pos] = '\0';
}


int main() {
   
    t_cadena cadena, cadena_inv;

    printf("Cadena: ");
    fgets(cadena, MAX_CHAR, stdin);
    cadena[strcspn(cadena, "\n")] = '\0';

    invertir_cadena(cadena, cadena_inv);
    printf("%s\n", cadena_inv);

    return 0;
}