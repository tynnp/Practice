#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAXN 1e5 + 1

ll n, m(0), ans(0);
vector<pair<ll, ll>> b(MAXN);

int seach(int l, int r, int x) {
    while (l <= r) {
        int mid = (l + r) / 2;
        if (b[mid].first == x) return mid;
        else if (b[mid].first > x) r = mid - 1;
        else l = mid + 1;
    }
    
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    vector<ll> a(n);
    
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    
    for (int i = 0; i < n; i++) {
        if (i == 0 || a[i] != a[i-1]) {
            m++;
            b[m].first = a[i];
            b[m].second = 1;
        } else 
            b[m].second++;
    }
    
    //debug
    // for (int i = 0; i < n; i++)
    //     cout << a[i] << endl;
    
    // for (int i = 1; i <= m; i++)
    //     cout << b[i].first << " " << b[i].second << endl;
    
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < 31; j++) {
            ll p = 1LL << j;
            
            if (p >= b[i].first) {
                if (p > b[i].first) {
                    int pos = seach(0, i-1, p - b[i].first);
                    if (pos != -1) ans += b[i].second * b[pos].second;
                } 
                
                if (p == b[i].first) 
                    ans += b[i].second * (b[i].second - 1) / 2;
            }
        }
    }
    
    cout << ans;
    return 0;
}