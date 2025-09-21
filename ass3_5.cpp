#include <iostream>
#include <string>

using namespace std;

const int MAX_SIZE = 100;
int stack[MAX_SIZE];
int top = -1;

void push(int a) {
    if (top >= MAX_SIZE - 1) {
        cout << "STACK OVERFLOW!\n";
    } else {
        stack[++top] = a;
    }
}

int pop() {
    if (top < 0) {
        return -1;
    } else {
        return stack[top--];
    }
}

int main() {
    string exp;
    cout << "Enter postfix expression: ";
    getline(cin, exp);

    for (char c : exp) {
        if (isdigit(c)) {
            push(c - '0');
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int operand2 = pop();
            int operand1 = pop();

            if (operand1 == -1 || operand2 == -1) {
                cout << "Error: Invalid expression, not enough operands." << endl;
                return 1;
            }

            int result;
            switch (c) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 == 0) {
                        cout << "Error: Division by zero." << endl;
                        return 1;
                    }
                    result = operand1 / operand2;
                    break;
            }
            push(result);
        }
    }

    if (top == 0) {
        cout << "Result: " << pop() << endl;
    } else {
        cout << "Error: Invalid expression, too many operands or not enough operators." << endl;
    }

    return 0;
}

