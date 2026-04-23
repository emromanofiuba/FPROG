/*
1. Se tiene una lista de casos confirmados de coronavirus por cada país se pide:

-Indicar cual es el promedio mundial
-Cantidad de Casos mundiales
-Que cantidad de casos tiene el país con menos casos
-Que cantidad de casos tiene el país con más casos

Ingrese casos -1 para termina
*/

# include <stdio.h>

void main()
{
    int caso, cant_casos, menor, mayor, suma;
    float promedio;

    suma = 0;
    promedio = 0;
    cant_casos = 0;
    
    printf("ingrese un caso (0 o menos para terminar): ");
    scanf("%i", &caso);
    menor = caso;
    mayor = caso;

    while (caso >= 0 ){

        if (caso > mayor)
            mayor = caso;
        else if (caso < menor)
            menor = caso;

        suma += caso;
        cant_casos++;

        printf("Ingrese un caso (0 o menos para terminar): ");
        scanf("%i", &caso);

    }
    promedio = suma / cant_casos;

    printf("\n %i casos mundiales", suma);
    printf("\nEl promedio de casos es: %f", promedio);
    printf("\nEl pais con la mayor cantidad de casos tiene %i casos", mayor);
    printf("\nEl pais con la menor cantidad de casos tiene %i casos\n", menor);
}