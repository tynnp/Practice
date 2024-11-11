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

int n, t, dp[MAXN][3];

signed main() {
    fastIO;
    cin >> t;
    dp[1][1] = dp[1][2] = 1;

    for (int i = 2; i < MAXN; i++) {
        (dp[i][1] = dp[i-1][2] % MOD + 4*dp[i-1][1] % MOD) %= MOD;
        (dp[i][2] = dp[i-1][1] % MOD + 2*dp[i-1][2] % MOD) %= MOD;
    }

    while (t--) {
        cin >> n;
        cout << (dp[n][1] % MOD + dp[n][2] % MOD) % MOD << endl;
    }
    
    return 0;
}