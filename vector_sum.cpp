#include <cstdio>
#include <vector>
#include <numeric>

#define VEC_LEN 100000
#define CONST_VAL 0.15

static double myadd(const double x, const double y)
{
    return x + y + CONST_VAL;
}

int main()
{
    std::vector<double> vec(VEC_LEN);

    std::printf("Last element: %f\n",
                std::accumulate(vec.begin(), vec.end(), 0.0, myadd));

    return 0;
}
