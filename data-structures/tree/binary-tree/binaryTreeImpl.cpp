#include <cstddef>
#include <iostream>
#include <queue>
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

void levelOrderTraversal(TreeNode *root, string &chk) {
  if (root == NULL) {
    return;
  }

  int level = 0;

  queue<TreeNode *> q;
  q.push(root);
  q.push(NULL);

  while (!q.empty()) {
    TreeNode *chkNode = q.front();
    q.pop();
    if (chkNode != NULL) {
      cout << chkNode->data << " ";
      if (chkNode->leftChild != NULL) {
        q.push(chkNode->leftChild);
      }
      if (chkNode->rightChild != NULL) {
        q.push(chkNode->rightChild);
      }
    } else {
      if (!q.empty()) {
        q.push(NULL);
        level++;
      }
    }
  }
}

int searchInorder(int inOrder[], int current, int start, int end) {
  for (int i = start; i <= end; i++) {
    if (inOrder[i] == current) {
      return i;
    }
  }

  return -1;
}

TreeNode *buildPreIn(int preOrder[], int inOrder[], int start, int end) {
  static int id = 0;

  int current = preOrder[id];
  TreeNode *newNode = new TreeNode(current);
  if (start == end) {
    return newNode;
  }
  int pos = searchInorder(inOrder, current, start, end);

  newNode->leftChild = buildPreIn(preOrder, inOrder, start, pos - 1);
  newNode->rightChild = buildPreIn(preOrder, inOrder, pos + 1, end);

  return newNode;
}

void printLeaves(TreeNode *root) {
  if (root == NULL) {
    return;
  }
  if (root->leftChild == NULL && root->rightChild == NULL) {
    cout << root->data << " ";
    return;
  }
  printLeaves(root->leftChild);
  printLeaves(root->rightChild);
}
void printLeftNonLeaves(TreeNode *root) {
  if (root == NULL) {
    return;
  }
  if (root->leftChild != NULL) {
    cout << root->data << " ";
    printLeftNonLeaves(root->leftChild);
  } else if (root->rightChild != NULL) {
    cout << root->data << " ";
    printLeftNonLeaves(root->rightChild);
  }
}
void printRightNonLeaves(TreeNode *root) {
  if (root == NULL) {
    return;
  }
  if (root->rightChild != NULL) {
    cout << root->data << " ";
    printLeftNonLeaves(root->rightChild);
  } else if (root->leftChild != NULL) {
    cout << root->data << " ";
    printLeftNonLeaves(root->leftChild);
  }
}

void boundryTraversal(TreeNode *root) {
  if (root == NULL) {
    return;
  }
  cout << root->data << " ";

  // 1. LB non leaves
  printLeftNonLeaves(root->leftChild);
  // 2. LB leaves
  printLeaves(root->leftChild);
  // 3. RB leaves
  printLeaves(root->rightChild);
  // 4. RB non leaves
  printRightNonLeaves(root->rightChild);
}

TreeNode *insertionBST(TreeNode *root, int value) {
  TreeNode *newNode = new TreeNode(value);
  if (root == NULL) {
    root = newNode;
    return root;
  }
  if (value < root->data) {
    root->leftChild = insertionBST(root->leftChild, value);

  } else if (value > root->data) {
    root->rightChild = insertionBST(root->rightChild, value);
  }
  return root;
}

TreeNode *searchBST(TreeNode *root, int value) {
  if (root == NULL) {
    return NULL;
  }
  if (root->data == value) {
    cout << root->data;
    return root;
  } else if (value < root->data) {
    cout << root->data << " -> ";
    searchBST(root->leftChild, value);
  } else {
    cout << root->data << " -> ";
    searchBST(root->rightChild, value);
  }

  return root;
}

TreeNode *deletionBST(TreeNode *root, int value) {}

int main() {
  // int n;
  // cin >> n;
  // TreeNode *allNodes[n];
  // for (int i = 0; i < n; i++) {
  //   allNodes[i] = new TreeNode(-1);
  // }

  // for (int i = 0; i < n; i++) {
  //   int value, left, right;
  //   cin >> value >> left >> right;
  //   allNodes[i]->data = value;
  //   if (left > n - 1 || right > n - 1) {
  //     cout << "Invalid Index" << endl;
  //     break;
  //   }
  //   if (left != -1) {
  //     allNodes[i]->leftChild = allNodes[left];
  //   }
  //   if (right != -1) {
  //     allNodes[i]->rightChild = allNodes[right];
  //   }
  // }
  // printTree(allNodes[0], 0);
  // string inOrderTraversal = "";
  // string preOrderTraversal = "";
  // string postOrderTraversal = "";
  // string levelordertraversal = "";

  // inOrder(allNodes[0], inOrderTraversal);
  // preOrder(allNodes[0], preOrderTraversal);
  // postOrder(allNodes[0], postOrderTraversal);

  // levelOrderTraversal(allNodes[0], levelordertraversal);

  // int n;
  // cin >> n;
  // int preorder[n], inOrder[n];
  // for (int i = 0; i < n; i++) {
  //   cin >> preorder[i];
  // }
  // for (int i = 0; i < n; i++) {
  //   cin >> inOrder[i];
  // }
  // TreeNode *root = buildPreIn(preorder, inOrder, 0, n - 1);
  // string chk = "";
  // preOrder(root, chk);
  // cout << chk << endl << endl;

  int n;
  cin >> n;
  TreeNode *root = NULL;
  for (int i = 0; i < n; i++) {
    int value;
    cin >> value;
    root = insertionBST(root, value);
  }

  return 0;
}
