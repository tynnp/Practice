#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

signed main() {
    fastIO;
    int n, m;
    cin >> n >> m;
    
    vector<int> v(n);
    for (int &e : v) cin >> e;
    sort(v.begin(), v.end());
    
    int l = 0, r = n-1;
    
    while (m--) {
        int x, k, ans(0);
        cin >> x >> k;
      
        while (l <= r && x - k > v[l]) 
            ans += v[l++];

        while (l <= r && x + k < v[r])
            ans += v[r--];
        
        cout << ans << endl;
    }
    
    return 0;
}