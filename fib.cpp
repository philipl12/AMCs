#include <iostream>
using namespace std;

unsigned long long fib(unsigned long long n) {
    static int memo[100] = {0};
    if (n == 1 || n == 2) { return 1; }
    if (memo[n] != 0) return memo[n];
    return memo[n] = fib(n - 1) + fib(n - 2);
}

int main() {
    for (unsigned long long i = 1; i <= 47; i++) {
        cout << "fib ("<<i<<") = " << fib(i) << endl;
    }
    return 0;
}
