# include <stdio.h>
# include <stdbool.h>
# include <string.h>
# define MAX_CHAR 51
# define LIMITE_ORACIONES 3
typedef char t_oraciones[LIMITE_ORACIONES][MAX_CHAR];
typedef char t_oracion[MAX_CHAR];
typedef char t_subcadena[MAX_CHAR];

void cargar_oraciones(t_oraciones oraciones)
{
    int i;
    for (i = 0; i < LIMITE_ORACIONES; i++){
        printf("Oracion %i: ", i+1);
        fgets(oraciones[i], MAX_CHAR, stdin);
        oraciones[i][strlen(oraciones[i]) - 1] = '\0';
    }
}

void oracion_mas_larga(t_oraciones oraciones, t_subcadena mas_larga)
{
    int i;
    strcpy(mas_larga, oraciones[0]);

    for (i = 1; i < LIMITE_ORACIONES; i++)
        if (strlen(oraciones[i]) > strlen(mas_larga))
            strcpy(mas_larga, oraciones[i]);
}

bool hay_dos_iguales(t_oraciones oraciones)
{
    bool hay_iguales = false;
    int i, j;
    while (i < LIMITE_ORACIONES - 1 && !hay_iguales) {
        j = i + 1;
        while(j < LIMITE_ORACIONES && !hay_iguales) {
            if (strcmp(oraciones[i], oraciones[j]) == 0)
                hay_iguales = true;
            j++;
        }
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

bool esta_subcadena(t_oracion oracion, t_subcadena subcadena)
{
    return (strstr(oracion, subcadena) != NULL);
}

void informar_estado_subcadena(t_oraciones oraciones, t_subcadena subcadena)
{
    int i;
    for (i = 0; i < LIMITE_ORACIONES; i++) {
        if (esta_subcadena(oraciones[i], subcadena))
            printf("\nLa subcadena ('%s') esta en la oracion ('%s\n')", subcadena, oraciones[i]);
        else 
            printf("La subcadena no se encuentra en la oracion");
    }

}

void main() {
    t_oraciones oraciones;
    t_oracion mas_larga;
    t_subcadena subcadena;
    bool esta_subcadena;

    cargar_oraciones(oraciones);
    
    printf("\n--ORACION MAS LARGA--\n");
    oracion_mas_larga(oraciones, mas_larga);
    printf("%s", mas_larga);

    printf("\n---HAY AL MENOS 2 ORACIONES IGUALES?---\n");
    printf("%d\n", hay_dos_iguales(oraciones));

    ingreso_subcadena(subcadena);
    printf("\n--ESTA LA SUBCADENA EN ALGUNA ORACION. SI ES ASI, EN CUALES?---\n");
    informar_estado_subcadena(oraciones, subcadena);
    
}