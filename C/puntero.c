# include <stdio.h>

void main()
{
    int edad;
    int* p1;

    edad = 15;

    printf("tu edad es: %i\n", edad);


    p1 = &edad;

    printf("p1 = %p\n", p1);

    *p1 = 12;

    printf("tu edad es: %i\n", edad);
}