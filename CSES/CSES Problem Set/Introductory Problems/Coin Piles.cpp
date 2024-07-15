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

int t, a, b;

void solve() {
    cin >> a >> b;

    if ((a + b) % 3 == 0 && min(a, b)*2 >= max(a, b)) 
        cout << "YES\n";
    else 
        cout << "NO\n";
}

signed main() {
    fastIO;
    cin >> t;
    while (t--) solve();
    return 0;
}