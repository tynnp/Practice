#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, cnt = 0;
    cin >> n;

    long long arr[n];
    for (long long &x : arr) cin >> x;

    long long m = arr[0];
    for (long long i = 1; i < n; i++) {
        cnt += max(0LL, m - arr[i]);
        m = max(m, arr[i]);
    }
    
    cout << cnt;
    return 0;
}