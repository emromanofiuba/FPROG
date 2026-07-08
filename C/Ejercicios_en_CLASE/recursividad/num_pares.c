# include <stdio.h>
//mostrar numeros pares entre 1 y x

void mostrar_pares(int x)
{    
    if (x >= 2) {
        if (x % 2 == 0) {
            printf("%i\n", x);
            mostrar_pares(x-2);
        }
        else 
            mostrar_pares(x-1);
    }
}

void main()
{
    mostrar_pares(100);
}