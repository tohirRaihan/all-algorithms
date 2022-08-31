#include <iostream>
using namespace std;

class Node {
public:
  int value;
  Node *Next;

  Node(int val) {
    this->value = val;
    this->Next = NULL;
  }
};

class Queue {
public:
  Node *front;
  Node *rear;

  Queue() {
    this->front = NULL;
    this->rear = NULL;
  }

  // enqueue --> push(val)
  void push(int val) { Node *newNode = new Node(val); }
};

int main(void) { return 0; }
