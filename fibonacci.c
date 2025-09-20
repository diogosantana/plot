int fibonacci(int n) {
    int f[n];
    f[0] = 1;
    f[1] = 1;        
    for (int i = 2; i < n; i++){

        // formula matematica: f(n) = f(n-1) + f(n-2)
        // 0  1  2  3
        // 1  1  2   
        f[i] = f[i-1] + f[i-2];
    }    
    return f[n-1];
}
