# include <stdio.h>

void main()
{
    int edad;

    printf("ingrese su edad: ");
    scanf("%i", &edad);

    while ((edad < 18)) {                            //Validacion de la mayoría de edad
        printf("\nsos menor de edad todavia");
        printf("\ncreciste? Ingresa tu edad: ");
        scanf("%i", &edad);
    }
    
    printf("\n¡ya sos mayor de edad!\n");          //Ciclo while terminado, porque el usuario ya es mayor de edad
}