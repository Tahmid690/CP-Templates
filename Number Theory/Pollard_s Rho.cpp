long long mult(long long a, long long b, long long mm) {
    return (__int128)a * b % mm;
}

long long f(long long x, long long c, long long mm) {
    return (mult(x, x, mm) + c) % mm;
}

long long rho(long long n, long long x0=2, long long c=1) {
	if(n%2==0) return 2;
    long long x = x0;
    long long y = x0;
    long long g = 1;
    while (g == 1) {
        x = f(x, c, n);
        y = f(y, c, n);
        y = f(y, c, n);
        g = __gcd(abs(x - y), n);
    }
    return g;
}