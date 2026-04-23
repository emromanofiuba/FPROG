/* PROBLEMA
Dadas dos fechas, informar cuál es la fecha anterior. Los datos se dan según
los siguientes casos:
a) Cada fecha consiste en 3 números, día, mes y año.
b) Cada fecha consiste en un único número en formato aaaammdd.
c) Cada fecha consiste en un único número en formato ddmmaaaa.
Puede darse el caso que las fechas sean iguales.
*/

/*
1. funcion para descomprimir el formato 2
2. " " " " " 3
3. " main

*/

# include <stdio.h>
# define DESCOMPRIMIR_AÑO_1 10000
# define DESCOMPRIMIR_DIA_1 100
# define DESCOMPRIMIR_DIA_2 1000000
# define DESCOMPRIMIR_MES_2 10000

void descomprimir_aaaammdd(long fecha, int *año, int *mes, int *dia)
{
    int aux;

    *año = fecha / DESCOMPRIMIR_AÑO_1;
    *dia = fecha % DESCOMPRIMIR_DIA_1;

    aux = fecha / DESCOMPRIMIR_DIA_1;
    *mes = aux % DESCOMPRIMIR_DIA_1;
}

void descomprimir_ddmmaaaa(long fecha, int *año, int *mes, int *dia)
{
    int mes_año;

    *dia = fecha / DESCOMPRIMIR_DIA_2;

    mes_año = fecha % DESCOMPRIMIR_DIA_2;

    *mes = mes_año / DESCOMPRIMIR_MES_2;
    *año = mes_año % DESCOMPRIMIR_MES_2;
}

void descomprimir_formato(long fecha, int formato, int *año, int *mes, int *dia)
{
    if ( formato == 1)
        descomprimir_aaaammdd(fecha, año, mes, dia);
    else 
        descomprimir_ddmmaaaa(fecha, año, mes, dia);
}

long comparacion_fecha(long fecha_1, long fecha_2)
{
    long fecha_anterior;
    int año_1, mes_1, dia_1, año_2, mes_2, dia_2;

    fecha_anterior = fecha_1;

    if (año_2 < año_1)
        fecha_anterior = fecha_2;
    else if ( año_1 == año_2 && mes_2 < mes_1)
            fecha_anterior = fecha_2;
    else if ( año_1 == año_2 && mes_1 == mes_2 && dia_2 < dia_1)
            fecha_anterior = fecha_2;
    else if ( año_1 == año_2 && mes_1 == mes_2 && dia_2 == dia_1)
            fecha_1 = fecha_2;

    return fecha_anterior;
}

void main()
{
    long fecha_1, fecha_2;
    int formato_1, formato_2, año_1, mes_1, dia_1, año_2, mes_2, dia_2;

    printf("Ingrese una fecha: ");
    scanf("%ld", &fecha_1);
    printf("Formato de fecha 1 (1 = aaaammdd): ");
    scanf("%d", &formato_1);

    printf("\nIngrese otra fecha: ");
    scanf("%ld", &fecha_1);
    printf("Formato de fecha 2 (1 = aaaammdd): ");
    scanf("%d", &formato_2);

    descomprimir_formato(fecha_1, formato_1, &año_1, &mes_1, &dia_1);
    descomprimir_formato(fecha_2, formato_2, &año_2, &mes_2, &dia_2);

    printf("\nla fecha anterior es %ld\n", comparacion_fecha(fecha_1, fecha_2));
}

