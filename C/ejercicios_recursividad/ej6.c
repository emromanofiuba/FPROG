#include <stdio.h>

int pedir_entero()
{
    int num;
    printf("Ingrese un numero para invertir: ");
    scanf("%i", &num);

    return num;
}

int invertir(int num, int invertido)
{
    if (num == 0)
        return invertido;
    else {
        invertido = invertido * 10 + (num % 10);
        return invertir(num / 10, invertido);
    }
}

int main(void) {
    int num;
    num = pedir_entero();
    printf("\nNumero ingresado: %i\n", num);
    printf("Numero invertido: %i\n", invertir(num, 0));

    return 0;
}