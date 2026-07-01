#include <stdio.h>
#include <string.h>

#define MAX_PERSONAS 1000
#define LARGO_CAD 35

typedef struct {
    char apellido[LARGO_CAD];
    char nombre[LARGO_CAD];
} t_persona;

typedef t_persona t_tabla[MAX_PERSONAS];

int leer_tabla(FILE *entrada, t_tabla tabla)
{
    int ml;

    ml = 0;
    fread(&tabla[ml], sizeof(t_persona), 1, entrada);
    while (!feof(entrada) && ml < MAX_PERSONAS) {
        ml++;
        fread(&tabla[ml], sizeof(t_persona), 1, entrada);
    }

    return ml;
}

int comparar_personas(t_persona a, t_persona b)
{
    int cmp;

    cmp = strcmp(a.apellido, b.apellido);
    if (cmp == 0)
        cmp = strcmp(a.nombre, b.nombre);

    return cmp;
}

void ordenar_por_insercion(t_tabla tabla, int ml)
{
    int i;
    int j;
    t_persona aux;

    for (i = 1; i < ml; i++) {
        aux = tabla[i];
        j = i - 1;
        while (j >= 0 && comparar_personas(tabla[j], aux) > 0) {
            tabla[j + 1] = tabla[j];
            j--;
        }
        tabla[j + 1] = aux;
    }
}

void ordenar_por_seleccion(t_tabla tabla, int ml)
{
    int i, j, posicion_menor;
    t_persona aux;

    for (i = 0; i < ml - 1; i++) {
        posicion_menor = i;

        for (j = i + 1; j < ml; j++) 
            if (comparar_personas(tabla[j], tabla[posicion_menor]) < 0) 
                posicion_menor = j;

        aux = tabla[posicion_menor];
        tabla[posicion_menor] = tabla[i];
        tabla[i] = aux;
    }
}

void grabar_tabla(FILE *salida, t_tabla tabla, int ml)
{
    int i;

    for (i = 0; i < ml; i++)
        fwrite(&tabla[i], sizeof(t_persona), 1, salida);
}

int main(void)
{
    FILE *entrada;
    FILE *salida;
    t_tabla tabla;
    int ml;

    entrada = fopen("desordenado_alfa.dat", "rb");
    salida = fopen("ordenado_alfa.dat", "wb");

    if (entrada == NULL || salida == NULL)
        printf("Error: no se pudieron abrir ambos archivos.\n");
    else {
        ml = leer_tabla(entrada, tabla);
        ordenar_por_insercion(tabla, ml);
        grabar_tabla(salida, tabla, ml);
    }

    if (entrada != NULL)
        fclose(entrada);
    if (salida != NULL)
        fclose(salida);

    return 0;
}