/* PROBLEMA 
Se realiza una encuesta de aceptacion de un producto x y de un producto y.
A cada encuestado se le pregunta si consume el producto x y si consume el y.
La respuesta puede ser si o no.
Luego, se pide calcular e informar el porcentaje de consumidores de:
a) del producto x
b) del producto y
c) del producto x solamente
d) del producto y solamente
e) de ambos productos
f) de ninguno de los productos
*/

# include <stdio.h>

void main()
{
    //Declaro variables
    int consumidores_x, consumidores_y, consumidores_solo_x, consumidores_solo_y, consumidores_ambos, consumidores_ninguno;
    int encuestados;
    int num_inicio_encuesta;
    char consume_x, consume_y;
    float porcentaje_x, porcentaje_y, porcentaje_solo_x, porcentaje_solo_y, porcentaje_ambos, porcentaje_ninguno;

    //Las inicializo en 0
    consumidores_x = consumidores_y = consumidores_solo_x = consumidores_solo_y = consumidores_ambos = consumidores_ninguno = 0;
    
    encuestados = 0;

    printf("Ingrese 1 para empezar la encuesta: ");         //Condicion de corte del ciclo
    scanf("%i", &num_inicio_encuesta);


    while (num_inicio_encuesta == 1){
        encuestados += num_inicio_encuesta;
        printf("\nEncuestado n° %i", encuestados);
        
        printf("\n¿Consume x? (ingrese 'S' o 'N'): ");
        scanf(" %c", &consume_x);
                                                            //Pregunto las consumiciones al encuestado n°i
        printf("¿Consume y? (ingrese 'S' o 'N'): ");
        scanf(" %c", &consume_y);

        if (consume_x == 'S')
            consumidores_x++;                               //Las evaluo
        if (consume_y == 'S')
            consumidores_y++;
        if (consume_x == 'S' && consume_y == 'N')
            consumidores_solo_x++;
        if (consume_y == 'S' && consume_x == 'N')
            consumidores_solo_y++;
        if (consume_x == 'S' && consume_y == 'S')
            consumidores_ambos++;
        if (consume_x == 'N' && consume_y == 'N')
            consumidores_ninguno++;
        
        printf("\nIngrese 1 para seguir la encuesta u otro numero para terminarla: ");      //Seguir con la encuesta (o no)
        scanf("%i", &num_inicio_encuesta);
    }

    printf("\nTerminó la encuesta. Se mostrarán los porcentajes de consumidores correspondientes\n");

    porcentaje_x = (float)consumidores_x / encuestados * 100;
    porcentaje_y = (float)consumidores_y / encuestados * 100;
    porcentaje_solo_x = (float)consumidores_solo_x / encuestados * 100;
    porcentaje_solo_y = (float)consumidores_solo_y / encuestados * 100;
    porcentaje_ambos = (float)consumidores_ambos / encuestados * 100;
    porcentaje_ninguno = (float)consumidores_ninguno / encuestados * 100;

    printf("\nPorcentaje x: %.2f \n", porcentaje_x);
    printf("Porcentaje y: %.2f \n", porcentaje_y);
    printf("Porcentaje solo x: %.2f \n", porcentaje_solo_x);
    printf("Porcentaje solo y: %.2f \n", porcentaje_solo_y);
    printf("Porcentaje ambos: %.2f \n", porcentaje_ambos);
    printf("Porcentaje ninguno: %.2f \n", porcentaje_ninguno);
}