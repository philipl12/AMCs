#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

bool ok(int q[], int c) {
    static int mp[3][3] = {
        {0, 2, 1},
        {0, 2, 1},
        {1, 2, 0}
    };
    static int wp[3][3] = {
        {2, 1, 0},
        {0, 1, 2},
        {2, 0, 1}
    };
    int nm = c, nw = q[c];

  for (int i = 0; i < c; i++) {
      if (q[c] == q[i]) { return false; }
  }

  for( int i = 0; i < c; i++) {
      int cm = i, cw = q[i];
      if (mp[cm][nw] < mp[cm][cw] && wp[nw][nm] > wp[nw][cm]) {
          return false;
      }
      if (mp[nm][cw] > mp[nm][nw] && wp[cw][nm] > wp[cw][cm]) {
          return false;
      }
  }
  return true;
}

void print (int q[], int c) {
    static int counter = 1;
    cout << "Solution # " << counter << endl;
    for (int i = 0; i < c; i++) {
      cout << q[i];
    }
    cout << endl;
    counter++;
}

void next(int q[], int c) {
  if (c == 3) { print(q, c); }
  else {
      for (q[c] = 0; q[c] < 3; q[c]++) {
          if (ok(q, c)) { next(q, c+1); }
      }
  }
}

int main() {
    int q[3];
    next(q, 0);
    return 0;
}
