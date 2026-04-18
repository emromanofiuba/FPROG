/* PROBLEMA
Se tiene un listado de alumnos que consiste en número de padrón y 4 notas por
alumno. Informar el mayor y el menor promedio registrado junto con el número de
padrón del alumno, suponiendo que ambos son únicos.
*/

# include <stdio.h>
# define CANT_NOTAS 4

void main()
{
    int num_padron, num_padron_menor, num_padron_mayor, i;
    float nota, promedio, mayor_promedio, menor_promedio, suma_notas;

    suma_notas = 0;

    for (i = 1; i <= CANT_NOTAS && nota >= 0; i++){
        printf("Ingrese la nota %i: ", i);
        scanf("%f", &nota);
        suma_notas += nota;
    }   
    if (nota >= 0){
        promedio = suma_notas / CANT_NOTAS;

        printf("Ingrese su numero de padrón: ");
        scanf("%i", &num_padron);
    }


    num_padron_menor = num_padron;
    num_padron_mayor = num_padron;
    mayor_promedio = promedio;
    menor_promedio = promedio;


    while (nota >= 0){
        if (promedio > mayor_promedio){
            mayor_promedio = promedio;
            num_padron_mayor = num_padron;
        }
        else if (promedio < menor_promedio){
            menor_promedio = promedio;
            num_padron_menor = num_padron;
        }

        suma_notas = 0;

        for (i = 1; i <= CANT_NOTAS && nota >= 0; i++){
            printf("Ingrese la nota %i: ", i);
            scanf("%f", &nota);
            suma_notas += nota;
        }
        if (nota >= 0){
            promedio = suma_notas / CANT_NOTAS;

            printf("Ingrese su numero de padrón: ");
            scanf("%i", &num_padron);
        }
    }   

    printf("\nMayor promedio = %f cuyo Numero de Padrón es = %i", mayor_promedio, num_padron_mayor);
    printf("\nMenor promedio = %f cuyo Numero de Padrón es = %i\n", menor_promedio, num_padron_menor);  
}