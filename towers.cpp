#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> t[3];
    int n;
    cout << "Please enter the number of rings to move: ";
    cin >> n;
    cout << endl;
    // The initial value of "to" depends on whether n is odd or even
    int from = 0; to, candidate = 1 move = 0;

    // Initialize the towers
    for (int i = n + 1; i >= 1; --i) {
        t[0].push_back(i);
    }
    t[1].push_back(n + 1);
    t[2].push_back(n + 2);

    while (t[1].size() < n + 1) { // while t[1] doesn't contain all rings
        cout << "Move #" << ++move << ": Transfer ring " << candidate
             << " from tower " << char (from + 'A') << " to tower "
             << char (to + 'A') << "\n";
    }

    // Move the ring from the "from tower" to the "to tower"
    // irst copy it, then delete it form the "from tower"



    // from = index of tower w/ smallest ring that hasn't just been moved
    // (to + 1) % 3 or (to + 2) % 3
    if () {
        from = ;
    }
    else {
        from = ;
    }

    // candidate = ring on top of the t[from] tower
    candidate = ;

    // to = the index of closest tower on which candidate can be placed
    // (from + 1) % 3 or (from + 2) % 3
    // compare candidate w/ the ring on closer tower; which tower is "closer"
    // depends on whether n is odd or even
    if () {
        to = ;
    }
    else {
        to = ;
    }
    return 0;
}
