#include <cstddef>
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

class SinglyLinkedList {
public:
  Node *head;
  Node *tail;
  int length;

  SinglyLinkedList() {
    this->head = NULL;
    this->tail = NULL;
    this->length = 0;
  }

  SinglyLinkedList *insertAtTail(int val) {
    Node *newNode = new Node(val);
    this->length++;
    if (this->head == NULL) {
      this->head = newNode;
      this->tail = this->head;
      return this;
    }
    this->tail->Next = newNode;
    this->tail = newNode;
    return this;
  }

  SinglyLinkedList *insertAtHead(int val) {
    Node *newNode = new Node(val);
    this->length++;
    newNode->Next = this->head;
    this->head = newNode;
    return this;
  }

  void display() {
    Node *temp = this->head;
    while (temp != NULL) {
      cout << temp->value << " ";
      temp = temp->Next;
    }
    cout << endl;
  }
};

int main(void) {
  SinglyLinkedList l1;
  l1.insertAtTail(3)->insertAtTail(4)->insertAtHead(1)->insertAtHead(2);

  l1.display();
  cout << l1.length;
  return 0;
}