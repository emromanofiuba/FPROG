# include <stdio.h>
# include <string.h>
# include <stdbool.h>
# define TAMANIO 5
typedef struct 
{
    char nombre[15];
    int padron;
    int notas[2];
    float promedio;
} t_alumno;


void cargar_datos(t_alumno alumno[TAMANIO])
{
    for (int i=0; i < TAMANIO; i++) {
        printf("\n--ALUMNO[%i]--\n", i+1);

        printf("Nombre: ");
        scanf("%s", alumno[i].nombre);
        
        printf("Padron: ");
        scanf("%i", &alumno[i].padron);

        printf("Nota 1: ");
        scanf("%i", &alumno[i].notas[0]);

        printf("Nota 2: ");
        scanf("%i", &alumno[i].notas[1]);

        alumno[i].promedio = (float)(alumno[i].notas[0] + alumno[i].notas[1]) / 2;

    }
}

int indice_mejor_promedio(t_alumno alumno[TAMANIO])
{
    int i;
    float promedio_mayor = alumno[0].promedio;
    int posicion_mejor = 0;

    for (i=0; i < TAMANIO; i++) 
        if (alumno[i].promedio > promedio_mayor) {
            promedio_mayor = alumno[i].promedio;
            posicion_mejor = i;
        }
    return posicion_mejor;
}

float promedio_parcial1(t_alumno alumno[TAMANIO])
{
    int i;
    int suma = 0;

    for (i=0; i < TAMANIO; i++) 
       suma += alumno[i].notas[0];

    return (float)suma / TAMANIO;
}

void ordenar_por_padron(t_alumno alumno[TAMANIO])
{
    int i, j, posicion_menor;
    t_alumno aux;

    for (i = 0; i < TAMANIO; i++) {
        posicion_menor = i;
        for (j = i+1; j < TAMANIO; j++) {
            if (alumno[j].padron < alumno[i].padron) {
                posicion_menor = j;
            }
            aux = alumno[posicion_menor];
            alumno[posicion_menor] = alumno[i];
            alumno[i] = aux;
        }
    }
}

long pedir_padron(t_alumno alumno[TAMANIO])
{
    long padron;
    printf("Ingrese el padron a buscar: ");
    scanf("%ld", &padron);

    return padron;
}

bool buscar_padron(t_alumno alumno[TAMANIO], long padron)
{
    int inicio, fin, centro;
    bool encontrado = false;
    inicio = alumno[0].padron;
    fin = alumno[TAMANIO-1].padron;

    while (!encontrado) {
        centro = inicio + (inicio + fin) / 2;
        if (padron == centro)
            encontrado = true;
        else 
            if (padron < centro)
                fin = centro - 1; 
            else
                inicio = centro + 1;
    }

    return encontrado;
}

void main() {
    t_alumno alumno[TAMANIO];

    cargar_datos(alumno);

    int posicion_mejor =  indice_mejor_promedio(alumno);
    printf("El nombre del mejor promedio es %s\n", alumno[posicion_mejor].nombre); 

    printf("Promedio de notas del 1° parcial es: %.2f\n", promedio_parcial1(alumno));

    ordenar_por_padron(alumno);

    long padron = pedir_padron(alumno);
    buscar_padron(alumno, padron);

}