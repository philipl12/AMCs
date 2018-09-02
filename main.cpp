#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

int main(int argc, char** argv) {
    /*
    cout << "It has " << argc << " arguments:" << endl;
    for (int i = 0; i < argc; ++i) {
        cout << argv[i] << endl;
    }

    FILE * pFile;
    char buffer[10000];

    pFile = fopen (argv[1] , "r");
    if (pFile == NULL) perror ("Error opening file");
    else {
        while ( ! feof (pFile) ) {
            if ( fgets (buffer , 10000 , pFile) == NULL ) break;
            fputs (buffer , stdout);
        }
    fclose (pFile);
    }
    */
    ifstream fileIn;
    fileIn.open(argv[1]);

    char myChar;

    while (!fileIn.eof()) {
        fileIn.get(myChar);
        cout << myChar << endl;
    }

    return 0;
}
