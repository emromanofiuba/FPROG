/*
Dado un listado de números reales del cual no se conoce la cantidad,
almacenar los números en un vector en el orden de entrada.
Informar la cantidad de números y el contenido del vector indicando la posición
ocupada por cada número a partir de la primera posición.
Considerar una estructura de datos de tamaño físico máximo de 1000
posiciones.
*/

# include <stdio.h>
# define MF 1000
# define VACIO -1.0

typedef float t_vec[MF];


void inicializar_vector(t_vec vector, int max)
{
    for (int i = 0; i < max; i++)
        vector[i] = VACIO;
}


void cargar_vector(t_vec vector, int max, int *ml)
{
    float numero;
    *ml = 0;
    int i = 0;

    printf("Ingrese un numero real para almacenarlo en la posicion %i, 0 para terminar: ", i);
    scanf("%f", &numero);

    while (numero != 0 && *ml < max){
        vector[i] = numero;
        i++;
        (*ml)++;

        printf("Ingrese otro numero real para almacenarlo en la posicion %i, 0 para terminar: ", i);
        scanf("%f", &numero);
    }
}


void imprimir_vector(t_vec vector, int ml)
{
    for (int i = 0; i < ml; i++){
        printf("Posicion %i: %.2f \n",i, vector[i]);
    }
    printf("\nLa cantidad de numeros ingresados es: %i\n", ml);
}


int main(void)
{
    t_vec vector;
    int ML;

    inicializar_vector(vector, MF);
    cargar_vector(vector, MF, &ML);
    imprimir_vector(vector, ML);
}