#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
private:
    Node* head = nullptr;
    Node* tail = nullptr;

public:
    ~DoublyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next_node = current->next;
            delete current;
            current = next_node;
        }
        head = tail = nullptr;
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node{data, tail, nullptr};
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int countNodes() {
        int count = 0;
        Node* current = head;
        
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        cout << "List: NULL <-> ";
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << " <-> ";
            }
            temp = temp->next;
        }
        cout << " <-> NULL" << endl;
    }
};

int main() {
    DoublyLinkedList list;

    cout << "--- Doubly Linked List Size Finder ---" << endl;

    cout << "\nTest 1: Empty List" << endl;
    list.display();
    cout << "Size of the list: " << list.countNodes() << endl;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    cout << "\nTest 2: Populated List" << endl;
    list.display();
    cout << "Size of the list: " << list.countNodes() << endl;

    list.insertAtEnd(50);
    
    cout << "\nTest 3: After adding one more element" << endl;
    list.display();
    cout << "Size of the list: " << list.countNodes() << endl;

    return 0;
}
