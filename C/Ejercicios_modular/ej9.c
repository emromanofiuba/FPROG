/* PROBLEMA
En una competencia de salto en largo, se presentaron 5 participantes. De
cada uno se ingresa:
Número de participante
Fecha de nacimiento (aaaammdd)
Distancias de sus 3 saltos expresados en metros.
El mejor de los 3 saltos se considera como la mejor marca obtenida.

a) Para cada participante mostrar por pantalla el número de participante, la
edad y la marca obtenida.
b) Informar el número del participante del atleta que obtuvo la mejor marca.
*/

# include <stdio.h>
# define CANT_PARTICIPANTES 5
# define CANT_SALTOS 3

float obtener_maximo_salto()
{
    float marca, aux_salto;
    int j;

    marca = 0;

    for(j = 1; j <= CANT_SALTOS; j++){
        printf("Salto %i : ", j);
        scanf("%f", &aux_salto);

        if (aux_salto > marca)
            marca = aux_salto;
    }

    return marca;
}


void ingresar_datos()
{
    int num, fecha_nacimiento;
    printf("Numero de participante: ");
    scanf("%i", &num);

    printf("Fecha de nacimiento: ");
    scanf("%i", &fecha_nacimiento);

    obtener_maximo_salto();
}


void main()
{
    int i, num, fecha_nacimiento;
    float salto;

    for (i = 1; i <= CANT_PARTICIPANTES; i++ ){
        printf("\nParticipante %i\n", i);
        ingresar_datos();
        printf("\nNumero de participante %i, Marca: %f", i, obtener_maximo_salto());
    }
}