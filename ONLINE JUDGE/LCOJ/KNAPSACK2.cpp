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

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

int n, m, sum;
int w[105], v[105];

signed main() {
    fastIO;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
        sum += v[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, LLONG_MAX));
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        dp[i][0] = 0;
        for (int j = 1; j <= sum; j++) {
            dp[i][j] = dp[i-1][j];
            if (j - v[i] >= 0 && dp[i-1][j - v[i]] != LLONG_MAX)
                dp[i][j] = min(dp[i][j], dp[i-1][j - v[i]] + w[i]);
        }
    }

    for (int ans = sum; ans > 0; ans--) {
        if (dp[n][ans] <= m) {
            cout << ans;
            break;
        }
    }
    
    return 0;
}