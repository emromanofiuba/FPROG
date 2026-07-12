#include <stdio.h>
#define MAX 20
#define MAX_TURNOS 3
typedef int t_turno[MAX_TURNOS];
typedef struct {
    int numero;
    char apellido[30];
    char nombre[30];
    t_turno turnos;
    int cant_turnos;
}t_alumno;

void carga_alumnos(t_alumno alumnos[MAX], int *mla)
{
    int mlt, numero, turno;
    mlt = 0;
    *mla = 0;

    printf("Numero del alumno %i (0 para terminar)", *mla+1);
    scanf("%i", &numero);
    while (*mla < MAX && numero != 0) {
        alumnos[*mla].numero = numero;

        printf("Apellido: ");
        scanf("%s", alumnos[*mla].apellido);
        printf("Nombre: ");
        scanf("%s", alumnos[*mla].nombre);

        printf("Turno (maximo 3 (1, 2, 3), 0 para terminar): ");
        scanf("%i", &turno);
        while (mlt < MAX_TURNOS && turno != 0) {
            alumnos[*mla].turnos[mlt] = turno;
            mlt++;
            printf("Turno (maximo 3 (1, 2, 3), 0 para terminar): ");
            scanf("%i", &turno);
        }
        alumnos[*mla].cant_turnos = mlt;
        mlt = 0;

        (*mla)++;
        printf("Numero del alumno %i (0 para terminar)", *mla+1);
        scanf("%i", &numero);
    }

}

void generar_listado_unico(t_alumno alumnos_1[MAX], t_alumno alumnos_2[MAX], int ml1, int ml2, t_alumno alumnos_tot[MAX+MAX], int *mlu)
{
    int i, j, k;
    i = j = k = 0;

    while (i < ml1 && j < ml2) {
        if (alumnos_1[i].numero <= alumnos_2[j].numero) {
            alumnos_tot[k] = alumnos_1[i];
            i++;
            k++;
        }
        else {
            alumnos_tot[k] = alumnos_2[j];
            j++;
            k++;
        }
    }

    while (i < ml1) {
        alumnos_tot[k] = alumnos_1[i];
        i++;
        k++;
    }

     while (j < ml2) {
        alumnos_tot[k] = alumnos_2[j];
        j++;
        k++;
    }
    
    *mlu = k;
}

void mostrar_listado(t_alumno alumnos_tot[MAX+MAX], int ml) 
{
    int i, j;

    for (i = 0; i < ml; i++) {
        printf("\nApellido: %s | Nombre: %s\n", alumnos_tot[i].apellido, alumnos_tot[i].nombre);
        printf("Turnos: ");
        for (j = 0; j < alumnos_tot[i].cant_turnos; j++)
            printf(" %i", alumnos_tot[i].turnos[j]);
    }
}

int main() {
    t_alumno alumnos_1[MAX];
    t_alumno alumnos_2[MAX];
    t_alumno alumnos_tot[MAX+MAX];
    int ml1, ml2, mlu;
    
    carga_alumnos(alumnos_1, &ml1);
    carga_alumnos(alumnos_2, &ml2);

    //ordenar_alumnos() no hace falta porque el ejercicio los asume ordenados por numero de alumno
    generar_listado_unico(alumnos_1, alumnos_2, ml1, ml2, alumnos_tot, &mlu);
    mostrar_listado(alumnos_tot, mlu);

    return 0;
}

