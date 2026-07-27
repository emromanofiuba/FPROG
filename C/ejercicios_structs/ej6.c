#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CHAR        50
#define MAX_PASAJES     1000
#define MAX_LOCALIDADES 250

typedef char t_localidad[MAX_CHAR];

typedef struct {
    char categoria;       /* 'a', 'b', 'c', 'd' */
    int codigo_destino;   /* 1 a 250 */
} t_pasaje;

typedef struct {
    int codigo;
    t_localidad nombre;
} t_destino;

int buscar_localidad(t_destino destinos[MAX_LOCALIDADES], int ml, int codigo)
{
    int inicio, centro, fin, posicion;
    bool terminado;

    inicio = 0;
    fin = ml - 1;
    posicion = -1;
    terminado = false;

    while (!terminado && inicio <= fin) {
        centro = inicio + (fin - inicio) / 2;
        if (destinos[centro].codigo == codigo) {
            posicion = centro;
            terminado = true;
        }
        else if (codigo > destinos[centro].codigo)
            inicio = centro + 1;
        else
            fin = centro - 1;
    }

    return posicion;
}

void ordenar_por_localidad_categoria(t_pasaje pasajes[MAX_PASAJES], int ml)
{
    int i, j, pos_menor;
    t_pasaje aux;

    for (i = 0; i < ml - 1; i++) {
        pos_menor = i;
        for (j = i + 1; j < ml; j++)
            if (pasajes[j].codigo_destino < pasajes[pos_menor].codigo_destino ||
               (pasajes[j].codigo_destino == pasajes[pos_menor].codigo_destino &&
                pasajes[j].categoria < pasajes[pos_menor].categoria))
                pos_menor = j;
        aux = pasajes[i];
        pasajes[i] = pasajes[pos_menor];
        pasajes[pos_menor] = aux;
    }
}

void ordenar_por_categoria(t_pasaje pasajes[MAX_PASAJES], int ml)
{
    int i, j, pos_menor;
    t_pasaje aux;

    for (i = 0; i < ml - 1; i++) {
        pos_menor = i;
        for (j = i + 1; j < ml; j++)
            if (pasajes[j].categoria < pasajes[pos_menor].categoria)
                pos_menor = j;
        aux = pasajes[i];
        pasajes[i] = pasajes[pos_menor];
        pasajes[pos_menor] = aux;
    }
}

void informar_pasajeros_loc_cat(t_pasaje pasajes[MAX_PASAJES], int ml_p, t_destino destinos[MAX_LOCALIDADES], int ml_d)
{
    int i, cantidad, codigo_actual, pos;
    char categoria_actual;

    cantidad = 0;
    codigo_actual = -1;   
    categoria_actual = '0';

    for (i = 0; i < ml_p; i++) {
        if (pasajes[i].codigo_destino != codigo_actual ||
            pasajes[i].categoria != categoria_actual) {
            if (cantidad > 0) {
                pos = buscar_localidad(destinos, ml_d, codigo_actual);
                printf("Localidad %s, categoria %c: %i pasajeros\n", destinos[pos].nombre, categoria_actual, cantidad);
            }
            codigo_actual = pasajes[i].codigo_destino;
            categoria_actual = pasajes[i].categoria;
            cantidad = 0;
        }
        cantidad++;
    }
    if (cantidad > 0) {
        pos = buscar_localidad(destinos, ml_d, codigo_actual);
        printf("Localidad %s, categoria %c: %i pasajeros\n", destinos[pos].nombre, categoria_actual, cantidad);
    }
}


void informar_pasajeros_loc(t_pasaje pasajes[MAX_PASAJES], int ml_p, t_destino destinos[MAX_LOCALIDADES], int ml_d)
{
    int i, cantidad, codigo_actual, pos;

    cantidad = 0;
    codigo_actual = -1;

    for (i = 0; i < ml_p; i++) {
        if (pasajes[i].codigo_destino != codigo_actual) {
            if (cantidad > 0) {
                pos = buscar_localidad(destinos, ml_d, codigo_actual);
                printf("Localidad %s: %i pasajeros\n",
                       destinos[pos].nombre, cantidad);
            }
            codigo_actual = pasajes[i].codigo_destino;
            cantidad = 0;
        }
        cantidad++;
    }
    if (cantidad > 0) {
        pos = buscar_localidad(destinos, ml_d, codigo_actual);
        printf("Localidad %s: %i pasajeros\n", destinos[pos].nombre, cantidad);
    }
}


void informar_pasajeros_cat(t_pasaje pasajes[MAX_PASAJES], int ml)
{
    int i, cantidad;
    char categoria_actual;

    cantidad = 0;
    categoria_actual = '0';

    for (i = 0; i < ml; i++) {
        if (pasajes[i].categoria != categoria_actual) {
            if (cantidad > 0)
                printf("Categoria %c: %i pasajeros\n", categoria_actual, cantidad);
            categoria_actual = pasajes[i].categoria;
            cantidad = 0;
        }
        cantidad++;
    }
    if (cantidad > 0)
        printf("Categoria %c: %i pasajeros\n", categoria_actual, cantidad);
}


int localidad_mas_pasajeros(t_pasaje pasajes[MAX_PASAJES], int ml)
{
    int i, cantidad, max_cantidad, codigo_actual, codigo_ganador;

    cantidad = 0;
    max_cantidad = 0;
    codigo_actual = -1;
    codigo_ganador = -1;

    for (i = 0; i < ml; i++) {
        if (pasajes[i].codigo_destino != codigo_actual) {
            if (cantidad > max_cantidad) {
                max_cantidad = cantidad;
                codigo_ganador = codigo_actual;
            }
            codigo_actual = pasajes[i].codigo_destino;
            cantidad = 0;
        }
        cantidad++;
    }
    if (cantidad > max_cantidad) {
        max_cantidad = cantidad;
        codigo_ganador = codigo_actual;
    }

    return codigo_ganador;
}


void informar_localidad_mas_pasajeros(t_pasaje pasajes[MAX_PASAJES], int ml_p, t_destino destinos[MAX_LOCALIDADES], int ml_d)
{
    int codigo, pos;

    codigo = localidad_mas_pasajeros(pasajes, ml_p);
    if (codigo == -1)
        printf("No hay pasajes registrados.\n");
    else {
        pos = buscar_localidad(destinos, ml_d, codigo);
        printf("Localidad con MAS pasajeros: %s\n", destinos[pos].nombre);
    }
}

int main()
{
    t_pasaje pasajes[MAX_PASAJES];
    t_destino destinos[MAX_LOCALIDADES];
    int ml_pasajes, ml_destinos;

    cargar_destinos(destinos, &ml_destinos);
    cargar_pasajes(pasajes, &ml_pasajes);

    ordenar_por_localidad_categoria(pasajes, ml_pasajes);

    printf("\n--- a) Pasajeros por localidad y categoria ---\n");
    informar_pasajeros_loc_cat(pasajes, ml_pasajes, destinos, ml_destinos);

    printf("\n--- b) Pasajeros por localidad ---\n");
    informar_pasajeros_loc(pasajes, ml_pasajes, destinos, ml_destinos);

    printf("\n--- d) Localidad con mas pasajeros ---\n");
    informar_localidad_mas_pasajeros(pasajes, ml_pasajes, destinos, ml_destinos);

    ordenar_por_categoria(pasajes, ml_pasajes);

    printf("\n--- c) Pasajeros por categoria ---\n");
    informar_pasajeros_cat(pasajes, ml_pasajes);

    return 0;
}