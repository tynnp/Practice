#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define int long long
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename K, typename V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

int m, n, a[105][105];
int dp[105][105];

signed main() {
    fastIO;
    cin >> m >> n;

    for (int i = 1; i <= m; i++) 
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    for (int i = 1; i <= m; i++)
        dp[i][1] = a[i][1];

    for (int j = 2; j <= n; j++) {
        for (int i = 1; i <= m; i++) {
            dp[i][j] = dp[i][j-1];

            if (i > 1)
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]);

            if (i < m - 1)
                dp[i][j] = max(dp[i][j], dp[i+1][j-1]);
            
            dp[i][j] += a[i][j];
        }
    }

    int ans = LLONG_MIN;
    for (int i = 1; i <= m; i++)
        ans = max(ans, dp[i][n]);
    
    cout << ans;
    return 0;
}