#include <iostream>
using namespace std;

template <typename N> class Node {
public:
  N value;
  Node *Next;
  Node *Prev;

  Node(int val) {
    this->value = val;
    this->Next = NULL;
    this->Prev = NULL;
  }
};

template <typename S> class Stack {
  Node<S> *head;
  Node<S> *top;
  int count = 0;

public:
  Stack() {
    head = NULL;
    top = NULL;
  }
  // PUSH
  void push(S val) {
    Node<S> *newNode = new Node<S>(val);
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
  S pop() {
    Node<S> *delNode;
    delNode = top;
    S chk;
    // there is no element in the stack
    if (head == NULL) {
      cout << "Stack Underflow" << endl;
      return chk;
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
  S getTop() {
    S chk;
    if (top == NULL) {
      cout << "Stack Underflow | There is no element in top" << endl;
      return chk;
    } else {
      chk = top->value;
    }
    return chk;
  }

  // MIDE OF STACK
  S mid() {
    int mid = count/2 +1;
    Node<S> *temp = head;
    while (mid !=1) {
      temp = temp->Next;
      mid--;
    }
    return temp->value;
  }
};
