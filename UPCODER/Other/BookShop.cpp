#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define int long long
#define inp freopen("BOOKS.INP", "r", stdin)
#define out freopen("BOOKS.OUT", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename K, typename V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

const int MAXN = 1e4 + 5;
const int MOD = 1e9 + 7;

int n, x, dp[MAXN];
int a[1005], b[1005];

signed main() {
    fastIO; inp; out;
    cin >> n >> x;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
        cin >> b[i];
    
    for (int i = 1; i <= n; i++) 
        for (int j = x; j >= a[i]; j--)
            if (j - a[i] >= 0)
                dp[j] = max(dp[j], dp[j - a[i]] + b[i]);

    cout << dp[x];
    return 0;
}