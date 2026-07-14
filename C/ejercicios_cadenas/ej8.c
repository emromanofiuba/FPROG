# include <stdio.h>
# include <string.h>
# include <stdbool.h>
# define MAX_CHAR 20
typedef char t_cadena[MAX_CHAR];

void ingresar_cadena(t_cadena cadena)
{
    printf("Ingrese una frase o palabra: ");
    fgets(cadena, MAX_CHAR, stdin);
    cadena[strlen(cadena)-1] = '\0';
}


bool es_palindromo(t_cadena cadena)
{
    bool es_capicua;
    int izq, der, largo;

    largo = strlen(cadena);
    es_capicua = true;
    der = largo - 1;
    izq = 0;

    while (izq < der && es_capicua) {
        if (cadena[izq] == ' ' || cadena[izq] == ',')
            izq++;
        else if (cadena[der] == ' ' || cadena[der] == ',')
            der--;
        else{
            if (cadena[izq] != cadena[der])
                es_capicua = false;
            izq++;
            der--;
        }
    }

    return es_capicua;
}

void main() {
    t_cadena cadena;
    bool es_capicua;
    
    ingresar_cadena(cadena);

    es_capicua = es_palindromo(cadena);
    if (es_capicua)
        printf("La cadena es un palindromo\n");
    else
        printf("La cadena no es un palindromo\n");
}