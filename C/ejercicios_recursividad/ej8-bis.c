#include <stdio.h>
#include <stdbool.h>

int divisor_extremo(int num) //PARA EXTRAER EL DIGITO IZQUIERDO
{
    int divisor;
    divisor = 1;

    while (divisor <= num)
        divisor *= 10;
    
    return divisor / 10;
}

bool es_capicua(int num, int divisor) //RECORRO Y EVALUO LOS DIGITOS DE IZQUIERDA A DERECHA (EL CENTRO = CENTRO)
{
    if (num < 10)
        return true;
    if (num % 10 != num / divisor)
        return false;
    else {
        return es_capicua((num % divisor) / 10, divisor / 100);
    }
}

int main(void) {
    int divisor;
    divisor = divisor_extremo(4454);

    printf("es capicua: %d\n", es_capicua(4454, divisor));
}