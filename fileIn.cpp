#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    string myArray[10];
    ifstream inFile("file.txt");
    if(inFile.is_open()) {
        for(int i = 0; i < 10; i++) {
            inFile >> myArray[i];
        }
    }
    for (int i = 0; i < 10; i++) {
        cout << myArray[i] << endl;
    }
    return 0;
}
