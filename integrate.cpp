#include <iostream>
using namespace std;

typedef double (*FUNC)(double);

double integrate(FUNC f, double a, double b) {
    static double base = .0001;
    double height = a, sum = 0;
    while (height <= b) {//correct loop
        f(height);//height not incrementing
        sum += base*height;
        height += base;
    }
    return sum;
}

double line (double x) { return x; }

double square (double x) { return x*x; }

double cube (double x) { return x*x*x; }

int main() {
    cout << "The integral of f(x) = x between 1 and 5 is: "
         << integrate(line, 1, 5) << endl;
    cout << "The integral of f(x) = x^2 between 1 and 5 is: "
         << integrate(square, 1, 5) << endl;
    cout << "The integral of f(x) = x^3 between 1 and 5 is: "
         << integrate(cube, 1, 5) << endl;
    return 0;
}
