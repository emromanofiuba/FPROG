# include <stdio.h>
# define MF 5
# define VACIO 0
typedef int t_matriz[MF][MF];
typedef int t_vec[MF];

void cargar_matriz(t_matriz matriz, int *i, int *j)
{
    int num;
    *i = 0;
    *j = 0;

    printf("Ingrese un valor (-1 para cambiar de fila, -2 para terminar): ");
    scanf("%i", &num);

    while (*i < MF && num != -2) {
        if (num == -1) {
            (*i)++;   // nueva fila
            *j = 0;   // resetear columna
        } else {
            matriz[*i][*j] = num;
            (*j)++;   // avanzar columna DESPUÉS de guardar
        }

        printf("Ingrese un valor (-1 para cambiar de fila, -2 para terminar): ");
        scanf("%i", &num);
    }
}

void inicializar_contador(t_vec contador)
{
    for (int i = 0; i < MF; i++)
        contador[i] = VACIO;
}

void contar_numeros(t_matriz matriz, int filas, int columnas, t_vec contador)
{
    for(int i = 0; i < filas + 1; i++)
        for(int j = 0; j < columnas; j++){
            contador[ matriz[i][j] ]++;
        }
}

void mostrar_apariciones_numeros(t_vec contador)
{
    for (int i = 0; i < MF; i++)
        if (contador[i] > VACIO)
            printf("El numero %i aparece %i veces\n", i, contador[i]);
}


void main()
{
    t_matriz matriz;
    t_vec contador;
    int i, j;

    cargar_matriz(matriz, &i, &j);

    inicializar_contador(contador);
    contar_numeros(matriz, i, j, contador);
    mostrar_apariciones_numeros(contador);
}