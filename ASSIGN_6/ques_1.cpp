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

    void insertAtBeginning(int data) {
        Node* newNode = new Node{data, nullptr};
        if (head == nullptr) {
            newNode->next = newNode; 
            head = newNode;
        } else {
            Node* last = findLastNode();
            newNode->next = head;
            last->next = newNode;
            head = newNode;
        }
        cout << "Inserted " << data << " at the beginning." << endl;
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node{data, nullptr};
        if (head == nullptr) {
            newNode->next = newNode;
            head = newNode;
            cout << "Inserted " << data << " at the end." << endl;
            return;
        }
        Node* last = findLastNode();
        newNode->next = head;
        last->next = newNode;
        cout << "Inserted " << data << " at the end." << endl;
    }

    void insertBefore(int target, int data) {
        if (head == nullptr) {
            cout << "List is empty, cannot insert before." << endl;
            return;
        }
        if (head->data == target) {
            insertAtBeginning(data);
            return;
        }

        Node* prev = findLastNode(); 
        Node* current = head;

        do {
            if (current->data == target) {
                Node* newNode = new Node{data, current};
                prev->next = newNode;
                cout << "Inserted " << data << " before " << target << "." << endl;
                return;
            }
            prev = current;
            current = current->next;
        } while (current != head);

        cout << "Node with value " << target << " not found." << endl;
    }

    void deleteNode(int data) {
        if (head == nullptr) {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }

        Node* toDelete = nullptr;
        
        if (head->data == data) {
            toDelete = head;
            if (head->next == head) { 
                head = nullptr;
            } else {
                Node* last = findLastNode();
                head = head->next;
                last->next = head;
            }
        } else {
            Node* prev = head;
            while (prev->next != head && prev->next->data != data) {
                prev = prev->next;
            }

            if (prev->next == head) {
                cout << "Node with value " << data << " not found." << endl;
                return;
            }
            
            toDelete = prev->next;
            prev->next = toDelete->next; 
        }
        
        if (toDelete != nullptr) {
            delete toDelete;
            cout << "Deleted node with value " << data << "." << endl;
        }
    }

    void searchNode(int data) {
        if (head == nullptr) {
            cout << "List is empty, cannot search." << endl;
            return;
        }
        int position = 1;
        Node* temp = head;
        
        do {
            if (temp->data == data) {
                cout << "Node with value " << data << " found at position " << position << "." << endl;
                return;
            }
            temp = temp->next;
            position++;
        } while (temp != head);
        
        cout << "Node with value " << data << " not found." << endl;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        cout << "List: ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "HEAD" << endl;
    }
};

void Menu(CLL& list) {
    int choice, data, target;
    do {
        cout << "\n--- Circular Linked List Menu ---" << endl;
        cout << "1. Display List" << endl;
        cout << "2. Insert at Beginning" << endl;
        cout << "3. Insert at End" << endl;
        cout << "4. Insert After a Node" << endl;
        cout << "5. Insert Before a Node" << endl;
        cout << "6. Delete Node (by value, e.g., 'Delete Node 60')" << endl;
        cout << "7. Search Node" << endl;
        cout << "8. Exit Program" << endl;
        cout << "Enter your choice (1-8): ";
        cin >> choice;

        switch (choice) {
            case 1: list.display(); break;
            case 2:
                cout << "Enter data to insert: "; cin >> data;
                list.insertAtBeginning(data); break;
            case 3:
                cout << "Enter data to insert: "; cin >> data;
                list.insertAtEnd(data); break;
            case 4:
                cout << "Enter target node value: "; cin >> target;
                cout << "Enter data to insert: "; cin >> data;
                list.insertBefore(target, data); break;
            case 5:
                cout << "Enter value of node to delete: "; cin >> data;
                list.deleteNode(data); break;
            case 6:
                cout << "Enter value of node to search: "; cin >> data;
                list.searchNode(data); break;
            case 7:
                cout << "Exiting Circular Linked List Program." << endl; break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);
}

int main() {
    CLL cll;
    Menu(cll);
    return 0;
}
