/*
Dada una fecha con año, mes y día, informar si es correcta o no. Solicitarle los
datos al usuario de forma independiente. Considerar años bisiestos.
*/

# include <stdio.h>

void main() {

    int dia, mes, año, bisiesto;
    
    printf("La fecha que debe ingresar debe respetar este formato: dd/mm/aaaa\n");
    printf("De todas formas, se le solicitaran los datos por separado\n");

    printf("\ningrese el dia: ");
    scanf("%2i", &dia);

    printf("ingrese el mes: ");
    scanf("%2i", &mes);

    printf("ingrese el año: ");
    scanf("%4i", &año);

    // Validar año
    if (año < 1)
        printf("\nNo se puede generar la fecha. El año ingresado es invalido.\n");
    else
    {
        // Validar mes
        if (mes < 1 || mes > 12)
        {
            printf("\nNo se puede generar la fecha. El mes ingresado es invalido.\n");
        }
        else
        {
            bisiesto = (año % 4 == 0 && año % 100 != 0) || (año % 400 == 0);

            //Validar mes para febrero
            if (mes == 2)
            {
                if (bisiesto && dia >= 1 && dia <= 29)
                    printf("\nLa fecha que ingresaste es: %02d/%02d/%04d\n", dia, mes, año);
                else if (!bisiesto && dia >= 1 && dia <= 28)
                    printf("\nLa fecha que ingresaste es: %02d/%02d/%04d\n", dia, mes, año);
                else
                    printf("\nNo se puede generar la fecha. El día ingresado no es valido para febrero.\n");
            }
            // Validar fecha para meses con 30 dias
            else if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
            {
                if (dia >= 1 && dia <= 30)
                    printf("\nLa fecha que ingresaste es: %02d/%02d/%04d\n", dia, mes, año);
                else
                    printf("\nNo se puede generar la fecha. El día ingresado no es valido para este mes.\n");
            }

            //El resto de los meses (tienen 31)
            else
            {
                if (dia >= 1 && dia <= 31)
                    printf("\nLa fecha que ingresaste es: %02d/%02d/%04d\n", dia, mes, año);
                else
                    printf("\nNo se puede generar la fecha. El día ingresado no es valido.\n");
            }
        }
    }

}