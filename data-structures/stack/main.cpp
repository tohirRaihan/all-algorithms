#include "MYSTACK.h"
#include <iostream>
using namespace std;

int main(void) {
  Stack st;
  st.push(1);
  st.push(2);
  st.push(3);
  while (!st.empty()) {
    cout << st.pop() << endl;
  }
  return 0;
}