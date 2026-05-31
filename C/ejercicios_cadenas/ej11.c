/*
posible variante: pedir un menu en el main en el que 
si presiona 1, haga tal cosa, presiona 2, tal otra, etc..

otra:
si esta ordenada la tabla, pedir los libros mas caros, los que menos se venden (los que mas stock tienen), etc...
*/

# include <stdio.h>
# include <stdbool.h>
# include <string.h>
# define MAX_CHAR 9
# define LIMITE_PAL 9
typedef char t_palabras[LIMITE_PAL][MAX_CHAR];
typedef char t_palabra[MAX_CHAR];

void cargar_palabras(t_palabras palabras, int *ml)
{
    char ingreso;
    *ml = 0;
    
    printf("Desea ingresar una palabra? (s/n): ");
    scanf(" %c", &ingreso);
    while (getchar() != '\n');

    while (*ml < LIMITE_PAL && ingreso == 's') {
        printf("Ingrese una palabra: ");
        fgets(palabras[*ml], MAX_CHAR, stdin);
        palabras[*ml][strlen(palabras[*ml]) - 1] = '\0';

        printf("Desea ingresar otra palabra? (s/n): ");
        scanf(" %c", &ingreso);
        while (getchar() != '\n');
        (*ml)++;
    }
}

void mostrar_palabras(t_palabras palabras, int ml)
{
    for (int i = 0; i < ml; i++)
        printf("palabras: %s\n", palabras[i]);
}

void palabra_mas_larga(t_palabras palabras, int ml, t_palabra mas_larga)
{
    int i;
    strcpy(mas_larga, palabras[0]);

    for (i = 1; i < ml; i++) {
        if (strlen(palabras[i]) > mas_larga)
            mas_larga = palabras[i];
    }
}

void pedir_palabra(t_palabra palabra)
{
    printf("\nQue palabra desea buscar: ");
    fgets(palabra, MAX_CHAR, stdin);
    palabra[strlen(palabra) - 1] = '\0';
}

void ordenar_palabras(t_palabras palabras, int ml)
{
    int i, j, posicion_menor;
    t_palabra aux;

    for (i = 0; i < ml-1; i++) {
        posicion_menor = i;
        for (j = i+1; j < ml; j++)
            if (strcmp(palabras[j], palabras[posicion_menor]) < 0)
                posicion_menor = j;

        strcpy(aux, palabras[posicion_menor]);
        strcpy(palabras[posicion_menor], palabras[i]);
        strcpy(palabras[i], aux);
    }
}

bool buscar_palabra(t_palabras palabras, int ml, t_palabra palabra)
{
    int inicio, fin, centro;
    bool encontrado;

    inicio = 0;
    fin = ml - 1;
    encontrado = false;

    while (!encontrado) {
        centro = inicio + ((fin - inicio) / 2);
        if (strcmp(palabras[centro], palabra) == 0)
            encontrado = true;
        else 
            if (strcmp(palabra, palabras[centro]) < 0) {
                fin = centro - 1;
            }
            else {
                inicio = centro + 1;
            }
    }

    return encontrado;
}


void main()
{
    t_palabras palabras;
    t_palabra palabra, mas_larga;
    int ml, posicion_palabra;

    cargar_palabras(palabras, &ml);
    
    mostrar_palabras(palabras, ml);

    palabra_mas_larga(palabras, ml, mas_larga);

    ordenar_palabras(palabras, ml);

    pedir_palabra(palabra);

}
