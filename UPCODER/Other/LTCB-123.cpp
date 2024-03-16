#include <iostream>
using namespace std;

int indexArr(int arr[], int n) {
    int min = 10e6, index = -1;
    for (int i = 0; i < n; i++)
        if ( arr[i] < min) min = arr[i], index = i;
    return index;
}

int main() {
    int n; 
    cin >> n; 
    int arr[n];
    for (int &x : arr) cin >> x;
    cout << indexArr(arr, n);
    return 0;
}