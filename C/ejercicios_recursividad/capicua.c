#include <stdio.h>
#include <stdbool.h>

bool es_capicua(char vec[], int izq, int der)
{
    if (izq >= der)
        return true;
    if (vec[izq] != vec[der])
        return false;
    return es_capicua(vec, izq + 1, der - 1);
}

int main() {
    char vec[] = "neuquen";
    int ml = 7;
    printf("El vector es capicua: %d\n", es_capicua(vec, 0, ml - 1));

    return 0;
}