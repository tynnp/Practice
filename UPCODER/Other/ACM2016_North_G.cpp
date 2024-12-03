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
#define fastIO ios_base::sync_with_stdio(false); cin.tie(nullptr)
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename K, typename V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

const int MAXN = 1000 + 5;
const int MOD = 1e9 + 7;

int n, m, ans;
int a[MAXN][MAXN];
int sum[MAXN][MAXN];

signed main() {
    fastIO;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    for (int i = 1; i <= n; i++)    
        for (int j = 1; j <= m; j++)
            sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + a[i][j];
    
    ans = INT_MAX;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x = sum[i][j];
            int y = sum[n][j] - x;
            int z = sum[i][m] - x;
            int t = sum[n][m] - x - y - z;

            int maxVal = max({x, y, z, t});
            int minVal = min({x, y, z, t});
            ans = min(ans, abs(maxVal - minVal));
        }
    }

    cout << ans;
    return 0;
}