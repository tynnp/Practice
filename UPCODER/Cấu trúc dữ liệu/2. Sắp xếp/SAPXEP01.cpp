#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int a, int b) {
    for (int i = a+1; i < b; i++) {
        int j = i;
        while (j > a && arr[j-1] > arr[j]) {
            swap(arr[j-1], arr[j]);
            j--;
        }
    }
}

void reverse(int arr[], int a, int b) {
    for (int i = a+1; i < b; i++) {
        int j = i;
        while (j > a && arr[j-1] < arr[j]) {
            swap(arr[j-1], arr[j]);
            j--;
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    int arr[n];
    for (int &x : arr) cin >> x;
    
    insertionSort(arr, 0, n/2);
    reverse(arr, (n + 1)/2, n);
    
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    
    return 0;
}