#include <stdio.h>

#define FILAS 3
#define COLUMNAS 3

void ingreso_datos(int matriz[FILAS][COLUMNAS], int filas, int columnas)
{
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Ingrese un valor para la posicion [%i, %i] ", i, j);
            scanf("%i", matriz[i][j]);
        }
    }
}

int suma_diagonal_principal(int matriz[FILAS][COLUMNAS], int filas)
{
    int suma_diag_1 = 0;

    for (int i = 0; i < filas; i++)
        suma_diag_1 += matriz[i][i];

    return suma_diag_1;
}

int suma_diagonal_secundaria(int matriz[FILAS][COLUMNAS], int filas, int columnas)
{
    int suma_diag_2 = 0;

    for (int i = 0; i < filas; i++)
        suma_diag_2 += matriz[i][COLUMNAS - 1 - i];
    
    return suma_diag_2;

}


int main(void) {

    int matriz[FILAS][COLUMNAS];

    ingreso_datos(matriz, 3, 3);
    
    printf("La suma de la diagonal principal es %i\n", suma_diagonal_principal(matriz, 3));
    
    printf("La suma de la diagonal secundaria es %i\n", suma_diagonal_secundaria(matriz, 3, 3));


    return 0;
}