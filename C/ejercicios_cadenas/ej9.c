#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 31
typedef char t_cadena[MAX];

void ingreso_palabra(t_cadena sustantivo)
{
    printf("Ingrese un sustantivo (en singular): ");
    scanf("%s", sustantivo);
}

void plural(t_cadena sustantivo)
{
    int largo;
    char ultima_letra;
    bool es_ult_voc_no_acentuada;
    largo = strlen(sustantivo);
    ultima_letra = sustantivo[largo-1];
    es_ult_voc_no_acentuada = (ultima_letra == 'a' || ultima_letra == 'e' || ultima_letra == 'i' || ultima_letra == 'o' || ultima_letra == 'u');
    
    if (es_ult_voc_no_acentuada)
        sustantivo[largo] = 's';
    else if (ultima_letra == 'é')
        sustantivo[largo] = 's';
    else if (ultima_letra == 'z') {
        ultima_letra = 'c';
        strcat(sustantivo, "es");
    }
    else if (!es_ult_voc_no_acentuada && (ultima_letra != 's' && ultima_letra != 'x' && ultima_letra != 'z'))
        strcat(sustantivo, "es");
}

int main() {
    t_cadena sustantivo;
    ingreso_palabra(sustantivo);
    plural(sustantivo);

    printf("El plural es %s", sustantivo);
}