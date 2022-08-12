#include <iostream>
using namespace std;

class Node {
public:
  int value;
  Node *Next;
};

void changeValue(Node *head) {
  Node *temp = head;
  head->Next = temp;
  cout << head->Next;
}

int main(void) {
  Node *head = new Node;

  head->value = 1;
  head->Next = NULL;

  changeValue(head);
  cout << head->value;

  return 0;
}
