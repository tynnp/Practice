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

int n, W, H, sum;
int w[105], v[105];
int dp[105][MAXN][2];

signed main() {
    fastIO;
    cin >> n >> W >> H;

    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
        sum += v[i];
    }

    memset(dp, 0x3f, sizeof(dp));
    dp[0][0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][0]);
            dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j][1]);

            if (j - v[i] >= 0) {
                dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j - v[i]][0] + w[i]);
                dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j - v[i]][1] + w[i]);
            }

            if (j - v[i] >= 0 && w[i] <= H) 
                dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j - v[i]][0]);
        }
    }

    for (int ans = sum; ans > 0; ans--) {
        if (dp[n][ans][0] <= W || dp[n][ans][1] <= W) {
            cout << ans;
            break;
        }
    }
    
    return 0;
}