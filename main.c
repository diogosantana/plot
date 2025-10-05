#include <stdio.h>
#include <math.h>
#include <time.h>
#include "fibonacci_recursive.c"
#include "fibonacci.c"

int main(int argc, char const *argv[])   
{
    FILE* file = fopen("dist/test.txt", "w");

    int n = 10;

    for (int x = 0; x < n + 1; x++)
    {
        float y = 1 / (float)x;
        fprintf(file, "%d %f\n", x, y);
        
        // int y = pow(2, x);
        // fprintf(file, "%d %d\n", x, y);
    }
    fclose(file);

    printf("fibonnaci(12) = %d\n", fibonacci(12));
    printf("fibonnaci_recursive(12) = %d\n", fibonacci_recursive(12));

    int n2 = 40;

    struct timespec start, end;
    clock_t clock_start = clock();  

    clock_gettime(CLOCK_MONOTONIC, &start);
    
    printf("fibonnaci(%d) = %d\n", n2, fibonacci(n2));
    
    clock_gettime(CLOCK_MONOTONIC, &end);
    clock_t clock_end = clock();  
    clock_t diff = clock_end - clock_start;

    printf("diff: %lu ms\n", diff);
    
    uint64_t delta_us = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1000;
    printf("Time: %lu us\n", delta_us);

    // for(int i = 0; i < 10; i++) {
    //     printf("i: %d\n", i);
    // }

    clock_start = clock();  
    clock_gettime(CLOCK_MONOTONIC, &start);
    
    printf("fibonnaci_recursive(%d) = %d\n", n2, fibonacci_recursive(n2));

    clock_gettime(CLOCK_MONOTONIC, &end);
    
    clock_end = clock();
    diff = clock_end - clock_start;
    printf("diff: %lu ms\n", diff);

    delta_us = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1000;
    printf("Time: %lu us\n", delta_us);
}
