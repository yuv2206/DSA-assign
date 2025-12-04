#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int v) {
        val = v;
        left = right = nullptr;
    }
};

class BST {
private:
    Node* root;

    Node* add(Node* cur, int v) {
        if (cur == nullptr)
            return new Node(v);

        if (v < cur->val)
            cur->left = add(cur->left, v);
        else if (v > cur->val)
            cur->right = add(cur->right, v);
        else
            cout << "Value already exists!\n";

        return cur;
    }

    Node* smallest(Node* cur) {
        while (cur && cur->left != nullptr)
            cur = cur->left;
        return cur;
    }

    Node* removeNode(Node* cur, int v) {
        if (cur == nullptr) {
            cout << "Not found!\n";
            return cur;
        }

        if (v < cur->val)
            cur->left = removeNode(cur->left, v);
        else if (v > cur->val)
            cur->right = removeNode(cur->right, v);
        else {
            if (cur->left == nullptr) {
                Node* temp = cur->right;
                delete cur;
                return temp;
            }
            else if (cur->right == nullptr) {
                Node* temp = cur->left;
                delete cur;
                return temp;
            }

            Node* temp = smallest(cur->right);
            cur->val = temp->val;
            cur->right = removeNode(cur->right, temp->val);
        }
        return cur;
    }

    int depthMax(Node* cur) {
        if (cur == nullptr)
            return 0;
        return 1 + max(depthMax(cur->left), depthMax(cur->right));
    }

    int depthMin(Node* cur) {
        if (cur == nullptr)
            return 0;
        if (!cur->left)
            return 1 + depthMin(cur->right);
        if (!cur->right)
            return 1 + depthMin(cur->left);
        return 1 + min(depthMin(cur->left), depthMin(cur->right));
    }

    void printInorder(Node* cur) {
        if (!cur) return;
        printInorder(cur->left);
        cout << cur->val << " ";
        printInorder(cur->right);
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int v) {
        root = add(root, v);
    }

    void erase(int v) {
        root = removeNode(root, v);
    }

    void show() {
        cout << "Inorder: ";
        printInorder(root);
        cout << endl;
    }

    int maxDepth() {
        return depthMax(root);
    }

    int minDepth() {
        return depthMin(root);
    }
};


int main() {
    BST tree;
    int ch, v;

    while (true) {
        cout << "\n===== BST Menu =====\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Show (Inorder)\n";
        cout << "4. Max Depth\n";
        cout << "5. Min Depth\n";
        cout << "6. Exit\n";
        cout << "Choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Value: ";
                cin >> v;
                tree.insert(v);
                break;

            case 2:
                cout << "Delete: ";
                cin >> v;
                tree.erase(v);
                break;

            case 3:
                tree.show();
                break;

            case 4:
                cout << "Max Depth: " << tree.maxDepth() << endl;
                break;

            case 5:
                cout << "Min Depth: " << tree.minDepth() << endl;
                break;

            case 6:
                return 0;

            default:
                cout << "Invalid!\n";
        }
    }
}
