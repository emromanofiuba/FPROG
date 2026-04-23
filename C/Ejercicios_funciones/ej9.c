/* PROBLEMA
Escribir una función que dada una fecha en formato aaaammdd (número
entero) la convierta en los parámetros numéricos aaaa, mm y dd.​
Ejemplo:​
fecha: 20140321 -> dia=21 mes=3 año=2014
*/

# include <stdio.h>

void convertir_fecha(long fecha, int *dia, int *mes, int *año)
{
    int aux;

    *año = fecha / 10000;

    aux = fecha / 100;
    *mes = aux % 100;

    *dia = fecha % 100;
}

void main()
{
    long fecha;
    int dia, mes, año;

    printf("Ingrese una fecha en formato aaaammdd: ");
    scanf("%ld", &fecha);

    convertir_fecha(fecha, &dia, &mes, &año);

    printf("dia=%i mes=%i año=%i\n", dia, mes, año);
}
