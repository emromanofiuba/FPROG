# include <stdio.h>
# include <string.h>
# define BYTES 20
typedef char t_cadena[BYTES];

void invertir_cadena(t_cadena cadena_org, t_cadena cadena_inv)
{
    int i, j = 0;
    int len = strlen(cadena_org);

    for (i = len - 1; i >= 0; i--)
        if (cadena_org[i] != ' ') {
            cadena_inv[j] = cadena_org[i];
            j++;
        }
    cadena_inv[j] = '\0';
}

void main()
{
    t_cadena cadena_org = "capicua";
    t_cadena cadena_inv;

    invertir_cadena(cadena_org, cadena_inv);

    printf("Cadena original: %s | Cadena invertida: %s\n", cadena_org, cadena_inv);
}