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

int n, x, sum, ans;
map<int, int> m;

void solve() {
    cin >> n >> x;
    vector<int> v(n);
    for (int &x : v) cin >> x;
    
    m[0] = 1;
    for (int e : v) {
        sum += e;
        
        if (m.find(sum - x) != m.end())
            ans += m[sum - x];
        
        m[sum]++;
    }
    
    cout << ans;
}

signed main() {
    fastIO;
    int t;
    //cin >> t;
    t = 1;
    
    while (t--)
        solve();
    return 0;
}