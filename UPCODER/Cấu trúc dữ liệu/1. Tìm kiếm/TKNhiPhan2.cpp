#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n, int x) {
    int left = 0;
    int right = n-1;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] < x) left = mid + 1;
        else if (arr[mid] > x) right = mid - 1;
        else return mid;
    }
    
    return -1;
}

int binarySearch(int arr[], int left, int right, int x) {
    if (left > right) return -1;
    int mid = (left + right) / 2;
    
    if (arr[mid] < x) return binarySearch(arr, mid+1, right, x);
    else if (arr[mid] > x) return binarySearch(arr, left, mid-1, x);
    else return mid;
}

int main() {
    int n, x;
    cin >> n >> x;
    
    int arr[n];
    for (int &i : arr) cin >> i;
    
    if (binarySearch(arr, n, x) != -1) {
        for (int i = 0; i < n; i++)
            if (arr[i] == x)
                cout << i << " ";
    } else cout << -1;
    
    return 0;
} 