#include <stdio.h>

int division(int dividendo, int divisor)
{
    if (divisor > dividendo)
        return 0;
    return 1 + division(dividendo - divisor, divisor);
}

int dividir(int dividendo, int divisor)
{
    int signo = 1;
    if (dividendo < 0) {
        signo = -signo;
        dividendo = -dividendo;
    }
    if (divisor < 0) {
        signo = -signo;
        divisor = -divisor;
    }
    return signo * division(dividendo, divisor);
}

int main() {
    printf("%i\n", dividir(0, -4));

    return 0;
}