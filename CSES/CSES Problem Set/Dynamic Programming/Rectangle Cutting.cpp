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

const int MAXN = 500 + 5;
const int MOD = 1e9 + 7;

int a, b, dp[MAXN][MAXN];

signed main() {
    fastIO;
    cin >> a >> b;

    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            if (i == j)
                dp[i][j] = 0;

            else {
                dp[i][j] = INT_MAX;

                for (int k = 1; k < i; k++)
                    dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
                
                for (int k = 1; k < j; k++)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
            }
        }
    }
    
    cout << dp[a][b];
    return 0;
}