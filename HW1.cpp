#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

bool checker(int q[], int c) {
    for (int i = 0; i < c;  i++) {
        if (q[i] == q[c] || (c - i) == abs(q[c] - q[i])) {
            return false;
        }
    return true;
    }
}

void backtrack(int &c) {
    c--;
    if (c == -1) {
        cout << "All solutions found\n";
        exit(1);
    }
}

void print_board(int q[]) {
    for (int i = 0; i < 8; i++) {
        cout << q[i] << " ";
    }
    cout << endl;
}

int main() {
    int q[8], c = 0;
    q[0] = 0;
    bool from_backtrack = false;

    while (true) {

        while (c < 8) {
            if (!from_backtrack) {
                c++;
                if (c == 8) { break; }
                q[c] = -1;
            }
            from_backtrack = false;

            while (q[c] < 8) {
                q[c]++;
                if (q[c] == 8) {
                    from_backtrack = true;
                    backtrack(c);
                    break;
                }
                if (checker(q, c)) {
                    from_backtrack = true;
                    c++;
                    break;
                }
            }
        }
        print_board(q);
        backtrack(c);
        from_backtrack = true;
    }
}
