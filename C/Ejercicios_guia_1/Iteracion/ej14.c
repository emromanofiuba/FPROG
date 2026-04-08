/* PROBLEMA
Escribir un programa que muestre las tablas de multiplicar desde la tabla del 1 hasta la
tabla del 9 para los primeros 100 números naturales.
*/

/* ANALISIS Y DISEÑO DEL ALGORITMO DE RESOLUCION
1. Declarar variables de control (iterables): num_natural, num_tabla y la que almacene las tablas (tabla)
2. Estructurar ciclo for 
    2.1 Empiece num_natural en 1 hasta llegar a 100, con un incremento de 1 unidad
    2.2 Estructurar ciclo for anidado para recorrer todos los numeros desde el 1 hasta 9 para asi armar las tablas
        2.2.1 Recorrer este ciclo hasta terminar con las tablas de todo un numero
3. Imprimir por pantalla las tablas armadas
*/

# include <stdio.h>

int main()
{
    int num_natural, num_tabla;
    long tabla;

    tabla = 1;

    for (num_natural = 1; num_natural <= 100; num_natural++){
         printf("\n**TABLA DEL %i**\n", num_natural);

        for (num_tabla = 1; num_tabla <= 9; num_tabla++){
            tabla = num_natural * num_tabla;
            printf("%i x %i = %ld \n", num_natural, num_tabla, tabla);
        }
    } 

    return 0;
}