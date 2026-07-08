#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 101
#define VOCALES_MIN "aeiou"
typedef char t_oracion[MAX];

void ingreso_oracion(t_oracion oracion)
{
    printf("Ingrese una oracion: ");
    fgets(oracion, MAX, stdin);

    oracion[strcspn(oracion, "\n")] = '\0';
}

bool es_vocal_min_no_acentuada(char c)
{
    int i;
    bool es_vocal;
    es_vocal = false;
    i = 0;

    while (VOCALES_MIN[i] != '\0' && !es_vocal) {
        if (c == VOCALES_MIN[i])
            es_vocal = true;
        i++;
    }
    return es_vocal;
}

int vocales_min_no_acentuadas(t_oracion oracion)
{
    int cantidad, i;
    cantidad = 0;

    for (i = 0; oracion[i]!= '\0'; i++) {
        if (es_vocal_min_no_acentuada(oracion[i]))
            cantidad++;
    }
    return cantidad;
}

int main() {
    t_oracion oracion;
    ingreso_oracion(oracion);
    printf("La cantidad de vocales minusculas no acentuadas es %i\n", vocales_min_no_acentuadas(oracion));

    return 0;
}