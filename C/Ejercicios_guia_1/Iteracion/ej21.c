/* PROBLEMA
Se dan como datos de entrada las fechas de nacimiento (día, mes, año) y los números
de DNI de cada integrante de un grupo.
Se indica fin de datos de entrada cuando día = 0.
Muestre por pantalla el número de DNI del integrante más joven del grupo.
*/

/* ALGORITMO DE RESOLUCIÓN
1. declarar variables dia_ingresado, mes_ingresado, año_ingresado, dia_menor, mes_menor, año_menor, dni;
    1.1 asignar a ._ingresado el valor ._menor
2. solicitar datos al usuario (dia, mes, año, dni)
    2.2 el dia_ingresado debe ser solicitado antes de entrar al while
3. pedir datos hasta que dia_ingresado = 0 con un while
    3. mes_ingresado, año_ingresado, dni
4. evaluar si los datos ingresados (actualmente) corresponden a una persona menor a la anterior
    4.1 año_ingresado > año_menor
    4.2 mes_ingresado > mes_menor (si el año es igual)
    4.3 dia_ingresado >  dia_menor (si el mes y año es igual)
5. volver a pedir los datos
    5.1 dia_ingresado, mes_ingresado, año_ingresado, dni
6. mostrar el numero de dni del integrante mas joven
*/

# include <stdio.h>

void main()
{
    int dia_ingresado, mes_ingresado, año_ingresado, dia_menor, mes_menor, año_menor, dni, dni_mas_joven;

    dia_menor = dia_ingresado;
    mes_menor = mes_ingresado;
    año_menor = año_ingresado;
    dni_mas_joven = dni;

    printf("Ingrese el dia de su nacimiento: ");
    scanf("%i", &dia_ingresado);

    while (dia_ingresado != 0){
        printf("Ingrese el mes de su nacimiento: ");
        scanf(" %i", &mes_ingresado);

        printf("Ingrese el año de su nacimiento: ");
        scanf(" %i", &año_ingresado);

        printf("Ingrese su DNI: ");
        scanf(" %i", &dni);

        if (año_ingresado > año_menor) {
            año_menor = año_ingresado;
            dni_mas_joven = dni;
        }
        else if (año_ingresado == año_menor && mes_ingresado > mes_menor) {
            mes_menor = mes_ingresado;
            dni_mas_joven = dni;
        }
        else if (año_ingresado == año_menor && mes_ingresado == mes_menor && dia_ingresado > dia_menor ) {
            dia_menor = dia_ingresado;
            dni_mas_joven = dni;
        }
        
        printf("\nIngrese el dia de su nacimiento: ");
        scanf("%i", &dia_ingresado);
    }

        printf("\nDNI del integrante más joven del grupo = %i\n", dni_mas_joven);
            
}