# include <stdio.h>
# define FILAS 3
# define COLUMNAS 3
typedef int t_matriz[FILAS][COLUMNAS];

void cargar_datos(t_matriz matriz, int filas, int columnas)
{
    int i, j;
    for (i = 0; i < filas; i++)
        for (j = 0; j < columnas; j++) {
            printf("Posicion %i %i: ", i, j);
            scanf("%i", &matriz[i][j]);
        }
}

void contador_menor(t_matriz matriz, int filas, int columnas, int *menor, int *contador)
{
    int i, j;
    *menor = matriz[0][0];
    *contador = 0;

    for (i = 0; i < filas; i++)
        for (j = 0; j < columnas; j++) {
            if (matriz[i][j] < *menor) {
                *menor = matriz[i][j];
                *contador = 1;
            }
            else if (matriz[i][j] == *menor)
                (*contador)++;
        }
}

void main()
{
    t_matriz matriz;
    int menor, contador;

    cargar_datos(matriz, FILAS, COLUMNAS);
    contador_menor(matriz, FILAS, COLUMNAS, &menor, &contador);

    printf("El menor numero es %i y aparece %i veces \n", menor, contador);
}
