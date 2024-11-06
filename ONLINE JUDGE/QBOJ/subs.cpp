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

int n, s;
int a[105], dp[105][1005];

signed main() {
    fastIO;
    cin >> n >> s;

    for (int i = 1; i <= n; i++) 
        cin >> a[i];

    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            dp[i][j] = dp[i-1][j];

            if (j - a[i] >= 0)
                (dp[i][j] += dp[i-1][j - a[i]]) %= MOD;
        }
    }
    
    cout << dp[n][s];
    return 0;
}