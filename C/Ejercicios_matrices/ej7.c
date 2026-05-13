# include <stdio.h>
# define DIAS 3
# define HORAS 4
typedef float t_matriz[DIAS][HORAS];

void cargar_datos(t_matriz matriz)
{
    int dia, hora;
    for (dia = 0; dia < DIAS; dia++)
        for (hora = 0; hora < HORAS; hora++) {
            printf("Dia %i | Hora %i: ", dia+1, hora+1);
            scanf("%f", &matriz[dia][hora]);
        }
}

void mostrar_matriz(t_matriz matriz)
{
    int dia, hora;
    for (dia = 0; dia < DIAS; dia++) {
        printf("\n");
        for (hora = 0; hora < HORAS; hora++) 
            printf(" %.1f°", matriz[dia][hora]);
    }
    printf("\n");
}

void min_max_temperatura_dia(t_matriz matriz, float *min, float *max, int dia)
{   
    int hora;
    *min = matriz[dia][0];
    *max = matriz[dia][0];

    for (hora = 0; hora < HORAS; hora++) {
        if (matriz[dia][hora] < *min)
            *min = matriz[dia][hora];
        else if (matriz[dia][hora] > *max)
            *max = matriz[dia][hora];
    }
}

void min_max_temperatura_mes(t_matriz matriz, float *min, float *max)
{
    int dia, hora;
    *min = matriz[0][0];
    *max = matriz[0][0];

    for (dia = 0; dia < DIAS; dia++)
        for (hora = 0; hora < HORAS; hora++) {
            if (matriz[dia][hora] < *min)
            *min = matriz[dia][hora];
        else if (matriz[dia][hora] > *max)
            *max = matriz[dia][hora];
        }
}

void main()
{
    t_matriz matriz;
    int dia;
    float min_dia, max_dia, min_mes, max_mes;

    cargar_datos(matriz);
    mostrar_matriz(matriz);

    for (dia = 0; dia < DIAS; dia++) {
        min_max_temperatura_dia(matriz, &min_dia, &max_dia, dia);

        printf("Minima temperatura del dia %i = %.1f° \n", dia+1, min_dia);
        printf("Maxima temperatura del dia %i = %.1f° \n", dia+1, max_dia);
        printf("\n");
    }

    min_max_temperatura_mes(matriz, &min_mes, &max_mes);
    printf("Minima temperatura del mes = %.1f° \n", min_mes);
    printf("Maxima temperatura del mes = %.1f° \n", max_mes);
    
}