#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void ingreso_palabra(char palabra[])
{
    printf("Palabra: ");
    scanf("%s", palabra);
}

bool es_vocal(char c)
{
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int contar_silabas(char palabra[])
{
    int cant_silabas, i, largo;
    bool anterior_fue_vocal;
    cant_silabas = 0;
    largo = strlen(palabra);

    if (largo <= 3)
        cant_silabas = 1;
    else {
        anterior_fue_vocal = false;
        for (i = 0; i < largo; i++) {
            if (es_vocal(palabra[i]) && !anterior_fue_vocal)
                cant_silabas++;
            anterior_fue_vocal = es_vocal(palabra[i]);
        }
    }

    return cant_silabas;
}

int main() {
    char palabra[25];
    int silabas;

    ingreso_palabra(palabra);
    silabas = contar_silabas(palabra);

    printf("La palabra tiene %i silaba(s)\n", silabas);

    return 0;
}