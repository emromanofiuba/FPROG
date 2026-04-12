/* PROBLEMA
Generar un dibujo por pantalla con el siguiente patrón solicitando al usuario la altura.
Ejemplo: altura=5 debe dibujar por pantalla:
*
**
***
****
*****
*/

/*
ALGORITMO DE RESOLUCIÓN
1. declarar variables altura, fila, asterisco
2. solicitar altura;
    2.1 debe ser mayor o igual a cero
        2.1.1 while para validar entrada del usuario
3.
4. imprimir por pantalla la altura y un mensaje con lo que deberia dibujar
*/

# include <stdio.h>

void main()
{
    int altura, fila, asterisco;

    printf("Ingrese una altura: ");
    scanf("%i", &altura);

    while (altura < 0){
        printf("Ingrese una altura válida: ");
        scanf("%i", &altura);
    }

    printf("\nAltura = %i debe dibujar por pantalla:\n", altura);

    for (fila = 1; fila <= altura; fila++){
        for (asterisco = 1; asterisco <= fila; asterisco++)
            printf("*");
        printf("\n");
    }
}