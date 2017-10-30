#include <iostream>
using namespace std;

unsigned long long fib(unsigned long long n) {
    if (n == 1 || n == 2) { return 1; }
    return fib(n - 1) + fib(n - 2);
}
/*
unsigned long long fib(unsigned long long n) {
    static int memo[1000] = {0};
    if (n == 1 || n == 2) { return 1; }
    if (memo[n] != 0) return memo[n];
    return neni[x] = fib(n - 1) + fib(n - 2);
}
*/
int main() {
    for (unsigned long long i = 0; i < 70; i++) {
        cout << "fib ("<<i<<") = " << fib(i) << endl;
    }
    return 0;
}
