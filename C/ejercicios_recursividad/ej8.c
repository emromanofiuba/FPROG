#include <stdio.h>
#include <stdbool.h>

int pedir_entero()
{
    int num;
    printf("Ingrese un numero para ver si es capicua: ");
    scanf("%i", &num);

    return num;
}

bool es_capicua(int num, int num_org, int invertido)
{
    if (num == 0)
        return (invertido == num_org);
    else {
        invertido = invertido * 10 + (num % 10);
        return es_capicua(num / 10, num_org, invertido);
    }
}

int main(void) {

    int num;
    num = pedir_entero();
    printf("Es capicua: %i\n", es_capicua(num, num, 0));

    return 0;
}