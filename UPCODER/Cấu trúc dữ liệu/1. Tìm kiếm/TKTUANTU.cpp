#include <iostream>
using namespace std;

int sequentialSearch(int arr[], int n, int k) {
    for (int i = 0; i < n; i++) 
        if (arr[i] == k) return i;
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k; 
    cin >> n >> k;
    int arr[n];
    
    for (int &x : arr) cin >> x;
    cout << sequentialSearch(arr, n, k);
    return 0;
}