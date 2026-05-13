# include <stdio.h>
# define MF 10
typedef int t_matriz[MF][MF];

void cargar_dimensiones(int *filas, int *columnas)
{
    printf("Cargue las dimensiones de la matriz\n");
    scanf("%i", filas);
    scanf("%i", columnas);
}

void cargar_matriz(t_matriz matriz, int filas, int columnas)
{
     for(int i = 0; i < filas; i++)
        for(int j = 0; j < columnas; j++){
            printf("ingrese el numero de %d %d: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
}

void multiplicar_matrices(t_matriz matriz_1, t_matriz matriz_2, t_matriz resultado, int m, int n, int p)
{
    int i, j, k;
    int suma = 0;
    
for (i = 0; i < m; i++) 
    for (k = 0; k < p; k++) {
        for (j = 0; j < n; j++) 
                suma += matriz_1[i][j] * matriz_2[j][k];
        resultado[i][k] = suma;
        suma = 0;
    } 
}

void mostrarMatriz(t_matriz matriz, int filas, int columnas){
    for(int i = 0; i < filas; i++){
        printf("\n");
        for(int j = 0; j < columnas; j++){
            printf(" %d ", matriz[i][j]);
        }
    }
}

void main()
{
    t_matriz matriz_1;
    t_matriz matriz_2;
    t_matriz resultado;
    int m, n, q, p;

    cargar_dimensiones(&m, &n);
    cargar_dimensiones(&q, &p);
    if (n != q) 
        printf("No es posible realizar la multiplicacion de las matrices\n");

    cargar_matriz(matriz_1, m, n);
    printf("\n");
    cargar_matriz(matriz_2, q, p);

    multiplicar_matrices(matriz_1, matriz_2, resultado, m, n, p);
    mostrarMatriz(resultado, m, p);

}