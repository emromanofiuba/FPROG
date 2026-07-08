#include <stdio.h>

int pedir_entero()
{
    int num;
    printf("Ingrese un numero: ");
    scanf("%i", &num);

    return num;
}

void mostrar_n_naturales(int n)
{
    if (n > 0) {
        mostrar_n_naturales(n - 1);
        printf(" %i", n);
    }
}

int main(void) {
    int num;
    num = pedir_entero();
    mostrar_n_naturales(num);

    return 0;
}