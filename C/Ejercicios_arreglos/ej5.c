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


void obtener_mayor(t_vec vector, int ML, float *max, int *posicion_max, int *contador)
{
    *max = vector[0];
    *posicion_max = 0;
    *contador = 0;

    for (int i = 1; i < ML; i++) {
        if (vector[i] > *max){
            *max = vector[i];
            *posicion_max = i;
            *contador = 1;
        }
        else if (vector[i] == *max)
            (*contador)++;
    }   
}


int main(void)
{
    t_vec vector;
    int ml, posicion_max, contador;
    float max, numero;

    ingreso_datos(vector, MAX, &ml);

    obtener_mayor(vector, ml, &max, &posicion_max, &contador);

    printf("\n mayor componente del vector: %.2f", max);
    printf("\n posicion donde este se encuentra: %i\n", posicion_max);
    printf("\n cantidad de veces que aparece: %i\n", contador);

    
    return 0;
}