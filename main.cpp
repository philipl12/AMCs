#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

int main(int argc, char** argv) {
    int letters[256];
    ifstream fileIn;
    char myChar;

    for (int i = 0; i < 256; i++) {
        letters[i] = 0;
    }
    /*
    cout << "It has " << argc << " arguments:" << endl;
    for (int i = 0; i < argc; ++i) {
        cout << argv[i] << endl;
    }
    */
    for (int i = 1; i < arc; i++) {
        fileIn.open(argv[i]);

        while (!fileIn.eof()) {
            fileIn.get(myChar);

            for (int i = 0; i < 256; i++) {
                if ((int)myChar == i) {
                    letters[i]++;
                    break;
                }
            }

        }

        for (int i = 32; i < 256; i++) {
            if (letters[i] > 0) {
                cout << (char)i << "   " << letters[i] << endl;
            }
        }
    }

    return 0;
}
