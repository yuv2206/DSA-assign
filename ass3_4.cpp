#include <iostream>
#include <string>
#include <stack>

using namespace std;

int pre(char c) {
    if (c == '*' || c == '/') {
        return 2;
    }
    if (c == '+' || c == '-') {
        return 1;
    }
    return -1;
}

int main() {
    string infix;
    cout << "Enter the expression: ";
    cin >> infix;
    string postfix = "";
    stack<char> s;
    s.push('(');
    infix += ')';
    for (char c : infix) {
        if (c == '(') {
            s.push(c);
        } else if (isalnum(c)) {
            postfix += c;
        } else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty()) {
                s.pop();
            }
        } else {
            while (!s.empty() && s.top() != '(' && pre(s.top()) >= pre(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    cout << "Postfix: " << postfix << endl;
    return 0;
}

