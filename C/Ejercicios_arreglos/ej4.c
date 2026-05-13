/*
Cargar una serie de números reales positivos en un vector. No se conoce la
cantidad exacta de datos, pero se sabe que no superan los 100. La serie finaliza
cuando se ingresa cero. Utilizar una función que invierta el contenido del vector.
Informar el contenido del vector indicando la posición ocupada por cada
número a partir de la primera posición
*/

# include <stdio.h>
# define MF 10

typedef float t_vec[MF];

void ingreso_positivos(t_vec vector, int mf, int *ml)
{
    *ml = 0;
    int i = 0;
    float numero;

    printf("Ingrese un numero real positivo: ");
    scanf("%f", &numero);

    while (numero != 0 && *ml < mf) {
       if (numero > 0) {
            vector[i] = numero;
            (*ml)++;
            i++;
        printf("Ingrese otro numero real positivo: ");
        scanf("%f", &numero);
       }
       else {
            printf("Debe ingresar un numero real positivo: ");
            scanf("%f", &numero);
        }
    }
}

void vector_invertido(t_vec vector, t_vec vector_inverso, int ml)
{
    for (int i = 0; i < ml; i++) 
        vector_inverso[i] = vector[ml - 1 - i];
}

void mostrar_vector(t_vec vector, int ml)
{
    for (int i = 0; i < ml; i++)
        printf("Posicion %i: %.2f \n", i, vector[i]);
}

int main(void)
{
    t_vec vector;
    t_vec vector_inverso;
    int ml;

    ingreso_positivos(vector, MF, &ml);

    vector_invertido(vector, vector_inverso, ml);

    if (ml > 0) {
        printf("\nVector original\n");
        mostrar_vector(vector, ml);

        printf("\nVector invertido\n");
        mostrar_vector(vector_inverso, ml);
    }
    else
        printf("No se ingresaron numeros al vector\n");


    return 0;   
}