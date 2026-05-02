/* PROBLEMA 
1. realizar la carga de notas
2. calcular el promedio de la carga de notas
3. mostrar las notas superiores al promedio
*/

# include <stdio.h>
# define MAX 50
typedef int Tvec[MAX];


void cargar_notas(Tvec vec, int *ML)
{
    int nota;
    *ML = 0;

    printf("Ingrese una nota, -1 para terminar: ");
    scanf("%i", &nota);

    while ((nota != -1) && (*ML < MAX)){
        vec[*ML] = nota;
        (*ML)++;

        printf("Ingrese otra nota, -1 para terminar: ");
        scanf("%i", &nota);
    }
}


float calcular_promedio(Tvec vec, int ML)
{
    int suma_notas = 0;
    int i;
    float promedio = 0;

    for (i = 0; i < ML; i++)
        suma_notas += vec[i];
    
    if (ML > 0)
        promedio = (float)suma_notas / ML;
    
    return promedio;
    
}


void notas_superiores_promedio(Tvec vec, int ML)
{
    int i;

    for (i = 0; i < ML; i++){
        if (vec[i] > calcular_promedio(vec, ML))
            printf("%i\n", vec[i]);
    }
}


void main()
{
    Tvec vec[MAX];
    int ML, i;

    cargar_notas(vec, &ML);

    if (ML != 0){
       printf("El promedio de las notas es: %f", calcular_promedio(vec, ML));
       printf("\nLas notas superiores al promedio son\n");
       notas_superiores_promedio(vec, ML);
    }
    else
        printf("\nNo se ingresaron notas\n");

}