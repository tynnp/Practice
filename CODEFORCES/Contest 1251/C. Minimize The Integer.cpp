#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
  
    ll t;
    cin >> t;
    
    while (t--) {
        string s;
        cin >> s;
        
        vector<ll> a, b, res;
        for (const char &c : s) {
            if (c & 1) b.push_back(c - '0');
            else a.push_back(c - '0');
        }
        
        ll i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] < b[j]) res.push_back(a[i++]);
            else res.push_back(b[j++]);
        }
        
        while (i < a.size()) 
            res.push_back(a[i++]);
            
        while (j < b.size())
            res.push_back(b[j++]);
        
        for (const ll &x : res) cout << x;
        cout << '\n';
    }
    
    return 0;
}