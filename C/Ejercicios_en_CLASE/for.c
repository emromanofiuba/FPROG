# include <stdio.h> 

//Imprimir los primeros 10 numeros pares 

int main(){
    int contador;

    for (contador=2; contador<=10; contador+=2)
        printf("%3i\n", contador);

    return 0;
}