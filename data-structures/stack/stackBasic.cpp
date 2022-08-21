#include <iostream>
using namespace std;

class Node {
public:
  int value;
  Node *Next;
  Node *Prev;

  Node(int val) {
    this->value = val;
    this->Next = NULL;
    this->Prev = NULL;
  }
};

class Stack {
  Node *head;
  Node *top;
  int count = 0;

public:
  Stack() {
    head = NULL;
    top = NULL;
  }
  // PUSH
  void push(int val) {
    Node *newNode = new Node(val);
    if (head == NULL) {
      head = top = newNode;
      count++;
      return;
    }

    top->Next = newNode;
    newNode->Prev = top;
    top = newNode;
    count++;
  }
  // POP
  int pop() {
    Node *delNode;
    delNode = top;
    int chk;
    // there is no element in the stack
    if (head == NULL) {
      cout << "Stack Underflow" << endl;
      return -1;
    }
    // there is only one element
    if (top == head) {
      top = head = NULL;
    } else { // there is more than one element
      top = delNode->Prev;
      top->Next = NULL;
    }
    chk = delNode->value;
    delete delNode;
    count--;
    return chk;
  }
  // EMPTY
  bool empty() {
    if (head == NULL) {
      return true;
    } else {
      return false;
    }
  }
  // SIZE
  int size() { return count; }
  // TOP
  int getTop() {
    if (top == NULL) {
      cout << "Stack Underflow | There is no element in top" << endl;
    } else {
      return top->value;
    }
  }
};

int main(void) { return 0; }
