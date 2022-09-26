#include <iostream>
#include <string>
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

void printTree(TreeNode *root, int level);
void spacePrint(int level);

void printTree(TreeNode *root, int level) {
  if (root == NULL) {
    return;
  }
  if (root->leftChild == NULL && root->rightChild == NULL) {
    cout << root->data << endl;
    return;
  } else {
    cout << endl;
    spacePrint(level);
    cout << "Root: " << root->data << endl;
  }

  if (root->leftChild != NULL) {
    spacePrint(level);
    cout << "Left: ";
    printTree(root->leftChild, level + 1);
  }

  if (root->rightChild != NULL) {
    spacePrint(level);
    cout << "Right: ";
    printTree(root->rightChild, level + 1);
  }
}

void spacePrint(int level) {
  for (int i = 0; i < level; i++) {
    cout << "   ";
  }
}

void inOrder(TreeNode *root, string &chk) {
  if (root == NULL) {
    return;
  }

  inOrder(root->leftChild, chk);
  chk += to_string(root->data);
  inOrder(root->rightChild, chk);
}

void preOrder(TreeNode *root, string &chk) {
  if (root == NULL) {
    return;
  }

  chk += to_string(root->data);
  preOrder(root->leftChild, chk);
  preOrder(root->rightChild, chk);
}

void postOrder(TreeNode *root, string &chk) {
  if (root == NULL) {
    return;
  }

  chk += to_string(root->data);
  postOrder(root->leftChild, chk);
  postOrder(root->rightChild, chk);
}

int main() {
  int n;
  cin >> n;
  TreeNode *allNodes[n];
  for (int i = 0; i < n; i++) {
    allNodes[i] = new TreeNode(-1);
  }

  for (int i = 0; i < n; i++) {
    int value, left, right;
    cin >> value >> left >> right;
    allNodes[i]->data = value;
    if (left > n - 1 || right > n - 1) {
      cout << "Invalid Index" << endl;
      break;
    }
    if (left != -1) {
      allNodes[i]->leftChild = allNodes[left];
    }
    if (right != -1) {
      allNodes[i]->rightChild = allNodes[right];
    }
  }
  printTree(allNodes[0], 0);
  string inOrderTraversal = "";
  string preOrderTraversal = "";
  string postOrderTraversal = "";

  inOrder(allNodes[0], inOrderTraversal);
  preOrder(allNodes[0], preOrderTraversal);
  postOrder(allNodes[0], postOrderTraversal);

  return 0;
}
