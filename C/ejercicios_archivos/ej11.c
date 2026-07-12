#include <stdio.h>
#include <string.h>
#define MAX 20
typedef char t_patente[11];

typedef struct {
    t_patente patente;
    char destino[31];
    float costo;
    float peso;
}t_viaje;

int viajes_cordoba(FILE *viajes)
{
    t_viaje viaje;
    int cantidad;
    cantidad = 0;

    fread(&viaje, sizeof(t_viaje), 1, viajes);
    while(!feof(viajes)) {
        if (strcmp(viaje.destino, "Cordoba") == 0)
            cantidad++;
        fread(&viaje, sizeof(t_viaje), 1, viajes);
    }

    return cantidad;
}

t_viaje camion_mas_viajero(FILE *viajes)
{
    t_viaje viaje;
    t_viaje mas_viajero;
    t_viaje grupo_actual;
    int cant_viajes;
    int max_viajes;

    cant_viajes = 0;
    max_viajes = 0;

    fread(&viaje, sizeof(t_viaje), 1, viajes);
    mas_viajero = viaje;
    grupo_actual = viaje;

    while (!feof(viajes)) {
        if (strcmp(viaje.patente, grupo_actual.patente)!= 0) {
            if (cant_viajes > max_viajes) {
                max_viajes = cant_viajes; //SE DESPIDE AL QUE SE VA
                mas_viajero = grupo_actual;
            }
            grupo_actual = viaje;  //SE SALUDA AL QUE LLEGA
            cant_viajes = 0;
        }
        cant_viajes++;
        fread(&viaje, sizeof(t_viaje), 1, viajes);
    }
    if (cant_viajes > max_viajes) {
            max_viajes = cant_viajes;
            mas_viajero = grupo_actual;
    }

    return mas_viajero;
}

void grabar_datos(FILE *viajes, FILE *datos_viaje)
{
    t_viaje viaje;
    t_patente patente_actual;
    float peso_total;
    strcpy(patente_actual, "-1");
    peso_total = 0.0;

    fread(&viaje, sizeof(t_viaje), 1, viajes);
    while (!feof(viajes)) {
        if (strcmp(viaje.patente, patente_actual) != 0) {
            if (peso_total > 0) {
                fwrite(patente_actual, sizeof(t_patente), 1, datos_viaje); //DESPIDO
                fwrite(&peso_total, sizeof(float), 1, datos_viaje);
            }
            strcpy(patente_actual, viaje.patente); //RECIBO
            peso_total = 0.0;
        }
        peso_total += viaje.peso;
        fread(&viaje, sizeof(t_viaje), 1, viajes);
    }
    fwrite(patente_actual, sizeof(t_patente), 1, datos_viaje);
    fwrite(&peso_total, sizeof(float), 1, datos_viaje);
}

