/* PROBLEMA
Escribir una función que dado un número entero, devuelva un valor booleano
que indique si dicho número es primo o no. 
*/

# include <stdio.h>
# include <stdbool.h>

bool es_primo(int num)
{
    int i;
    bool primo = true;

    for (i = 2; i <= num / 2 && primo; i++){
        if (num % i == 0)
            primo = false;
    }

    return primo;
}

void main()
{
    printf("¿El numero 22 es primo? ", es_primo(22));
}


