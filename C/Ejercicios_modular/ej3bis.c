#include <stdio.h>

long pedir_fecha(){
    long fecha;

    printf("escribi la fecha wachin: ");
    scanf("%ld", &fecha);

    return fecha;
}

long fechas_separadas(){
    int año, dia, mes;
    long fecha;

    printf("ingrese el dia: ");
    scanf("%d", &dia);
    printf("ingrese el mes: ");
    scanf("%d", &mes);
    printf("ingrese el año: ");
    scanf("%d", &año);

    fecha = (año * 10000) + (mes * 100) + dia;

    return fecha;

}

long revertir_fecha(long fecha){
    
    long año, dia, mes;

    año = fecha % 10000;
    fecha = fecha / 10000;
    mes = fecha % 100;
    dia = fecha / 100;

    return (año * 10000) + (mes * 100) + dia;
}

long comparar_fechas(long *fecha_1, long *fecha_2){
    long fecha_anterior = *fecha_2;
    
    if (*fecha_1 < *fecha_2)
        fecha_anterior = *fecha_1;
    else if (*fecha_1 == *fecha_2)
        fecha_anterior == 0;
    
    return fecha_anterior;

}

void main(){
    long fecha_1, fecha_2;
    int caso;

    printf("ingrese el caso del ejercicio: ");
    scanf("%d", &caso);

    if (caso == 1){
        fecha_1 = fechas_separadas();
        fecha_2 = fechas_separadas();}
    else if(caso == 2){
        fecha_1 = pedir_fecha();
        fecha_2 = pedir_fecha();}
    else{
        fecha_1 = pedir_fecha();
        fecha_1 = revertir_fecha(fecha_1);
        fecha_2 = pedir_fecha();
        fecha_2 = revertir_fecha(fecha_2);
    }

    printf("la fecha anterior es: %ld\n", comparar_fechas(&fecha_1, &fecha_2));  

}