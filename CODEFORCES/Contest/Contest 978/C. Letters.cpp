#include <bits/stdc++.h>  
#define ll long long
using namespace std;

int main() {
    ll n, m, tmp, sum(0), i(0);
    cin >> n >> m;
    
    vector<ll> v(n);
    for (ll &x : v) cin >> x;
    
    while (m--) {
        cin >> tmp;
        while (sum + v[i] < tmp) sum += v[i++];
        cout << i+1 << " " << tmp - sum << endl;
    }
    
    return 0;
}