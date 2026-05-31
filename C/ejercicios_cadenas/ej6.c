# include <stdio.h>
# include <stdbool.h>
# include <string.h>

void ingreso_cadena(char cadena[], int tamanio)
{
    int longitud;

    printf("Ingrese una cadena: ");
    fgets(cadena, tamanio, stdin);

    longitud = strlen(cadena);

    if (longitud > 0 && cadena[longitud - 1] == '\n')
        cadena[longitud - 1] = '\0';
}

bool es_cadena_numerica (char cadena[])
{
    int i = 0;
    bool es_numerica = true;

   while (cadena[i] != '\0' && es_numerica) {
        if (strlen(cadena) >= 4 && strlen(cadena) <= 8) {  
            if ((cadena[i] >= '0') && (cadena[i] <= '9'))
                i++;
            else 
                es_numerica = false;
        }
        else
            es_numerica = false;
    }

    return es_numerica;
}

bool validar_clave(char cadena[])
{
    int i;
    char numero_ant, numero_pos;
    bool es_valido;

    i = 0;
    es_valido = false;

    if (es_cadena_numerica(cadena))
        while ((cadena[i+1] != '\0') && (!es_valido)) {
            if (cadena[i] != cadena[i+1]) 
                es_valido = true;
            i++;
        }
    
    return es_valido;
}

void main()
{
    char cadena[15];
    ingreso_cadena(cadena, 15);

    bool es_valida = validar_clave(cadena);
    printf("¿La cadena (%s) es valida? %d\n", cadena, es_valida);
}