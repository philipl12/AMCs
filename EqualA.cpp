#include <iostream>
using namespace std;

void shifter (int array[], int n) {
    for (int i = 1; i < n; i++) {
        int temp = array[i];
        array[i] = array[i - 1];
        array[i - 1] = temp;
    }
}

bool equivalent(int a[], int b[], int n) {
    int copy[n], count = 0;
    for (int i = 0; i < 5; i++) {
        copy[i] = a[i];
    }
    while (count <= 5) {
        shifter(copy, n);
        for (int i = 0; i < n; i++) {
            if (copy[i] != b[i]) {
                break;
            }
            if (copy[i] == b[i] && i == (n - 1)) {
                return true;
            }
        }
        count++;
    }
    return false;
}

int main() {
    /*
    This short loop will print out
    the first perfect square root
    only if the last two digits match
    */
    int j = 0;
    for (int i = 0; ; i++) {
        j = i * i;
        if (j > 9) {
            if (((j % 10) % 2 == 0) && ((j % 10 / 10) % 2 == 0)) {
                continue;
            }
            cout << "The perfect square is " << i << endl;
            break;
        }
    }

    /*
    This part uses functions
    in order to complete the task
    of checking for equivalence
    */
    int a[5] = {1, 2, 3, 4, 5}, b[5] = {3, 4, 5, 1, 2};
    if (equivalent(a, b, 5)) {
        cout << "They are equivalent\n";
    }
    else {
        cout << "They are not equivalent\n";
    }

    return 0;
}
