#include <bits/stdc++.h>  
#define ll long long
using namespace std;

int main() {
    ll n, m, tmp;
    cin >> n >> m;
    
    vector<ll> v(n);
    for (ll &x : v) cin >> x;
    
    while (m--) {
        cin >> tmp;
        int i = 0;
        while (tmp - v[i] > 0) tmp -= v[i],  i++;
        cout << i+1 << " " << tmp << endl;
    }
    
    return 0;
}