#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int k) {
    int mid;
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] == k) return mid;
        if (arr[mid] < k) left = mid + 1;
        else right = mid - 1;
    }

    return -1;
}

int main() {
    int n, k; 
    cin >> n >> k;
    int arr[n];
    for (int &x : arr) cin >> x;

    if (binarySearch(arr, n, k) != -1) {
        for (int i = 0; i < n; i++)
            if (arr[i] == k) cout << i << " ";
    } else cout << -1;
    
    return 0;
}