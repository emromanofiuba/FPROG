# include <stdio.h>
# include <stdbool.h>

void main()
{
    short num, i;
    bool es_primo;

    printf("Ingrese un numero: ");
    scanf("%hd", &num);

    es_primo = true;

    for (i = 2; i <= num / 2; i++){
        if (num % i == 0)
            es_primo = false;
    }
    
    if (es_primo)
        printf("El numero %hd es primo\n", num);
    else
        printf("El numero %hd no es primo\n", num);
}