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

bool validar_clave(char cadena[])
{
    int cantidad_pares, cantidad_impares, i;
    bool es_valido;
    cantidad_pares = cantidad_impares = i = 0;
    es_valido = true;

    while ((cadena[i] != '\0') && (es_valido)) {
        if (strlen(cadena) >= 6 && strlen(cadena) <= 12) {
            if ((cadena[i] >= '0') && (cadena[i] <= '9')) {
                if (cadena[i] % 2 == 0) 
                    cantidad_pares++;
                else 
                    cantidad_impares++;
            }
            else 
                es_valido = false;
        }
        else 
            es_valido = false;
        i++;
    }

    if (cantidad_pares <= cantidad_impares)
        es_valido = false;
    
    return es_valido;
}

void main()
{
    char cadena[15];
    ingreso_cadena(cadena, 15);

    bool es_valida = validar_clave(cadena);
    printf("¿La cadena (%s) es valida? %d\n", cadena, es_valida);
}