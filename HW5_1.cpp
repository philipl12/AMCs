#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    int q[8], c = 0;
    q[0] = 0;

    next_col:
    ++c;
    if (c == 8) {
        goto print;
    }
    q[c] = -1;

    next_row:
    ++q[c];
    if (q[c] == 8) {
        goto backtrack;
    }
    for (int i = 0; i < c; ++i) {
        if (q[i] == q[c] || (c - i) == abs(q[c] - q[i])) {
            goto next_row;
        }
    }
    goto next_col;

    backtrack:
    --c;
    if (c == -1) {
        return 0;
    }
    goto next_row;

    print:
    for (int i = 0; i < 8; ++i) {
        cout << q[i] << " ";
    }
    cout << endl;
    goto backtrack;

    return 0;
}
