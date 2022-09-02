#include "MYQUEUE.h"
#include <iostream>
#include <utility>
using namespace std;

typedef pair<int, int> mytype;

int main(void) {
  Queue<mytype> q;
  q.push(make_pair(1, 2));
  q.push(make_pair(3, 4));
  q.push(make_pair(5, 6));
  q.push(make_pair(7, 8));

  while (!q.empty()) {
    mytype chk;
    chk = q.pop();
    cout << chk.first << " " << chk.second << endl;
  }

  return 0;
}
