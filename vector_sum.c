#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define VEC_LEN 100000
#define CONST_VAL 0.15

#define USE_PTR 0

int main()
{
    #ifdef USE_PTR
    double* restrict vec = (double*) calloc(VEC_LEN, sizeof(double));
    #else
    double vec[VEC_LEN];
    #endif
    
    vec[0] = CONST_VAL;
    
    for (uint64_t i = 1; i < VEC_LEN; i++)
    {
        vec[i] = vec[i-1] + CONST_VAL;
    }

    printf("Last element: %f\n", vec[VEC_LEN-1]);
    #ifdef USE_PTR
    free(vec);
    #endif
    
    return EXIT_SUCCESS;
}
