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
/*
void backtrack(int &c) {
    c--;
    if (c == -1) {
        cout << "All solutions found\n";
        exit(1);
    }
}
*/
void print(int q[]) {
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

    //Creates the queen pieces
    static box bq = { {char(219),char(219),char(219),char(219),char(219),char(219),char(219)},
                     {char(219),' '      ,char(219),' '      ,char(219),' '      ,char(219)},
                     {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
                     {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
                     {char(219),char(219),char(219),char(219),char(219),char(219),char(219)} };

    static box wq = { {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      },
                     {' '      ,char(219),' '      ,char(219),' '      ,char(219),' '      },
                     {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },
                     {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },
                     {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      } };

    //fill board with pointers to respective colors
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (j == q[i] && (i + j) % 2 == 0) {
                board[i][j] = &wq;
            }
            else if (j == q[i]) {
                board[i][j] = &bq;
            }
            else if ((i + j) % 2 == 0) { board[i][j] = &wb; }
            else { board[i][j] = &bb; }
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

void next(int q[], int c) {
  if (c == 8) { print(q); }
  else {
      for (q[c] = 0; q[c] < 8; q[c]++) {
          if (ok(q, c)) { next(q, c+1); }
      }
  }
}

int main() {
    int q[8];
    next(q, 0);
    return 0;
}
