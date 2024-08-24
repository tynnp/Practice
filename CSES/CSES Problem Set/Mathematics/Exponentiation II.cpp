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

int binaryPow(int a, int b, int m) {
    int res = 1;
    a %= m;
    
    while (b) {
        if (b & 1) 
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    
    return res;
}

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << binaryPow(a, binaryPow(b, c, MOD - 1), MOD) << endl;
}

signed main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}