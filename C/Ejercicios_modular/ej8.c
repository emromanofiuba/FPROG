/* PROBLEMA
Escribir un programa que solicite el ingreso de una serie de números. Por
cada número ingresado se deberá informar si el mismo es o no, un número
capicúa.
Se debe evaluar que lo ingresado, sea un número entero positivo, de lo
contrario, se debe enviar el mensaje “Número Inválido”, y solicitar el siguiente. El
ingreso de números, termina cuando el usuario ingresa el número cero.
*/

# include <stdio.h>
# include <stdbool.h>

int calculo_capicua(int numero_original)
{
    int numero_invertido, ultimo_digito;

    numero_invertido = 0;

    while ( numero_original > 0){
        ultimo_digito = numero_original % 10;
        numero_invertido = numero_invertido * 10 + ultimo_digito;
        numero_original = numero_original / 10;
    }

    return numero_invertido;
}

bool es_capicua(int numero_original)
{
    bool capicua = false;

    if (numero_original == calculo_capicua(numero_original))
        capicua = true;
    
    return capicua;
}

void main()
{
    int numero_original;

    printf("Ingrese un numero: ");
    scanf("%i", &numero_original);

    while(numero_original != 0){
        if (numero_original < 0){
            printf("Numero invalido. Ingrese el siguiente: ");
            scanf("%i", &numero_original);
        }
        else {
            printf("¿El numero %i es capicua?: %d\n", numero_original, es_capicua(numero_original));

            printf("\nIngrese otro numero: ");
            scanf("%i", &numero_original);
        }
    }
}