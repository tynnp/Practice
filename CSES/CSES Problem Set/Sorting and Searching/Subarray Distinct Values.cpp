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

int n, k, cnt, ans;
map<int, int> m;

void solve() {
    cin >> n >> k;
    vector<int> v(n);
    for (int &x : v) cin >> x;
    
    int l = 0, r = 0;
    for (r = 0; r < n; r++) {
        m[v[r]]++;
        if (m[v[r]] == 1) cnt++;
        
        while (cnt > k) {
            if (m[v[l]] == 1) cnt--;
            m[v[l]]--;
            l++;
        } 
        
        ans += r - l + 1;
    }
    
    cout << ans;
}

signed main() {
    fastIO;
    solve();
    return 0;
}