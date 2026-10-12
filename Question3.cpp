#include <iostream>

using namespace std;

int sumRow(int* row, int n) {
    if (n <= 0) {
        return 0;
    }
    return row[n - 1] + sumRow(row, n - 1);
}

int recursiveArraySum(int* arr[], int sizes[], int dim) {
    if (dim <= 0) {
        return 0;
    }
    
    int currentRowSum = sumRow(arr[dim - 1], sizes[dim - 1]);
    return currentRowSum + recursiveArraySum(arr, sizes, dim - 1);
}

int main() {
    int numRows = 3;
    
    int** arr = new int*[numRows];
    int* sizes = new int[numRows];
    
    sizes[0] = 4;
    sizes[1] = 2;
    sizes[2] = 3;
    
    for (int i = 0; i < numRows; ++i) {
        arr[i] = new int[sizes[i]];
    }
    
    arr[0][0] = 1; arr[0][1] = 2; arr[0][2] = 3; arr[0][3] = 4;
    arr[1][0] = 5; arr[1][1] = 6;
    arr[2][0] = 7; arr[2][1] = 8; arr[2][2] = 9;
    
    int totalSum = recursiveArraySum(arr, sizes, numRows);
    
    cout << "Total Sum of Jagged Array: " << totalSum << endl; 
    
    for (int i = 0; i < numRows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
    delete[] sizes;
    
    return 0;
}
