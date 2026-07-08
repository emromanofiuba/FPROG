# include <stdio.h>
# include <stdbool.h>
# include <string.h>
# define MAX_CHAR 21
# define LIMITE_PAL 10
typedef char t_palabras[LIMITE_PAL][MAX_CHAR];
typedef char t_palabra[MAX_CHAR];

void cargar_palabras(t_palabras palabras, int *ml)
{
    char ingreso;
    *ml = 0;
    
    printf("Desea ingresar una palabra? (s/n): ");
    scanf(" %c", &ingreso);
    //while (getchar() != '\n');

    while (*ml < LIMITE_PAL && ingreso == 's') {
        printf("Ingrese una palabra: ");
        fgets(palabras[*ml], MAX_CHAR, stdin);
        palabras[*ml][strcspn(palabras[*ml], "\n")] = '\0';

        printf("\nDesea ingresar otra palabra? (s/n): ");
        scanf(" %c", &ingreso);
        (*ml)++;
    }
}

void ordenar_palabras(t_palabras palabras, int ml)
{
    int i, j;
    t_palabra aux;
    bool hubo_intercambio;

    hubo_intercambio = true;
    i = 1;

   while (i < ml && hubo_intercambio) {
        hubo_intercambio = false;

        for (j = 0; j < ml - i; j++)
            if (strcmp(palabras[j+1], palabras[j]) < 0) {
                strcpy(aux, palabras[j]);
                strcpy(palabras[j], palabras[j+1]);
                strcpy(palabras[j+1], aux);
                hubo_intercambio = true;
            }
        i++;
    }
}

void mostrar_palabras_ordenadas(t_palabras palabras, int ml)
{
    for (int i = 0; i < ml; i++)
        printf("palabras: %s\n", palabras[i]);
}

void main()
{
    t_palabras palabras;
    int ml;

    cargar_palabras(palabras, &ml);

    ordenar_palabras(palabras, ml);

    printf("\n---PALABRAS ORDENADAS ALFABETICAMENTE---\n");
    mostrar_palabras_ordenadas(palabras, ml);
}
