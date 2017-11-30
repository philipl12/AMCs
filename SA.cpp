#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;

class SA {

private:
    int low, high;
    int* p;

public:
    // default
    SA() {
        low = 0;
        high = -1;
        p = NULL;
    }

    // 2 parameter: SA x(10, 20)
    SA(int l, int h) {
        if ((h - l + 1) <= 0) {
            cout << "Constructor error in bounds definition" << endl;
            exit(1);
        }
        low = l;
        high = h;
        p = new int[h + 1];
    }

    // single parameter: SA x(10)
    SA(int i) {
        low = 0;
        high = i -1;
        p = new int[i];
    }

    // copies constructor for pass by value and initialization
    SA(const SA &s) {
        int size = s.high - s.low + 1;
        p = new int[size];
        for(int i = 0; i < size; i++) {
            p[i] = s.p[i];
        }
        low = s.low;
        high = s.high;
    }

    // destroyer!!!
    ~SA() { delete[] p; }

    // overloaded []: SA x(10, 20); x[15] = 100
    int& operator[](int i) {
        if(i < low || i > high) {
            cout << "Index " <, i << " is out of range" << endl;
            exit(1);
        }
        return p[i - low];
    }

    // overloaded assignment: assign one SA to another
    SA & operator=(const SA &s) {
        if (this == &s) return *this;
        delete[] p;
        int size = s.high - s.low + 1;
        p = new int[size];
        for (int i = 0; i < size; i++) {
            p[i] = s.p[i];
        }
        low = s.low;
        high = s.high;
        return *this;
    }

    // overloads << so we can directly print SAs
    friend ostream& operator<<(ostream& os, SA s);
}; // end SA class

ostream& operator<<(ostream& os, SA s) {
    int size = s.high - s.low + 1;
    for (int i = 0; i < size; i++) {
        cout << s.p[i] << endl;
    }
    return os;
};

int main() {
    SA a(10), b(3, 5);
    b[3] = 3;
    b[4] = 4;
    b[5] = 5;
    int i;
    for (int i = 0; i < 10; i++) {
        a[i] = 10 - 1;
    }

    cout << "Printing a the first time:" << endl;
    cout << a << endl;

    cout << "Printing using []:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << a[i] << endl;
    }

    //Sort(a, 10);

    cout << "Printing a the second time:" << endl;
    cout << a << endl;

    b[4] = 12;
    cout << "Printing b:" << endl;
    cout << b << endl;
    return 0;
}
