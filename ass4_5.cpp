#include <iostream>
using namespace std;

const int Max = 100;

class Queue {
private:
    int arr[Max];
    int front = -1;
    int rear = -1;
public:
    void enqueue(int x) {
        if (rear == Max - 1) return;
        if (front == -1) front = 0;
        rear++;
        arr[rear] = x;
    }
    int dequeue() {
        if (front == -1 || front > rear) return -1;
        int val = arr[front];
        front++;
        if (front > rear) {
            front = -1;
            rear = -1;
        }
        return val;
    }
    bool isEmpty() {
        return front == -1;
    }
    int peek() {
        if (isEmpty()) return -1;
        return arr[front];
    }
};

class StackWithTwoQueues {
private:
    Queue q1, q2;
public:
    void push(int x) {
        q1.enqueue(x);
    }
    int pop() {
        if (q1.isEmpty()) return -1;
        while (q1.peek() != -1) {
            int val = q1.dequeue();
            if (q1.peek() != -1) {
                q2.enqueue(val);
            } else {
                return val;
            }
        }
        while (!q2.isEmpty()) {
            q1.enqueue(q2.dequeue());
        }
        return -1;
    }
    int peek() {
        if (q1.isEmpty()) return -1;
        while (q1.peek() != -1) {
            int val = q1.dequeue();
            q2.enqueue(val);
            if (q1.peek() == -1) {
                while (!q2.isEmpty()) {
                    q1.enqueue(q2.dequeue());
                }
                return val;
            }
        }
        return -1;
    }
    bool isEmpty() {
        return q1.isEmpty();
    }
};

class StackWithOneQueue {
private:
    Queue q;
public:
    void push(int x) {
        q.enqueue(x);
        int size = 0;
        Queue temp_q;
        while(!q.isEmpty()){
            size++;
            temp_q.enqueue(q.dequeue());
        }
        q = temp_q;
        for(int i = 0; i < size-1; i++){
            q.enqueue(q.dequeue());
        }
    }
    int pop() {
        return q.dequeue();
    }
    int peek() {
        return q.peek();
    }
    bool isEmpty() {
        return q.isEmpty();
    }
};

int main() {
    int choice, sub_choice, val;
    StackWithTwoQueues stack_two;
    StackWithOneQueue stack_one;

    do {
        cout<<"\nChoose a Stack Implementation:\n";
        cout<<"1. Using Two Queues\n";
        cout<<"2. Using One Queue\n";
        cout<<"3. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        if (choice == 1) {
            do {
                cout<<"\nTwo Queues Stack Operations:\n";
                cout<<"1. Push\n";
                cout<<"2. Pop\n";
                cout<<"3. Peek\n";
                cout<<"4. Is Empty\n";
                cout<<"5. Go Back\n";
                cout<<"Enter your choice: ";
                cin>>sub_choice;
                switch (sub_choice) {
                    case 1:
                        cout<<"Enter value to push: ";
                        cin>>val;
                        stack_two.push(val);
                        break;
                    case 2:
                        val = stack_two.pop();
                        if (val != -1) {
                            cout<<"Popped: "<<val<<"\n";
                        } else {
                            cout<<"Stack is empty.\n";
                        }
                        break;
                    case 3:
                        val = stack_two.peek();
                        if (val != -1) {
                            cout<<"Top element: "<<val<<"\n";
                        } else {
                            cout<<"Stack is empty.\n";
                        }
                        break;
                    case 4:
                        if (stack_two.isEmpty()) {
                            cout<<"Stack is empty.\n";
                        } else {
                            cout<<"Stack is not empty.\n";
                        }
                        break;
                }
            } while (sub_choice != 5);
        } else if (choice == 2) {
            do {
                cout<<"\nOne Queue Stack Operations:\n";
                cout<<"1. Push\n";
                cout<<"2. Pop\n";
                cout<<"3. Peek\n";
                cout<<"4. Is Empty\n";
                cout<<"5. Go Back\n";
                cout<<"Enter your choice: ";
                cin>>sub_choice;
                switch (sub_choice) {
                    case 1:
                        cout<<"Enter value to push: ";
                        cin>>val;
                        stack_one.push(val);
                        break;
                    case 2:
                        val = stack_one.pop();
                        if (val != -1) {
                            cout<<"Popped: "<<val<<"\n";
                        } else {
                            cout<<"Stack is empty.\n";
                        }
                        break;
                    case 3:
                        val = stack_one.peek();
                        if (val != -1) {
                            cout<<"Top element: "<<val<<"\n";
                        } else {
                            cout<<"Stack is empty.\n";
                        }
                        break;
                    case 4:
                        if (stack_one.isEmpty()) {
                            cout<<"Stack is empty.\n";
                        } else {
                            cout<<"Stack is not empty.\n";
                        }
                        break;
                }
            } while (sub_choice != 5);
        }

    } while (choice != 3);

    return 0;
}
