# include <stdio.h>

void main()
{
    float temperatura;
    char u_medida;

    printf("ingrese la temperatura: ");
    scanf("%f", &temperatura);

    printf("¿En que unidad de medida se encuentra (F o C)?: ");
    scanf(" %c", &u_medida);
    

    if (u_medida == 'C') {
        temperatura = (temperatura * 1.8) + 32;
        printf("\nDe C a F: %f\n", temperatura);
    }
    else if (u_medida == 'F') {
        temperatura = (temperatura -32) *0.55;
        printf("\nDe F a C: %f\n", temperatura);
    }
    else
        printf("\nOperacion no realizable. Debe ingresar una C o una F\n");
}