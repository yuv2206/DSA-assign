#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CLL {
private:
    Node* head = nullptr;
    
    Node* findLastNode() {
        if (head == nullptr) return nullptr;
        Node* current = head;
        while (current->next != head) {
            current = current->next;
        }
        return current;
    }

public:
    ~CLL() {
        if (head == nullptr) return;
        Node* current = head->next;
        head->next = nullptr;
        while (current != nullptr) {
            Node* next_node = current->next;
            delete current;
            current = next_node;
        }
        delete head; 
        head = nullptr;
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node{data, nullptr};
        if (head == nullptr) {
            newNode->next = newNode;
            head = newNode;
            return;
        }
        Node* last = findLastNode();
        newNode->next = head;
        last->next = newNode;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        
        Node* temp = head;
        cout << "List Sequence: ";

        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        
        cout << head->data << " (Head Repeated)" << endl;
    }
};

void Menu(CLL& list) {
    int choice, data, target;
    do {
        cout << "\n--- Circular Linked List Menu ---" << endl;
        cout << "1. Insert at End" << endl;
        cout << "2. Display List (Repeat Head Value)" << endl;
        cout << "3. Exit Program" << endl;
        cout << "Enter your choice (1-3): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert: "; cin >> data;
                list.insertAtEnd(data); break;
            case 2:
                list.display(); break;
            case 3:
                cout << "Exiting Circular Linked List Program." << endl; break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);
}

int main() {
    CLL cll;
    Menu(cll);
    return 0;
}
