#include <stdio.h>
#include <stdbool.h>
#define MAX_PASAJES 1000
#define MAX_DESTINOS 251
#define MAX_CAT 4
typedef int t_matriz[MAX_DESTINOS][MAX_CAT];

typedef struct {
    char categoria;
    int destino;
} t_pasaje;

typedef struct {
    int destino;
    char localidad[30];
}t_localidad;


void cantidad_pasajeros_loc_cat(t_matriz cantidad, t_pasaje pasajes[MAX_PASAJES], int ml)
{
    int i;
    for (i = 0; i < ml; i++)
        cantidad[pasajes[i].destino][pasajes[i].categoria - 'a']++;
}

void cantidad_pasajeros_loc(t_matriz cantidad, int total_loc[MAX_DESTINOS])
{
    int i, j, suma;
    for (i = 1; i < MAX_DESTINOS - 1; i++) {
        suma = 0;
        for (j = 0; j < MAX_CAT; j++)
            suma += cantidad[i][j]; 
        total_loc[i] = suma;
        printf("Destino %i: %i", i+1, suma);
        }
}

void cantidad_pasajeros_cat(t_matriz cantidad, int total_cat[MAX_CAT])
{
    int i, j, suma;
    for (j = 0; j < MAX_CAT; j++) {
        suma = 0;
        for (i = 0; i < MAX_DESTINOS; i++) 
            suma += cantidad[i][j];
        total_cat[j] = suma;
        printf("Categoria: %i", suma);
    }
}

int mayor_localidad(t_localidad localidades[MAX_DESTINOS], int total_loc[MAX_DESTINOS])
{
    int i, mayor_loc, codigo;
    mayor_loc = 0;

    for (i = 1; i < MAX_DESTINOS; i++) {
        if (total_loc[i] > mayor_loc) {
            mayor_loc = total_loc[i];
            codigo = i;
            }
    }
    return codigo;
}

int buscar_codigo(t_localidad localidades[MAX_DESTINOS], int ml, int codigo)
{
    int inf, mit, sup, pos;
    bool terminado;
    inf = 0;
    sup = ml - 1;
    pos = -1;
    terminado = false;

    while (!terminado) {
        if (codigo < localidades[inf].destino || codigo > localidades[sup].destino)
            terminado = true;
        else {
            mit = inf + ((sup - inf) / 2);
            if (codigo == localidades[mit].destino) {
                pos = mit;
                terminado = true;
            }
            else if (codigo < localidades[mit].destino)
                sup = mit - 1;
            else 
                inf = mit + 1;
        }
    }
    return pos;
}

void informar_localidad_mayor(t_localidad localidades[MAX_DESTINOS], int ml, int codigo)
{
    int pos;
    pos = buscar_codigo(localidades, ml, codigo);
    if (pos == -1)
        printf("No se encuentra el nombre de la localidad con dicho codigo\n");
    else {
        printf("Nombre: %s", localidades[pos].localidad);
    }
}



