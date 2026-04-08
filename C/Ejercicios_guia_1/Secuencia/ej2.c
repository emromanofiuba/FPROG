/*
Calcular el sueldo de un operario ingresando por teclado la cantidad de horas que
trabajó en el mes y el valor de la hora. Mostrarle el resultado al usuario con un
mensaje adecuado.
*/

#include <stdio.h>

void main(){
    int cantidad_horas, valor_hora, sueldo;

    printf("Ingrese la cantidad de horas trabajas en el mes: ");
    scanf("%i", &cantidad_horas);

    printf("Ingrese el valor de la hora trabajada en el mes: ");
    scanf("%i", &valor_hora);

    sueldo = cantidad_horas * valor_hora;
    printf("\nEl sueldo que cobrará este mes es un total de $%i\n", sueldo);
}