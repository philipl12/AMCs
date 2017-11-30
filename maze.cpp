#include <iostream>
using namespace std;

bool winnable(int maze[5][5], int startRow , int startCol) {

    return false;
}

int main() {
    int maze1[5][5] = {{0, 0, 0, 1, 1},
                       {1, 1, 0, 1, 1},
                       {0, 0, 0, 1, 1},
                       {0, 1, 1, 1, 1},
                       {0, 0, 0, 0, 0}};

   int maze2[5][5] = {{0, 0, 0, 0, 1},
                      {0, 1, 0, 1, 1},
                      {0, 1, 1, 0, 0},
                      {0, 0, 0, 1, 0},
                      {1, 0, 1, 0, 0}};

   int maze3[5][5] = {{0, 0, 0, 0, 1},
                      {0, 1, 1, 0, 1},
                      {0, 1, 1, 0, 1},
                      {0, 0, 1, 1, 1},
                      {1, 0, 0, 0, 0}};

   int maze4[5][5] = {{0, 1, 0, 0, 0},
                      {0, 1, 0, 1, 0},
                      {0, 0, 1, 0, 0},
                      {0, 1, 0, 1, 0},
                      {0, 0, 0, 1, 0}};

   cout << boolalpha; // to print bool values as true/false instead of 1/0
   cout << winnable(maze1, 0, 0) << endl;
   cout << winnable(maze2, 0, 0) << endl;
   cout << winnable(maze3, 0, 0) << endl;
   cout << winnable(maze4, 0, 0) << endl;
   return 0;
}
