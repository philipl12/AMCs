#include <iostream>
using namespace std;

void print() {
    int i, j, k, l;

    typedef char box [5][7];

    box bb, wb, *board[8][8];

    //fills in board with respective "colors"
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 7; j++) {
            wb[i][j] = ' ';
            bb[i][j] = char(219);
        }
    }

    //fill board with pointers to respective colors
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) { board [i][j] = &wb; }
            else { board [i][j] = &bb; }
        }
    }

    //prints board with pointers to respective colors

    //upper border
    cout << "    ";
    for (i = 0; i < 7*8; i++) {
        cout << char(196);
    }
    cout << endl;

    //board actual
    for (i = 0; i < 8; i++) {
        for (k = 0; k < 5; k++) {
            cout << "   " << char(179); //left border

            for (j = 0; j < 8; j++) {
                for (l = 0; l < 7; l++) {
                    cout << (*board[i][j])[k][l];
                }
            }
            cout << char(179) << endl;
        }
    }

    //lower border
    cout << "    ";
    for (i = 0; i < 7*8; i++) {
        cout << char(196);
    }
    cout << endl;
}

int main() {
    int b[8][8] = {0}, r, c = 0;
    b[0][0] = 1;

    next_col:
    ++c;
    if (c == 8) { goto print; }
    r = -1;

    next_row:
    ++r;
    if (r == 8) { goto backtrack; }
    for (int i = 0; i < c; ++i) {
        if (b[r][i] == 1) { goto next_row; }
    }
    for (int i = 1; (r - i) >= 0 && (c - i) >= 0; ++i) {
        if (b[r - i][c - i] == 1) { goto next_row; }
    }
    for (int i = 1; (r + i) < 8 && (c - i) >= 0; ++i) {
        if (b[r + i][c - i] == 1) { goto next_row; }
    }
    b[r][c] = 1;
    goto next_col;

    backtrack:
    --c;
    if (c == -1) { return 0; }
    r = 0;
    while (b[r][c] != 1) {
        ++r;
    }
    b[r][c] = 0;
    goto next_row;

    print:
    
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            cout << b[i][j];
        }
        cout << endl;
    }

    //print();
    goto backtrack;
}
