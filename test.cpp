#include <iostream>
using namespace std;

bool leapYear(int n) {
    return n % 4 == 0;
    return false;
}

int main() {
    if (leapYear(1990)) { cout << "Leap year!!\n"; }
    else { cout << "Not a leap year\n"; }
    return 0;
}
