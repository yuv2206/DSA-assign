#include <iostream>

using namespace std;

const int Max = 100;
char queue[Max];
int front = -1, rear = -1;

void enqueue(char c) {
    if (rear >= Max - 1) {
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = c;
}

char dequeue() {
    if (front == -1 || front > rear) {
        return '\0';
    }
    char value = queue[front];
    front++;
    if (front > rear) {
        front = -1;
        rear = -1;
    }
    return value;
}

char peek() {
    if (front == -1) {
        return '\0';
    }
    return queue[front];
}

bool isEmpty() {
    return front == -1;
}

int main() {
    char c;
    int freq[26] = {0};
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add character to stream\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter a character: ";
                cin >> c;

                int index = c - 'a';
                if (index >= 0 && index < 26) {
                    freq[index]++;

                    if (freq[index] == 1) {
                        enqueue(c);
                    }

                    while (!isEmpty() && freq[peek() - 'a'] > 1) {
                        dequeue();
                    }

                    if (isEmpty()) {
                        cout << "First non-repeating character: -1\n";
                    } else {
                        cout << "First non-repeating character: " << peek() << "\n";
                    }
                } else {
                    cout << "Invalid character. Please enter a lowercase letter.\n";
                }
                break;
            }
            case 2:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice.\n";
                break;
        }
    } while (choice != 2);

    return 0;
}

