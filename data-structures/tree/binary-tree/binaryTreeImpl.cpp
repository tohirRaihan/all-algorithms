#include <iostream>
using namespace std;

class TreeNode {
public:
  int data;
  TreeNode *leftChild;
  TreeNode *rightChild;

  TreeNode(int value) {
    this->data = value;
    this->leftChild = NULL;
    this->rightChild = NULL;
  }
};

void printTree(TreeNode* root, int level) {
  if (root == NULL) {
    return;
  }
  cout << "Root: " << endl;
}

int main() {
  int n;
  cin >> n;
  TreeNode *allNodes[n];
  for (int i = 0; i < n; i++) {
    allNodes[i]->data = -1;
  }

  for (int i = 0; i < n; i++) {
    int value, left, right;
    cin >> value >> left >> right;
    allNodes[i]->data = value;
    if (left != -1) {
      allNodes[i]->leftChild = allNodes[left];
    }
    if (right != -1) {
      allNodes[i]->rightChild = allNodes[right];
    }
  }
  return 0;
}
