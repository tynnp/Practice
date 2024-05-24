#include <bits/stdc++.h>
#define ll unsigned long long 
using namespace std;

int main() {
    ll n, m, i(0), tmp(0);
    cin >> n >> m;
    vector<ll> v(n);
    
    for (ll i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        v[i] = a*b;
    }
    
    while (m--) {
        int k;
        cin >> k;
        k -= tmp;
        
        while (i < n) {
            if (k <= v[i]) {
                cout << i + 1 << '\n';
                break;
                
            } else {
                k -= v[i];
                tmp += v[i];
            }
            
            i++;
        }
    }
    
    return 0;
}