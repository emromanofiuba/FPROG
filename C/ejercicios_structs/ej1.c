# include <stdio.h>
# define TAMANIO 10
# define FECHA_ACTUAL 20260701

typedef char t_string[35];

typedef struct {
int dia;
int mes;
int anio;
} t_fecha;

typedef struct {
t_string apellido;
t_string nombre;
t_fecha fecha_nacimiento;
t_fecha fecha_ingreso;
float sueldo_basico;
} t_empleado;

void cumpleanieros_febrero(t_empleado empleados[TAMANIO], int ml)
{
    int i;
    int mes_actual;
    mes_actual = (FECHA_ACTUAL / 100) % 100;

    for (i = 0; i < ml; i++)
        if (empleados[i].fecha_nacimiento.mes == mes_actual) {
            printf("Nombre: %s | Apellido: %s", empleados[i].nombre, empleados[i].apellido);
            printf("\n");
        }
}

long comprimir_fecha(t_fecha fecha)
{
    return fecha.anio * 10000 + fecha.mes * 100 + fecha.dia;
}

void regalo_por_antiguedad(t_empleado empleados[TAMANIO], int ml)
{
    int antiguedad, i;
    float suma_anio_cumplido;

    for (i = 0; i < ml; i++) {
        suma_anio_cumplido = 0.0;
        antiguedad = FECHA_ACTUAL / 10000 - comprimir_fecha(empleados[i].fecha_ingreso) / 10000;

        if (FECHA_ACTUAL % 10000 < comprimir_fecha(empleados[i].fecha_ingreso) % 10000)
            antiguedad--;

        if (antiguedad == 0)
            printf("No habra suma de regalo ya que el empleado no tiene al menos 1 año de antiguedad");
        else {
            suma_anio_cumplido = empleados[i].sueldo_basico * 0.001 * antiguedad;
            printf("Empleado %i | Suma de regalo: $%.2f", i+1, suma_anio_cumplido);
            printf("\n");
        }
    }
}