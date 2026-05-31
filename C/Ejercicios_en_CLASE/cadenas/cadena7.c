//Idem ej6 pero buscar una palabra dentro del vector palabras
//busqueda binaria o busqueda lineal...

# include <stdio.h>
# include <stdbool.h>
# include <string.h>
# define MAX_CHAR 7
# define LIMITE_PAL 5
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

void pedir_palabra(t_palabra palabra)
{
    printf("\nQue palabra desea buscar: ");
    fgets(palabra, MAX_CHAR, stdin);
    palabra[strlen(palabra) - 1] = '\0';
}

int buscar_palabra(t_palabras palabras, int ml, t_palabra palabra)
{
    int i = 0;
    int posicion_palabra = -1;

    while (i < ml && strcmp(palabras[i], palabra) != 0)
        i++;
    if (i < ml)
        posicion_palabra = i;
    
    return posicion_palabra;
}



void main()
{
    t_palabras palabras;
    t_palabra palabra;
    int ml, posicion_palabra;

    cargar_palabras(palabras, &ml);

    pedir_palabra(palabra);

    posicion_palabra = buscar_palabra(palabras, ml, palabra);
    if (posicion_palabra == -1)
        printf("No se encontro tu palabra\n");
    else 
        printf("Tu palabra se encontro y esta en la posicion %i\n", posicion_palabra);
}
