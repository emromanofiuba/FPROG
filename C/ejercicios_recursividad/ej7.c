#include <stdio.h>

int pedir_n()
{
    int num;
    printf("Ingrese un numero n: ");
    scanf("%i", &num);

    return num;
}

int suma_n_naturales(int num)
{
    
    if (num == 0)
        return 0;
    else 
        return num + suma_n_naturales(num - 1);
}

int main(void) {
    int num;
    num = pedir_n();
    printf("\nSuma primeros N naturales: %i\n", suma_n_naturales(num));

    return 0;
}

