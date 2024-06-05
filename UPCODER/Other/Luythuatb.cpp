#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;

ll binaryMul(ll a, ll b, ll MOD) {
    ll res = 0;
    a = a % MOD;
    
    while (b) {
        if (b & 1) res = (res + a) % MOD;
        a = (a << 1) % MOD;
        b /= 2;
    }
    
    return res;
}

ll binaryPow(ll a, ll b, ll MOD) {
    ll res = 1;
    a = a % MOD;
    
    while (b) {
        if (b & 1) res = binaryMul(res, a, MOD);
        a = binaryMul(a, a, MOD);
        b /= 2;
    }
    
    return res;
}

int main() {
    ll a, b;
    cin >> a >> b;
    cout << binaryPow(a, b, MOD);
    return 0;
}