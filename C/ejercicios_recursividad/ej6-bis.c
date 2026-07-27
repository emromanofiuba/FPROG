#include <stdio.h>

int invertir(int num, int invertido)
{
    if (num == 0)
        return invertido;
    return invertir(num / 10, invertido * 10 + num % 10);
}

int main() {
    printf("%i\n", invertir(123, 0));
}