# include <stdio.h>
# include <string.h>
# include <stdbool.h>
# define TAMANIO 100
typedef struct 
{
    int codigo;
    char titulo[20];
    char autor[15];
    int stock;
    float precio;
} t_libros;

typedef struct 
{
    int codigo;
    int stock;
    char titulo[20];
} t_pedidos;

void cargar_libros(t_libros libros[TAMANIO], int *ml) {
    *ml = 0;

    printf("Codigo del %i libro, 0 para salir: ", *ml+1);
    scanf("%i", &libros[*ml].codigo);

    while (*ml < TAMANIO && libros[*ml].codigo != 0) {
        printf("Titulo: ");
        scanf(" ");
        fgets(libros[*ml].titulo, 20, stdin);
        libros[*ml].titulo[strcspn(libros[*ml].titulo, "\n")] = '\0';

        printf("Autor: ");
        scanf(" ");
        fgets(libros[*ml].autor, 15, stdin);
        libros[*ml].autor[strcspn(libros[*ml].autor, "\n")] = '\0';

        printf("Stock: ");
        scanf("%i", &libros[*ml].stock);

        printf("Precio: ");
        scanf("%f", &libros[*ml].precio);

        (*ml)++;


        printf("\nCodigo del %i° libro, o para salir: ", *ml+1);
        scanf("%i", &libros[*ml].codigo);
    }
}

void mostrar_libro(t_libros libro) {
   printf("Codigo: %i | Titulo: %s | Autor: %s | Stock: %i | Precio: %.2f",
    libro.codigo, libro.titulo, libro.autor, libro.stock, libro.precio);
}

void agregar_pedido(t_libros libros[TAMANIO], int ml, t_pedidos pedidos[TAMANIO], int *mlp)
{   
    int i;
    *mlp = 0;

    for (i=0; i < ml; i++)
        if (libros[i].stock < 5) {
            pedidos[*mlp].codigo = libros[i].codigo;
            pedidos[*mlp].stock = libros[i].stock;
            strcpy(pedidos[*mlp].titulo, libros[i].titulo);
            (*mlp)++;
        }

}

void ordenar_por_codigo(t_libros libros[TAMANIO], int ml)
{
    int i, j;
    t_libros aux;
    bool hubo_intercambio = true;
    i = 0;

    while (i <= ml && hubo_intercambio) {
        hubo_intercambio = false;
        for (j = 0; j < ml - i; j++)
            if (libros[i].codigo > libros[i+1].codigo) {
                aux = libros[i];
                libros[i] = libros[i+1];
                libros[i+1] = aux;
                hubo_intercambio = true;
            }
        i++;
    }
}

void main()
{
    t_libros libros[TAMANIO];
    t_pedidos pedidos[TAMANIO];
    int ml;
    cargar_libros(libros, &ml);

    ordenar_por_codigo(libros, ml);
}