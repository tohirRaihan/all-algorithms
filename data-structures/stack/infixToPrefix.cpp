#include "MYSTACK.h"
#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;

int precisionCalc(char c) {
  if (c == '^')
    return 3;
  else if (c == '*' || c == '/')
    return 2;
  else if (c == '+' || c == '-')
    return 1;
  else
    return -1;
}

string infixToPrefix(string chk) {
  reverse(chk.begin(), chk.end());
  Stack<char> st;
  string result;

  for (int i = 0; i < chk.length(); i++) {
    if (chk[i] >= '0' && chk[i] <= '9') {
      result += chk[i];
    } else if (chk[i] == ')') {
      st.push(chk[i]);
    } else if (chk[i] == '(') {
      while (!st.empty() && st.getTop() != ')') {
        result += st.pop();
      }
      if (!st.empty()) {
        st.pop();
      }
    } else {
      while (!st.empty() &&
             precisionCalc(st.getTop()) >= precisionCalc(chk[i])) {
        result += st.pop();
      }
      st.push(chk[i]);
    }
  }
  while (!st.empty()) {
    result += st.pop();
  }
  reverse(result.begin(), result.end());
  return result;
}

int prefixEvaluation(string chk) {
  Stack<int> st;
  for (int i = chk.length() - 1; i >= 0; i--) {
    if (chk[i] >= '0' && chk[i] <= '9') {
      st.push(chk[i] - '0');

    } else {
      int a = st.pop();
      int b = st.pop();

      switch (chk[i]) {
      case '+':
        st.push(a + b);
        break;
      case '-':
        st.push(a - b);
        break;
      case '*':
        st.push(a * b);
        break;
      case '/':
        st.push(a / b);
        break;
      case '^':
        st.push(pow(a, b));
        break;
      default:
        break;
      }
    }
  }
  return st.getTop();
}

int main(void) {
  string infix = "(7+(4*5))-(2+0)";
  string prefix = infixToPrefix(infix);

  cout << endl << prefix << endl << prefixEvaluation(prefix) << endl;
  return 0;
}