/* PROBLEMA
Calcular el producto de Wallis a traves de una funcion que reciba como parametro la
maxima cantidad de iteraciones del productorio (n).
Esta debe retornar el valor de Pi obtenido
*/

# include <stdio.h>

double producto_Wallis(int n)
{
    int i;
    double acumulador_productos;

    acumulador_productos = 1;


    for (i = 1; i <= n; i++){
        acumulador_productos *= ((double)(2*i) / (2*i - 1)) * ((double)(2*i) / (2*i + 1)); 
    }

   return 2 * acumulador_productos;
}

void main()
{
    int n;

    printf("Ingrese el maximo numero para aproximar el calculo de Pi: ");
    scanf("%i", &n);

    printf("\nEl valor de Pi obtenido es: %lf\n", producto_Wallis(n));
}