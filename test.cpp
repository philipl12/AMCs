#include <iostream>
using namespace std;

int main() {
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

    return 0;
}
