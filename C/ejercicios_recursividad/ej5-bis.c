#include <stdio.h>

int menor_posicion(int vec[], int ml)
{
    int menor;

    if (ml == 1)
        return 0;
    menor = menor_posicion(vec, ml-1);
    if (vec[ml-1] < vec[menor] )
        return ml-1;
    return menor;
}

int main()
{
    int vec[] = {9, 4, 8, 7, 6};
    int ml = 5;
    printf("Posicion del menor valor: %i\n", menor_posicion(vec, ml));
}