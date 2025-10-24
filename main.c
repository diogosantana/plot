#include <stdio.h>
#include <math.h>
#include <time.h>
#include "fibonacci_recursive.c"
#include "fibonacci.c"
#include <Windows.h>
#include <inttypes.h>


int main(int argc, char const *argv[])
{
    LARGE_INTEGER StartingTime, EndingTime, ElapsedMicroseconds;
    LARGE_INTEGER Frequency;

    QueryPerformanceFrequency(&Frequency);
    QueryPerformanceCounter(&StartingTime);

    FILE *file = fopen("dist/test.txt", "w");

    int n = 10;

    for (int x = 0; x < n + 1; x++)
    {
        float y = 1 / (float)x;
        fprintf(file, "%d %f\n", x, y);

        // int y = pow(2, x);
        // fprintf(file, "%d %d\n", x, y);
    }
    fclose(file);

    QueryPerformanceCounter(&EndingTime);
    ElapsedMicroseconds.QuadPart = EndingTime.QuadPart - StartingTime.QuadPart;

    ElapsedMicroseconds.QuadPart *= 1000000;
    ElapsedMicroseconds.QuadPart /= Frequency.QuadPart;

    printf("diff Arquivo: %lld us\n", ElapsedMicroseconds.QuadPart);





    int n2 = 92;
    double times[n2]; 

    uint64_t fib;

    for (int i = 1; i <= n2; i++) {
        QueryPerformanceCounter(&StartingTime);
        
        fib = fibonacci(i);
        
        QueryPerformanceCounter(&EndingTime);
        double elapsed = (double)(EndingTime.QuadPart - StartingTime.QuadPart) * 1000000000.0 / Frequency.QuadPart;
        printf("1 - fibonnaci(%d) = %ld - time: %.0f ns\n", i, fib, elapsed);
        times[i - 1] = elapsed;
    }

    // for(int i = 0; i < 10; i++) {
    //     printf("i: %d\n", i);
    // }
    
    // QueryPerformanceCounter(&StartingTime);

    // fib = fibonacci_recursive(n2);
    
    // QueryPerformanceCounter(&EndingTime);
    // elapsed = (double)(EndingTime.QuadPart - StartingTime.QuadPart) * 1000000000 / Frequency.QuadPart;
    // printf("Time fib recursive (%i): %.0f us\n", n2, elapsed);

    // printf("fibonnaci_recursive(%d) = %ld\n", n2, fib);


    file = fopen("dist/fibo-recursive-microseconds.txt", "w");

    for (int x = 0; x < n2; x++)
    {
        double time = times[x];
        if (time > 1.0) {
            fprintf(file, "%d %.3f\n", x + 1, time);
        }
    }
    fclose(file);


}
