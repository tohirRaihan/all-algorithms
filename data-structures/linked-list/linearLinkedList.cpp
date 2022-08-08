#include <iostream>
using namespace std;

class Node {
public:
  int value;
  Node *Next;

  // constructer creation
  Node(int val) {
    this->value = val;
    this->Next = NULL;
  }
};

void insertAtTail(Node *&head, int val) {
  Node *newNode = new Node(val);
  if (head == NULL) {
    head = newNode;
    return;
  }
  Node *temp = head;
  while (temp->Next != NULL) {
    temp = temp->Next;
  }
  temp->Next = newNode;
}

void insertAtHead(Node *&head, int val) {
  Node *newNode = new Node(val);
  newNode->Next = head;
  head = newNode;
}

void display(Node *n) {
  while (n != NULL) {
    cout << n->value << " ";
    n = n->Next;
  }
}

int main(void) {
  Node *head = NULL;

  int n;
  cout << "Choice 1: Insert at Head" << endl
       << "Choice 2: Insert at Tail" << endl
       << "Choice 3: Exit" << endl;
  int choice = 2;
  while (choice == 1 || choice == 2) {
    cout << "Enter The Value" << endl;
    cin >> n;
    if (choice == 1)
      insertAtHead(head, n);
    else if (choice == 2)
      insertAtTail(head, n);
    cout << "Next Choice: (1/2/3) ?" << endl;
    cin >> choice;
  }

  display(head);
  return 0;
}
