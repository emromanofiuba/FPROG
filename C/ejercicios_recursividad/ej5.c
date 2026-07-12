#include <stdio.h>
#define MAX 10
typedef int t_vec[MAX];

int mayor_vector(t_vec vec, int ml)
{
    int mayor;
    if (ml == 1)
        return vec[0];

    mayor = mayor_vector(vec, ml-1);
    if (vec[ml-1] > mayor)
        return vec[ml-1];
    return mayor;
}

int main(void) {
    t_vec vec = {1, 2, 9, 7, 3, 4};
    int ml = 6;
    printf("El mayor es: %i\n", mayor_vector(vec, ml));

    return 0;
}