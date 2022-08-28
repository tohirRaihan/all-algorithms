#include "MYSTACK.h"
#include <iostream>
using namespace std;

int main(void) {
  Stack<int> st;
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(4);
  st.push(5);
  st.push(6);
  st.push(7);
  cout << st.mid()<<endl;
  return 0;
}
