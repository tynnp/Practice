#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define int long long
#define inp freopen("DIGITS.INP", "r", stdin)
#define out freopen("DIGITS.OUT", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename K, typename V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

int n, dp[MAXN];

signed main() {
    fastIO; inp; out;
    cin >> n;
    fill(dp, dp + MAXN, INT_MAX);

    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int d = i;

        while (d) {
            dp[i] = min(dp[i], dp[i - d % 10] + 1);
            d /= 10;
        }
    }
    
    cout << dp[n];
    return 0;
}