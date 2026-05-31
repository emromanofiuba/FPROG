# include <stdio.h>
# include <stdbool.h>
# include <string.h>
# define MAX_CHAR 50
# define LIMITE_ORACIONES 3
typedef char t_oracion[LIMITE_ORACIONES][MAX_CHAR];
typedef char t_subcadena[MAX_CHAR];

void cargar_oraciones(t_oracion oraciones)
{
    int i;
    for (i = 0; i < LIMITE_ORACIONES; i++){
        printf("Oracion %i", i+1);
        fgets(oraciones[i], MAX_CHAR, stdin);
        oraciones[i][strlen(oraciones[i]) - 1] = '\0';
    }
}

void oracion_mas_larga(t_oracion oraciones, t_oracion mas_larga)
{
    int i;
    mas_larga = oraciones[0];

    for (i = 1; i < LIMITE_ORACIONES; i++)
        if (strlen(oraciones[i]) > strlen(oraciones[i-1]))
            mas_larga = oraciones[i];
}

bool hay_dos_iguales(t_oracion oraciones)
{
    bool hay_iguales = false;
    int i = 1;

    while (i < LIMITE_ORACIONES && !hay_iguales){
        if (strcmp(oraciones[i], oraciones[i-1]) == 0)
            hay_iguales = true;
        i++;
    }

    return hay_iguales;
}

void ingreso_subcadena(t_subcadena subcadena)
{
    printf("Ingrese una subcadena (palabra o parte de una oracion): ");
    fgets(subcadena, MAX_CHAR, stdin);
    subcadena[strlen(subcadena) - 1] = '\0';
}

void donde_esta_subcadena(t_oracion oraciones, t_subcadena subcadena, bool *esta_subcadena)
{
    int i, j = 0;
    *esta_subcadena = false;

    for (i = 0; i < LIMITE_ORACIONES; i++)
        if (strstr(oraciones[i], subcadena) != NULL) {
            *esta_subcadena = true;
            printf("La subcadena (%s) esta en la oracion (%s)\n", subcadena, oraciones[i]);
        }
    if (*esta_subcadena == false)
        printf("La subcadena (%s) no se encuentra en ninguna oracion\n", subcadena);
}

void main() {
    t_oracion oraciones;
    t_oracion mas_larga;
    t_subcadena subcadena;
    bool esta_subcadena;

    cargar_oraciones(oraciones);
    
    printf("\n--ORACION MAS LARGA--\n");
    oracion_mas_larga(oraciones, mas_larga);
    printf("%s", mas_larga);

    printf("\n---HAY AL MENOS 2 ORACIONES IGUALES?---\n");
    printf("%d", hay_dos_iguales(oraciones));

    printf("\n--ESTA LA SUBCADENA EN ALGUNA ORACION. SI ES ASI, EN CUAL?---\n");
    donde_esta_subcadena(oraciones, subcadena, &esta_subcadena);
    
}