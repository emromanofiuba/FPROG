# include <stdio.h>
# include <string.h>
# include <stdbool.h>
# define MAX_CHAR 20
typedef char t_cadena[MAX_CHAR];

void ingresar_cadena(t_cadena cadena, int *ml)
{
    *ml = 0;

    printf("Ingrese una frase o palabra: ");
    fgets(cadena, MAX_CHAR, stdin);
    cadena[strlen(cadena)-1] = '\0';

    *ml = strlen(cadena);
}

void borrar_blancos_comas(t_cadena cadena, int ml, t_cadena cadena_filtrada, int *max)
{
    int posicion_valida = 0;
    int i;

    for (i=0; i < ml; i++)
        if (cadena[i] != ' ' && cadena[i] != ',') {
            cadena_filtrada[posicion_valida] = cadena[i];
            posicion_valida++;
        }
    cadena_filtrada[posicion_valida] = '\0';
    *max = posicion_valida;

}

bool es_palindromo(t_cadena cadena, int max, t_cadena cadena_inv)
{
    bool es_capicua = false;
    int i, j = 0;
    
    for (i = max - 1; i >= 0; i--) {
            cadena_inv[j] = cadena[i];
            j++;
    }

    cadena_inv[j] = '\0';

    if (strcmp(cadena_inv, cadena) == 0)
        es_capicua = true;
    
    return es_capicua;
}

void main() {
    t_cadena cadena, cadena_filtrada, cadena_inv;
    int ml, max;
    bool es_capicua;
    
    ingresar_cadena(cadena, &ml);
    borrar_blancos_comas(cadena, ml, cadena_filtrada, &max);

    es_capicua = es_palindromo(cadena_filtrada, max, cadena_inv);
    if (es_capicua)
        printf("La cadena (%s) es un palindromo\n", cadena);
    else
        printf("La cadena (%s) no es un palindromo\n", cadena);
}