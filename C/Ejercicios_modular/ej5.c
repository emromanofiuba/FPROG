/* PROBLEMA
Dada una secuencia de números enteros ingresados por el usuario, informar
aquellos que sean primos. El listado finaliza al ingresar cero. Al finalizar el
ingreso se debe indicar la cantidad y la sumatoria de aquellos que fueron
primos.
*/

/* ALGORITMO DE RESOLUCION
1. funcion para generar la secuencia de numeros enteros
    1.1 parametros como cantidad_primos y suma_primos
2. funcion main para poner la condicion de corte de la secuencia y mostrar el resultado
*/

# include <stdio.h>
# include <stdbool.h>


bool secuencia_primos(int numero)
{
    int divisor;
    bool es_primo = true;

    if (numero <= 1)
        es_primo = false;
    else {
        for (divisor = 2; divisor < numero && es_primo; divisor++)
            if (numero % divisor == 0)
                es_primo = false;
    }

    return es_primo;
}

void cantidad_y_suma(int numero, int *cantidad_primos, int *suma_primos)
{
     if (secuencia_primos(numero) == true){
        (*cantidad_primos)++;
        (*suma_primos) += numero;
    }
}


int main()
{
    int numero;
    int cantidad_primos, suma_primos;
    cantidad_primos = suma_primos = 0;

    printf("Ingrese un numero: ");
    scanf("%i", &numero);

    while (numero != 0) {
        cantidad_y_suma(numero, &cantidad_primos, &suma_primos);
        
        printf("Ingrese un numero: ");
        scanf("%i", &numero);
    }

    printf("\nCantidad de primos: %i\n", cantidad_primos);
    printf("Suma de primos: %i\n", suma_primos);

    return 0;
}