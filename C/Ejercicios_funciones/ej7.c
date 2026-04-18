/* PROBLEMA
Escribir una función que dados a y b devuelva el cociente de la división
entera, sin utilizar el operador correspondiente del lenguaje. Para esta
resolución deben considerar la utilización de restas sucesivas.
*/

# include <stdio.h>

int cociente_division_entera (int numero, int divisor)
{
    int i, cant_restas, numero_original;

    numero_original = numero;   
    cant_restas = 0;

    while (numero != 0){
        numero = numero - divisor;
        cant_restas++;
    }

    return cant_restas;
}

void main()
{
    int cociente, numero_original, divisor, cant_restas;

    cociente = cociente_division_entera(20, 4);

    printf("La division entera de %i y %i : %i\n", numero_original, divisor, cant_restas);
}