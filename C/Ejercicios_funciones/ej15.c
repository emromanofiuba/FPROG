/* PROBLEMA
Diseñar un algoritmo que calcule la aproximación del seno:
sen(x)= x - (x^3)/3! + (x^5)/5! - (x^7)/7! + ..........
*/

# include <stdio.h>
# define CANT_TERMINOS 10

double potenciacion(double base, int exp)
{
    int i;
    double resultado_potencia = 1;

    if (exp >= 0){
        for (i = 1; i <= exp; i++)
            resultado_potencia *= base;
    }
    else {
        for (i = -1; i >= exp; i--)
            resultado_potencia *= (double)1 / base;
    }

    return resultado_potencia;
}

long long calcular_factorial (int numero)
{
    int i;
    long long factorial, resultado;
    factorial = 1;
     
    if (numero < 0)
        resultado = 0;
    else {
        for (i = 1; i <= numero; i++)
            factorial *= i;

        resultado = factorial;
    }

    return resultado;
}

double aproximacion_seno(double x)
{
    int exp, factorial, terminos;
    double suma_terminos, signo;

    suma_terminos = 0;
    factorial = 1;
    exp = 1;
    signo = 1.0;

    for (terminos = 1; terminos <= CANT_TERMINOS; terminos++){
            suma_terminos += signo * (potenciacion(x, exp) / calcular_factorial(factorial));
            signo *= -1.0;
            exp+=2;
            factorial+=2;
        }
    
    return suma_terminos;
}

   
void main()
{
    double x;

    printf("Ingrese un valor de x para aproximar al seno: ");
    scanf("%lf", &x);

    printf("\nsen(%.3lf) = %lf\n", x, aproximacion_seno(x));
}

