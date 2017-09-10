#include <iostream>
#include <string>
using namespace std;

int main() {
    string input = "";
    int j = 0, array[91] = {0};
    while (input != "done") {
        cout << "Input outcome of race or done: ";//must be 65 - 90
        cin >> input;
        if (input == "done") { return 0; }
        while (j < input.length()) {
            for (int i = 65; i < 91; i++) {
            /*    if (input[j] < 'A' || input[j] > 'Z') {
                    cout << "You didn't enter an uppercase. Try again.\n";
                    break;
                }
            */
                if(input[j] == i) {
                    array[i]++;
                    cout << i << " " << array[i] << endl;
                    j++;
                }
            }
        }
        input = "";
        j = 0;
    }

    return 0;
}
