#include <iostream>
#include <string.h>
#include <array>
using namespace std;

void reset(int a[], int n) {
    for (int i = 65; i < n ; i++) {
        a[i] = 0;
    }
}

int main() {
    string input = "";
    int j = 0, runners = 0, teamNum = 0, top = 1000000, winner = 0;
    int position[91] = {0}, array[91] = {0};
    //while (input != "done") { //loops the input process
        start: cout << "Input uppercase letters or \"done\": ";
        cin >> input;
        if (input == "done") { return 0; }
        while (j < input.length()) { //use this to go through string array
            //purposely start array at 65 so that
            //array[i] corresponds with input[j]
            for (int i = 65; i < 91; i++) {
                if (input[j] == i) {
                    array[i]++;
                    position[i] += (j + 1);
                    j++;
                }
            }
        }
        j = 0;
        //loop to tally the team counts
        for (int i = 65; i < 91; i++) {
            if (array[i] == 0) { continue; }
            if (array[i] > 0) {
                runners = array[i];
                teamNum++;
            }
            if (array[i] > runners || array[i] < runners) {
                cout << "Uneven team numbers.\n";
                goto end;
            }
        }

        //this section does the job of printing team results
        cout << "There are " << teamNum << " teams.\n\n"
             << "Each team has " << runners << " runner(s)\n\n"
             << "Team   Score\n";
        for (int i = 65; i < 91; i++) {
            if (position[i] == 0) { continue; }
            if (position[i] != 0) {
                cout << char(i) << "      " << position[i] / (double)runners
                     << endl;
            }
            if (position[i] < top) {
                top = position[i];
                winner = i;
            }
        }
        cout << "The winning team is team " << char(winner)
             << " with a score of " << (double)top / runners << ".\n";
        end: input = "";
        j = 0, teamNum = 0, runners = 0, top = 1000000, winner = 0;
        reset(array, 91);
        reset(position, 91);
        goto start;
    //}

    return 0;
}
