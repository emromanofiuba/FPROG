/*
Dado un vector a ordenado ascendente de longitud ml y un elemento p del
mismo tipo que los elementos del vector, insertar p en el vector a de modo
que siga ordenado. Validar previamente que en el vector haya espacio libre para
guardar el nuevo dato.
Se solicita resolver lo solicitado recorriendo una sola vez el vector y sin utilizar
un arreglo auxiliar.
*/

# include <stdio.h>
# define MF 10
typedef int t_vec[MF];

void ingreso_datos(t_vec vector, int mf, int *ml)
{
    int numero;
    *ml = 0;

    printf("\nIngrese un numero: ");
    scanf("%i", &numero);

    while ((numero != -1) && (*ml < mf)) {
        vector[*ml] = numero;
        (*ml)++;

        printf("Ingrese otro numero, -1 para terminar: ");
        scanf("%i", &numero);
    }
}

int ingreso_nuevo_elemento(t_vec vector, int ml)
{
    int p;
    printf("\nIngrese un numero para insertarlo al vector original: ");
    scanf("%i", &p);
    return p;
}

void insertar_numero(t_vec vector, int p, int *ml)
{
    int i = *ml - 1;

    while (i >= 0 && vector[i] > p) {
            vector[i + 1] = vector[i];
            i--;
        }
    
    vector[i + 1] = p;
    (*ml)++;
}

void mostrar_vector_resultante(t_vec vector, int ml)
{
    for (int i = 0; i < ml; i++) 
        printf(" %i", vector[i]);
    printf("\n");
}


int main(void)
{
    t_vec vector;
    int ml, mln, p;

    printf("A continuacion, debera ingresar una serie de numeros < 10\n");
    ingreso_datos(vector, MF, &ml);

    if (ml < MF) {
        p = ingreso_nuevo_elemento(vector, ml);
        insertar_numero(vector, p, &ml);
    }
    else 
        printf("\nEl vector ha llegado a su capacidad máxima\n");
    
    mostrar_vector_resultante(vector, ml);
}