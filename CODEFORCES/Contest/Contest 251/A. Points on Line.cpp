#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, d, res(0);
    cin >>n >> d;
    
    vector<long long> v(n);
    for (long long &x : v) cin >> x;
    sort(v.begin(), v.end());
    
    for (long long i = 0, j = 0; i < n; i++) {
        while (v[i] - v[j] > d) j++;
        res += (i-j) * (i-j-1) / 2;
    }
    
    cout << res;
    return 0;
}