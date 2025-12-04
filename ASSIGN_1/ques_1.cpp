#include<iostream>
using namespace std;


void first(){
    int arr[100], n, choice;
    cout << "enter size of array : ";
    cin >> n;
    
    cout << "Enter " << n << " elements: " << endl;
    for (int i = 0; i < n; i++) {
    cin >> arr[i];
    }
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    int pos, val;
    cout << "Enter position and value: ";
    cin >> pos >> val;
    if (pos < 0 || pos > n) {
        cout << "Invalid position" << endl;
        return;
    }
    for (int i = n; i > pos; i--){
        arr[i] = arr[i-1];
    }
    arr[pos] = val;
    n++;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    int pos1;
    cout << "Enter position to delete: ";
    cin >> pos1;
    if (pos1 < 0 || pos1 >= n) {
        cout << "Invalid position" << endl;
        return;
    }
    for (int i = pos1; i < n-1; i++) arr[i] = arr[i+1];
    n--;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    int key;
    cout << "Enter value to search: ";
    cin >> key;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Found at index " << i << endl;
            cout << "\n\n\n\n\n";
            return;
        }
    }
    cout << "Not found" << endl;
    cout << "\n\n\n\n\n";

}


void second(){
    int  arr[100];
    int arr2[100];
    int n,k=0;
    cout << "enter size of array ";
    cin >> n;
    cout << "enter array" << endl;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    for(int j=0; j<n; j++){
        for(int k=0; k < n - j - 1; k++){
            if(arr[k] > arr[k+1]){
                int temp = arr[k];
                arr[k] = arr[k+1];
                arr[k+1] = temp;
            }
        }
    }

    k = 0;
    for(int i = 0; i < n; i++) {
        if (i == 0 || arr[i] != arr[i - 1]) {
            arr2[k] = arr[i];
            k++;
        }
    }

    cout << "Distinct elements are: " <<endl;
    for(int i = 0; i < k; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    cout << "\n\n\n\n\n";
}


void third(){
    int i;
    int arr[5] = {1};
    for (i = 0; i < 5; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "\n\n\n\n\n";
}


void fourth(){
    //PART A
    int arr[100];
    int n;

    cout << "enter size of array ";
    cin >> n;
    cout << "enter array" << endl;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    for (int i = 0; i < n/2; i++){
        swap(arr[i], arr[n-i-1]);
    }
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    
    // PART B
    int a[100][100], b[100][100], c[100][100];
    int r1, c1, r2, c2;
    cout << "Enter rows & cols of first matrix: ";
    cin >> r1 >> c1;
    cout << "Enter rows & cols of second matrix: ";
    cin >> r2 >> c2;

    if (c1 != r2) {
        cout << "Multiplication not possible!";
    }

    cout << "Enter first matrix:" << endl;
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            cin >> a[i][j];

    cout << "Enter second matrix:" <<endl;
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            cin >> b[i][j];

    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++) {
            c[i][j] = 0;
            for (int k = 0; k < c1; k++)
                c[i][j] += a[i][k] * b[k][j];
        }

    cout << "Result:" << endl;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++)
            cout << c[i][j] << " ";
        cout << endl;
    }

    //PART C
    int arr1[100][100];
    int row,col;

    cout << "enter size of row " << endl;
    cin >> row;
    cout << "enter size of col " << endl;
    cin >> col;
    cout << "enter array" << endl;
    for(int i=0; i<row; i++){
        for(int j=0;j<col;j++){
         cin >> arr1[i][j];
        }
    }
    int tran[100][100];
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
             tran[j][i] = arr1[i][j];

    cout << "Transpose:\n";
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++)
            cout << tran[i][j] << " ";
        cout << endl;
    }
    cout << "\n\n\n\n\n";
}


void fifth(){
    int a[100][100], r, c;
    cout << "Enter rows and columns: ";
    cin >> r >> c;
    cout << "Enter matrix:" << endl;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> a[i][j];

    for (int i = 0; i < r; i++) {
        int sumRow = 0;
        for (int j = 0; j < c; j++) {
        sumRow += a[i][j];
        }
        cout << "Sum of row " << i << ": " << sumRow << endl;
    }

    for (int j = 0; j < c; j++) {
        int sumCol = 0;
        for (int i = 0; i < r; i++){
            sumCol += a[i][j];
        }
        cout << "Sum of col " << j << ": " << sumCol << endl;
    }
}


int main(){
    first();
    second();
    third();
    fourth();
    fifth();
    return 0;
}
