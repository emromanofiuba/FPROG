# include <stdio.h>
# define FILAS 3
# define COLUMNAS 4

typedef float t_matrix[FILAS][COLUMNAS];
typedef float t_vec[FILAS];

void ingreso_datos(t_matrix matriz, int filas, int columnas)
{
    int i, j;
    for (i = 0; i < filas; i++)
        for (j = 0; j < columnas; j++) {
            printf("Posicion %i %i: ", i, j);
            scanf("%f", &matriz[i][j]);
        }
}

void vector_elementos_minimos(t_matrix matriz, int filas, int columnas, t_vec vector)
{
    int i, j;
    float minimo_fila;

    for (i = 0; i < filas; i++) {
        minimo_fila = matriz[i][0];

        for (j = 1; j < columnas; j++) 
            if (matriz[i][j] < minimo_fila) {
                minimo_fila = matriz[i][j];
            }
        vector[i] = minimo_fila;
        }
}

void mostrar_vector(t_vec vector, int filas)
{
    int i;
    for (i = 0; i < filas; i++) 
        printf("posicion %i: %.2f \n", i, vector[i]);
}


int main(void)
{
    t_matrix matriz;
    t_vec vector;

    ingreso_datos(matriz, FILAS, COLUMNAS);

    vector_elementos_minimos(matriz, FILAS, COLUMNAS, vector);

    printf("\n Vector resultante \n");
    mostrar_vector(vector, FILAS);
}