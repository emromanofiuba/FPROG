# include <stdio.h>
# include <string.h>
# include <stdbool.h>

# define TAMANIO 10
# define OP_SALIR     0
# define OP_NOMBRE    1
# define OP_LOCALIDAD 2
# define OP_LEGAJO    3
# define OP_EDAD      4
# define OP_ANTIGUEDAD 5
# define OP_LISTAR    6

typedef char t_nombre[35];
typedef char t_lugar[50];
typedef struct {
    int dia;
    int mes;
    int anio;
} t_fecha; 

typedef struct {
    t_nombre apellido;
    t_nombre nombre;
    int legajo;
    t_lugar calle;
    int numero;
    t_lugar localidad;
    t_lugar provincia;
    int codigo_postal;
    t_fecha fecha_nacimiento;
    t_fecha fecha_ingreso;
} t_empleado;


void cargar_empleados(t_empleado empleados[TAMANIO], int *ml)
{
    *ml = 0;

    printf("Legajo del %i° empleado, 0 para salir: ", *ml + 1);
    scanf("%i", &empleados[*ml].legajo);

    while (*ml < TAMANIO && empleados[*ml].legajo != 0) {
        printf("Apellido: ");
        scanf("%s", empleados[*ml].apellido);

        printf("Nombre: ");
        scanf("%s", empleados[*ml].nombre);

        printf("Calle: ");
        scanf("%s", empleados[*ml].calle);

        printf("Numero: ");
        scanf("%i", &empleados[*ml].numero);

        printf("Localidad: ");
        scanf("%s", empleados[*ml].localidad);

        printf("Provincia: ");
        scanf("%s", empleados[*ml].provincia);

        printf("Codigo postal: ");
        scanf("%i", &empleados[*ml].codigo_postal);

        printf("Fecha de nacimiento (dia mes anio): ");
        scanf("%i %i %i", &empleados[*ml].fecha_nacimiento.dia,
                          &empleados[*ml].fecha_nacimiento.mes,
                          &empleados[*ml].fecha_nacimiento.anio);

        printf("Fecha de ingreso (dia mes anio): ");
        scanf("%i %i %i", &empleados[*ml].fecha_ingreso.dia,
                          &empleados[*ml].fecha_ingreso.mes,
                          &empleados[*ml].fecha_ingreso.anio);

        (*ml)++;

        if (*ml < TAMANIO) {
            printf("\nLegajo del %i° empleado, 0 para salir: ", *ml + 1);
            scanf("%i", &empleados[*ml].legajo);
        }
    }
}


void mostrar_menu(void)
{
    printf("\n--- MENU ---\n");
    printf("%i - Ordenar por nombre \n", OP_NOMBRE);
    printf("%i - Ordenar por localidad\n", OP_LOCALIDAD);
    printf("%i - Ordenar por legajo\n", OP_LEGAJO);
    printf("%i - Ordenar por edad\n", OP_EDAD);
    printf("%i - Ordenar por antiguedad\n", OP_ANTIGUEDAD);
    printf("%i - Listar tabla\n", OP_LISTAR);
    printf("%i - Salir\n", OP_SALIR);
    printf("Opcion: ");
}

void ordenar_por_nombre(t_empleado empleados[TAMANIO], int ml) //BURBUJEO MEJORADO
{
    int i, j;
    t_empleado aux;
    bool hubo_intercambio = true;
    i = 1;

    while (i < ml && hubo_intercambio) {
        hubo_intercambio = false; 
        for (j = 0; j < ml - i; j++)
            if (strcmp(empleados[j].nombre, empleados[j+1].nombre) > 0) {
                aux = empleados[j];
                empleados[j] = empleados[j+1];
                empleados[j+1] = aux;
                hubo_intercambio = true;
            }
        i++;
    }
}

void ordenar_por_legajo(t_empleado empleados[TAMANIO], int ml) //SELECCION
{
    int i, j, posicion_min;
    t_empleado aux;

    for (i = 0; i < ml-1; i++) {
        posicion_min = i;
        for (j = i + 1; j < ml; j++) 
            if (empleados[j].legajo < empleados[posicion_min].legajo)
                posicion_min = j;
        aux = empleados[posicion_min];
        empleados[posicion_min] = empleados[i];
        empleados[i] = aux;
    }

}

long comprimir_fecha(t_fecha fecha) {
    return fecha.anio * 10000 + fecha.mes *100 + fecha.dia;
}

void ordenar_por_edad(t_empleado empleados[TAMANIO], int ml, long fecha_nacimiento)
{ //DE MAS JOVEN A MAS VIEJO
    int i, j;
    t_empleado aux;

    for (i = 1; i < ml; i++){
        aux = empleados[i];
        j = i - 1;

        while ((j >=0) && (comprimir_fecha(aux.fecha_nacimiento) > comprimir_fecha(empleados[j].fecha_nacimiento))) {
            empleados[j+1] = empleados[j];
            j--;
        }
        empleados[j+1] = aux;
    }
}

void procesar_menu(t_empleado empleados[], int cant)
{
    int opcion;
    bool seguir = true;

    while (seguir) {
        mostrar_menu();
        scanf("%i", &opcion);

        switch (opcion) {
            case OP_NOMBRE:
                ordenar_por_nombre(empleados, cant);
                break;
            case OP_LOCALIDAD:
                ordenar_por_localidad(empleados, cant);
                break;
            case OP_LEGAJO:
                ordenar_por_legajo(empleados, cant);
                break;
            case OP_EDAD:
                ordenar_por_edad(empleados, cant);
                break;
            case OP_ANTIGUEDAD:
                ordenar_por_antiguedad(empleados, cant);
                break;
            case OP_LISTAR:
                listar_empleados(empleados, cant);
                break;
            case OP_SALIR:
                seguir = false;
                break;
            default:
                printf("Opcion invalida.\n");
        }
    }
}

void main() 
{
    int cant;
    t_empleado empleados[TAMANIO];

    ingreso_empleados(empleados, &cant);
    mostrar_menu();
    procesar_menu(empleados, cant);
}