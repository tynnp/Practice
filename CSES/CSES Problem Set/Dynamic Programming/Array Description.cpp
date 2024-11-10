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

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int n, m, ans;
int x[MAXN], dp[MAXN][105];

signed main() {
    fastIO;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> x[i];

    if (x[0] == 0) {
        for (int v = 1; v <= m; v++)
            dp[1][v] = 1;
    } else 
        dp[1][x[0]] = 1;

    for (int i = 2; i <= n; i++) {
        for (int v = 1; v <= m; v++) {
            if (x[i-1] == 0 || x[i-1] == v) {
                dp[i][v] = dp[i-1][v];
                (dp[i][v] += dp[i-1][v-1] + dp[i-1][v+1]) %= MOD;
            }
        }
    }

    for (int v = 1; v <= m; v++)    
        (ans += dp[n][v]) %= MOD;

    cout << ans;
    return 0;
}