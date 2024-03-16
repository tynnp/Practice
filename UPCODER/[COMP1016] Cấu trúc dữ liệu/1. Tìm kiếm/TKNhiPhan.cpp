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
    cout << binarySearch(arr, n, k);
    return 0;
}