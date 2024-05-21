#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main() {
    ll n, tmp;
    const ll MOD = 1e6 + 7;
    cin >> n;
    
    ll res = 4;
    ll cur = res;
    
    for (ll i = 2; i <= n; i++) {
        if (i & 1) tmp = 1 + i;
        else tmp = 2 + 4*i;
        
        cur = (cur + tmp % MOD) % MOD;
        res = (res + cur) % MOD;
    }
    
    cout << res;
    return 0;
}