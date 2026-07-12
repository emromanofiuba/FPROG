#include <stdio.h>

int pedir_entero()
{
    int num;
    printf("Ingrese un numero: ");
    scanf("%i", &num);

    return num;
}

int sumar_digitos(int num)
{
    if (num == 0)
        return 0;
    else {
        return num % 10 + sumar_digitos(num / 10);
    }
}

int main(void) {
    int num;
    num = pedir_entero();
    printf("\nNumero ingresado: %i\n", num);
    printf("Suma de sus digitos: %i\n", sumar_digitos(num));

    return 0;
}