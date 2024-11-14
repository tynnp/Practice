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
int a[MAXN], dp[MAXN][105];

signed main() {
    fastIO;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    if (a[1]) 
        dp[1][a[1]] = 1;
    else {
        for (int j = 1; j <= m; j++)
            dp[1][j] = 1;
    }

    for (int i = 2; i <= n; i++) 
        for (int j = 1; j <= m; j++) 
            if (!a[i] || a[i] == j)
                (dp[i][j] += (dp[i-1][j]+ dp[i-1][j-1] + dp[i-1][j+1])) %= MOD;
            
    for (int j = 1; j <= m; j++)
        (ans += dp[n][j]) %= MOD;

    cout << ans;
    return 0;
}