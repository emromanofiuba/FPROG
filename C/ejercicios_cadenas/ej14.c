#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_CHAR_TEXTO 1000
#define MAX_CHAR_PALABRA 25
typedef char t_texto[MAX_CHAR_TEXTO];

void ingreso_texto(t_texto texto)
{
    printf("Ingrese un texto: ");
    fgets(texto, MAX_CHAR_TEXTO, stdin);
    texto[strcspn(texto, "\n")] = '\0';
}

bool validar_texto(t_texto texto)
{
    int i, largo;
    bool letras, numeros, signos_puntuacion, valido;

    valido = true;
    i = 0;
    largo = strlen(texto);

    while (i < largo && valido) {
        letras = ((texto[i] >= 'a' && texto[i] <= 'z') || (texto[i] >= 'A' && texto[i] <= 'Z'));
        numeros = (texto[i] >= '0' && texto[i] <= '9');
        signos_puntuacion = (texto[i] == ' ' || texto[i] == '.' || texto[i] == ',' || texto[i] == ';' || texto[i] == ':' || texto[i] == '(' || texto[i] == ')');
        if (!letras && !numeros && !signos_puntuacion)
            valido = false;
        i++;
    }
    return valido;
}

int importe_palabra(int largo)
{
    int i, importe;
    importe = 0;

    if (largo >= 3) {
        for (i = 0; i < largo; i+=3) {
            if (largo - i < 3)
                importe += 8;
            else 
                importe += 10;
        }
    }
    else 
        importe = 8;

    return importe;
}

void importe_total_pagar(t_texto texto, int *cantidad_palabras, int *importe_tot)
{
    bool anterior_fue_espacio;
    int i, largo, cant_caracteres;
    
    largo = strlen(texto);
    anterior_fue_espacio = true;
    cant_caracteres = 1;
    *cantidad_palabras = 0;
    *importe_tot = 0;

    for (i = 0; i < largo; i++) {
        if (texto[i] == ' ' && !anterior_fue_espacio) {
            *importe_tot += importe_palabra(cant_caracteres-1);
            (*cantidad_palabras)++;
            cant_caracteres = 0;
        }
        cant_caracteres++;

        anterior_fue_espacio = (texto[i] == ' ');
    }
    if (texto[i-1] != ' ') {
        *importe_tot += importe_palabra(cant_caracteres-1);
        (*cantidad_palabras)++;
    }
}

int main() {
    t_texto texto;
    int cantidad_palabras, importe_abonar;

    ingreso_texto(texto);

    if (!validar_texto(texto))
        printf("Se ingreso un texto invalido\n");
    else {
        importe_total_pagar(texto, &cantidad_palabras, &importe_abonar);
        printf("Se ingresaron %i palabras y el importe a abonar es de $%i\n", cantidad_palabras, importe_abonar);
    }

    return 0;
}