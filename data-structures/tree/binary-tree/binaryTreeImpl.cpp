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

int main() { return 0; }
