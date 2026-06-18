# include <stdio.h>

//Mostrar de a uno los dígitos impares de un Número

void mostrar_digitos_impares(int num)
{
    if (num > 9 ) {
        if((num % 10)% 2 != 0) 
            printf("%i", num % 10);
        mostrar_digitos_impares(num / 10);
    }
    else 
        if (num % 2 != 0)
            printf("%i", num);
    
}