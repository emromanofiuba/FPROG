# include <stdio.h>

void main()
{ 
 	int num, cubo;
    
    printf("Ingrese un numero para elevarlo al cubo (0 para terminar): ");
    scanf("%i", &num);
    
    while (num != 0){
 		cubo = num * num * num;
        printf("El cubo de %i es = %i\n", num, cubo);
        printf("Ingrese otro numero para elevarlo al cubo (0 para terminar): ");
        scanf("%i", &num);
  	}
    printf("\nIngrestaste el 0. Se termino la serie\n");
}