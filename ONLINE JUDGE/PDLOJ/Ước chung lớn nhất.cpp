#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define inp freopen("uoc.inp", "r", stdin)
#define out freopen("uoc.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

signed main() {
    fastIO; inp; out;
    int a, b;
    cin >> a >> b;
    cout << __gcd(a, b);
    return 0;
}