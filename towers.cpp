#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> t[3];
    int n;
    cout << "Please enter the number of rings to move: ";
    cin >> n;
    cout << endl;
    int from = 0, to, candidate = 1, move = 0;
    if (n % 2 == 0) { to = 2; } // if/else for initiating correct
    else { to = 1; }            //  "to" tower

    // Initialize the towers
    for (int i = n + 1; i >= 1; --i) {
        t[0].push_back(i);
    }
    t[1].push_back(n + 1);
    t[2].push_back(n + 1);

    while (t[1].size() < n + 1) { // while t[1] doesn't contain all rings
        cout << "Move #" << ++move << ": Transfer ring " << candidate
             << " from tower " << char (from + 'A') << " to tower "
             << char (to + 'A') << "\n";

        candidate = t[from].back(); // make canditate equal to last element in from
        t[from].pop_back(); // delete last element in from
        t[to].push_back(candidate); // add candidate to correct tower

        // if/else is supposed to set the correct "from" tower
        if (t[(to + 1) % 3].back() < t[(to + 2) % 3].back()) {
            from = (to + 1) % 3;
        }
        else {
            from = (to + 2) % 3;
        }

        // if/else is supposed to set the correct "to" tower
        if (t[(from + 1) % 3].back() < t[from % 3].back()) {
            to = (from + 2) % 3;
        }
        else {
            to = (from + 1) % 3;
        }
    }
    return 0;
}
