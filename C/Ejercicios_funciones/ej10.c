/* PROBLEMA
Escribir una función que dado un tiempo expresado en segundos, devuelva
por parámetros el equivalente en días, horas, minutos y segundos.
Utilizar esta función dentro de un programa que solicite el valor al usuario.
Se debe validar que el valor ingresado sea entero positivo, de lo contrario,
deberá mostrarse el mensaje: “Valor ingresado inválido”.

Ejemplo:
Valor ingresado representando una cantidad de segundos: 1234567
Resultado: Días: 14, Horas: 6, Minutos: 56, Segundos 7
*/

# include <stdio.h>
# define SEGUNDOS_DE_UN_DIA 86400
# define SEGUNDOS_DE_UNA_HORA 3600
# define SEGUNDOS_DE_UN_MINUTO 60


void conversion (int tiempo_total, int *dias, int *horas, int *minutos, int *segundos)
{
    int tiempo_sobrante;

    *dias = tiempo_total / SEGUNDOS_DE_UN_DIA;

    tiempo_sobrante = tiempo_total - (*dias * SEGUNDOS_DE_UN_DIA);
    *horas = tiempo_sobrante / SEGUNDOS_DE_UNA_HORA;

    tiempo_sobrante = tiempo_sobrante - (*horas * SEGUNDOS_DE_UNA_HORA);
    *minutos = tiempo_sobrante / SEGUNDOS_DE_UN_MINUTO;

    tiempo_sobrante = tiempo_sobrante - (*minutos * SEGUNDOS_DE_UN_MINUTO);
    *segundos = tiempo_sobrante;
    
}

void main()
{
    int tiempo_total, *dias, *horas, *minutos, *segundos;

    printf("Ingrese un valor de tiempo en segundos: ");
    scanf("%i", &tiempo_total);

    conversion(tiempo_total, &dias, &horas, &minutos, &segundos);

    if (tiempo_total < 0)
        printf("Valor ingresado inválido\n");
    else
        printf("\nResultado: Dias: %i, Horas: %i, Minutos: %i, Segundos: %i\n", dias, horas, minutos, segundos);


}