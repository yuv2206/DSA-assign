#include <iostream>
#include <string.h>
using namespace std;


void first() {
    int arr[100], n, i, key;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter " << n << " sorted elements:\n";
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the element to search: ";
    cin >> key;

    int low = 0, high = n - 1, mid;
    int found = 0;
    int pos = -1;

    while (low <= high) {
        mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            found = 1;
            pos = mid;
            break;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (found == 1) {
        cout << "Element found at position " << pos << ".\n";
    } else {
        cout << "Element not found in the array.\n";
    }

}


void second() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = 7;
    int i, j, temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Sorted array is: ";
    for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

}



void third1() {
    int arr[100], n, i;
    cout << "Enter the size of the array (n-1): ";
    cin >> n;
    cout << "Enter " << n << " distinct sorted elements from 1 to " << n + 1 << ":\n";
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (i = 0; i < n; i++) {
        if (arr[i] != i + 1) {
            cout << "The missing number is " << i + 1 << ".\n";
           return;
        }
    }

    cout << "The missing number is " << n + 1 << ".\n";

}


void third2() {
    int arr[100], n, i;
    cout << "Enter the size of the array (n-1): ";
    cin >> n;
    cout << "Enter " << n << " distinct sorted elements from 1 to " << n + 1 << ":\n";
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int low = 0, high = n - 1, mid;
    int ans = n + 1;

    while (low <= high) {
        mid = low + (high - low) / 2;
        if (arr[mid] == mid + 1) {
            low = mid + 1;
        } else {
            ans = mid + 1;
            high = mid - 1;
        }
    }

    cout << "The missing number is " << ans << ".\n";

}


void fourth1() {
    char str1[100], str2[100];
    int i, j;

    cout << "Enter the first string: ";
    cin >> str1;
    cout << "Enter the second string: ";
    cin >> str2;

    i = 0;
    while (str1[i] != '\0') {
        i++;
    }

    j = 0;
    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';

    cout << "The concatenated string is: " << str1 << endl;

}


void fourth2() {
    char str[100], temp;
    int i, j;

    cout << "Enter a string: ";
    cin >> str;

    j = 0;
    while(str[j] != '\0'){
        j++;
    }
    j = j - 1;

    i = 0;
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }

    cout << "The reversed string is: " << str << endl;

}


void fourth3() {
    char str[100], result[100];
    int i, j = 0;

    cout << "Enter a string: ";
    cin >> str;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u' &&
            str[i] != 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'O' && str[i] != 'U') {
            result[j] = str[i];
            j++;
        }
    }
    result[j] = '\0';

    cout << "String after deleting vowels: " << result << endl;

}


void fourth4() {
    char str[10][50], temp[50];
    int i, j, n;

    cout << "Enter the number of strings: ";
    cin >> n;

    cout << "Enter " << n << " strings:\n";
    for (i = 0; i < n; i++) {
        cin >> str[i];
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(str[i], str[j]) > 0) {
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }

    cout << "Strings in alphabetical order:\n";
    for (i = 0; i < n; i++) {
        cout << str[i] << endl;
    }

}


void fourth5() {
    char ch;
    cout << "Enter an uppercase character: ";
    cin >> ch;

    if (ch >= 'A' && ch <= 'Z') {
        ch = ch + 32;
        cout << "The lowercase character is: " << ch << endl;
    } else {
        cout << "The character is not an uppercase letter.\n";
    }

}


void fifth1(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
	cout<<"Enter the diagonal elements: \n";
	cin>>arr[i];
    }
    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
	    if(row==col){
	        cout<<arr[row]<<" ";	
	    }
	    else{
	        cout<<"0 ";
	    }
        }
    cout<<endl;
    }
}


void fifth2(){
    int n;
    cout<<"Enter the size of matrice: ";
    cin>>n;
    int size = 3 * n - 2;
    int arr[size];
        cout << "Enter the " << size << " elements of the tridiagonal matrix:\n";
    for (int i = 0; i < size; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }
    int k = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row == col || row + 1 == col || col + 1 == row) {
                if (k < size) {
                    cout << arr[k] << " ";
                    k++;
                }
            } 
            else {
                cout << "0 ";
            }
        }
        cout << endl;
    }

}


void fifth3(){
    int n;
    cout<<"Enter the size of matrice: ";
    cin>>n;
    int size = (n*n + n)/2;
    int arr[size];
        cout << "Enter the " << size << " elements of the lower diagonal matrice:\n";
    for (int i = 0; i < size; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }
    int k = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row >= col){
                if (k < size) {
                    cout << arr[k] << " ";
                    k++;
                }
            } 
            else {
                cout << "0 ";
            }
        }
        cout << endl;
    }

    
}


void fifth4(){
    int n;
    cout<<"Enter the size of matrice: ";
    cin>>n;
    int size = (n*n + n)/2;
    int arr[size];
        cout << "Enter the " << size << " elements of the upper diagonal matrice:\n";
    for (int i = 0; i < size; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }
    int k = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row <= col){
                if (k < size) {
                    cout << arr[k] << " ";
                    k++;
                }
            } 
            else {
                cout << "0 ";
            }
        }
        cout << endl;
    }

    
}


void fifth5(){
    int n;
    cout<<"Enter the size of matrice: ";
    cin>>n;
    int size = (n*n + n)/2;
    int arr[size];
        cout << "Enter the " << size << " upper diagonal elements for symmetric matrice :\n";
    for (int i = 0; i < size; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }
    int k = 0;
    for (int row = 0; row < n; row++) {
        int t=row,q=n-1;
        for (int col = 0; col < n; col++) {
            if (row <= col){
                if (k < size) {
                    cout << arr[k] << " ";
                    k++;
                } 
            } 
            if (row>col){
                cout << arr[t]<<" ";
                t=t+q;
                q--;
            }   
        }
        cout << endl;
    }
}


void sixth3{
    //PART A
    int a[100][100], b[100][100], c[100][100];
    int r1, c1, r2, c2;
    cout << "Enter rows & cols of first matrix: ";
    cin >> r1 >> c1;
    cout << "Enter rows & cols of second matrix: ";
    cin >> r2 >> c2;

    if (r1 != r2 && c1!=c2) {
        cout << "addition not possible!";
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
            c[i][j] = a[i][j] * b[i][j];
        }

    cout << "Result:" << endl;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++)
            cout << c[i][j] << " ";
        cout << endl;
    }

}

    
void sixth2(){
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
}


void sixth1(){
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


void seven() {
    int arr[100], n, i, j;
    int count = 0;

    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements:\n";
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                count++;
            }
        }
    }

    cout << "The number of inversions is: " << count << endl;

}


void eight() {
    int arr[100], n, i, j;
    int count = 0;

    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements:\n";
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (i = 0; i < n; i++) {
        int is_distinct = 1;
        for (j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                is_distinct = 0;
                break;
            }
        }
        if (is_distinct == 1) {
            count++;
        }
    }

    cout << "The total number of distinct elements is: " << count << endl;
    
}

int main(){
    fifth5();
    return 0;
}
