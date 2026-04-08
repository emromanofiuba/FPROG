/* PROBLEMA
Solicitar un número entero positivo al usuario y calcular su factorial. En el caso de
ingresar un número negativo mostrar un mensaje que diga “no se puede calcular el factorial
del número ingresado”.
Recordar que por definición factorial(0)=1 y factorial(1)=1
*/

/* ANALISIS Y DISEÑO DEL ALGORITMO
1. Declarar variables entero_positivo, factorial, contador_factorial, numero_actual
2. Solicitar un numero positivo entero al usuario
 2.1 Si el numero es negativo, mostrar dicho mensaje y pedir un numero hasta que sea un entero positivo (uso de estructura while)
 2.2 Si el numero es 0 o 1, mostrar que su factorial es 1 (uso de estrucutra if)
 2.3 Si es positivo, realizar el ciclo del calculo del factorial (uso de estructura else)
3. Programar un ciclo for que multiplique cada numero natural en sucesion hasta llegar al entero_positivo (calculo del factorial)
4. Imprimir por pantalla el factorial de entero_positivo
*/

# include <stdio.h>

void main()
{
    int entero_positivo, factorial, contador_factorial, numero_actual;

    printf("Ingrese un numero entero positivo para calcularle el factorial: ");
    scanf("%i", &entero_positivo);

    while (entero_positivo < 0){
        printf("\n no se puede calcular el factorial del numero ingresado. Ingrese un numero entero positivo: ");
        scanf("%i", &entero_positivo);
    }
    if (entero_positivo == 0 || entero_positivo == 1)
        printf("\n %i! = 1\n", entero_positivo);
    else {
        factorial = 1;
        numero_actual = 1;

        for (contador_factorial = 1; contador_factorial <= entero_positivo; contador_factorial++){
            factorial *= numero_actual;
            numero_actual++;
        }
        printf("\n %i! = %i\n", entero_positivo, factorial );
    }
}
