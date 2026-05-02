# include <stdio.h>
# define MAX 20
#define CANT_VOCALES 4
typedef char Tvec[MAX];
typedef char t_vec[CANT_VOCALES];

void ingreso_palabra(Tvec palabra, int tamanio_1)
{
    for (int i = 0; i < tamanio_1; i++ ){
        printf("Ingrese la %i° letra", i+1);
        scanf("%c", palabra[i]);
    }
}

void cant_vocales(Tvec palabra, t_vec vocales, int tamanio_1, int tamanio_2, int *contador_vocales)
{
    *contador_vocales = 0;

    for (int i = 0; i < tamanio_1; i++){
        for (int j = 0; j < tamanio_2; j++){
            if (palabra[i] == vocales[j])
                (*contador_vocales)++;
        }
    }
}


int main(void)
{
    int contador_vocales;
    Tvec palabra;
    t_vec vocales = {"a", "e", "i", "o", "u"};
    int tamanio_1 = sizeof(palabra) / sizeof(palabra[0]);
    int tamanio_2 = sizeof(vocales) / sizeof(vocales[0]);

    printf("Ingrese una palabra con maximo 20 letras\n");
    ingreso_palabra(palabra, tamanio_1);

    cant_vocales(palabra, vocales, tamanio_1, tamanio_2, &contador_vocales);

    printf("\nLa palabra %i tiene %i vocales", palabra, contador_vocales);

    return 0;

}