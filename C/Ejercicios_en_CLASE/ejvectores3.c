/*
Dado un ingreso de una serie de numeros que van del 0 al 999,
cortarla con un numero negativo y mostrar la cantidad de veces que se ingreso cada numero.
*/

# include <stdio.h>
# define MAX 10
typedef int tvec_cont[MAX];


void inicializar_contador(tvec_cont contador)
{
    for (int i = 0; i < MAX; i++)
        contador[i] = 0;
}

void ingresar_numeros(tvec_cont contador)
{
    int numero;

    printf("Ingrese un numero del 0 al 10 (num negativo para terminar): ");
    scanf("%i", &numero);

    while (numero >= 0){
            contador[numero]++;
            
        printf("Ingrese otro numero del 0 al 10 (num negativo para terminar): ");
        scanf("%i", &numero);
    }
}

void mostrar_contador(tvec_cont contador)
{
    for (int i = 0; i < MAX; i++)
        if (contador[i] > 0)
            printf("el numero %i se ingreso %i veces\n", i, contador[i]);
}



int main(void)
{
    tvec_cont contador;

    inicializar_contador(contador);
    ingresar_numeros(contador);
    mostrar_contador(contador);

    return 0;
}