#include <stdio.h>
#include <math.h>
#include "fibonacci_recursive.c"
#include "fibonacci.c"

int main(int argc, char const *argv[])   
{
    FILE* file = fopen("test.txt", "w");

    //int writes = fwrite("Hello, World!\n", sizeof(char), 14, file);

    // if (writes != 14) {
    //     perror("fwrite");
    // }

    int n = 10;

    for (int x = 0; x < n + 1; x++)
    {
        int y = pow(2, x);

        fprintf(file, "%d %d\n", x, y);

        // fwrite("Hello, World!\n", sizeof(char), 14, file);
    }
    

    fclose(file);

    printf("fibonnaci(12) = %d\n", fibonacci(12));
    printf("fibonnaci_recursive(12) = %d", fibonacci_recursive(12));
}
