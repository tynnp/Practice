#include <bits/stdc++.h>
using namespace std;

int sum(int n) {
    int res = 0;
    while (n) {
        res += n % 10;
        n /= 10;
    }
    return res;
}

bool check(int n) {
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) return false;
    return n > 1;
}

bool check(int a, int b) {
    if (sum(a) < sum(b)) return true;
    if (sum(a) == sum(b)) return a > b;
    return false;
} 

void reverseSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && check(arr[j-1], arr[j])) {
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
    
    for (int x : arr) 
        if (check(sum(x)))
            cout << x << " ";
    cout << endl;
    
    reverseSort(arr, n);
    for (int x : arr)
        cout << x << " ";
    
    return 0;
}