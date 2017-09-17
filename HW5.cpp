#include <iostream>
#include <stdio.h>
using namespace std;

bool checker(int q[], int c) {
    for (int i = 0; i < c; ++i) {
        if (q[i] == q[c] || (c - i) == abs(q[c] - q[i])) {
            return false;
        }
    return true;
    }
}

void backtrack(int c) {
    c--;
    if (c == -1) {
        cout << "All solutions found\n";
        exit(0);
    }
}

void print_board(int q[]) {
    for (int i = 0; i < 8; ++i) {
        cout << q[i] << " ";
    }
    cout << endl;
}

int main() {
    int q[8], c = 0;
    q[0] = 0;
    while (true) {
        while (c < 8) {
            c++;
            if (q[c] == 8) { print_board(q); }
            q[c] = -1;

            while (q[c] < 8) {
                q[c]++;
                if (q[c] == 8) {
                    backtrack(c);
                    break;
                }
                if (checker(q, c)) {
                    c++;
                    break;
                }
            }
        }
        print_board(q);
        backtrack(c);
    }

    return 0;
}
