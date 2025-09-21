#include <iostream>
using namespace std;

const int MAX_SIZE = 5;
int queue[MAX_SIZE];
int front = -1, rear = -1;

bool isEmpty() {
    return front == -1 && rear == -1;
}

bool isFull() {
    return (rear + 1) % MAX_SIZE == front;
}

void enqueue(int value) {
    if (isFull()) {
        cout << "Queue full!" << endl;
    } else {
        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }
        queue[rear] = value;
        cout << "Enqueued: " << value << endl;
    }
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue empty!" << endl;
    } else {
        cout << "Dequeued: " << queue[front] << endl;
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
    }
}

void peek() {
    if (isEmpty()) {
        cout << "Queue empty!" << endl;
    } else {
        cout << "Peeked element: " << queue[front] << endl;
    }
}

void display() {
    if (isEmpty()) {
        cout << "Queue empty." << endl;
    } else {
        cout << "Queue elements: ";
        int i = front;
        while (i != rear) {
            cout << queue[i] << " ";
            i = (i + 1) % MAX_SIZE;
        }
        cout << queue[rear] << endl;
    }
}

int main() {
    int choice, value;
    do {
        cout << "\n--- Queue Operations Menu ---" << endl;
        cout << "1. Enqueue " << endl;
        cout << "2. Dequeue " << endl;
        cout << "3. Peek " << endl;
        cout << "4. Check if Empty" << endl;
        cout << "5. Check if Full" << endl;
        cout << "6. Display Queue" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                if (isEmpty()) {
                    cout << "Queue is empty." << endl;
                } else {
                    cout << "Queue is not empty." << endl;
                }
                break;
            case 5:
                if (isFull()) {
                    cout << "Queue is full." << endl;
                } else {
                    cout << "Queue is not full." << endl;
                }
                break;
            case 6:
                display();
                break;
            case 7:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);
    return 0;
}

