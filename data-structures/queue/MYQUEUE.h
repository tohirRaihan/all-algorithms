#include <iostream>
using namespace std;

template <typename N> class Node {
public:
  N value;
  Node *Next;

  Node(N val) {
    this->value = val;
    this->Next = NULL;
  }
};

template <typename Q> class Queue {
public:
  Node<Q> *front;
  Node<Q> *rear;

  Queue() {
    this->front = NULL;
    this->rear = NULL;
  }

  // enqueue --> push(val)
  void push(Q val) {
    Node<Q> *newNode = new Node<Q>(val);
    if (front == NULL) {
      front = newNode;
      rear = newNode;
      return;
    }
    rear->Next = newNode;
    rear = rear->Next;
  }

  // dequeqe --> pop()
  Q pop() {
    Q chk;
    if (rear == NULL) {
      cout << "Queue Underflow | There is no value in the queue" << endl;
      return chk;
    }
    Node<Q> *delNode;
    delNode = front;
    front = front->Next;
    if (front == NULL) {
      rear = NULL;
    }
    chk = delNode->value;
    delete delNode;
    return chk;
  }

  // peek top() bottom()
  Q top() {
    Q chk = front->value;
    return chk;
  }

  Q bottom() {
    Q chk = rear->value;
    return chk;
  }

  // empty --> empty()
  bool empty() {
    if (front == NULL && rear == NULL) {
      return true;
    } else {
      return false;
    }
  }
};
