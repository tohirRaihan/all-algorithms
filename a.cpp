#include <iostream>
using namespace std;

class DoublyNode {
public:
  int value;
  DoublyNode *Next;
  DoublyNode *Prev;

  DoublyNode(int val) {
    this->value = val;
    this->Next = NULL;
    this->Prev = NULL;
  }
};

void display(DoublyNode *n) {
  while (n != NULL) {
    cout << n->value << " ";
    n = n->Next;
  }
  cout << endl;
}

int main(void) {
  int n;
  cin >> n;

  DoublyNode *head = NULL;

  for (int i = 1; i <= n; i++) {
    int l, r;
    cin >> l >> r;

    DoublyNode *newNode = new DoublyNode(i);

    int flag = 0;
    DoublyNode *temp = head;

    DoublyNode *leftNode = new DoublyNode(l);
    DoublyNode *rightNode = new DoublyNode(r);
    while (temp != NULL) {
      if (temp->value == l) {
        leftNode = temp;
      } else if (temp->value == r) {
        rightNode = temp;
      }
      temp = temp->Next;
    }

    if (r != 0) {
      newNode->Next = rightNode;
      rightNode->Prev = newNode;
    }
    if (l != 0) {
      newNode->Prev = leftNode;
      leftNode->Next = newNode;
    }
    if (i == 1) {
      head = newNode;
    }
    while (head->Prev != NULL) {
      head = head->Prev;
    }


    // temp = head;
    // flag = 0;
    // while (temp->Next !=NULL) {
    //   if (temp->value == newNode->value) {
    //     flag = 1;
    //   }
    //   temp = temp->Next;
    // }
    // if (flag == 0) {

    //   temp->Next = newNode;
    // }
  }

  cout << "output" << endl;
  display(head);

  return 0;
}
