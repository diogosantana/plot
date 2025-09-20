int fibonacci_recursive(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    int var = fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
    return var;
}
