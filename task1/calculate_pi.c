#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char** argv) {
    long long N = (argc > 1) ? atoll(argv[1]) : 100000000LL;
    long long hits = 0;

    #pragma omp parallel reduction(+:hits)
    {
        unsigned int seed = omp_get_thread_num() * 1234567u + 1u;

        #pragma omp for
        for (long long i = 0; i < N; ++i) {
            double x = 2.0 * rand_r(&seed) / RAND_MAX - 1.0;
            double y = 2.0 * rand_r(&seed) / RAND_MAX - 1.0;
            if (x*x + y*y <= 1.0)
                hits += 1;
        }
    }

    double pi = 4.0 * (double)hits / (double)N;
    printf("N = %lld, hits = %lld\n", N, hits);
    printf("pi ~ %.10f  (ошибка ~ %.2e)\n", pi, pi - 3.141592653589793);
    return 0;
}