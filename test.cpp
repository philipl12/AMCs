#include <iostream>
#include <ctime>
using namespace std;

int main() {
  srand(time(NULL));
  int length = 0;
  while(length <= 0) {
    cout << "Enter desired password length:";
    cin >> length;
  }
  char *array = new char[length];
  int *b = new int[length];
  for (int i = 0; i < length; ++i) {
    b[i] = rand()% 94 + 33;
    array[i] = (char)b[i];
    cout << array[i];
  }
  cout << endl << endl;
  delete []array;
  return 0;
}
