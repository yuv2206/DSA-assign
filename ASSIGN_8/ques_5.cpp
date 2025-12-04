#include <iostream>
using namespace std;

void heapifyMax(int a[], int n, int i) {
    int big = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && a[l] > a[big])
        big = l;
    if (r < n && a[r] > a[big])
        big = r;

    if (big != i) {
        swap(a[i], a[big]);
        heapifyMax(a, n, big);
    }
}

void heapifyMin(int a[], int n, int i) {
    int small = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && a[l] < a[small])
        small = l;
    if (r < n && a[r] < a[small])
        small = r;

    if (small != i) {
        swap(a[i], a[small]);
        heapifyMin(a, n, small);
    }
}

void heapSortInc(int a[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapifyMax(a, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapifyMax(a, i, 0);
    }
}

void heapSortDec(int a[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapifyMin(a, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapifyMin(a, i, 0);
    }
}

int main() {
    int n;
    cout << "Size: ";
    cin >> n;

    int a[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "\n1. Increasing Order\n2. Decreasing Order\nChoice: ";
    int ch;
    cin >> ch;

    if (ch == 1)
        heapSortInc(a, n);
    else
        heapSortDec(a, n);

    cout << "Sorted: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}
