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

int n, ans, sum;

void solve() {
    cin >> n;
    vector<int> v(n);
    
    for (int &x : v) 
      cin >> x; 
    
    int i = 0;
    while (i < n) {
        int l = i;
        int r = i + 1;
        int sl = 0, sr = 0;
        
        while (l >= 0) {
            sl += v[l];
            
            while (r < n && (sr < sl || v[r] == 0)) 
                sr += v[r++];
            
            if (sl == sr) 
                ans = max(ans, r - l);
            
            l--;
        }
        
        i++;
    }
      
    cout << ans; 
}

signed main() {
    fastIO;
    solve();
    return 0;
}