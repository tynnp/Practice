#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll n;
vector<ll> v;

int search(ll x) {
    ll l = 0;
    ll r = v.size()-1;
    
    while (l <= r) {
        ll mid = (l + r)/2;
        if (v[mid] >= x) r = mid - 1;
        else if (v[mid] < x) l = mid + 1;
    }
    
    return l;
}

int main() {
    cin >> n;
    vector<ll> a(n);
    for (ll &x : a) cin >> x;
    
    for (ll x : a) {
        ll pos = search(x);
        if (pos == v.size()) v.push_back(x);
        else v[pos] = x;
    }
    
    cout << v.size();
    return 0;
}
