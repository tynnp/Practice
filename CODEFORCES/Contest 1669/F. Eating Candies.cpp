#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
  
    ll t;
    cin >> t;
    
    while (t--) {
        ll n;
        cin >> n;
        
        vector<ll> v(n);
        for (ll &x : v) cin >> x;
        
        ll i = 0, j = n-1;
        ll sumA = 0, sumB = 0, ans = 0;
        
        while (i <= j) {
            if (sumA > sumB) sumB += v[j--];
            else if (sumA < sumB) sumA += v[i++];
            else if (v[i] > v[j]) sumB += v[j--];
            else sumA += v[i++];
            if (sumA == sumB) ans = max(ans, n+i-j-1);
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}