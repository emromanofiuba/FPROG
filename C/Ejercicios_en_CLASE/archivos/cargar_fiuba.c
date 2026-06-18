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

void cargar_archivo(FILE *archivo)
{
    TRegistro registro;
     printf("DNI: ");
     scanf("%i", &registro.DNI);

    while (registro.DNI != -1) {
        printf("nombre, email, sede: ");
        scanf("%s", registro.Nombre);
        scanf("%s", registro.Email);
        scanf("%i", &registro.Sede);

        fwrite(&registro, sizeof(registro), 1, archivo);

        printf("DNI: ");
        scanf("%i", &registro.DNI);
    }
}

void main()
{
    FILE *archivo;
    archivo = fopen("alumnos_fiuba.dat", "wb");
    cargar_archivo(archivo);
    fclose(archivo);
}