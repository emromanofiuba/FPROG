#include <stdio.h>

#define TAM_FISICO 1000
#define VACIO -1.0

void inicializar_vector(float vector[], int tam)
{
    int i;
    for (i = 0; i < tam; i++)
        vector[i] = VACIO;
}

void cargar_vector(float vector[], int *cant_cargados)
{
    int indice;
    float valor;

    *cant_cargados = 0;

    printf("Ingrese pares (i x). Para terminar ingrese 0 0:\n");
    scanf("%d %f", &indice, &valor);

    while (indice != 0) {
        vector[indice] = valor;
        (*cant_cargados)++;
        scanf("%d %f", &indice, &valor);
    }
}

void informar_vector(float vector[], int tam)
{
    int i;
    int cant_mostrados = 0;

    printf("\nContenido del vector:\n");

    for (i = 1; i < tam; i++) {
        if (vector[i] != VACIO) {
            printf("Posicion %d: %.2f\n", i, vector[i]);
            cant_mostrados++;
        }
    }

    printf("Cantidad de posiciones cargadas: %d\n", cant_mostrados);
}

int main()
{
    float vector[TAM_FISICO];
    int cant_cargados;

    inicializar_vector(vector, TAM_FISICO);
    cargar_vector(vector, &cant_cargados);
    informar_vector(vector, TAM_FISICO);

    return 0;
}