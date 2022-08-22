#include <iostream>
using namespace std;

template <typename T> T myMax(T a, T b) { return a > b ? a : b; }

int main(void) {
  cout << myMax<int>(2, 3) << endl;
  cout << myMax<float>(2.5, 3.2) << endl;
  cout << myMax<char>('2', 'a') << endl;
  return 0;
}
