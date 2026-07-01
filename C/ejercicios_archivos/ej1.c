#include <stdio.h>

long factorial(int numero)
{
    if (numero == 0)
        return 1;
    return numero * factorial(numero - 1);
}

void generar_factoriales(FILE *entrada, FILE *salida)
{
    int numero;
    long resultado;

    fread(&numero, sizeof(int), 1, entrada);
    while (!feof(entrada)) {
        resultado = factorial(numero);
        fwrite(&resultado, sizeof(long), 1, salida);
        fread(&numero, sizeof(int), 1, entrada);
    }
}

void procesar_archivos(void)
{
    FILE *entrada;
    FILE *salida;

   entrada = fopen("enteros.dat", "rb");
   salida = fopen("factoriales.dat", "wb");

    if (entrada == NULL)
        printf("No se pudo abrir el archivo de entrada");
    else if (salida == NULL)
        printf("No se pudo crear el archivo de salida");
    else {
        generar_factoriales(entrada, salida);
        fclose(entrada);
        fclose(salida);
    }
}

int main(void)
{
    procesar_archivos();
    return 0;
}