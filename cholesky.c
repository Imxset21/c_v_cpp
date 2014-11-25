#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
double* cholesky(const double *restrict A, const int n)
{
    double *restrict L = calloc(n * n, sizeof(double));
 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (i+1); j++)
        {
            double s = 0;
            for (int k = 0; k < j; k++)
            {
                s += L[i * n + k] * L[j * n + k];
            }
            L[i * n + j] = (i == j) ?
                           sqrt(A[i * n + i] - s) :
                           (1.0 / L[j * n + j] * (A[i * n + j] - s));
        }
    }
    return L;
}
 
void show_matrix(const double *restrict A, const int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%2.5f ", A[j * n + i]);
        }
        printf("\n");
    }
}
 
int main()
{
    int n = 3;
    double m1[] = {25, 15, -5,
                   15, 18,  0,
                   -5,  0, 11};
    const double *restrict c1 = cholesky(m1, n);
    
    #ifdef DEBUG
    show_matrix(c1, n);
    printf("\n");
    #endif
    
    free((void*) c1);
 
    n = 4;
    double m2[] = {18, 22,  54,  42,
                   22, 70,  86,  62,
                   54, 86, 174, 134,
                   42, 62, 134, 106};
    const double *restrict c2 = cholesky(m2, n);
    
    #ifdef DEBUG
    show_matrix(c2, n);
    printf("\n");
    #endif
    
    free((void*) c2);
 
    return EXIT_SUCCESS;
}
