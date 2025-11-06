#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class BST {
public:
    Node* root = nullptr;

    Node* createNode(int val) {
        Node* temp = new Node;
        temp->data = val;
        temp->left = temp->right = nullptr;
        return temp;
    }

    Node* insert(Node* root, int val) {
        if (root == nullptr)
            return createNode(val);

        if (val < root->data)
            root->left = insert(root->left, val);
        else if (val > root->data)
            root->right = insert(root->right, val);

        return root;
    }

    // (a) Search - Recursive
    Node* searchRecursive(Node* root, int key) {
        if (root == nullptr || root->data == key)
            return root;
        if (key < root->data)
            return searchRecursive(root->left, key);
        else
            return searchRecursive(root->right, key);
    }

    // (a) Search - Non-Recursive
    Node* searchIterative(Node* root, int key) {
        while (root != nullptr) {
            if (root->data == key)
                return root;
            else if (key < root->data)
                root = root->left;
            else
                root = root->right;
        }
        return nullptr;
    }

    // (b) Maximum element
    Node* findMax(Node* root) {
        if (root == nullptr)
            return nullptr;
        while (root->right != nullptr)
            root = root->right;
        return root;
    }

    // (c) Minimum element
    Node* findMin(Node* root) {
        if (root == nullptr)
            return nullptr;
        while (root->left != nullptr)
            root = root->left;
        return root;
    }

    // (d) In-order Successor
    Node* inorderSuccessor(Node* root, Node* target) {
        if (target->right != nullptr)
            return findMin(target->right);

        Node* successor = nullptr;
        while (root != nullptr) {
            if (target->data < root->data) {
                successor = root;
                root = root->left;
            } else if (target->data > root->data) {
                root = root->right;
            } else
                break;
        }
        return successor;
    }

    // (e) In-order Predecessor
    Node* inorderPredecessor(Node* root, Node* target) {
        if (target->left != nullptr)
            return findMax(target->left);

        Node* predecessor = nullptr;
        while (root != nullptr) {
            if (target->data > root->data) {
                predecessor = root;
                root = root->right;
            } else if (target->data < root->data) {
                root = root->left;
            } else
                break;
        }
        return predecessor;
    }

    // Inorder Traversal
    void inorder(Node* root) {
        if (root == nullptr)
            return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
};

int main() {
    BST tree;
    int n, val;
    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> val;
        tree.root = tree.insert(tree.root, val);
    }

    cout << "\nInorder Traversal: ";
    tree.inorder(tree.root);
    cout << endl;

    int key;
    cout << "\nEnter key to search: ";
    cin >> key;

    Node* res1 = tree.searchRecursive(tree.root, key);
    Node* res2 = tree.searchIterative(tree.root, key);

    cout << (res1 ? "Found (Recursive)" : "Not Found (Recursive)") << endl;
    cout << (res2 ? "Found (Iterative)" : "Not Found (Iterative)") << endl;

    Node* minNode = tree.findMin(tree.root);
    Node* maxNode = tree.findMax(tree.root);
    cout << "\nMinimum element: " << minNode->data << endl;
    cout << "Maximum element: " << maxNode->data << endl;

    if (res1) {
        Node* succ = tree.inorderSuccessor(tree.root, res1);
        Node* pred = tree.inorderPredecessor(tree.root, res1);
        if (succ)
            cout << "Inorder Successor of " << key << " is " << succ->data << endl;
        else
            cout << "No Inorder Successor for " << key << endl;
        if (pred)
            cout << "Inorder Predecessor of " << key << " is " << pred->data << endl;
        else
            cout << "No Inorder Predecessor for " << key << endl;
    }

    return 0;
}
