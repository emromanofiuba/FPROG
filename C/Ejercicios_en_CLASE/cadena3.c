# include <stdio.h>
#define LONG_NOMBRES 15
#define LONG_APELLIDOS 10
#define LONG_DOMICILIO 16

char nombre[LONG_NOMBRES];
char apellido[LONG_APELLIDOS];
char domicilio[LONG_DOMICILIO];

void main()
{
    printf("Nombre: ");
    scanf("%s", nombre);

    fflush(stdin);

    printf("Apellido: ");
    scanf("%10[^\n]s", apellido);

    fflush(stdin);

    printf("Domicilio: ");
    fgets(domicilio, LONG_DOMICILIO, stdin);


    printf("\nTu nombre completo es: %s %s\n", nombre, apellido);
    printf("Y vivis en: %s", domicilio);
}