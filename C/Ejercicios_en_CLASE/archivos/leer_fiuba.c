#include <stdio.h>
#include <string.h>
#define MAX_NOM 100
typedef char string[MAX_NOM];
typedef struct  {
   int DNI;
   string Nombre;
   string Email; 
   int Sede;
} TRegistro;

void leer_archivo(FILE *archivo)
{
    TRegistro registro;
    
    printf("\nDNI \t Nombre \t Email \t Sede");
    fread(&registro, sizeof(registro), 1, archivo);

    while (!feof(archivo)) {
        printf("\n%i \t %s \t %s \t %i", registro.DNI, registro.Nombre, registro.Email, registro.Sede);
        fread(&registro, sizeof(registro), 1, archivo);
    }
}

void main()
{
    FILE *archivo;
    archivo = fopen("alumnos_fiuba.dat", "rb");

    leer_archivo(archivo);
    fclose(archivo);
}