/* PROBLEMA
Escribir una función que reciba un mes y un año como números enteros; y
devuelva la cantidad de días del mes, considerando los años bisiestos. Tenga en
cuenta que un año bisiesto es aquel divisible por 4, salvo que sea divisible por
100, en cuyo caso también debe ser divisible por 400.
*/

# include <stdio.h>
# define MES_CON_30_DIAS 30
# define MES_CON_31_DIAS 31
# define FEBRERO_EN_AÑO_BISIESTO 29

int calcular_dias_mes(int mes, int año)
{
    int dias;

    if (año % 4 || año % 100 && año % 400){
        if (mes == 2) 
            dias = FEBRERO_EN_AÑO_BISIESTO;
    }
    else if (mes == 2)
        dias = 28;

    else if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
        dias = MES_CON_31_DIAS;

    else if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
        dias = MES_CON_30_DIAS;

    return dias;
}

void main()
{
    printf("Dias: %i\n",calcular_dias_mes(4, 2001));
}