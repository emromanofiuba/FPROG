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

void cerrar_camion(FILE *datos_viaje, int cant_viajes, float peso_total, int max_viajes, t_patente patente, t_patente mas_viajera)
{
  fwrite(patente, sizeof(t_patente), 1, datos_viaje);
  fwrite(&peso_total, sizeof(float), 1, datos_viaje);

  if (cant_viajes > max_viajes) {
    max_viajes = cant_viajes;
    mas_viajera = patente;
  }
}

void procesar_camion(FILE *viajes, FILE *datos_viaje)
{
    t_viaje viaje;
    t_patente patente_actual, patente_mas_viajera;
    float peso_total;
    int cant_viajes, max_viajes;

    strcpy(patente_actual, "0");
    peso_total = 0.0;
    cant_viajes = max_viajes = 0;

    fread(&viaje, sizeof(t_viaje), 1, viajes);
    while (!feof(viajes)) {
        if (strcmp(viaje.patente, patente_actual) != 0) {
            if (peso_total > 0) {
                cerrar_camion(datos_viaje, cant_viajes, max_viajes, peso_total, patente_actual, patente_mas_viajera);
            }
            strcpy(patente_actual, viaje.patente); //RECIBO
            peso_total = 0.0;
            cant_viajes = 0;
        }
        peso_total += viaje.peso;
        cant_viajes++;

        fread(&viaje, sizeof(t_viaje), 1, viajes);
    }
    if (peso_total > 0) 
        cerrar_camion(datos_viaje, cant_viajes, max_viajes, peso_total, patente_actual, patente_mas_viajera);
}

