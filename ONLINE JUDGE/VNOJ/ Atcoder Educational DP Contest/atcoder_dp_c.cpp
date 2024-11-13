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

int n, dp[MAXN][4];

signed main() {
    fastIO;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        dp[i][1] = max(dp[i-1][2], dp[i-1][3]) + a;
        dp[i][2] = max(dp[i-1][1], dp[i-1][3]) + b;
        dp[i][3] = max(dp[i-1][1], dp[i-1][2]) + c;
    }
    
    cout << max({dp[n][1], dp[n][2], dp[n][3]});
    return 0;
}