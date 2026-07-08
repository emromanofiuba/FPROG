#include <stdio.h>
#include <stdbool.h>

int pedir_entero()
{
    int num;
    printf("Ingrese un numero: ");
    scanf("%i", &num);

    return num;
}

bool es_binario(int num)
{
    if (num % 10 != 0 && num % 10 != 1)
        return false;
    if (num == 0)
        return true;
    return es_binario(num / 10);
}

int main() {
    int num;
    num = pedir_entero();
    printf("%i es binario: %d\n", num, es_binario(num));
}
