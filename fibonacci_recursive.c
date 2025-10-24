#include <inttypes.h>

uint64_t fibonacci_recursive(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    uint64_t var = fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
    return var;
}
