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
        input = "";
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
        //loop to tally the team counts
        int teamNum = 0, runners = 0;
        for (int i = 65; i < 91; i++) {
            if (array[i] == 0) { continue; }
            if (array[i] > 0) { teamNum++; }
            if (array[i] > runners || (array[i] < runners && array[i] != 0)) {
                cout << "Uneven team numbers.\n";
                input =="done";
                break;
            }
            runners = array[i];
        }
        //this section does the job of printing team results
        cout << "There are " << teamNum << " teams.\n"
             << "Each team has " << runners << " runners\n";
        //input = "";
        j = 0;
        reset(array, 91);
    }

    return 0;
}
