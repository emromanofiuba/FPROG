#include <stdio.h>
typedef int t_vec[6];
#define NO_ENCONTRADO -1

int busqueda_binaria(t_vec vec, int num, int inf, int sup)
{
    int centro;

    if (num < vec[inf] || num > vec[sup])
        return NO_ENCONTRADO;
    else {
        centro = inf + ((sup - inf) / 2);

        if (num > vec[centro])
            return busqueda_binaria(vec, num, centro + 1, sup);
        else if (num < vec[centro])
            return busqueda_binaria(vec, num, inf, centro - 1);
        else 
            return centro;
    }
}

void main() {
    t_vec vec = {1, 2, 3, 4, 5, 6};
    int ml = 6;
    int buscado = 5;
    int posicion = busqueda_binaria(vec, buscado, 0, ml-1);
    printf("Esta el %i, en que posicion = %d\n", buscado, posicion);
}