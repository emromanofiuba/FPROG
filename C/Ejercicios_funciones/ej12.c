/* PROBLEMA
Escribir una función que reciba dos valores enteros, y devuelva el máximo
común divisor entre ambos números.
Utilizar el algoritmo de Euclides
*/

/* ALGORITMO DE RESOLUCION
1. declarar int main(void) con variables num_mayor, num_menor, resto;
    1.1 pedir ingreso de numeros
    1.2 validar entrada del num_menor != 0
    1.3 invocar la funcion hasta que el resto = 0
2. invocar int calculo_MCD(num_mayor, num_menor, *resto)
    2.1 declarar variable cociente;
    2.2 hacer la logica correspondiente
3. mostrar por pantalla el MCD
*/


# include <stdio.h>

int calculo_MCD(int num_mayor, int num_menor)
{
    int resto;

    while (num_menor != 0){
        resto = num_mayor % num_menor;
        num_mayor = num_menor;
        num_menor = resto;
    }

    return num_mayor;
}


int main(void)
{
    int num_mayor, num_menor;

    printf("A continuacion, ingresara 2 numeros enteros (uno mayor y otro menor) para calcular el MCD entre ellos\n");

    printf("\nNumero mayor: ");
    scanf("%i", &num_mayor);

    printf("Numero menor: ");
    scanf("%i", &num_menor);

    if (num_menor == 0)
        printf("No se puede realizar el calculo del MCD");
    else
        printf("El MCD entre %i y %i es %i\n", num_mayor, num_menor, calculo_MCD(num_mayor, num_menor));

    
    return 0;

}
