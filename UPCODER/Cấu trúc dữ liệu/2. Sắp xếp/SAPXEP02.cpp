#include <bits/stdc++.h>
using namespace std;

bool check(int n) {
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) return false;
    return n > 1;
}

void sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++)
            if (check(arr[i]) && check(arr[j]) && arr[j] < arr[i])
                swap(arr[i], arr[j]);
    }
}

int main() {
    int n;
    cin >> n;
    
    int arr[n];
    for (int &x : arr) cin >> x;
    
    sort(arr, n);
    for (int x : arr) cout << x << " ";
    return 0;
}