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

int n, ans;

void solve() {
    cin >> n;
    int k = 5;
    ans = 0;
    
    while (k <= n) {
        ans += n/k;
        k  *= 5;
    }
    
    cout << ans << endl;
}

signed main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}