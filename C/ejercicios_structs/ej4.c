# include <stdio.h>
# define MAX 200
# define TAMANIO 10
typedef char t_descripcion[MAX];

typedef struct {
    int codigo;
    float cantidad_en_stock;
} t_stock;

typedef struct {
   int codigo;
   t_descripcion descripcion;
   float precio_unitario;
} t_producto;

typedef struct {
    int codigo;
    int cantidad_vendida_por_venta;
} t_venta;

typedef struct {
    t_stock stock;
    t_producto producto;
    t_venta venta;
}t_alimentos;

void cargar_tablas(t_stock stock[TAMANIO], t_venta ventas[TAMANIO],
                   t_producto productos[TAMANIO], int *ml)
{
    *ml = 0;

    printf("Codigo del producto %i (0 para terminar): ", *ml + 1);
    scanf("%i", &productos[*ml].codigo);

    while (*ml < TAMANIO && productos[*ml].codigo != 0) {
        stock[*ml].codigo = productos[*ml].codigo;
        ventas[*ml].codigo = productos[*ml].codigo;

        printf("Descripcion: ");
        scanf("%s", productos[*ml].descripcion);

        printf("Precio unitario: ");
        scanf("%f", &productos[*ml].precio_unitario);

        printf("Cantidad en stock: ");
        scanf("%f", &stock[*ml].cantidad_en_stock);

        printf("Cantidad vendida: ");
        scanf("%i", &ventas[*ml].cantidad_vendida_por_venta);

        (*ml)++;

        if (*ml < TAMANIO) {
            printf("\nCodigo del producto %i (0 para terminar): ", *ml + 1);
            scanf("%i", &productos[*ml].codigo);
        }
    }
}


void listar_por_pantalla (t_venta ventas[TAMANIO], t_producto productos[TAMANIO], int ml)
{
    int i;
    float monto_venta_prod, monto_total;
    monto_total = 0.0;

    for (i = 0; i < ml; i++) {
        monto_venta_prod = (float)ventas[i].cantidad_vendida_por_venta * productos[i].precio_unitario;
        monto_total += monto_venta_prod;

        printf("Cantidad vendida del producto %i: %i\n", i+1, ventas[i].cantidad_vendida_por_venta);
        printf("Monto vendido del producto %i: %.2f\n", i+1, monto_venta_prod);
    }
    printf("Monto total vendido: %.2f", monto_total);
}

void generar_lista_faltantes_y_eliminarlos (t_stock stock[TAMANIO], t_producto productos[TAMANIO], int *mlp, t_producto faltantes[TAMANIO], int *mlf)
{
    int i, destino;
    *mlf = destino = 0;
    for (i = 0; i < *mlp; i++) {
        if (stock[i].cantidad_en_stock == 0) {
            faltantes[*mlf] = productos[i];
            (*mlf)++;
        }
        else {
            productos[destino] = productos[i];
            stock[destino] = stock[i];
            destino++;
        }
    }
    *mlp = destino;
}

void mostrar_stock_actualizado(t_stock stock[TAMANIO], int ml)
{
    int i;
    printf("\n--STOCK ACTUALIZADO--\n");

    for (i = 0; i < ml; i++) {
        printf("Codigo: %i | Cantidad en stock: %i\n",
               stock[i].codigo, stock[i].cantidad_en_stock);
    }
}

int main(void)
{
    t_stock stock[TAMANIO];
    t_venta ventas[TAMANIO];
    t_producto productos[TAMANIO];
    t_producto faltantes[TAMANIO];
    int ml, mlf;

    cargar_tablas(stock, ventas, productos, &ml);
    listar_por_pantalla(ventas, productos, ml);
    generar_lista_faltantes_y_eliminarlos(stock, productos, &ml, faltantes, &mlf);
    mostrar_stock_actualizado(stock, ml);

    return 0;
}
