#include <stdio.h>
#include <stdbool.h>

long ingreso_fecha() //20210912
{
    long fecha;
    printf("Ingrese una fecha en formato aaaammdd: ");
    scanf("%ld", &fecha);

    return fecha;
}

void procesar_fecha(long fecha, int *anio, int *mes, int *dia)
{
    int aux;
    *anio = fecha / 10000;
    aux = fecha / 100;
    *mes = aux % 100;
    *dia = fecha % 100;
}

bool validar_dia_segun_mes (int dia, int mes)
{
    bool fecha_validada = false;
    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
        if (dia >= 1 && dia <= 31)
            fecha_validada = true;
    else if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
        if (dia >= 1 && dia <= 30)
            fecha_validada = true;
    else if (mes == 2)
        if (dia >= 1 && dia <= 28)
            fecha_validada = true;
    
    return fecha_validada;

}

void validar_fecha(int anio, int mes, int dia)
{
    if (anio >= 0)
        if (validar_dia_segun_mes(dia, mes))
            printf("%i del %i de %i", dia, mes, anio);
        else 
            printf("error, fecha invalida");
    else 
        printf("error, el año no existe");
    
}

void main() {
    long fecha;
    int anio, mes, dia;

    fecha = ingreso_fecha();
    procesar_fecha(fecha, &anio, &mes, &dia);
    validar_fecha(anio, mes, dia);
}
