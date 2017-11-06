#include <iostream>
#include <cmath>
using namespace std;

bool ok(int n);

int primes(int a, int b);

int main() {
    cout << primes(2, 100) << endl;
    return 0;
}

bool ok(int n) {
    for(int i = 2; i < n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int primes(int a, int b) {
    int count = 0;
    for (int i = a; i <= b; ++i) {
        if (ok(i)) ++count;
    }
    return count;
}
