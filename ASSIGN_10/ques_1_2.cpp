#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Matrix {
    int matrix[10][10];
    int n;
    int sum = 0, sum1 = 0;

public:
    void set() {
        cout << "enter size: ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << "enter input [" << i + 1 << "][" << j + 1 << "] : ";
                cin >> matrix[i][j];
            }
        }
    }

    void display() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void calcd() {
        sum = 0;
        sum1 = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    sum = sum + matrix[i][j];
                sum1 = sum1 + matrix[i][j];
            }
            cout << i + 1 << " : " << sum1 << endl;
            sum1 = 0;
        }
        cout << "self: " << sum << endl;
    }

    void calci() {
        sum = 0;
        sum1 = 0;
        cout << "outorder: " << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sum1 = sum1 + matrix[i][j];
            }
            cout << i + 1 << " : " << sum1 << endl;
            sum1 = 0;
        }
        cout << "inorder: " << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sum1 = sum1 + matrix[j][i];
            }
            cout << i + 1 << " : " << sum1 << endl;
            sum1 = 0;
        }
    }

    void BFS(int start) {
        vector<bool> visited(n, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);
        cout << "BFS Traversal: ";
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u + 1 << " ";
            for (int v = 0; v < n; v++) {
                if (matrix[u][v] == 1 && !visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }

    void DFSUtil(int node, vector<bool> &visited) {
        visited[node] = true;
        cout << node + 1 << " ";
        for (int v = 0; v < n; v++) {
            if (matrix[node][v] == 1 && !visited[v]) {
                DFSUtil(v, visited);
            }
        }
    }

    void DFS(int start) {
        vector<bool> visited(n, false);
        cout << "DFS Traversal: ";
        DFSUtil(start, visited);
        cout << endl;
    }
};

int main() {
    int choice = 0;
    Matrix obj;
    obj.set();
    obj.display();

    cout << "\nChoose operation:\n";
    cout << "1. Undirected (Degree)\n";
    cout << "2. Directed (In/Out Degree)\n";
    cout << "3. BFS Traversal\n";
    cout << "4. DFS Traversal\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1)
        obj.calcd();
    else if (choice == 2)
        obj.calci();
    else if (choice == 3) {
        int start;
        cout << "Enter starting node (1 to n): ";
        cin >> start;
        obj.BFS(start - 1);
    }
    else if (choice == 4) {
        int start;
        cout << "Enter starting node (1 to n): ";
        cin >> start;
        obj.DFS(start - 1);
    }
    else
        cout << "Invalid choice";

    return 0;
}
