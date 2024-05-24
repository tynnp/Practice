#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
  
    ll t = 1;
    
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
            else sumB += v[j--];
            if (sumA == sumB) ans = max(ans, sumA);
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}