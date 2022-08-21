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
public:
  Node *head;
  Node *top;

  // PUSH
  void push(int val) {
    Node *newNode = new Node(val);
    if (head == NULL) {
      head = top = newNode;
      return;
    }

    top->Next = newNode;
    newNode->Prev = top;
    top = newNode;

  }
  // POP
  // EMPTY
  // SIZE
  // TOP
};

int main(void) { return 0; }