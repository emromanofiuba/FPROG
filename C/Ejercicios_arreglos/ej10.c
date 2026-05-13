/*
Dado un vector a de longitud n y un elemento p del mismo tipo que los
elementos del vector, buscar p en el vector a y devolver la posición que ocupa
en caso de encontrarlo o una señal en caso contrario. Suponer que no hay
repeticiones.
*/

# include <stdio.h>
# include <stdbool.h>
# define MF 5

typedef int t_vec[MF];

void ingreso_datos(t_vec vector, int mf)
{
    for (int i = 0; i < mf; i++) {
        printf("Posicion %i: ", i);
        scanf("%i", &vector[i]);
    }
}

int ingreso_numero()
{
    int p;
    printf("Ingrese un numero: ");
    scanf("%i", &p);

    return p;
}

void esta_p(t_vec vector, int mf, int p, int *posicion_p, int *p_esta)
{
    *p_esta = false;
    int i = 0;

    while (i < mf && !(*p_esta)) {
        if (vector[i] == p) {
            *p_esta = true;
            *posicion_p = i;
        }
        i++;
    }
}

int main(void)
{
    t_vec vector;
    int p;
    int posicion_p;
    int p_esta;

    ingreso_datos(vector, MF);

    p = ingreso_numero();

    esta_p(vector, MF, p, &posicion_p, &p_esta);
    printf("El numero %i está en el vector? (0 si no esta, 1 si esta) %d\n", p, p_esta);

    if (p_esta)
        printf("y esta en la posición %i\n", posicion_p);


    return 0;

}
