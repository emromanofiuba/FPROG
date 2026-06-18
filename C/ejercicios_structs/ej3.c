# include <stdbool.h>
# include <string.h>
# include <stdio.h>
# define TAMANIO 10
typedef char t_nombre[35];
typedef char t_lugar[50];
typedef struct {
    t_nombre apellido;
    t_nombre nombre;
    int legajo;
    t_lugar calle;
    int numero;
    t_lugar localidad;
    t_lugar provincia;
    int codigo_postal;
    //t_fecha fecha_nacimiento;
    //t_fecha fecha_ingreso;
} t_empleado;

int encontrar_legajo(t_empleado empleados[TAMANIO], int ml, int legajo)
{
    int inicio, centro, fin, posicion;
    bool terminado;
    inicio = 0;
    fin = ml-1;
    terminado = false;

    while (!terminado) {
        if (legajo < empleados[inicio].legajo || legajo > empleados[fin].legajo) {
            terminado = true;
            posicion = -1;
        }
        else {
            centro = inicio + (fin - inicio) / 2;
            if (legajo == empleados[centro].legajo) {
                terminado = true;
                posicion = centro;
            }
            else if (legajo > empleados[centro].legajo)
                inicio = centro + 1;
            else 
                fin = centro - 1;
        }
    }

    return posicion;
}

int encontrar_apellido(t_empleado empleados[TAMANIO], int ml, t_nombre apellido)
{
    int inicio, centro, fin, posicion;
    bool terminado = false;
    inicio = 0;
    fin = ml - 1;

    if (ml == 0) {
        terminado = true;
        posicion = -1;
    }

    while (!terminado) {
    if (strcmp(apellido, empleados[inicio].apellido) < 0 || strcmp(apellido, empleados[fin].apellido) > 0) {
        terminado = true;
        posicion = -1;
    }
    else {
        centro = inicio + (fin - inicio) / 2;
        if (strcmp(apellido, empleados[centro].apellido) == 0) {
            terminado = true;
            posicion = centro;
        }
        else if (strcmp(apellido, empleados[centro].apellido) > 0)
            inicio = centro + 1;
        else 
            fin = centro - 1;
    }
    }

    return posicion;
}

void procesar_menu()
{
    t_empleado empleados[TAMANIO];
    int opcion, ml, legajo;
    t_nombre apellido;

    printf("\n--Lista de opciones--\n");
    printf("1 -> buscar por legajo | 2 -> buscar por apellido\n");
    printf("Elija alguna opcion: ");
    scanf("%i", &opcion);

    while (opcion != 1 && opcion != 2) {
        printf("No existe esa opcion. Elija alguna entre 1 o 2: ");
        scanf("%i", &opcion);
    }

    if (opcion == 1) {
        printf("Numero de legajo a buscar: ");
        scanf("%i", &legajo);
        encontrar_legajo(empleados, ml, legajo);
    }
    else if (opcion == 2) {
        printf("Apellido a buscar: ");
        scanf("%s", apellido);
        encontrar_apellido(empleados, ml, apellido);
    }
}

int main(void) {
    procesar_menu();
}