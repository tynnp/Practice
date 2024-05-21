#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, t, res(INT_MIN);
    cin >> n >> t;
    vector<long long> arr(n+5, 0);
    
    while (t--) {
        int a, b, k;
        cin >> a >> b >> k;
        arr[a] += k;
        arr[b+1] -= k;
    }
    
    for (int i = 1; i <= n; i++)
        arr[i] += arr[i-1],
        res = max(res, arr[i]);
    
    cout << res;
    return 0;
}
