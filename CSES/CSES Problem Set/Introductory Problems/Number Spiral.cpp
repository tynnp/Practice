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

int t, x, y;

void solve() {
    cin >> x >> y;
    
    if (x >= y) {
        if (x & 1) cout << x*x - 2*x + y + 1;
        else cout << x*x - y + 1;
        cout << endl;
        return;
    }

    if (y & 1) cout << y*y - x + 1;
    else cout << y*y - 2*y + x + 1;
    cout << endl;
}

signed main() {
    fastIO;
    cin >> t;
    while (t--) solve();
    return 0;
}