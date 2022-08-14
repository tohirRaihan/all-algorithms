#include <cstddef>
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

int countLength(Node *&head) {
  int count = 0;
  Node *temp = head;
  while (temp != NULL) {
    count++;
    temp = temp->Next;
  }
  return count;
}

void insertAtSpecificPosition(Node *&head, int pos, int val) {
  int i = 0;
  Node *temp = head;

  while (i < pos - 2) {
    temp = temp->Next;
    i++;
  }
  Node *newNode = new Node(val);
  newNode->Next = temp->Next;
  temp->Next = newNode;
}

int searchByValueUnique(Node *&head, int val) {
  Node *temp = head;
  int count = 1;

  if (temp == NULL) {
    return -1;
  }

  while (temp->value != val) {
    if (temp->Next == NULL) {
      return -1;
    }
    temp = temp->Next;
    count++;
  }
  return count;
}

void searchByValueDuplicate(Node *&head, int val) {
  Node *temp = head;
  int count = 1;
  int flag = 0;

  while (temp != NULL) {
    if (temp->value == val) {
      cout << count << " ";
      flag = 1;
    }
    temp = temp->Next;
    count++;
  }

  if (flag == 0)
    cout << "Value did not found";
}

void deletionAtHead(Node *&head) {
  Node *temp = head;
  if (temp != NULL) {
    head = temp->Next;
    delete temp;
  } else {
    cout << "There is no value in the Linked List" << endl;
  }
}

void deletionAtTail(Node *&head) {
  Node *temp = head;
  if (temp != NULL && temp->Next != NULL) {
    while (temp->Next->Next != NULL) {
      temp = temp->Next;
    }
    Node *delNode = temp->Next;
    temp->Next = NULL;
    delete delNode;
  }
}

/* Function to reverse the linked list */
void reversedListPrint(Node *head) {
  if (head == NULL)
    return;
  reversedListPrint(head->Next);
  cout << head->value << " ";
}

void display(Node *n) {
  while (n != NULL) {
    cout << n->value << " ";
    n = n->Next;
  }
  cout << endl;
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
    switch (choice) {
    case 1:
      insertAtHead(head, n);
      break;
    case 2:
      insertAtTail(head, n);
      break;
    default:
      break;
    }
    cout << "Next Choice: (1/2/3) ?" << endl;
    cin >> choice;
  }
  display(head);

  searchByValueDuplicate(head, 4);

  return 0;
}
