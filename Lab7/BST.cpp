#include <iostream>
using namespace std;

struct node { ;
    int key;
    struct node *left, *right;
};
//Create a node
node* newNode(int value) {
    node* temp = new node;
    temp->key = value;
    temp->left = temp->right = nullptr;
    return temp;
}


// Inorder traversal
void traverseInOrder(const node* root) {
    if (root != nullptr) {
        traverseInOrder(root->left);
        std::cout << root->key <<" ";
        traverseInOrder(root->right);
    }
}


// Insert a node
struct node *insertNode(struct node *node, int key) {
    if (node == NULL) return newNode(key);
    if (key < node->key) {
        node->left = insertNode(node->left, key);
    }else node->right = insertNode(node->right, key);
    return node;
}

//finding the inorder successor
struct node *minVal(struct node *node) {
    struct node *current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}


// Deleting a node
node* deleteNode(node* root, int key) {
    if (root == NULL) return root; // no elements in BST
    if (key < root->key) {
        root->left = deleteNode(root->left, key); //recursively checking in the left side
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key); //recursively checking in the right side
    } else {
        if (root->left == NULL) { //have a child only in right side
            node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {  //have a child only in left side
            node* temp = root->left;
            delete root;
            return temp;
        }
        node* temp = minVal(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}



// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}