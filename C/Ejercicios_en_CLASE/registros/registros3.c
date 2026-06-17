/*
e-Generar un alumnos ordenado por padron
f-Generar un alumnos de alumnos aprobados y otro de no aprobados a partir del alumnos del punto anterior
*/
#include <stdio.h>
#include <string.h>
#define MAXALUMNOS 200
typedef struct
{
    char nombre[30];
    char apellido[25];
    int nota;
    int padron;
} talumno;

typedef talumno tvalumnos[MAXALUMNOS];

void ordenar_por_patron(tvalumnos valumno, int ML)
{
    int i = 0;
    int j;
    int bool_encontrado = 1;
    talumno aux;

    while ((i < ML) && (bool_encontrado == 1))
    {
        bool_encontrado = 0;
        for (j = 0; j < ML - i; j++)
        {
            if (valumno[j].padron > valumno[j + 1].padron)
            {
                aux = valumno[j];
                valumno[j] = valumno[j + 1];
                valumno[j + 1] = aux;
                bool_encontrado = 1;
            }
        }
        i++;
    }

    return;
}

void mostrar_todo(tvalumnos valumno, int ML)
{
    int i;

    return;
}

void crear_alumnos(tvalumnos valumno, int ml)
{
    FILE *alumnos;
    int i;
    alumnos = fopen("valumnos.dat", "wb");

    ordenar_por_patron(valumno, ml);
    for (i=0; i < ml; i++) {
        fwrite(&valumno[i], sizeof(valumno), 1, alumnos);
    }
    fclose(alumnos);
}

void alumnos_aprobados(FILE *alumnos) //por buenas practicas, los otros alumnoss deberian pasarse como params
{
    tvalumnos alumno;
    FILE *aprobados, *desaprobados;
    int i;

    alumnos = fopen("valumnos.dat", "rb");
    aprobados = fopen("aprobados.dat", "wb");
    desaprobados = fopen("aprobados.dat", "wb");

    fread(&alumnos, sizeof(alumnos), 1, alumnos);
    i = 0;

    while (!feof(alumnos)) {
        if (alumno[i].nota >= 4) 
            fwrite(&alumnos, sizeof(alumno), 1, aprobados);
        else 
            fwrite(&alumnos, sizeof(alumno), 1, desaprobados);

        fread(&alumnos, sizeof(alumnos), 1, alumnos);
    }

    fclose(aprobados);
    fclose(desaprobados);
    fclose(alumnos);
}