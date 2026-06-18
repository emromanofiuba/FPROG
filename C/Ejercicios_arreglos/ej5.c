# include <stdio.h>
# define MAX 100
typedef float t_vec[MAX];

float validar_positivo()
{
    float numero;

    printf("\nIngrese un numero real positivo: ");
    scanf("%f", &numero);

    while (numero < 0) {
        printf("Debe ingresar un numero real positivo: ");
        scanf("%f", &numero);
    }

    return numero;
}


void ingreso_datos(t_vec vector, int mf, int *ml)
{
    printf("A continuacion, ingresará las componentes del vector (máximo 10) ");

    *ml = 0;
   float numero = validar_positivo();
    
    while (numero !=0 && *ml < mf){
        vector[*ml] = numero;
        (*ml)++;
    
        numero = validar_positivo();
    }
}


void obtener_maximo(t_vec vector, int ML, float *max)
{
    *max = vector[0];

    for (int i = 1; i < ML; i++) {
        if (vector[i] > *max)
            *max = vector[i];
    }
}

void obtener_posiciones_y_cantidades(t_vec vector, int ml, float max, int *contador)
{
    int i;
    *contador = 0;
    for (i = 0; i < ml; i++)
        if (vector[i] == max) {
            (*contador)++;
            printf("\t%i", i);
        }
}


int main(void)
{
    t_vec vector;
    int ml, posicion_max, contador;
    float max, numero;

    ingreso_datos(vector, MAX, &ml);

    obtener_maximo(vector, ml, &max);

    printf("\n mayor componente del vector: %.2f\n", max);
    printf("max se encuentra en la posicion/es");
    obtener_posiciones_y_cantidades(vector, ml, max, &contador);
    printf("\n cantidad de veces que aparece: %i\n", contador);

    
    return 0;
}