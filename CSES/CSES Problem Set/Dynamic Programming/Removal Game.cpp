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

const int MAXN = 5000 + 5;
const int MOD = 1e9 + 7;

int n, sum, a[MAXN];
int dp[MAXN][MAXN];

signed main() {
    fastIO;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    for (int len = 1; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;

            if (i == j)
                dp[i][j] = a[i];
            else 
                dp[i][j] = max(a[i] - dp[i+1][j], a[j] - dp[i][j-1]);
        }
    }
    
    cout << (sum + dp[1][n]) / 2;
    return 0;
}