#include <iostream>
using namespace std;

typedef double (*FUNC)(double);

double line (double x) { return x; }

double square (double x) { return x*x; }

double cube (double x) { return x*x*x; }

int integrate(FUNC f, int n) {
    return f(n);
}

int main() {
    int n = 0;
    cout << "Enter a number: ";
    cin >> n;
    cout << integrate(line, n) << endl;
    cout << integrate(square, n) << endl;
    cout << integrate(cube, n) << endl;
    return 0;
}
