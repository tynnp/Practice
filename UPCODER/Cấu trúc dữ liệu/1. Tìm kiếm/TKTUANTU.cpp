#include <bits/stdc++.h>
using namespace std;

int sequentialSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int main() {
    int n, x;
    cin >> n >> x;
    
    int arr[n];
    for (int &i : arr) cin >> i;
    
    cout << sequentialSearch(arr, n, x);
    return 0;
}