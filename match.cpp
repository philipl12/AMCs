#include <iostream>
using namespace std;

int* return_matches(int a[], int& size, TEST t);

typedef bool (*TEST)(int);

bool even(int n) {
    return n % 2 == 0;
}

bool odd(int n) {
    return n % 2 == 1;
}

int main() {
    int a[100];
    for (int i = 0; i < 100; ++i) {
        a[i] = i + 1;
    }
    int* b = return_matches(a, 100, odd);
    //return_matches(a, 100, even);
    return 0;
}

int* return_matches(int a[], int& size, TEST t) {
    int count = 0;
    int* b = new int[size];
    for (int i = 0; i < size; ++i) {
        if (t(a[i])) {
            b[count] = a[i];
            ++count;
        }
    }
    return b;
}
