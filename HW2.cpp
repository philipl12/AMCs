#include <iostream>
#include <string.h>
#include <array>
using namespace std;

void reset(int a[], int n) {
    for (int i = 0; i < n ; i++) {
        a[i] = 0;
    }
}

int main() {
    string input = "";
    int j = 0, array[91] = {0};
    while (input != "done") { //loops the input process
        cout << "Input outcome of race or done: ";
        cin >> input;
        if (input == "done") { return 0; }
        while (j < input.length()) { //use this to go through string array
            //purposely start array at 65 so that
            //array[i] corresponds with input[j]
            for (int i = 65; i < 91; i++) {
                if(input[j] == i) {
                    array[i]++;
                    j++;
                }
            }
        }

        //this section does the job of printing team results
        int teamNum = 0;
        for (int i = 65; i < 91; i++) {
            if (array[i] == 0) { continue; }
            teamNum = array[i];
        }

        input = "";
        j = 0;
        reset(array, 91);
    }

    return 0;
}
