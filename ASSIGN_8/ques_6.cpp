#include <iostream>
using namespace std;

class PriorityQueue {
    int heap[100];
    int size;

public:
    PriorityQueue() {
        size = 0;
    }

    void insert(int value) {
        heap[size] = value;
        int i = size;
        size++;

        while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    int extractMax() {
        if (size <= 0) {
            cout << "Queue is empty!\n";
            return -1;
        }

        int maxVal = heap[0];
        heap[0] = heap[size - 1];
        size--;

        heapify(0);
        return maxVal;
    }

    void heapify(int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && heap[left] > heap[largest])
            largest = left;

        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapify(largest);
        }
    }

    void display() {
        cout << "Priority Queue (Heap): ";
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }

    bool isEmpty() {
        return size == 0;
    }
};


int main() {
    PriorityQueue pq;
    int choice, value;

    while (true) {
        cout << "\n=== Priority Queue Menu ===\n";
        cout << "1. Insert\n2. Extract Max\n3. Display\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                pq.insert(value);
                break;

            case 2:
                value = pq.extractMax();
                if (value != -1)
                    cout << "Removed Max: " << value << endl;
                break;

            case 3:
                pq.display();
                break;

            case 4:
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}
