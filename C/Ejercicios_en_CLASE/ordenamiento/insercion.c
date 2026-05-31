# include <stdio.h>
# include <stdbool.h>
# define MF 100
typedef int t_vec[MF];

void pedir_vector(t_vec vec, int *ml)
{   
    int num;
    *ml = 0;

    printf("Ingrese un entero, -1 para terminar: ");
    scanf("%i", &num);

    while (*ml < MF && num != -1) {
        vec[*ml] = num;
        (*ml)++;
        printf("Ingrese otro entero, -1 para terminar: ");
        scanf("%i", &num);
    }
}

void ordenar_por_insercion(t_vec vec, int ml)
{
    int i, j, aux;

    for (i = 1; i < ml; i++){
        aux = vec[i];
        j = i - 1;

        while ((j >=0) && (aux < vec[j])) {
            vec[j+1] = vec[j];
            j--;
        }
        vec[j+1] = aux;
    }
}

void vector_desordenado(t_vec vec, int ml) {
    for (int i = 0; i < ml; i++)
        printf("\t %i", vec[i]);
    printf("\n");
}

void vector_ordenado(t_vec vec, int ml) {
    for (int i = 0; i < ml; i++)
        printf("\t %i", vec[i]);
    printf("\n");
}

int main(void) {
    t_vec vec;
    int ml;

    pedir_vector(vec, &ml);

    printf("\n--VECTOR DESORDENADO--\n");
    vector_desordenado(vec, ml);

    ordenar_por_insercion(vec, ml);

    printf("\n--VECTOR ORDENADO--\n");
    vector_ordenado(vec, ml);

    return 0;

}
