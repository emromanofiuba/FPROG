/* PROBLEMA
Escribir un programa donde el usuario ingrese una secuencia de números
terminada en cero y se le informe la cantidad de múltiplos de 2, 3, 5 y 7. Utilizar
una función que dados dos números como parámetros por valor devuelve un
valor boolean que indique si el primero es o no múltiplo del segundo.
Ejemplo:
Números ingresados: 35, 20, 14, 21, 2
múltiplos de 2: 3
múltiplos de 3: 3
múltiplos de 5: 2
múltiplos de 7: 3
*/

# include <stdio.h>
# include <stdbool.h>

bool es_multiplo(int num, int divisor)
{
    return num % divisor == 0;
}

int cant_multiplos(int num, int *cant_multiplos_2, int *cant_multiplos_3, int *cant_multiplos_5, int *cant_multiplos_7)
{

    if (es_multiplo(num, 2))
        (*cant_multiplos_2)++;

    if (es_multiplo(num, 3))
        (*cant_multiplos_3)++;      //Primero desreferencia, luego incrementa

    if (es_multiplo(num, 5))
        (*cant_multiplos_5)++;
    
    if (es_multiplo(num, 7))
        (*cant_multiplos_7)++;

    return num;
}

void main()
{
    int num, cant_multiplos_2, cant_multiplos_3, cant_multiplos_5, cant_multiplos_7;
    cant_multiplos_2 = cant_multiplos_3 = cant_multiplos_5 = cant_multiplos_7 = 0;

    printf("Numeros ingresados: ");
    scanf("%i", &num);

    while (num != 0){       //Calcula la cantidad de multiplos de 2, 3, 5 y 7 para cada numero validado
        cant_multiplos(num, &cant_multiplos_2, &cant_multiplos_3, &cant_multiplos_5, &cant_multiplos_7);
        scanf("%i", &num);  
    }

    printf("multiplos de 2: %i\n", cant_multiplos_2);
    printf("multiplos de 3: %i\n", cant_multiplos_3);
    printf("multiplos de 5: %i\n", cant_multiplos_5);
    printf("multiplos de 7: %i\n", cant_multiplos_7);
}