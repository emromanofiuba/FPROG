/*
Dados a y n números enteros, informar la potencia enésima de a por productos sucesivos.
*/

/*
DISEÑO DEL ALGORITMO
1. declarar variables a, n, i
2. solicitar al usuario el numero a
3. solicitar al usuario el numero n
4. iterar n - 1 veces la potenciacion, con base a
    4.1 multiplicar a x a
    4.2 imprimir por pantalla los n productos sucesivos de potencias de a
*/

# include <stdio.h>

int main()
{
    int a, n, contador_de_x, resultado_multiplicacion;

    printf("ingrese un numero entero a (base): ");
    scanf("%i", &a);
    
    printf("ingrese un numero entero n (exponente): ");
    scanf("%i", &n);


    if (n == 0)
        printf("%i^%i = 1\n", a, n);


    else {
        printf("%i^%i = ", a, n);

        for (contador_de_x = 1; contador_de_x <= n - 1; contador_de_x++) 
            printf("%i x ", a);
        printf("%i = ", a);
        
        resultado_multiplicacion = 1;

        for (contador_de_x = 1; contador_de_x <= n; contador_de_x++)
            resultado_multiplicacion *= a;
        printf("%i\n", resultado_multiplicacion);
    }

    return 0;
}