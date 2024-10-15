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

const int MAXN = 100 * 1000 + 5;
const int MOD = 1e9 + 7;

int n, W, ans;
int w[105], v[105], dp[MAXN];

signed main() {
    fastIO;
    cin >> n >> W;

    for (int i = 0; i < n; i++) 
        cin >> w[i] >> v[i];
    fill(dp, dp + MAXN, INT_MAX);

    dp[0] = 0;
    for (int i = 0; i < n; i++)
        for (int x = MAXN - 1; x >= v[i]; x--)
            dp[x] = min(dp[x], dp[x - v[i]] + w[i]);
    
    for (int i = 0; i < MAXN; i++)
        if (dp[i] <= W)
            ans = i;

    cout << ans;
    return 0;
}