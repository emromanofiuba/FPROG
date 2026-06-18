# include <stdio.h>
# define MAX_FILAS 3
# define COLUMNAS 4
typedef int t_matriz[MAX_FILAS][COLUMNAS];


void carga_matriz(t_matriz matriz, int *mlf)
{
    int j;
    char carga;
    *mlf = 0;

    printf("Quiere cargar la fila 1?: ");
    scanf(" %c", &carga);

    while (*mlf < MAX_FILAS && carga == 's') {
        for (j = 0; j < COLUMNAS; j++){
            printf("valor %i %i: ", *mlf, j);
            scanf("%i", &matriz[*mlf][j]);
        }
        (*mlf)++;
         printf("Quiere cargar la fila %i?: ",*mlf+1);
         scanf(" %c", &carga);
    }

}

void main()
{
    t_matriz matriz;
    int mlf;
    carga_matriz(matriz, &mlf);

    for (int i=0; i < mlf; i++) {
        for (int j=0; j < COLUMNAS; j++) {
            printf("% i", matriz[i][j]);
        }
        printf("\n");
    }
}

