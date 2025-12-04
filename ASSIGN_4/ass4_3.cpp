#include <iostream>

using namespace std;

const int Max = 100;
int queue[Max];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear >= Max - 1) {
        return;
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = value;
    }
}

int dequeue() {
    if (front == -1 || front > rear) {
        return -1;
    } else {
        int value = queue[front];
        front++;
        return value;
    }
}

int stack[Max];
int top = -1;

void push(int value) {
    if (top >= Max - 1) {
        return;
    }
    top++;
    stack[top] = value;
}

int pop() {
    if (top < 0) {
        return -1;
    }
    int value = stack[top];
    top--;
    return value;
}

int main() {
    int n, value;
    cout << "Enter the number of elements in the queue: ";
    cin >> n;

    if (n % 2 != 0) {
        cout << "The number of elements must be even." << endl;
        return 1;
    }

    cout << "Enter " << n << " numbers:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> value;
        enqueue(value);
    }

    for (int i = 0; i < n / 2; i++) {
        push(dequeue());
    }

    for (int i = 0; i < n / 2; i++) {
        enqueue(pop());
    }

    for (int i = 0; i < n / 2; i++) {
        push(dequeue());
    }

    for (int i = 0; i < n / 2; i++) {
        int a = pop();
        int b = dequeue();
        enqueue(a);
        enqueue(b);
    }

    cout << "Interleaved queue: ";
    for (int i = 0; i < n; i++) {
        cout << dequeue() << " ";
    }
    cout << endl;

    return 0;
}


