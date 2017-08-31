#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
    string input = "";
    cout << "Input outcome of race: ";//must be 65 - 90
    cin >> input;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] < 65 || input[i] > 90) {
            break;
        }
        cout << int(input[i]) << endl;
    }

    return 0;
}
