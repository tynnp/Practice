#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define int long long
#define elif else if 
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)
#define indexed_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

int n, m, s;
int dp[505][130005];

signed main() {
    fastIO;
    cin >> n;
    m = n*(n + 1) >> 1;
    s = m >> 1;

    dp[0][0] = 1;
    for (int i = 0; i <= s; i++) {
        for (int j = 1; j < n; j++) {
            dp[j][i] = dp[j-1][i];

            if (i - j >= 0) {
                dp[j][i] = dp[j-1][i] + dp[j-1][i-j];
                dp[j][i] %= MOD;
            }
        }
    }

    if (m & 1)
        cout << 0;
    else 
        cout << dp[n-1][s];
    
    return 0;
}