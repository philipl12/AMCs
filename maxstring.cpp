#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    map <string, int> d;
    vector <string> in
           {"hello", "one", "hello", "bye", "glerp", "one", "hello"};

    for(auto i : in) {
        if (d.find(i) == d.end()) d[i] = 1;
        else d[i]++;
    }

    int max = 0;
    string val;

    for (auto i: d) {
        cout << i.first << " found " << i.second << " times.\n";
        if (i.second > max) {
            val = i.first;
            max = i.second;
        }
    }
    cout << "The string most found is: " << val
         << ". It was found " << max << " times.\n";
    return 0;
}
