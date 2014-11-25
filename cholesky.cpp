#include <cstdio>
#include <cmath>
#include <vector>
 
std::vector<double> cholesky(std::vector<double>& A, const int n)
{
    std::vector<double> L (n * n);
 
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
 
void show_matrix(std::vector<double> &A, const int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::printf("%2.5f ", A[i * n + j]);
        }
        std::printf("\n");
    }
}
 
int main()
{
    int n = 3;
    std::vector<double> m1 = {25, 15, -5,
                              15, 18,  0,
                              -5,  0, 11};
    std::vector<double> c1 = cholesky(m1, n);
    #ifdef DEBUG
    show_matrix(c1, n);
    std::printf("\n");
    #endif
 
    n = 4;
    std::vector<double> m2 = {18, 22,  54,  42,
                              22, 70,  86,  62,
                              54, 86, 174, 134,
                              42, 62, 134, 106};
    std::vector<double> c2 = cholesky(m2, n);
    #ifdef DEBUG
    show_matrix(c2, n);
    std::printf("\n");
    #endif
 
    return 0;
}
