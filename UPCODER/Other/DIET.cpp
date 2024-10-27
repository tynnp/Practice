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

int n, a[MAXN], b[MAXN], c[MAXN];
int dp[MAXN][4];

signed main() {
    fastIO;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
        cin >> b[i];

    for (int i = 1; i <= n; i++)
        cin >> c[i];

    for (int i = 1; i <= n; i++) {
        dp[i][1] = max(dp[i-1][2], dp[i-1][3]) + a[i];
        dp[i][2] = max(dp[i-1][1], dp[i-1][3]) + b[i];
        dp[i][3] = max(dp[i-1][2], dp[i-1][1]) + c[i];

    }
    
    cout << max(dp[n][1], max(dp[n][2], dp[n][3]));
    return 0;
}