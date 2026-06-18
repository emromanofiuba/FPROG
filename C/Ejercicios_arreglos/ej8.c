# include <stdio.h>
# include <stdbool.h>
#define MAX 10
typedef int t_vec[MAX];

void cargar_vector(t_vec vec, int *ml)
{
    int num;
    *ml = 0;

    printf("Componente %i: ", *ml+1);
    scanf("%i", &num);

    while (*ml < MAX && num > 0) {
        vec[*ml] = num;
        (*ml)++;
        printf("Componente %i: ", *ml+1);
        scanf("%i", &num);
    }
}

void procesar_vector(t_vec vec, int ml, bool *ordenado_asc, int *menor_dif)
{
    int i, dif;
    *ordenado_asc = true;
    
    if (ml < 2)
        *menor_dif = 0;
    else {
        *menor_dif = vec[1] - vec[0];
        if (vec[0] > vec[1])
            *menor_dif = -(*menor_dif); 
    }

    for (i = 1; i < ml -1; i++) {
        dif = vec[i+1] - vec[i];
        if (vec[i] > vec[i+1]) {
            *ordenado_asc = false;
            dif = -dif; 
        }
        
        if (dif < *menor_dif)
            *menor_dif = dif;
    }
}

void main ()
{
    t_vec vec;
    int ml;
    bool ordenado_asc;
    int menor_dif;

    cargar_vector(vec, &ml);
    procesar_vector(vec, ml, &ordenado_asc, &menor_dif);

    printf("Menor dif: %i\n", menor_dif);
    printf("Ordenado asc?: %d\n", ordenado_asc);
}