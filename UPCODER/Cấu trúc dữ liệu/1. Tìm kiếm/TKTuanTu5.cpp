#include <bits/stdc++.h>
using namespace std;

int sequentialSearch(int arr[], int n, int x, int y) {
    for (int i = 0; i < n; i++)
        if (arr[i] == x) return i;
        
    int a = x, b = x;
    while (a >= x - y && b <= x + y) {
        for (int i = 0; i < n; i++) {
            if (arr[i] == a || arr[i] == b)
                return i;
        }
        a--, b++;
    }
    
    return -1;
}

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    
    int arr[n];
    for (int &i : arr) cin >> i;
    
    cout << sequentialSearch(arr, n, x, y);
    return 0;
}