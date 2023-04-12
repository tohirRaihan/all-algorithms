#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  Node *leftChild;
  Node *rightChild;

  Node(int value) {
    this->data = value;
    this->leftChild = NULL;
    this->rightChild = NULL;
  }
};
vector<int> ans;
void inorderTraversal(Node *root) {
  if (root != NULL) {
    inorderTraversal(root->leftChild);
    ans.push_back(root->data);
    inorderTraversal(root->rightChild);
  }
}
int second_minimum(Node *root) {
  inorderTraversal(root);
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size() - 1; i++)
    if (ans[i] != ans[i + 1])
      return ans[i + 1];
  return -1;
}

int main(void) {
  Node *root = new Node(1);
  Node *root1 = new Node(1);
  Node *root2 = new Node(2);
  root->leftChild = root1;
  root->rightChild = root2;
  cout << second_minimum(root);

  return 0;
}
