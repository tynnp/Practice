#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define int long long
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)
#define indexed_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int n, m, dp[105][MAXN];
int w[105], v[105];

signed main() {
    fastIO;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) 
        cin >> w[i] >> v[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = dp[i-1][j];
            if (j - w[i] >= 0) 
                dp[i][j] = max(dp[i][j], dp[i-1][j - w[i]] + v[i]);
        }
    }
    
    cout << dp[n][m];
    return 0;
}