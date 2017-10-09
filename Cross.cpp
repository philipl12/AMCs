#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

bool ok(int q[], int c) {
  static int adj[8][4] = {
    {-1},             //0
    {0, -1},          //1
    {1, -1},          //2
    {0, 1, 2, -1},    //3
    {1, 2, 3, -1},    //4
    {0, 3, 4, -1},    //5
    {3, 4, 5, -1},    //6
    {2, 4, 6, -1}     //7
  };

  for (int i = 0; i < c; i++) {
      if (q[c] == q[i]) { return false; }
  }

  for( int i = 0; adj[c][i] != -1; i++) {
    if (abs(q[c] - q[adj[c][i]]) == 1) { return false; }
  }

  return true;
}

void print (int q[]) {
  static int counter = 1;
  cout << "Solution # " << counter << endl;
  cout << " " << q[1] << q[2] << endl;
  cout << q[0] << q[3] << q[4] << q[7] << endl;
  cout << " " << q[5] << q[6] << endl;

  counter++;
}

void next(int q[], int c) {
  if (c == 8) { print(q); }
  else {
    for (q[c] = 0; q[c] < 8; q[c]++) {
      if (ok(q, c)) { next(q, c+1); };
    }
  }
}

int main() {
  int q[8];
  next(q, 0);
  return 0;
}
