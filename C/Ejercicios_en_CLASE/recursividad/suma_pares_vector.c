//Una función recursiva en C que suma los elementos en las posiciones pares de un arreglo
#define MAX 20
typedef int Tvector[MAX];

int suma(Tvector vector, int ml)
{
    if (ml > 0) {
        if((ml -1)%2 == 0)
            return vector[ml-1] + suma(vector, ml-2);
        else 
            return suma(vector, ml-1);
    }
    else
        return 0;
}
