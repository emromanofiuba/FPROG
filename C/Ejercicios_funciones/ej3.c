/* PROBLEMA
Escribir una función que reciba un valor y calcule el factorial del mismo.
No debe imprimir el valor, debe solamente devolverlo.
Si no se puede calcular el factorial del valor recibido, la función deberá devolver 0, de lo contrario deberá devolver el valor calculado. 

Invocarla para los valores -8, 0, 1, 5; mostrando en cada caso lo que devuelve.

Definición: El factorial de un entero positivo n,  se define como el producto de todos los números enteros positivos desde 1 hasta n.  El factorial de 0 es 1.
*/

# include <stdio.h>

    int calcular_factorial ( int numero )
    {
        int factorial, i, resultado;
        factorial = 1;
        
        for (i = 1; i <= numero; i++)
            factorial *= i;

        if (numero < 0)
            resultado = 0;
        else 
            resultado = factorial;
        
        return resultado;
    }

    int main()
    {
        printf("0! = %i\n", calcular_factorial(0));
        printf("4! = %i\n", calcular_factorial(4));
        printf("1! = %i\n", calcular_factorial(1));
        printf("-2! = %i\n", calcular_factorial(-2));
    }
    