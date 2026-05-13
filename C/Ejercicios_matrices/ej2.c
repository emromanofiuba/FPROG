# include <stdio.h>
# include <stdbool.h>
# define FILAS 5
# define COLUMNAS 5

typedef int t_matrix[FILAS][COLUMNAS];

void ingreso_datos(t_matrix matriz, int filas, int columnas)
{
    int i, j;

    for (i = 0; i < filas; i++)
        for (j = 0; j < columnas; j++) {
            printf("Posicion %i %i: ", i, j);
            scanf("%i", &matriz[i][j]);
        }
}


int suma_diagonal_secundaria(t_matrix matriz, int filas, int columnas)
{
    int i, suma;
    suma = 0;

    for (i = 0; i < filas; i++) 
        suma += matriz[i][columnas - 1 - i];

    return suma;
}

int suma_hipo_triang_sup(t_matrix matriz, int filas)
{
    int i, suma;
    suma = 0;

    for (i = 0; i < filas; i++)
        suma += matriz[i][i + 1];
    
    return suma;
}

bool es_diagonal(t_matrix matriz, int filas, int columnas)
{
    bool sera_diagonal = true;
    int i, j;

    for (i = 0; i < filas; i++)
        for (j = 0; j < columnas; j++)
            if ((i != j) && (matriz[i][j] != 0))
                sera_diagonal = false;

    return sera_diagonal;
}

void main()
{
    t_matrix matriz;

    ingreso_datos(matriz, FILAS, COLUMNAS);

    printf("suma diag secundaria = %i\n", suma_diagonal_secundaria(matriz, FILAS, COLUMNAS));

    printf("La matriz es diagonal? %d\n", es_diagonal(matriz, FILAS, COLUMNAS));
}
