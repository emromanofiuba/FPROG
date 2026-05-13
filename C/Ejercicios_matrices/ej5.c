/*
Dadas dos matrices A y B cuadradas de igual dimensión, tales que A∈Rn×n y
B∈Rn×n , escribir un programa que permita cargar su dimensión y sus datos. El
programa debe sumarlas y mostrar la matriz resultante. Para la estructura de
datos considere un tamaño máximo de 10 (1 <= n <= 10).
*/

# include <stdio.h>
# define MF 10

typedef int t_matrix[MF][MF];

void cargar_dimensiones(int *n)
{
    printf("Ingrese una cantidad de filas y columnas: ");
    scanf("%i", n);
}

void cargar_datos(t_matrix matriz, int n)
{
    int i, j;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            printf("Posicion %i %i: ", i, j);
            scanf("%i", &matriz[i][j]);
        }
}

void suma_matrices(t_matrix matriz_1, t_matrix matriz_2, int n, t_matrix matriz_suma)
{
     int i, j;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            matriz_suma[i][j] = matriz_1[i][j] + matriz_2[i][j];
        }
}

void mostrar_suma(t_matrix matriz_suma, int n)
{
      int i, j;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            printf("posicion %i %i: %i \n",i, j, matriz_suma[i][j]);
        }
}

void main()
{
    t_matrix matriz_1, matriz_2, matriz_suma;
    int n;

    printf("\nA continuacion, debe cargar la cantidad de filas y columnas (i = j) < 10 \n");
    cargar_dimensiones(&n);

    while (n < 1 || n > 10) {
        printf("\nDebe ingresar una cantidad de filas y columnas (1 < n < 10)\n");
        cargar_dimensiones(&n);
    }   

    printf("\n Matriz 1 \n");
    cargar_datos(matriz_1, n);
    printf("\n Matriz 2\n");
    cargar_datos(matriz_2, n);

    suma_matrices(matriz_1, matriz_2, n, matriz_suma);

    printf("\n Matriz 1 + Matriz 2 \n");
    mostrar_suma(matriz_suma, n);
}