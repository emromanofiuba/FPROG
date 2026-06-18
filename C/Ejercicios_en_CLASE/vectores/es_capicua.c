# include <stdio.h>
# include <stdbool.h>
# define MAX 30
typedef int t_vec[MAX];

void ingreso_vector(t_vec vec, int *ml)
{
    int num;
    *ml = 0;
    printf("Componente 0: ");
    scanf("%i", &num);

    while (num != 0) {
        vec[*ml] = num;

        printf("Componente %i: ", *ml);
        scanf("%i", &num);
    }
}

bool es_capicua(t_vec vec, int ml)
{
    int i;
    bool capicua = true;
    i = 0;
    while (i < ml && capicua) {
        if (vec[i] != vec[ml-i-1])
            capicua = false;
        i++;
    }

    return capicua;
}