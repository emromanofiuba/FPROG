/*
Crear una función que reciba como parámetro un vector, un numero entero llamada NUM y un segundo numero llamado CANT. 
La función debe devolver en cada posición del vector, un divisor del numero NUM y debe cargar como máximo CANT posiciones (o divisores).
No se puede superar el MAX de divisores cuya constante es MAX.
*/

# include <stdio.h>
# define MAX 10
typedef int Tvec[MAX];



void ingreso_numero(int *num, int *cant)
{
    printf("Ingrese un numero entero: ");
    scanf("%i", num);

    printf("Ingrese una cantidad de divisores: ");
    scanf("%i", cant);
    
    while (*cant > MAX){
        printf("Ingrese una nueva cantidad de divisores. Excedio el rango. ");
        scanf("%i", cant);
    }

}


void cargar_divisores(Tvec divisores, int num, int cant)
{
    int posicion = 0;

    for (int i = 1; i <= num && posicion < cant; i++){
        if (num % i == 0){
            divisores[posicion] = i;
            posicion++;
        }
    }
}

void mostrar_divisores(Tvec divisores, int cant)
{
    for (int i = 0; i < cant; i++)
        if (divisores[i] != 0)
            printf("%i ", divisores[i]);

    printf("\n");
}

int main(void)
{
    int num, cant;
    Tvec divisores = {0};

    ingreso_numero(&num, &cant);
    cargar_divisores(divisores, num, cant);

    printf("Divisores del %i: \n", num);
    mostrar_divisores(divisores, cant);

    return 0;
}

