//Una función recursiva que sume la diagonal principal de una matriz cuadrada
#define MAX 20
typedef int Tmatriz[MAX][MAX];

int suma_diagonal(Tmatriz matriz,int ml)
{
    if (ml > 0)
        return matriz[ml-1][ml-1] + suma_diagonal(matriz, ml-1);
    else
        return 0; 
}
