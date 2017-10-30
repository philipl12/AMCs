#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

bool ok(int q[], int c) {
    for (int i = 0; i < c;  i++) {
        if (q[i] == q[c] || (c - i) == abs(q[c] - q[i])) {
            return false;
        }
    }
    return true;
}

void print(int q[]) {
    static int counter = 0;
    delete [] q;
}

void next(int q[], int c, int i) {
  if (c == i) { print(q); }
  else {
      for (q[c] = 0; q[c] < nCopy; q[c]++) {
          if (ok(q, c)) { next(q, c+1); }
      }
  }
}

int main() {
    int n = 0;
    while (n <= 0) {
        cout << "Enter a number: ";
        cin >> n;
    }
    for (int i = 0; i < n; i++) {
        next(q, 0, i)
    }
    return 0;
}
