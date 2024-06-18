#include <bits/stdc++.h>
using namespace std;

int arr[3];

bool prime(int n) {
    for (int i = 2; i*i <= n; i++)  
        if (n % i == 0) return false;
    return n > 1;
}

int solve() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (i != j && prime(arr[i]*10 + arr[j]))
                return arr[i]*10 + arr[j];
    return -1;
}

int main() {
    for (int &x : arr) cin >> x;
    cout << solve();
    return 0;
}