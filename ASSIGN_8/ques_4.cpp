#include <iostream>
#include <climits>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int x) {
        val = x;
        left = right = nullptr;
    }
};

bool checkBST(Node* cur, int& last) {
    if (!cur)
        return true;

    if (!checkBST(cur->left, last))
        return false;

    if (cur->val <= last)
        return false;

    last = cur->val;
    return checkBST(cur->right, last);
}

bool isBST(Node* root) {
    int last = INT_MIN;
    return checkBST(root, last);
}

int main() {
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);

    if (isBST(root))
        cout << "Tree is a BST.\n";
    else
        cout << "Tree is not a BST.\n";

    return 0;
}
