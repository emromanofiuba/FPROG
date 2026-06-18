# include <stdio.h>

void intercalar_a_b(int a[], int b[], int c[], int n, int m)
{
    int i, j, k;
    i = k = 0;
    j = m - 1;

    while (i < n && j >= 0) {
        if (a[i] <= b[j]) {
            c[k] = a[i];
            k++;
            i++;
        }
        else {
            c[k] = b[j];
            k++;
            j--;
        }
    }

    while (i < n) {
            c[k] = a[i];
            i++;
            k++;
        }
    while (j >= 0) {
            c[k] = b[j];
            j--;
            k++;
        }
}

void mostrar_resultante(int vec[], int n, int m)
{
    int i;
    for (i = 0; i < n + m; i++)
        printf(" %i", vec[i]);
}
int main()
{
    int n, m;
    int a[] = {1, 3, 5, 7, 9};
    int b[] = {8, 6, 4};
    n = sizeof(a) / sizeof(a[0]);
    m = sizeof(b) / sizeof(b[0]);
    int c[n+m];

    intercalar_a_b(a, b, c, n, m);

    mostrar_resultante(c, n, m);

    return 0;
}