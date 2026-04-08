# include <stdio.h>

void main()
{
    float base, altura, area; //Es buena practica declarar las variables que va a usar la funcion main() al principio del programa

    printf("ingrese la base del triangulo: ");
    scanf("%f", &base);

    printf("ingrese la altura del triangulo: ");
    scanf("%f", &altura);

    area = (base * altura)/2;
    printf("\nla superficie del triangulo es: %f\n", area);
}