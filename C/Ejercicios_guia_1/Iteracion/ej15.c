/* PROBLEMA
Dada una serie de números ingresados de a uno.
Indicar mayor, menor y promedio de la serie.
El ingreso de números finaliza cuando el usuario ingresa 0.
*/

/* ANALISIS Y DISEÑO DEL ALGORITMO DE RESOLUCION
1. Declarar las variables numero_anterior, numero_actual, cant_numeros y promedio
 1.1 Darle un valor a numero_anterior, numero_actual, cant_numeros y promedio
2. Dentro de un ciclo while, pedir el ingreso de numeros mientras sea distinto de 0 y contar su cantidad
3. Calcular el mayor de la serie
    3.1 Con un if.., comparar el numero anterior con el numero actual
4. Calcular el menor de la serie
    4.1 Con un if.., comparar el numero anterior con el numero actual
5. Calcular el promedio fuera del bucle while
6. Mostrar un mensaje al usuario de que su serie termino (porque ingresó el 0)
7. Mostrar los resultados finales
    7.1 Mayor
    7.2 Menor
    7.3 Promedio
*/

# include <stdio.h>

int main()
{
    float numero, promedio, mayor, menor, suma;     //1
    int cant_numeros;

    numero = 1;                                                   //1.1
    cant_numeros = 0;
    promedio = 0;
    suma = 0;

    while (numero != 0){                     //2

        printf("Ingrese un numero: ");
        scanf("%f", &numero);

        if (numero == 0)
            break;
        
        cant_numeros++;

        if (cant_numeros == 1) {
            mayor = numero;
            menor = numero;
        }
        else {
            if (numero > mayor)                          
                mayor = numero;                           
            else if (numero < menor)
                menor = numero;
        }

        suma += numero;
}
       

    promedio = suma / cant_numeros;                                         //5

    printf("\n Ingresó el 0, por lo que cortó la serie \n");                   //6

    printf("\nMayor de la serie: %f \n", mayor);                            //7.1
    printf("Menor de la serie: %f \n", menor);                              //7.2
    printf("Promedio de la serie: %f \n", promedio);                       //7.3

    return 0;
}