#include <iostream>
using namespace std;

const int rows = 5;
const int cols = 6;

int calculateCost(int i, int j) {
    int weight[rows][cols] = {
    {3, 4, 1, 2, 8, 6},
    {6, 1, 8, 2, 7, 4},
    {5, 9, 3, 9, 9, 5},
    {8, 4, 1, 3, 2, 6},
    {3, 7, 2, 8, 6, 4}};
/*
    static int weight[rows][cols] = {
    {3, 4, 1, 2, 8, 6},
    {6, 1, 8, 2, 7, 4},
    {5, 9, 3, 9, 9, 5},
    {8, 4, 1, 3, 2, 6},
    {3, 7, 2, 1, 2, 3}};

    static int cost[rows][cols] = {0};
    if (cost[i][j] != 0) {
        return cost[i][j];
    }
*/
    // base case
    if (j == 0) {
         return weight[i][0];
    }

    // recursive call
    int left = calculateCost(i, j - 1);
    int up = calculateCost((i - 1 + rows) % rows, j - 1);
    int down = calculateCost((i + 1) % rows, j - 1);

    int min = left;
    if (up < min) min = up;
    else if (down < min) min = down;
    return min + weight[i][j];
}

int main() {
    int ex[rows];

    // get the shortest path out of each cell on the right
    for (int i = 0; i < rows; ++i) {
        ex[i] = calculateCost(i, cols - 1);
    }

    int min = 100;

    for (int i = 0; i < rows; ++i) {
        if (ex[i] < min) min = ex[i];
    }

    cout << "The shortest path is of length " << min << endl;
    return 0;
}
