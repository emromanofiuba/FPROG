# include <stdio.h>
# include <stdbool.h>

int ingreso_numero()
{
    int num;
    printf("Ingrese un numero, 0 para terminar: ");
    scanf("%i", &num);

    return num;
}

int solicitar_limite_primos()
{
    int n;
    printf("Ingrese un numero limite de primos: ");
    scanf("%i", &n);

    return n;
}

bool es_primo(int num)
{
    bool primo = true;
    int i = 2;

    if (num < 2)
        primo = false; 
    else
        while (i <= num / 2 && primo) {
            if (num % i == 0)
                primo = false;
            i++;
        }

    return primo;
}

void main()
{
    int cant_primos_tot, contador_primos, suma, num;

    cant_primos_tot = solicitar_limite_primos();
    contador_primos = suma = 0;
    num = ingreso_numero();

    while (contador_primos < cant_primos_tot && num != 0) {
        if (es_primo(num)) {
            printf("%i -> es primo\n", num);
            suma += num;
            contador_primos++;
        }
        num = ingreso_numero();
    }

    printf("La suma de los primeros %i numeros primos es %i\n", cant_primos_tot, suma);
}