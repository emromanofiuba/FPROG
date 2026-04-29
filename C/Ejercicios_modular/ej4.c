/* PROBLEMA
Dada una fecha en formato aaaammdd, verificar si es correcta.
Si lo es, informarla según “dd de cccc de aaaa”.
Si no lo es, mostrar un mensaje de error acorde.
cccc es la cadena de caracteres correspondiente al mes mm.
Ejemplo 1:
fecha = 19910123
“23 de enero de 1991”
Ejemplo 2:
fecha = 19910231
“error fecha inválida”
*/


# include <stdio.h>

void descomprimir_fecha(long fecha, int *año, int *mes, int *dia){
    int aux;
    
    *año = fecha / 10000;

    aux = fecha % 10000;

    *mes = aux / 100;
    *dia = aux % 100;
}